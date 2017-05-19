/*
** TablePePeNoel.hpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Classes/TablePePeNoel.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 11:52:01 2017 Antoine FORET
** Last update Sat Jan 14 11:52:01 2017 Antoine FORET
*/

#ifndef CPP_SANTA_TABLEPEPENOEL_HPP
# define CPP_SANTA_TABLEPEPENOEL_HPP

# include			"Interfaces/ITable.hpp"

# define MAX_TABLE_CAPACITY	(10)

class					TablePePeNoel : public ITable{

private:
  AObject				*_items[MAX_TABLE_CAPACITY + 1];
  const std::string			*_itemsName[MAX_TABLE_CAPACITY + 1];

public:
  TablePePeNoel();
  TablePePeNoel(const TablePePeNoel &tablePePeNoel);
  virtual ~TablePePeNoel();

  /* GETTERS */
  virtual const std::string * const 	*look() const;
  AObject				*getItem(unsigned int idx) const;
  unsigned int				getItemsNumber() const;

  /* SETTERS */
  virtual bool				put(AObject *object);
  virtual AObject			*take();
  void					refreshNames();
  void					setItem(unsigned int idx, AObject *item);

  /* OPERATORS */
  TablePePeNoel			&operator=(const TablePePeNoel &tablePePeNoel);

};


#endif //CPP_SANTA_TABLEPEPENOEL_HPP
