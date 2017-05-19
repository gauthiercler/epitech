/*
** koaladoctor.cpp for cpp_d06 in /home/gogo/rendu/tek2/cpp_d06/ex04/koaladoctor.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 09 18:32:09 2017 Gauthier CLER
** Last update Mon Jan 09 18:32:09 2017 Gauthier CLER
*/

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "koaladoctor.h"

KoalaDoctor::~KoalaDoctor() {
  this->isWorking = false;
}

KoalaDoctor::KoalaDoctor(std::string name) {
  this->name = name;
  std::cout << "Dr. " << this->name << ": Je suis le Dr." << this->name << "! Comment Kreoggez-vous ?" << std::endl;
}

void KoalaDoctor::diagnose(SickKoala *Koala) {

  std::ofstream	file;
  std::string	drugs[] = {"mars", "Buronzand", "Viagra", "Extasy", "Feuille d’eucalyptus"};
  std::string	chosen = drugs[random() % 5];

  std::cout << "Dr. " << this->name << ": Alors, qu'est-ce qui vous goerk, Mr." << Koala->getName() << " ?" << std::endl;
  Koala->poke();
  file.open((Koala->getName() + ".report").c_str());
  file.write(chosen.c_str(), chosen.length());
  file.close();
}

void KoalaDoctor::timeCheck() {
  if (!this->isWorking)
    std::cout << "Dr." << this->name << ": Je commence le travail!" << std::endl;
  else
    std::cout << "Dr." << this->name << ": Je rentre dans ma foret d'eucalyptus!" << std::endl;
  this->isWorking = !this->isWorking;
}

