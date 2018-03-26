//
// Created by montag_v on 15/01/2018.
//

#pragma once

#ifdef WIN32
#	pragma warning (disable: 4251)
#	pragma warning (disable: 4275)
#	ifdef RNETWORK_EXPORTS
#	define RNETWORK_API __declspec(dllexport)
#	else
#	define RNETWORK_API __declspec(dllimport)
#	endif
#else
#	define RNETWORK_API
#endif