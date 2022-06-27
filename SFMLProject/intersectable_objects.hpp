#ifndef INTERSECTABLE_OBJECTS_HPP
#define INTERSECTABLE_OBJECTS_HPP

#include <SFML/Graphics.hpp>

#include "objects.hpp"

class Intersectable_Objects : public Objects
{
public:

    Intersectable_Objects();

    /////////////////////��������� ��� ��������/////////////////////
    sf::FloatRect ColLine_Right;
    sf::FloatRect ColLine_Left;
    sf::FloatRect ColLine_Top;
    sf::FloatRect ColLine_Down;
    /////////////////////��������� ��� ��������/////////////////////
};

#endif // !INTERSECTABLE_OBJECTS