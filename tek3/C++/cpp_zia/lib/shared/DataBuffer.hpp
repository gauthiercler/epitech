//
// Created by valentin on 15/02/18.
//

#ifndef CPP_ZIA_DATABUFFER_HPP
#define CPP_ZIA_DATABUFFER_HPP

#include <string>
#include <vector>

namespace zia::shared {

    class DataBuffer {

	unsigned int			_idx {0};
	std::string			_cache;
	const std::string 		&_data;
	std::vector<std::string> 	_buf;
	std::vector<bool>		_format;

    public:
	explicit DataBuffer(const std::string &data);
	~DataBuffer();

	/**
	 * Generate an array of string in the DataBuffer
	 * @param delimiter
	 */
	void split(const std::string &delimiter);

	/**
	 * Get the line of the buffer
	 * @return
	 */

	bool getLine(std::string &line);
	bool getLine(std::string &line, size_t idx);

	/**
	 * Reset the buffer
	 */

	void reset();
	void reset(const std::string &delim, unsigned int offset = 0);

	/**
	 * Check if the line is ready to parse or not
	 */

	bool ready(const std::string &line);

    };

}

#endif //CPP_ZIA_DATABUFFER_HPP
