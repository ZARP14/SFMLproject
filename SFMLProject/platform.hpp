#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <SFML/Graphics.hpp>

#include "program.hpp"

class Platform /*: public Objects*/
{
public:
    Program Pprogram;
    sf::Texture PlatformTexture;
    sf::IntRect PlatformRectangle;
    sf::Sprite PlatformSprite;
    Platform();
};

#endif // !PLATFORM_HPP