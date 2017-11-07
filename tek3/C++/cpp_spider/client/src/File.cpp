#include <windows.h>
#include <iostream>
#include <boost/regex.hpp>
#include "File.hpp"

Client::File::File(const std::string &name, Client::CommunicationManager &manager, Client::AOutStream::StreamType type,
				   const std::string &path) : AOutStream(name, manager, type), _path(path) {
	_stream.open(path, std::ios::out | std::ios::in | std::ios::app);
	if (!this->isOpen()) {
		throw Spider::Error("Couldn't open file stream : " + path);
	}
}

bool Client::File::write(const std::string &data) {
  std::cout << "Send to file : " << data << std::endl;
	_stream << data;
	return true;
}

bool Client::File::isOpen() const {
	return _stream.is_open();
}

bool Client::File::isAlive() {
	return this->isOpen();
}

bool Client::File::hasData() {
	return _stream.peek() != EOF;
}

const std::string Client::File::extractData() {
	std::ostringstream oss;
	auto currentPos = _stream.tellg();
	std::string data(4096, '\0');
	boost::regex	 	expr{
			R"(\{\s*"timestamp":\s"(.+),\s*"process":\s*(.+),\s*"data":\s*(.+),\s*"type":\s*(.+)\s*\})"};
	boost::smatch  what;

	_stream.read(&data[0], 4096);
	if (boost::regex_search(data, what, expr)) {
	}
	std::string t = what[0];
	_stream.seekg(currentPos);
	_stream.read(&data[0], t.size());
	return std::move(t);
}

void Client::File::clear() {
	_stream.close();
	_stream.open(_path, std::ios::out | std::ios::in | std::ios::trunc);
}
