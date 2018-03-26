//
// Created by valentin on 06/02/18.
//

#ifndef CPP_RTYPE_DLINSTANCELOADER_HPP
#define CPP_RTYPE_DLINSTANCELOADER_HPP

#include <memory>
#include <cassert>
#include <iostream>
#include <functional>
#include "ImplDllLoader.hpp"

namespace zia {
	namespace module
	{

		namespace detail {

			class loader_base {
			public:

				using Loader = detail::ImplDllLoader;

				loader_base(char const *lib) noexcept :
					_loader(), _handle(_loader.loadLibrary(lib))
				{}


				loader_base(loader_base const&) = delete;
				loader_base& operator=(loader_base const&) = delete;

				loader_base(loader_base&& r) :
					_handle(r._handle), _loader(std::move(r._loader))
				{
					r._handle = InvalidHandle;
				}

				loader_base& operator=(loader_base&& r)
				{
					if (this != &r)
					{
						_handle = r._handle;
						_loader = std::move(r._loader);
						r._handle = InvalidHandle;
					}
					return *this;
				}

				~loader_base() noexcept {
					_loader.closeLibrary(_handle);
					_handle = InvalidHandle;
				}

				Sym loadSymbol(char const *s) noexcept
				{
					return _loader.loadSymbol(_handle, s);
				}

				bool isLoaded() const noexcept {
					return _handle != InvalidHandle;
				}

				Handle handle() const {
					return _handle;
				}

			private:
				Loader _loader;
				Handle _handle;
			};

			template<typename TInterface>
			class InstanceLoaderBase {
			public:

				using value_type = std::remove_pointer_t<TInterface>;
				using pointer = std::add_pointer_t<value_type>;

				InstanceLoaderBase() noexcept :
					_ctor(InvalidSym), _dtor(InvalidSym)
				{}

				template<typename TLoader>
				InstanceLoaderBase(TLoader& loader, char const *entry,
								   char const *dtor) noexcept :
					_ctor(loader.loadSymbol(entry)), _dtor(loader.loadSymbol(dtor))
				{}

				template<typename TLoader>
				bool loadSymbols(TLoader& loader,
								 char const *ctor,
								 char const *dtor) noexcept {
					_ctor = loader.loadSymbol(ctor);
					_dtor = loader.loadSymbol(dtor);
					return canLoad();
				}

				template<typename ...Args>
				pointer loadInstance(Args&& ...args) {
					using ctor_t = pointer (*)(std::remove_reference_t<Args>...);

					if (!canLoad())
						return nullptr;
					auto make_instance = reinterpret_cast<ctor_t>(_ctor);
					return make_instance(std::forward<Args>(args)...);
				}

				void deleteInstance(pointer i) const noexcept
				{
					if (canLoad())
					{
						std::cout << "Delete instance" << std::endl;
						using dtor_t = void (*)(pointer);
						auto dtor_instance = reinterpret_cast<dtor_t>(_dtor);
						dtor_instance(i);
					}
				}

				bool canLoad() const noexcept {
					return _ctor != InvalidSym && _dtor != InvalidSym;
				}
			private:
				Sym _ctor;
				Sym _dtor;
			};


