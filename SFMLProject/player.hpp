#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#include "config.hpp"
#include "program.hpp"
#include "intersectable_objects.hpp"

class Player : public Intersectable_Objects
{
public:
    int CFG_JumpStrength; //загружаемые из файла значения для указания силы прыжка
    int CFG_WalkingSpeed; //загружаемые из файла значения для указания скорости ходьбы
    int CFG_Forse_Of_Gravity; //загружаемые из файла значения для указания силы притяжения
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

    Player();

    float SpriteVx = 0;
    float SpriteVy = 0;

    void update(int vx, int vy, sf::IntRect& a, float time); //через это мы должны сделать движение
    
};

#endif // !PLAYER_HPP