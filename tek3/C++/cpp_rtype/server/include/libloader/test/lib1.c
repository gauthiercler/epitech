//
// lib1.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/lib1.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  ven. janv. 19 01:22:32 2018 Anthony LECLERC
// Last update ven. janv. 19 01:22:32 2018 Anthony LECLERC
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#ifdef WIN32
#include <corecrt_malloc.h>
#	ifdef LIB_EXPORTS
#	define LIB1_API __declspec(dllexport)
#	else
#	define LIB1_API __declspec(dllimport)
#	endif
#else
#	define LIB1_API
#endif

LIB1_API char *ctor();
LIB1_API int ah();
LIB1_API void dtor(char *s);

char *ctor()
{
/*	printf("Lib1.so :: CTOR.\n");
	char *str = malloc (12);
	strcpy(str, "lib1 test.");
	return str;
 */
	return 0;
}

int ah()
{
	return 10;
}

void dtor(char *s)
{
	printf("Lib1.so :: DTOR.\n");
//	free(s);
}