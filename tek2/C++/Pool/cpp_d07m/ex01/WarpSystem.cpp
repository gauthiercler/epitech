/*
** WarpSystem.cpp for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07m/ex00/WarpSystem.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 10:40:02 2017 Gauthier CLER
** Last update Tue Jan 10 10:40:02 2017 Gauthier CLER
*/

#include <clocale>
#include "WarpSystem.hh"

WarpSystem::QuantumReactor::QuantumReactor() {
  this->_stability = true;
}

bool WarpSystem::QuantumReactor::isStable() {
  return this->_stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability) {
  this->_stability = stability;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *reactor) {
  this->_coreReactor = reactor;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor() {
  return this->_coreReactor;
}

WarpSystem::Core::~Core() {

}
