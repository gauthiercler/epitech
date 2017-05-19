/*
** XorCracker.cpp for cpp_plazza in /home/ventinc/epitech/cpp/xorcracker/XorCracker.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Apr 27 21:03:58 2017 Vincent DUSAUTOIR
** Last update Thu Apr 27 21:03:58 2017 Vincent DUSAUTOIR
*/

#include <complex>
#include <iostream>
#include "XorCracker.hpp"

plazza::XorCracker::XorCracker() : _maxKeyLength(20) {

}

plazza::XorCracker::~XorCracker() {

}

void plazza::XorCracker::setMaxKeyLength(const size_t keyLength) {
  this->_maxKeyLength = keyLength;
}

size_t plazza::XorCracker::getMaxKeyLength() const {
  return this->_maxKeyLength;
}

const std::map<size_t, double> &plazza::XorCracker::getFitnesses() const {
  return this->_fitnesses;
}

size_t plazza::XorCracker::countEquals(const size_t keyLength) {
  size_t equalsCount = 0;
  std::map<char, size_t> charsCount;

  if (keyLength >= this->_buffer.size())
    return (0);
  for (size_t offset = 0; offset < keyLength; offset++) {
    charsCount = this->charCountAtOffset(keyLength, offset);
    equalsCount += this->getMaxCount(charsCount) - 1;
  }
  return equalsCount;
}

std::map<char, size_t> plazza::XorCracker::charCountAtOffset(const size_t keyLength, const size_t offset) {
  std::map<char, size_t> charsCount;

  for(size_t pos = offset; pos < this->_buffer.size(); pos += keyLength) {
    char c = this->_buffer.at(pos);

    auto find = charsCount.find(c);
    if (find != charsCount.end()) {
      charsCount[c] += 1;
    } else {
      charsCount.insert({c, 1});
    }
  }

  return charsCount;
}

size_t plazza::XorCracker::getMaxCount(const std::map<char, size_t> &chars) {

  auto it = chars.begin();
  auto end = chars.end();
  size_t max_value = it->second;

  for( ; it != end; ++it) {
    if(it->second > max_value)
      max_value = it->second;
  }
  return max_value;
}

void plazza::XorCracker::setKnownKeyLength(const size_t keyLength) {
  this->_knownKeyLength = keyLength;
}

size_t plazza::XorCracker::getKnownKeyLength() const {
  return this->_knownKeyLength;
}

void plazza::XorCracker::setBuffer(const std::string &buffer) {
  this->_buffer = buffer;
}

size_t plazza::XorCracker::getMaxFitnessKeyLength() const {
  double maxFitness = 0.0;
  size_t maxFitnessKeyLength = 0;

  for (auto fitness : this->_fitnesses) {
    if (fitness.second > maxFitness) {
      maxFitness = fitness.second;
      maxFitnessKeyLength = fitness.first;
    }
  }
  return maxFitnessKeyLength;
}

std::string plazza::XorCracker::getKeyXor() {
  std::string key;
  size_t keyLength = this->getKnownKeyLength();
  std::map<size_t, char>	possibleKeys;
  std::map<char, size_t> charsCount;
  size_t		max;

  for (size_t i = 0; i != keyLength; i++) {
    possibleKeys.insert({i, 0});
  }

  for (size_t offset = 0; offset != keyLength; offset++) {
    charsCount = this->charCountAtOffset(keyLength, offset);
    max = this->getMaxCount(charsCount);

    for (auto &ch : charsCount) {
      if (ch.second >= max)
	possibleKeys.at(offset) = (ch.first);
    }
  }
  for (auto &k : possibleKeys) {
    key += k.second + 32;
  }
  return key;
}

void plazza::XorCracker::run() {
  double pprev = 0.0;
  double prev = 0.0;
  double fitness;

  for (size_t keyLength = 1; keyLength < this->getMaxKeyLength() + 1; keyLength++) {
    fitness = this->countEquals(keyLength);
    fitness = (fitness / (this->getMaxKeyLength() + std::pow(keyLength, 1.5)));

    if (pprev < prev && prev > fitness)
      this->_fitnesses.insert({keyLength - 1, prev});

    pprev = prev;
    prev = fitness;
  }
  this->setKnownKeyLength(this->getMaxFitnessKeyLength());
}

void plazza::XorCracker::run(const std::string &buffer) {
  this->setBuffer(buffer);
  this->run();
}

size_t plazza::XorCracker::getKeyCaesar() {
  std::string key;
  size_t keyLength = this->getKnownKeyLength();
  std::map<size_t, char>	possibleKeys;
  std::map<char, size_t> charsCount;
  size_t		max;
  size_t		caesar;

  for (size_t i = 0; i != keyLength; i++) {
    possibleKeys.insert({i, 0});
  }

  for (size_t offset = 0; offset != keyLength; offset++) {
    charsCount = this->charCountAtOffset(keyLength, offset);
    max = this->getMaxCount(charsCount);

    for (auto &ch : charsCount) {
      if (ch.second >= max)
	possibleKeys.at(offset) = (ch.first);
    }
  }
  for (auto &k : possibleKeys) {
    key += k.second + 32;
  }

  caesar = 255 - (key.at(0) - 65);

  return caesar;
}
