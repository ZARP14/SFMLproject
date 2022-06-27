#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#include "config.hpp"
#include "program.hpp"
#include "intersectable_objects.hpp"

class Player : public Intersectable_Objects
{
public:
    float CFG_JumpStrength; //загружаемые из файла значения для указания силы прыжка
    float CFG_WalkingSpeed; //загружаемые из файла значения для указания скорости ходьбы
    float CFG_Forse_Of_Gravity; //загружаемые из файла значения для указания силы притяжения
    Config Mconfig;
    Program Mprogram;

    /////////////////////ректанглы для анимации/////////////////////
    sf::IntRect RightWalkingRectanle;
    sf::IntRect LeftWalkingRectanle;
    sf::IntRect WaitingRectanle;
    /////////////////////ректанглы для анимации/////////////////////

    Player();

    bool moving_right = false;
    bool moving_left = flase;
    float SpriteVx = 0;
    float SpriteVy = 0;
    float vx = 0;
    float vy = 0;
    sf::IntRect a;
    float time = 0;

    void animation(float& time, char t);
    void update(char t, float time); //через это мы должны сделать движение    
};

#endif // !PLAYER_HPP