#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics/RenderWindow.hpp>

namespace Bakemono {
  sf::VideoMode getBestVideoMode();

  class Window : public sf::RenderWindow {
    public:
      Window(sf::VideoMode mode = sf::VideoMode(640, 480));

      void drawText(const unsigned int x, const unsigned int y, const sf::String& text, const unsigned int size = 12);
  };

};

#endif//WINDOW_H
