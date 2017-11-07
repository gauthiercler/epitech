/*
** File.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/File.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:13:29 2017 Gauthier Cler
** Last update Sun Oct 08 22:13:30 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_FILE_HPP
#define CPP_SPIDER_FILE_HPP

#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "AOutStream.hpp"

namespace Client {

	class File : public AOutStream {

	private:

		std::fstream _stream;
		const std::string &_path;

	public:

		File(const std::string &name, CommunicationManager &manager, Client::AOutStream::StreamType type,
			 const std::string &path);

		~File() override = default;

		bool write(const std::string &data) override;

		bool isOpen() const override;

		bool isAlive() override;

		bool hasData() override;

		void clear() override;

		const std::string extractData() override;
	};
}


#endif //CPP_SPIDER_FILE_HPP
