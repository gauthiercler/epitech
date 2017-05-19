/*
** koalanurse.cpp for cpp_d06 in /home/gogo/rendu/tek2/cpp_d06/ex03/koalanurse.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 09 16:10:53 2017 Gauthier CLER
** Last update Mon Jan 09 16:10:53 2017 Gauthier CLER
*/

#include <iostream>
#include <fstream>
#include "koalanurse.h"

KoalaNurse::KoalaNurse(int ID)
{
  this->ID = ID;
  this->isWorking = false;
}

KoalaNurse::~KoalaNurse()
{
  std::cout << "Nurse " << this->ID << ": Enfin un peu de repos!" << std::endl;
}

std::string	KoalaNurse::readReport(std::string filename)
{
  std::ifstream	file;
  std::string	drug;

  file.open(filename.c_str());
  if (file.is_open()){
    std::getline(file, drug);
    std::cout << "Nurse " << this->ID << ": Kreog! Il faut donner un " << drug << " a Mr." << filename.substr(0, filename.find_last_of(".")) << "!" << std::endl;
    return drug;
  }
  drug = "";
  return drug;
}

void		KoalaNurse::giveDrug(std::string drug, SickKoala *Koala)
{
  Koala->takeDrug(drug);
}

void		KoalaNurse::timeCheck()
{
  if (!this->isWorking)
    std::cout << "Nurse " << this->ID << ": Je commence le travail!" << std::endl;
  else
    std::cout << "Nurse " << this->ID << ": Je rentre dans ma foret d'eucalyptus!" << std::endl;
  this->isWorking = !this->isWorking;
}

int KoalaNurse::getID() {
  return this->ID;
}


