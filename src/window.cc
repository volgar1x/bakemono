#include "window.h"
#include "fonts.h"
#include <SFML/Graphics/Text.hpp>

using namespace sf;

namespace Bakemono {
  VideoMode getBestVideoMode() {
    std::vector<VideoMode> fullscreenModes = VideoMode::getFullscreenModes();
    if (fullscreenModes.size() > 1) {
      return fullscreenModes[0];
    }
    return VideoMode(640, 480);
  }

  Window::Window(VideoMode mode) : RenderWindow(mode, "Bakemono", Style::None) {
    clear();
  }

  void Window::drawText(const unsigned int x, const unsigned int y, const sf::String& text, const unsigned int size) {
    Text t(text, Fonts::hackRegular, size);
    t.setPosition(x, y);

    draw(t);
  }
};
