#ifndef CPP_RTYPE_EXPORT_HPP
#define CPP_RTYPE_EXPORT_HPP


#ifdef WIN32
#	pragma warning (disable: 4251)
#	ifdef RTECS_EXPORTS
#	define RTECS_API __declspec(dllexport)
#	else
#	define RTECS_API __declspec(dllimport)
#	endif
#else
#	define RTECS_API
#endif

#endif