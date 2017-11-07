/*
** CommunicationManager.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/CommunicationManager.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:10:44 2017 Gauthier Cler
** Last update Sun Oct 08 22:10:44 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_CLIENT_COMMUNICATION_H
# define CPP_SPIDER_CLIENT_COMMUNICATION_H

#include              	<vector>
#include              	<memory>
#include              	<queue>
#include              	<boost/property_tree/ptree.hpp>
#include              	"AOutStream.hpp"
#include 		"Network.hpp"
#include		"File.hpp"
#include 		"Config.hpp"

namespace 		Client {

  class 		AOutStream;

  class 		CommunicationManager {

    std::vector<std::unique_ptr<AOutStream>> _streams;
    std::queue<boost::property_tree::ptree> _commands;

  public:

    CommunicationManager() = default;

    void initialize();

    bool addStream(std::unique_ptr<AOutStream> stream);
    std::unique_ptr<Client::AOutStream> &getStream(const std::string &name);
    bool removeStream(const std::string &name);
    bool sendDataTo(const std::string &name, const std::string &data);
    void addCommand(boost::property_tree::ptree &command);
    bool hasCommand() const;
    boost::property_tree::ptree getCommand();
    void refreshConnection();

  };

}

#endif //CPP_SPIDER_COMMUNICATION_H
