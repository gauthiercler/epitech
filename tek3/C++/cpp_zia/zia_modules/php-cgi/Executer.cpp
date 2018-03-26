#include "Executer.hpp"
#include <unistd.h>
#include <wait.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

std::stringstream &zia::modules::php::Executer::run(const std::string &cmd,
                                                    const std::unordered_map<std::string, std::string> &env,
                                                    const std::string &data) {
    openFds();
    startCmd(cmd, env);
    sendData(data);
    close(_inputFds[1]);
    receiveData();
    waitCmd();
    return _result;
}

void zia::modules::php::Executer::openFds() {
    if (pipe(_inputFds) != 0 || pipe(_ouptutFds) != 0)
        throw std::runtime_error("Unable to open pipes");
}

void zia::modules::php::Executer::startCmd(const std::string &cmd, const std::unordered_map<std::string, std::string> &env) {
    _pid = fork();
    switch (_pid) {
        case -1:
            throw std::runtime_error("Unable to fork");
        case 0:
            execCmd(cmd, env);
            break;
        default:
            closeHost();
    }
}

void zia::modules::php::Executer::execCmd(const std::string &cmd, const std::unordered_map<std::string, std::string> &env) {
    char *params[2] = {const_cast<char *>(""), nullptr};
    close(_inputFds[1]);
    close(_ouptutFds[0]);
    dup2(_ouptutFds[1], 1);
    dup2(_inputFds[0], 0);
    execve(cmd.c_str(), params, generateEnv(env));
    std::clog << "[WARNING][PHP] Unable to execute php-cgi. Check config file and cgi path (" << cmd << ")" << std::endl;
    std::exit(0);
}

void zia::modules::php::Executer::closeHost() {
    close(_inputFds[0]);
    close(_ouptutFds[1]);
}

void zia::modules::php::Executer::waitCmd() const {
    waitpid(_pid, nullptr, 0);
}

void zia::modules::php::Executer::receiveData() {
    char buff[1024];
    long int size;

    do {

        size = read(_ouptutFds[0], buff, 1023);
        if (size > 0) {
            buff[size] = '\0';
            _result << buff;
        }
    } while (size > 0); // TODO pass to select
}

void zia::modules::php::Executer::sendData(const std::string &data) const {
    write(_inputFds[1], data.c_str(), data.size());
}

char **zia::modules::php::Executer::generateEnv(const std::unordered_map<std::string, std::string> &envMap) const {
    auto **env = new char*[envMap.size() + 1];
    unsigned int registered = 0;
    std::for_each(envMap.begin(), envMap.end(), [&](const std::pair<std::string, std::string> &pair)  {
        env[registered++] = strdup(std::string(pair.first + "=" + pair.second).c_str());
    });
    env[envMap.size()] = nullptr;
    return env;
}