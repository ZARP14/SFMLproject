#include "player.hpp"

Player::Player() :
    RightWalkingRectanle(0, 300, 90, 84),
    LeftWalkingRectanle(0, 206, 90, 84),
    WaitingRectanle(0, 0, 90, 84)
{
    /////////////////////��������� ���������� �������� �� �����/////////////////////
    std::ifstream config_file(CONFIG_PATH + "config.cfg");
    CFG_JumpStrength = Mconfig.getConfigFunction(config_file);
    CFG_WalkingSpeed = Mconfig.getConfigFunction(config_file);
    CFG_Forse_Of_Gravity = Mconfig.getConfigFunction(config_file);
    /////////////////////��������� ���������� �������� �� �����/////////////////////

    /////////////////////����� �������� ��� ���������/////////////////////
    SpriteTexture.loadFromFile(TEXTURE_PATH + "SpriteList.png");
    /*Sprite.setTextureRect(RightWalkingRectanle);*/
    Sprite.setTexture(SpriteTexture);
    /////////////////////����� �������� ��� ���������/////////////////////
    hub = Sprite.getPosition().x;
}

void
Player::update(int vx, int vy, sf::IntRect& a, float time)//����� ��� �� ������ ������� ��������
{
    hub = Sprite.getPosition().x;
    /////////////////////������� ����� ������������ ������ (������� ������ ��������) �� ��� �����/////////////////////
    ColLine_Right = Sprite.getGlobalBounds();
    ColLine_Left = ColLine_Right;
    ColLine_Top = Sprite.getGlobalBounds();
    ColLine_Down = ColLine_Top;
    /////////////////////������� ����� ������������ ������ (������� ������ ��������) �� ��� �����/////////////////////

    /////////////////////�� ��� ������ � ����� ����� ��������/////////////////////
    ColLine_Right.left += ColLine_Right.width - 1;
    ColLine_Right.width = 1;
    ColLine_Left.width = 1;
    ColLine_Right.height -= 10;
    ColLine_Left.height -= 10;
    /////////////////////�� ��� ������ � ����� ����� ��������/////////////////////

    /////////////////////�� ��� ������� � ������ ����� ��������/////////////////////
    ColLine_Down.top += ColLine_Top.height - 1;
    ColLine_Down.height = 1;
    ColLine_Top.height = 1;
    ColLine_Down.width -= 10;
    ColLine_Top.width -= 10;
    /////////////////////�� ��� ������� � ������ ����� ��������/////////////////////

    /////////////////////��������/////////////////////
    Sprite.setTextureRect(a);
    if (a.top != 0)
    {
        a.left += 100.0;
    }
    else
    {
        a.left = 0;
    }

    if (a.left > 950)
    {
        a.left = 0;
    }
    /////////////////////��������/////////////////////

    /////////////////////��������/////////////////////
    if (Sprite.getPosition().y == 250) SpriteVy += vy;

    float sX = vx * time;
    float sY = SpriteVy * time;

    if (Sprite.getPosition().y + (SpriteVy + CFG_Forse_Of_Gravity) * time < 245.0 || SpriteVy < 0) SpriteVy += CFG_Forse_Of_Gravity; //���� �� �� ����� ����� ������ ������ ������ ����
    else
    {
        Sprite.setPosition(hub, 250);
        SpriteVy = 0; //���� �� ����� �� �� ������
    }
    Sprite.move(vx * time, SpriteVy * time); //������� �� �������� �� � � �

    std::cout << Sprite.getPosition().x << ' ' << Sprite.getPosition().y << ' ' << 
        vx << ' ' << SpriteVy << '\n';
    /////////////////////��������/////////////////////
}


