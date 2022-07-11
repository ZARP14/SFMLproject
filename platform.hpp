#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <SFML/Graphics.hpp>

#include "program.hpp"
#include "objects.hpp"

class Platform : public Objects
{
public:
    Program Pprogram;
    sf::IntRect PlatformRectangle;
    Platform();
};

#endif // !PLATFORM_HPP