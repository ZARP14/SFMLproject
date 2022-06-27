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
    Sprite.setTextureRect(WaitingRectanle);
    Sprite.setPosition(150, 250);
}

void 
Player::animation(float& time, char t)
{
    /////////////////////��������/////////////////////
    switch (t)
    {
    case 'A':
        a = LeftWalkingRectanle;
        break;
    case 'D':
        a = RightWalkingRectanle;
        break;
    default:
        a = WaitingRectanle;
    }

    Sprite.setTextureRect(a);
    if (time >= 0.05)
    {
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
        time = 0;
        Sprite.setTextureRect(a);
    }
    /////////////////////��������/////////////////////
}

void
Player::update(float time)//����� ��� �� ������ ������� ��������
{
    if (Sprite.getPosition().y + (SpriteVy + CFG_Forse_Of_Gravity) < 250.0 + CFG_Forse_Of_Gravity)
    {
        SpriteVy += CFG_Forse_Of_Gravity; //���� �� �� ����� ����� ������ ������ ������ ����
        jump = false;
    }
    else
    {
        SpriteVy = 0; //���� �� ����� �� �� ������
    }

    if (jump == true && Sprite.getPosition().y >= 250)
    {
        SpriteVy += CFG_JumpStrength;
        jump = false;
    }

    if (moving_right == true && moving_left == false)
    {
        vx = CFG_WalkingSpeed;
    }
    else if (moving_left == true && moving_right == false)
    {
        vx = CFG_WalkingSpeed * -1;
    }
    /////////////////////��������/////////////////////
    float sX = vx * time;
    float sY = SpriteVy * time;

    if (Sprite.getPosition().y > 250) Sprite.setPosition(Sprite.getPosition().x, 250);

    if (Sprite.getPosition().x >= 800)Sprite.setPosition(-80, Sprite.getPosition().y);
    else if (Sprite.getPosition().x <= -84) Sprite.setPosition(790, Sprite.getPosition().y);

    Sprite.move(sX, sY); //������� �� �������� �� � � �

    std::cout << Sprite.getPosition().x << ' ' << Sprite.getPosition().y << ' ' << 
        vx << ' ' << SpriteVy << '\n';
    vx = 0;
    /////////////////////��������/////////////////////
}


