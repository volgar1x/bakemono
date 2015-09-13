#ifndef FONTS_H
#define FONTS_H

#include <SFML/Graphics/Font.hpp>

namespace Bakemono { namespace Fonts {
  namespace priv {
    class LoadFont : public sf::Font {
      public:
        LoadFont(std::string filename) {
          loadFromFile(filename);
        }
    };
  };

  priv::LoadFont hackRegular("/home/antoine/.fonts/Hack-Regular.ttf");
}};

#endif//FONTS_H
