/*
** ConveyorBeltPePeNoel.hpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Classes/ConveyorBeltPePeNoel.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 12:40:45 2017 Antoine FORET
** Last update Sat Jan 14 12:40:45 2017 Antoine FORET
*/

#ifndef CPP_SANTA_CONVEYORBELTPEPENOEL_HPP
# define CPP_SANTA_CONVEYORBELTPEPENOEL_HPP

# include		"Interfaces/IConveyorBelt.hpp"

# define		NBR_MODELS (2)

class			ConveyorBeltPePeNoel : public IConveyorBelt {

private:
  AObject		*_currentObject;
  AWrap			*_models[NBR_MODELS];
  unsigned int		_model_idx;

public:
  ConveyorBeltPePeNoel();
  ConveyorBeltPePeNoel(const ConveyorBeltPePeNoel &conveyorBeltPePeNoel);
  virtual ~ConveyorBeltPePeNoel();

  virtual bool			in();
  virtual bool			out();

  virtual AObject		*take(); // Non const cause will set currentObject to NULL;

  /* GETTERS */
  virtual const std::string	*look() const;
  unsigned int			getModelIdx() const;
  AObject			*getCurrentObject() const;
  AWrap				*getModel(unsigned int idx) const;

  /* SETTERS */
  virtual bool			put(AObject *object);
  void				setModel(unsigned int idx, AWrap *wrap);
  void				setCurrentObject(AObject *object);
  void				incrementIdx();

  /* OPERATORS */
  ConveyorBeltPePeNoel	&operator=(const ConveyorBeltPePeNoel &conveyorBeltPePeNoel);
};


#endif //CPP_SANTA_CONVEYORBELTPEPENOEL_HPP
