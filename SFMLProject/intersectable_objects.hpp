#ifndef INTERSECTABLE_OBJECTS_HPP
#define INTERSECTABLE_OBJECTS_HPP

#include <SFML/Graphics.hpp>

#include "objects.hpp"

class Intersectable_Objects : public Objects
{
public:

    Intersectable_Objects();

    /////////////////////ректанглы для коллизии/////////////////////
    sf::FloatRect ColLine_Right;
    sf::FloatRect ColLine_Left;
    sf::FloatRect ColLine_Top;
    sf::FloatRect ColLine_Down;
    /////////////////////ректанглы для коллизии/////////////////////
};

#endif // !INTERSECTABLE_OBJECTS