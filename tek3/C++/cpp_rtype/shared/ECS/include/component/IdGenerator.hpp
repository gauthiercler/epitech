//
// idGenerator.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/idGenerator.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  sam. janv. 13 06:07:12 2018 Anthony LECLERC
// Last update sam. janv. 13 06:07:12 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_IDGENERATOR_HPP
#define CPP_RTYPE_IDGENERATOR_HPP

#include "Export.hpp"

namespace ecs {

	template<typename Traits>
	struct Generator_id {
		using traits = Traits;
		using Id = typename Traits::Id;
		static Id _lastid;
	};

	template<typename Traits>
	typename Traits::Id Generator_id<Traits>::_lastid = Traits::invalid_id;

	template<typename T, typename Traits>
	class Generator_type_id : public Generator_id<Traits> {
	private:
		using Base = Generator_id<Traits>;

		using Id = typename Base::Id;

		static Id _type;
		static bool _initialized;

		Generator_type_id() {
			if (!_initialized)
				_type = ++this->_lastid;
			_initialized = true;
		}
	public:

		using type = T;
		using this_type = Generator_type_id<T, Traits>;

		static Id make() {
			if (_initialized)
				return Traits::invalid_id;
			else
				return this_type().ctype();
		}


		inline
		static Id ctype() { return _type; }

		operator Id() const { return ctype(); }
	};

	template<typename T, typename Traits>
	typename Generator_type_id<T, Traits>::Id //.
		Generator_type_id<T, Traits>::_type = Traits::invalid_id;

	template<typename T, typename Traits>
	bool Generator_type_id<T, Traits>::_initialized = false;
};

#endif /* CPP_RTYPE_IDGENERATOR_HPP */
