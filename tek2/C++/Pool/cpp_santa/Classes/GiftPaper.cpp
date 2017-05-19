/*
** GiftPaper.cpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Classes/GiftPaper.cpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 14:48:38 2017 Antoine FORET
** Last update Sat Jan 14 14:48:38 2017 Antoine FORET
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper() : AWrap("Gift Paper", true, true) {
}

GiftPaper::GiftPaper(const GiftPaper &giftPaper) : AWrap(giftPaper.getName(), giftPaper.isWrappable(), giftPaper.canWrap()) {
}

GiftPaper::~GiftPaper() {
}

GiftPaper &GiftPaper::operator=(const GiftPaper &giftPaper) {
  if (this != &giftPaper)
    AWrap::operator=(giftPaper);
  return *this;
}

AObject *GiftPaper::clone() const {
  return new GiftPaper(*this);
}
