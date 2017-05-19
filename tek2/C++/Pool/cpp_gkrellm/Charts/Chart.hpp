/*
** ProgressBar.hpp for cpp_gkrellm in /home/foret_a/Lab/cpp_gkrellm/Charts/ProgressBar.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jan 22 00:04:47 2017 Antoine FORET
** Last update Sun Jan 22 00:04:47 2017 Antoine FORET
*/

#ifndef CPP_GKRELLM_PROGRESSBAR_HPP
#define CPP_GKRELLM_PROGRESSBAR_HPP

#include "SFML/Graphics.hpp"

class Chart {

public:
  static void drawProgressBar(sf::RenderTexture &texture, float percent, sf::Color complete, sf::Color background);
};


#endif //CPP_GKRELLM_PROGRESSBAR_HPP