			template<typename TInterface>
			class LoaderImpl
				: public loader_base,
				  public InstanceLoaderBase<TInterface>
			{
			public:
				using Base = loader_base;
				using InstanceBase = InstanceLoaderBase<TInterface>;
				using value_type = typename InstanceBase::value_type;
				using pointer = typename InstanceBase::pointer;
				using deleter_type = std::function<void (pointer )>;

				template<typename ...Args>
				LoaderImpl(char const *lib, char const *entry, char const *dest,
				Args&& ...args) noexcept : Base(lib),
					InstanceBase(static_cast<Base&>(*this), entry, dest),
					_value(this->loadInstance(std::forward<Args>(args)...), [this](pointer v) { this->deleteInstance(v); })
				{}

				LoaderImpl(char const *lib) noexcept : Base(lib),
					InstanceBase (),
					_value(nullptr, [this](pointer v) { this->deleteInstance(v); })
				{}

				~LoaderImpl() {}

				template<typename ...Args>
				bool reload(char const *entry, char const *dtor, Args&&... args)
				{
					this->loadSymbols(static_cast<Base&>(*this), entry, dtor);
					_value.reset(this->loadInstance(std::forward<Args>(args)...));
					return !!_value;
				}

				template<typename F>
				F loadFunction(char const *s)
				{
					return reinterpret_cast<F>(loadSymbol(s));
				}

				template<bool V = std::is_pointer<TInterface>::value>
				std::enable_if_t<V, pointer> get() {
					std::cout << "Return pointer no const" << std::endl;
					checkLoader();
					return _value.get();
				}

				template<bool V = !std::is_pointer<TInterface>::value && !std::is_void<value_type>::value>
				std::enable_if_t<V, std::add_lvalue_reference_t<value_type> > get() {
					std::cout << "Return reference no const" << std::endl;
					checkLoader();
					checkInstance();
					return *_value;
				}

				template<bool V = std::is_pointer<TInterface>::value>
				std::enable_if_t<V, const pointer> get() const {
					std::cout << "Return pointer const" << std::endl;
					checkLoader();
					return _value.get();
				}

				template<bool V = !std::is_pointer<TInterface>::value && !std::is_void<value_type>::value>
				std::enable_if_t<V, const std::add_lvalue_reference_t<value_type> > get() const {
					std::cout << "Return reference const" << std::endl;
					checkLoader();
					checkInstance();
					return *_value;
				}


			private:

				void checkLoader() const {
					if (!this->canLoad())
						throw std::runtime_error("Loader :: Cannot get instance, entry points are not loaded.");
				}

				void checkInstance() const {
					if (!_value)
						throw std::runtime_error("Loader :: Instance has not been loaded correctly.");
				}

				std::unique_ptr<value_type, deleter_type> _value;
			};

		}

		/// @brief Loader of dynamic libraries. Must give the name of the library
		/// at construction. If there is an instance to load, use the constructor
		/// with entry point and delete point symbols, otherwise use the constructor
		/// with the library name only. The library instance can be loaded lateer thanks to
		/// the function "reload".
		///
		/// @tparam TInterface Interface type abstracting the library instance.
		/// Library entry_point must give an implementation.
		template<typename TInterface>
		class DLInstanceLoader : public detail::LoaderImpl<TInterface> {
		public:

			using this_type = DLInstanceLoader<TInterface>;
			using Base = detail::LoaderImpl<TInterface>;
			using value_type = typename Base::value_type;
			using pointer = typename Base::pointer;

			template<typename ...Args>
			DLInstanceLoader(char const *lib, char const *entry, char const *destruct,
							 Args&& ...args) :
				Base(lib, entry, destruct, std::forward<Args>(args)...), _path(lib)
			{}

			DLInstanceLoader(char const *lib) : Base(lib), _path(lib)
			{}

			~DLInstanceLoader() = default;

			/// @brief Reload the symbols used to manage the library instance and create it.
			/// @tparam Args Types Arguments to forward to the constructor in the library.
			/// @param entry Entry point symbol name.
			/// @param dtor Destructor symbol name.
			/// @param args @tparam
			/// @return true if the instance creation has succeeded.
			template<typename ...Args>
			bool reload(char const *entry, char const *dtor, Args&&... args)
			{
				return Base::reload(entry, dtor,
								   std::forward<Args>(args)...);
			}

			/// @brief Get the instance of the library created at load time.
			/// @return If the interface type is a pointer, the same type is returned.
			/// otherwise the interface type is returned as a pointer.
			decltype(auto)
			get()
			{
				return Base::get();
			}

			decltype(auto)
			get() const
			{
				std::cout << "OK" << std::endl;
				return Base::get();
			}

			/// @brief Path to the library.
			/// @return
			std::string const& path() const
			{ return _path; }

			/// @brief Load a function from the current library.
			/// @tparam F Type of the function to return. Must be a function pointer
			/// @param s Symbol name.
			/// @return Typed function.
			template<typename F>
			F loadFunction(char const *s) { return Base::template loadFunction<F>(s); }

		private:
			std::string const _path;
		};
	}
}


#endif //CPP_RTYPE_DLINSTANCELOADER_HPP
