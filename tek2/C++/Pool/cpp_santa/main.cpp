#include <Classes/Teddy.hpp>
#include <Classes/ConveyorBeltPePeNoel.hpp>
#include <Classes/TablePePeNoel.hpp>
#include <Classes/Elf.hpp>
#include <Classes/LittlePony.hpp>
#include <iostream>

/*
** main.cpp for cpp_santa in /home/ventinc/epitech/piscine/cpp_santa/main.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sat Jan 14 14:02:15 2017 Vincent DUSAUTOIR
** Last update Sat Jan 14 14:02:15 2017 Vincent DUSAUTOIR
*/

int main(void)
{
  Elf *elf = new Elf("Padion");
  TablePePeNoel *table = new TablePePeNoel();
  ConveyorBeltPePeNoel *conveyorBeltPePeNoel = new ConveyorBeltPePeNoel();


  std::cout << "Hello little elf named " << elf->getName() << ", I'm santa claus !" << std::endl;

  std::cout << "I add you two object on the table, a Teddy and a Little Pony, can you wrap me that ?" << std::endl;
  table->setItem(0, new Teddy);
  table->setItem(1, new LittlePony);

  elf->createGift(*conveyorBeltPePeNoel, *table);
  elf->createGift(*conveyorBeltPePeNoel, *table);
  elf->createGift(*conveyorBeltPePeNoel, *table);

  delete conveyorBeltPePeNoel;
  delete table;
  delete elf;

  return 0;
}
