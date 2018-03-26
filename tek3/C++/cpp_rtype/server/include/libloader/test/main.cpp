//
// main.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/main.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  ven. janv. 19 01:22:16 2018 Anthony LECLERC
// Last update ven. janv. 19 01:22:16 2018 Anthony LECLERC
//

#include <utility>
#include <server/include/libloader/DLLoaderManager.hpp>
#include "../DLInstanceLoader.hpp"

using namespace rtype;

int main()
{
#ifdef WIN32
	const std::string &lib1Path = "./test1.dll";
	const std::string &lib2Path = "./test2.dll";
#else
	const std::string& lib1Path = "./lib/libtest1.so";
	const std::string& lib2Path = "./lib/libtest2.so";
#endif
	{
		module::DLInstanceLoader<char *>       loader1(
			lib1Path.c_str(),
			"ctor",
			"dtor");
		const module::DLInstanceLoader<char *> loader2(
			lib2Path.c_str(),
			"ctor",
			"dtor");

		const module::DLInstanceLoader<int> loader3(
			lib2Path.c_str(),
			"ctor",
			"dtor");

		module::DLInstanceLoader<void> loader4(lib2Path.c_str());

		static_assert(
			std::is_same<
				int *,
				module::DLInstanceLoader<int>::pointer
			>::value, "Must be pointer to interface");
		static_assert(
			std::is_same<
				char *,
				module::DLInstanceLoader<char *>::pointer
			>::value, "Must be array type");
		static_assert(
			std::is_same<
				char *,
				decltype(std::declval<
					module::DLInstanceLoader<char *>&
				>().get())
			>::value, "ok");
		static_assert(
			std::is_same<
				char *,
				decltype(std::declval<
					module::DLInstanceLoader<char *> const&
				>().get())
			>::value, "ok");

		loader1.get();
		std::cout << "Getter OK" << std::endl;

		auto f = loader2.get();
		std::cout << "Assignation OK" << std::endl;

		std::cout << loader1.get() << std::endl;
		std::cout << f << std::endl;

		auto getAh = loader1.loadFunction < int(*)() > ("ah");
		std::cout << getAh() << std::endl;
	}
	{
		module::DLInstanceLoader<char *> floader1 (lib1Path.c_str(), "ctor", "dtor");
		auto f = floader1.loadFunction<int (*)()>("ah");
		std::cout << f() << std::endl;

		module::DLInstanceLoader<char *> loader3(lib1Path.c_str());

		loader3.reload("ctor", "dtor");
		std::cout << loader3.get() << std::endl;
	}
	{
		module::DLLoaderManager<char *> manager ("./lib/");
		std::cout << manager.size() << std::endl;
		for (auto&& lib : manager)
		{
			if (lib->reload("ctor", "dtor"))
				std::cout << lib->get() << std::endl;
		}
	}
	{
		module::DLLoaderManager<void *> manager1 ("./lib/");
		std::cout << manager1.size() << std::endl;
	}
}