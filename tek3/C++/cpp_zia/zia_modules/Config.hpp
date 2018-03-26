#ifndef CPP_MODULE_EXPORT_HPP
#define CPP_MODULE_EXPORT_HPP

#ifdef WIN32
#	pragma warning (disable: 4251)
#	pragma warning (disable: 4275)
#	pragma warning (disable: 4190)
#	ifdef MODULE_EXPORTS
#	define MODULE_API __declspec(dllexport)
#	else
#	define MODULE_API __declspec(dllimport)
#	endif
#else
#	define MODULE_API
#endif

#endif