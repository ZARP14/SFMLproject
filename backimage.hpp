#ifndef BACKIMAGE_HPP
#define BACKIMAGE_HPP

#include <SFML/Graphics.hpp>

#include "program.hpp"

class BackImage
{
public:
    Program Bprogram;
    sf::Sprite BackImageSprite;
    sf::IntRect BackImageRectangle;
    sf::Texture BackImageTexture;
    BackImage();
};

#endif // !BACKIMAGE_HPP