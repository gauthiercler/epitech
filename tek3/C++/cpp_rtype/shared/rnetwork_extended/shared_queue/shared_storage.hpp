//
// shared_storage.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/shared_storage.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  sam. janv. 13 07:25:18 2018 Anthony LECLERC
// Last update sam. janv. 13 07:25:18 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_SHARED_STORAGE_HPP
#define CPP_RTYPE_SHARED_STORAGE_HPP

#include <queue>
#include "alias.hpp"

namespace rnetwork {
	template<typename T, template <typename...> typename TStorage = std::queue>
	class shared_storage {
	public:
		using this_type = shared_storage<T, TStorage>;

		using value_type = T;
		using container = TStorage<T>;

		shared_storage() = default;

		shared_storage(this_type&& m)
			: this_type(std::forward<this_type>(m),
							 lock_guard<mutex>(m._mtx))
		{}
		shared_storage(this_type const& m)
			: this_type(std::forward<this_type>(m),
						lock_guard<mutex>(m._mtx))
		{}

		void terminate()
		{
			_terminated = true;
		}

		bool push(T&& v)
		{
			lock_guard<mutex> l(_mtx);

			if (_terminated)
				return false;
			_c.push(std::forward<T>(v));
			_cond.notify_one();
			return true;
		}

		bool push(T const& v)
		{
			lock_guard<mutex> l(_mtx);
			if (_terminated)
				return false;
			_c.push(v);
			return true;
		}

		bool trypop(T& v)
		{
			lock_guard<mutex> l(_mtx);
			if (_c.empty())
				return false;
			v = this->get();
			return true;
		}

		template<typename TF>
		void for_all(TF f)
		{
			lock_guard<mutex> l(_mtx);

			while (!_c.empty())
			{
				f(this->get());
				_c.pop();
			}
		}

		template<typename TF>
		void for_n(TF f, std::size_t n)
		{
			lock_guard<mutex> l(_mtx);

			T v;
			if (n >= _c.size()) {
				this->for_all(f);
			}
			else {
				while (n > 0) {
					f(this->get());
					_c.pop();
					--n;
				}
			}
		}

	private:
		T& get()
		{
			return _c.front();
		}

		shared_storage(this_type&& m, lock_guard<mutex> const& l) :
			_terminated(false)
			, _c(std::move(m._c))
			, _mtx()
			{}

		shared_storage(this_type const& m, lock_guard<mutex> const& l) :
			_terminated(false)
			, _c(m._c)
			, _mtx()
		{}

		bool _terminated { false };
		container _c;
		mutex _mtx;
		condition_variable _cond;
	};

	template<typename T>
	using shared_queue = shared_storage<T, std::queue>;

}

#endif /* CPP_RTYPE_SHARED_STORAGE_HPP */
