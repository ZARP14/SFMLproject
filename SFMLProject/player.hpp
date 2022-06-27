#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#include "config.hpp"
#include "program.hpp"
#include "intersectable_objects.hpp"

class Player : public Intersectable_Objects
{
public:
    float CFG_JumpStrength; //����������� �� ����� �������� ��� �������� ���� ������
    float CFG_WalkingSpeed; //����������� �� ����� �������� ��� �������� �������� ������
    float CFG_Forse_Of_Gravity; //����������� �� ����� �������� ��� �������� ���� ����������
    Config Mconfig;
    Program Mprogram;

    /////////////////////��������� ��� ��������/////////////////////
    sf::IntRect RightWalkingRectanle;
    sf::IntRect LeftWalkingRectanle;
    sf::IntRect WaitingRectanle;
    /////////////////////��������� ��� ��������/////////////////////

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
    void update(char t, float time); //����� ��� �� ������ ������� ��������    
};

#endif // !PLAYER_HPP