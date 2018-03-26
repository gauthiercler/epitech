//
// fstest.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/fstest.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  ven. janv. 19 23:06:15 2018 Anthony LECLERC
// Last update ven. janv. 19 23:06:15 2018 Anthony LECLERC
//

#include <iostream>
#include "../FileSystem.hpp"

int main()
{
	using namespace rtype;

	fs::FolderDescriptor foldd("./lib");

	while (foldd.hasNext())
	{
		auto it = foldd.next();
		std::cout << "File : " << it.name() << std::endl;
	}
	foldd.reset();
	while (foldd.hasNext())
	{
		auto it = foldd.next();
		std::cout << "File ! " << it.name() << std::endl;
	}
}