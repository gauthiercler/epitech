#ifndef CPP_RTYPE_SINGLETON_HPP
# define CPP_RTYPE_SINGLETON_HPP

#include <Entity.hpp>

namespace rtype {
	template <typename T>
	class Singleton {
	protected:
		Singleton () = default;
		virtual ~Singleton () = default;

	public:
		static T &get() {
			static T instance;

			return instance;
		}

	};


}

#endif /* !CPP_RTYPE_SINGLETON_HPP*/
