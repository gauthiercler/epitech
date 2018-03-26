//
// lib2.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/lib2.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  ven. janv. 19 01:25:37 2018 Anthony LECLERC
// Last update ven. janv. 19 01:25:37 2018 Anthony LECLERC
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <corecrt_malloc.h>

#ifdef WIN32
#	ifdef LIB_EXPORTS
#	define LIB2_API __declspec(dllexport)
#	else
#	define LIB2_API __declspec(dllimport)
#	endif
#else
#	define LIB2_API
#endif

LIB2_API char *ctor();
LIB2_API int ah();
LIB2_API void dtor(char *s);

char *ctor()
{
	printf("Lib2.so :: CTOR.\n");
	char *str = malloc (12);
	strcpy(str, "lib2 test.");
	return str;
}

void dtor(char *s)
{
	printf("Lib2.so :: DTOR.\n");
	free(s);
}