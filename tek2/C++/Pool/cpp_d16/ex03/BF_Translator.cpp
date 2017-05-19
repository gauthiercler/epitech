/*
** BF_Translator.cpp for cpp_d16 in /home/gogo/rendu/tek2/cpp_d16/ex03/BF_Translator.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 19 16:53:15 2017 Gauthier CLER
** Last update Thu Jan 19 16:53:15 2017 Gauthier CLER
*/

#include <fstream>
#include <sstream>
#include <iostream>
#include "BF_Translator.h"

BF_Translator::BF_Translator() {

}

BF_Translator::~BF_Translator() {

}

static std::string	writeHeader()
{
  std::ostringstream	ret;

  ret << "#include <unistd.h>" << std::endl;
  ret << "#include <strings.h>" << std::endl;
  ret << "int main()" << std::endl;
  ret << "{" << std::endl;
  ret << "unsigned char tab[60001];" << std::endl;
  ret << "bzero(tab, 60001);" << std::endl;
  ret << "unsigned char *ptr = tab;" << std::endl;
  return ret.str();
}

static std::string	writeFooter()
{
  std::ostringstream	ret;

  ret << "return 0;" << std::endl;
  ret << "}" << std::endl;
  return ret.str();
}

static std::string	convertBF(char symbol)
{
  std::ostringstream	ret;
  switch (symbol)
  {
    case '+': ret << "(*ptr)++;\n"; break;
    case '-': ret << "(*ptr)--;\n"; break;
    case '>': ret << "ptr++;\n"; break;
    case '<': ret << "ptr--;\n"; break;
    case '.': ret << "write(1, ptr, 1);\n"; break;
    case ',': ret << "read(0, ptr, 1);\n"; break;
    case '[': ret << "while (*ptr){\n"; break;
    case ']': ret << "}\n"; break;
    default : ret << ""; break;
  }
  return ret.str();
}

int BF_Translator::translate(std::string in, std::string out) {
  std::ifstream		inputFile;
  std::ofstream		outputFile;
  std::stringstream	BFContent;

  inputFile.open(in.c_str());
  if (!inputFile.is_open())
    return 1;
  outputFile.open(out.c_str());
  if (!outputFile.is_open())
    return 1;
  BFContent << inputFile.rdbuf();
  inputFile.close();
  outputFile << writeHeader();
  for (unsigned int it = 0 ; it < BFContent.str().length(); it += 1)
    outputFile << convertBF((BFContent.str().c_str()[it]));
  outputFile << writeFooter();
  outputFile.close();
  return 0;
}
