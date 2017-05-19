/*
** ToyUnitTest.cpp for cpp_santa in /home/rubysh/Work/Repositories/Epitech/SecondYear/Pool/cpp_santa/Tests/ToyUnitTest.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jan 14 19:22:37 2017 Anas Buyumad
** Last update Sat Jan 14 19:22:37 2017 Anas Buyumad
*/

#include <Classes/LittlePony.hpp>
#include <Classes/Teddy.hpp>

AObject **MyUnitTests()
{
  AObject **ObjectArray = new AObject*[2];

  ObjectArray[0] = new Teddy("bisounours");
  ObjectArray[1] = new LittlePony("gay pony");

  return ObjectArray;
}
