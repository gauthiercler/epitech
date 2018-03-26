//
// alias.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/alias.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  sam. janv. 13 07:29:42 2018 Anthony LECLERC
// Last update sam. janv. 13 07:29:42 2018 Anthony LECLERC
//

#pragma once

#include <mutex>
#include <thread>
#include <condition_variable>

namespace rnetwork {
	using std::mutex;
	using std::thread;
	using std::lock_guard;
	using std::condition_variable;
}
