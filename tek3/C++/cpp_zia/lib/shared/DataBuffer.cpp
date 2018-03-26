//
// Created by valentin on 15/02/18.
//

#include "DataBuffer.hpp"

zia::shared::DataBuffer::DataBuffer(const std::string &data)
    : _cache(data), _data(data)
{}

zia::shared::DataBuffer::~DataBuffer()
{}

void zia::shared::DataBuffer::split(const std::string &delimiter) {
    std::string data = _data;

    if (data.empty())
	_buf.emplace_back();
    else {
	while (!data.empty()) {
	    const auto &posEOL = data.find(delimiter);

	    _buf.emplace_back(data.substr(0, posEOL));
	    _format.emplace_back(posEOL != std::string::npos);
	    if (posEOL == std::string::npos)
		data = "";
	    else
		data = data.substr(posEOL + delimiter.size());
	}
    }
}

bool zia::shared::DataBuffer::getLine(std::string &line) {
    if (_idx >= _buf.size())
	return (false);
    line = _buf[_idx];
    _idx += 1;
    return (true);
}

bool zia::shared::DataBuffer::getLine(std::string &line, size_t idx) {
    if (idx >= _buf.size())
	return (false);
    line = _buf[idx];
    return (true);
}

void zia::shared::DataBuffer::reset() {
    _idx = 0;
    if (_cache != _data) {
	_buf.clear();
	_format.clear();
	_cache = _data;
    }
}

void zia::shared::DataBuffer::reset(const std::string &delim, unsigned int offset) {
    _idx = offset;
    if (_cache != _data) {
	_buf.clear();
	_format.clear();
	split(delim);
	_cache = _data;
    }
}

bool zia::shared::DataBuffer::ready(const std::string &line) {
    size_t idx = 0;

    for (const auto &l : _buf) {
	if (l == line)
	    return (_format[idx]);
	idx += 1;
    }
    return (false);
}
