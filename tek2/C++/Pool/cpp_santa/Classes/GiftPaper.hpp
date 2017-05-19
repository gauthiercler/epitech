/*
** GiftPaper.hpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Classes/GiftPaper.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 11:28:19 2017 Antoine FORET
** Last update Sat Jan 14 11:28:19 2017 Antoine FORET
*/

#ifndef CPP_SANTA_GIFTPAPER_HPP
# define CPP_SANTA_GIFTPAPER_HPP

# include	"Abstracts/AWrap.hpp"

class		GiftPaper : public AWrap {

private:

public:
  GiftPaper();
  GiftPaper(const GiftPaper &giftPaper);
  virtual ~GiftPaper();

  AObject	*clone() const;

  /* OPERATORS */
  GiftPaper	&operator=(const GiftPaper &giftPaper);

};


#endif //CPP_SANTA_GIFTPAPER_HPP
