/*
** sickkoala.cpp for cpp_d06 in /home/gogo/rendu/tek2/cpp_d06/ex02/sickkoala.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 09 14:14:19 2017 Gauthier CLER
** Last update Mon Jan 09 14:14:19 2017 Gauthier CLER
*/

#include <iostream>
#include <algorithm>
#include "sickkoala.h"

SickKoala::SickKoala(std::string name)
{
  this->name = name;
}

std::string SickKoala::formatName()
{
  return "Mr. " + this->name + ": ";
}

SickKoala::~SickKoala()
{
  std::cout << this->formatName() << "Kreooogg!! Je suis gueriiii!" << std::endl;
}

void SickKoala::poke()
{
  std::cout << this->formatName() << "Gooeeeeerrk!! :'(" << std::endl;
}

int SickKoala::takeDrug(std::string drug)
{
  std::string lower = drug;

  std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
  if (lower == "mars") {
    std::cout << this->formatName() << "Mars, et ca kreog!" << std::endl;
    return true;
  }else if (drug == "Buronzand"){
    std::cout << this->formatName() << "Et la fatigue a fait son temps!" << std::endl;
    return true;
  }
  std::cout << this->formatName() << "Goerkreog!" << std::endl;
  return false;
}

void SickKoala::overDrive(std::string string)
{
  std::string 	replaced;
  size_t 	foundRet = 0;

  replaced = string;
  while ((foundRet = replaced.find("Kreog!")) != std::string::npos)
    replaced.replace(foundRet, 6, "1337!");

  std::cout << this->formatName() << replaced << std::endl;
}

std::string SickKoala::getName()
{
  return this->name;
}
