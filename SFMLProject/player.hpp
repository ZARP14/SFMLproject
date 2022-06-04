#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#include "config.hpp"
#include "program.hpp"
#include "intersectable_objects.hpp"

class Player : public Intersectable_Objects
{
public:
    int CFG_JumpStrength; //����������� �� ����� �������� ��� �������� ���� ������
    int CFG_WalkingSpeed; //����������� �� ����� �������� ��� �������� �������� ������
    int CFG_Forse_Of_Gravity; //����������� �� ����� �������� ��� �������� ���� ����������
    Config Mconfig;
    Program Mprogram;
    int hub;
    /////////////////////������/////////////////////
    sf::Sprite Sprite;
    /////////////////////������/////////////////////

    /////////////////////�������� ��� �������/////////////////////
    sf::Texture SpriteTexture;
    /////////////////////�������� ��� �������/////////////////////

    /////////////////////��������� ��� ��������/////////////////////
    sf::IntRect RightWalkingRectanle;
    sf::IntRect LeftWalkingRectanle;
    sf::IntRect WaitingRectanle;
    /////////////////////��������� ��� ��������/////////////////////

    Player();

    float SpriteVx = 0;
    float SpriteVy = 0;

    void update(int vx, int vy, sf::IntRect& a, float time); //����� ��� �� ������ ������� ��������
    
};

#endif // !PLAYER_HPP