#include <SFML/Window/Event.hpp>
#include <SFML/System.hpp>

#include "window.h"

int main() {
  Bakemono::Window win;
  sf::Event evt;

  win.drawText(100, 100, "Hello, World!");

  while (win.isOpen()) {
    while (win.pollEvent(evt)) {
      if (evt.type == sf::Event::Closed) {
        win.close();
      }
      if (evt.type == sf::Event::KeyPressed && evt.key.code == sf::Keyboard::Escape) {
        win.close();
      }
    }

    win.display();
  }


  return 0;
}
