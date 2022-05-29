#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "config.hpp"
#include "program.hpp"

#include <SFML/Graphics.hpp>

class Player /*: public Objects*/
{
public:
    int CFG_JumpStrength; //����������� �� ����� �������� ��� �������� ���� ������
    int CFG_WalkingSpeed; //����������� �� ����� �������� ��� �������� �������� ������
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

    /////////////////////��������� ��� ��������/////////////////////
    sf::FloatRect ColLine_Right;
    sf::FloatRect ColLine_Left;
    sf::FloatRect ColLine_Top;
    sf::FloatRect ColLine_Down;
    /////////////////////��������� ��� ��������/////////////////////

    Player();

    float SpriteVx = 0;
    float SpriteVy = 0;

    void update(int vx, int vy, sf::IntRect& a); //����� ��� �� ������ ������� ��������
    
};

#endif // !PLAYER_HPP