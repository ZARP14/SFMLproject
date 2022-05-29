#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "config.hpp"
#include "program.hpp"

#include <SFML/Graphics.hpp>

class Player /*: public Objects*/
{
public:
    int CFG_JumpStrength; //загружаемые из файла значения для указания силы прыжка
    int CFG_WalkingSpeed; //загружаемые из файла значения для указания скорости ходьбы
    Config Mconfig;
    Program Mprogram;
    int hub;
    /////////////////////спрайт/////////////////////
    sf::Sprite Sprite;
    /////////////////////спрайт/////////////////////

    /////////////////////текстура для спрайта/////////////////////
    sf::Texture SpriteTexture;
    /////////////////////текстура для спрайта/////////////////////

    /////////////////////ректанглы для анимации/////////////////////
    sf::IntRect RightWalkingRectanle;
    sf::IntRect LeftWalkingRectanle;
    sf::IntRect WaitingRectanle;
    /////////////////////ректанглы для анимации/////////////////////

    /////////////////////ректанглы для коллизии/////////////////////
    sf::FloatRect ColLine_Right;
    sf::FloatRect ColLine_Left;
    sf::FloatRect ColLine_Top;
    sf::FloatRect ColLine_Down;
    /////////////////////ректанглы для коллизии/////////////////////

    Player();

    float SpriteVx = 0;
    float SpriteVy = 0;

    void update(int vx, int vy, sf::IntRect& a); //через это мы должны сделать движение
    
};

#endif // !PLAYER_HPP