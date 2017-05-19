/*
** CommunicationAPI.cpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14a/ex02/CommunicationAPI.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 20:08:43 2017 Gauthier CLER
** Last update Tue Jan 17 20:08:43 2017 Gauthier CLER
*/

#include <stdexcept>
#include "CommunicationAPI.hpp"

CommunicationAPI::CommunicationAPI(std::istream &input, std::ostream &output)
    : _usersOffset(0),
      _input(input),
      _output(output)
{
    if (!_input.good())
        throw std::runtime_error("Invalid input stream.");
    if (!_output.good())
        throw std::runtime_error("Invalid output stream.");
}

CommunicationAPI::~CommunicationAPI()
{
}

bool
CommunicationAPI::hasUser(std::string const &userName) const
{
    for (size_t i = 0; i < _usersOffset; ++i) {
        if (_users[i] == userName)
            return true;
    }
    return false;
}

    void
CommunicationAPI::startMission(std::string const &missionName)
{
    if (missionName.size() == 0)
        throw std::invalid_argument("`missionName` should be at least 1 char.");
    _missionName = missionName;
}

    void
CommunicationAPI::addUser(std::string const &userName)
{
    if (userName.size() == 0)
        throw std::invalid_argument("`userName` should be at least 1 char.");
    if (_usersOffset > MAX_USERS)
        throw std::out_of_range("Exceed max number of users added.");
    _users[_usersOffset] = userName;
    _usersOffset += 1;
}

void
CommunicationAPI::sendMessage(std::string const &userName,
        std::string const &message) const
{
    if (!hasUser(userName))
        throw std::invalid_argument("User " + userName + " not found.");
    if (_missionName.size() == 0)
        throw std::runtime_error("No mission started.");
    _output << message;
}

void
CommunicationAPI::receiveMessage(std::string const &userName,
        std::string &message) const
{
    if (!hasUser(userName))
        throw std::invalid_argument("User " + userName + " not found.");
    if (_missionName.size() == 0)
        throw std::runtime_error("No mission started.");
    _input >> message;
}
