#include <iostream>
#include "Chart.hpp"

void Chart::drawProgressBar(sf::RenderTexture &texture, float percent, sf::Color complete, sf::Color background)
{
  sf::RectangleShape progress(sf::Vector2f(texture.getSize().x * (percent / 100), texture.getSize().y));

  texture.clear(background);
  progress.setFillColor(complete);
  progress.setPosition(0, 0);
  texture.draw(progress);
  texture.display();
}
