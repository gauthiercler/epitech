#ifndef CPP_ENEMY_EXPORT_HPP
#define CPP_ENEMY_EXPORT_HPP

#include <Entity.hpp>
#include <Manager.hpp>

#ifdef WIN32
#	pragma warning (disable: 4251)
#	pragma warning (disable: 4275)
#	pragma warning (disable: 4190)
#	ifdef ENEMY_EXPORTS
#	define ENEMY_API __declspec(dllexport)
#	else
#	define ENEMY_API __declspec(dllimport)
#	endif
#else
#	define ENEMY_API
#endif

#endif