#include "player.hpp"

Player::Player() :
    RightWalkingRectanle(0, 300, 90, 84),
    LeftWalkingRectanle(0, 206, 90, 84),
    WaitingRectanle(0, 0, 90, 84)
{
    /////////////////////загружаем переменные скорости из файла/////////////////////
    std::ifstream config_file(CONFIG_PATH + "config.cfg");
    CFG_JumpStrength = Mconfig.getConfigFunction(config_file);
    CFG_WalkingSpeed = Mconfig.getConfigFunction(config_file);
    /////////////////////загружаем переменные скорости из файла/////////////////////

    /////////////////////задаём текстуру для персонажа/////////////////////
    SpriteTexture.loadFromFile(TEXTURE_PATH + "SpriteList.png");
    /*Sprite.setTextureRect(RightWalkingRectanle);*/
    Sprite.setTexture(SpriteTexture);
    /////////////////////задаём текстуру для персонажа/////////////////////
    hub = Sprite.getPosition().x;
}

void
Player::update(int vx, int vy, sf::IntRect& a)//через это мы должны сделать движение
{
    hub = Sprite.getPosition().x;
    /////////////////////передаём нашим коллизионным линиям (крайним линиям хитбокса) всё что нужно/////////////////////
    ColLine_Right = Sprite.getGlobalBounds();
    ColLine_Left = ColLine_Right;
    ColLine_Top = Sprite.getGlobalBounds();
    ColLine_Down = ColLine_Top;
    /////////////////////передаём нашим коллизионным линиям (крайним линиям хитбокса) всё что нужно/////////////////////

    /////////////////////всё для правой и левой части хитбокса/////////////////////
    ColLine_Right.left += ColLine_Right.width - 1;
    ColLine_Right.width = 1;
    ColLine_Left.width = 1;
    ColLine_Right.height -= 10;
    ColLine_Left.height -= 10;
    /////////////////////всё для правой и левой части хитбокса/////////////////////

    /////////////////////всё для верхней и нижней части хитбокса/////////////////////
    ColLine_Down.top += ColLine_Top.height - 1;
    ColLine_Down.height = 1;
    ColLine_Top.height = 1;
    ColLine_Down.width -= 10;
    ColLine_Top.width -= 10;
    /////////////////////всё для верхней и нижней части хитбокса/////////////////////

    /////////////////////всё для верхней и нижней части хитбокса/////////////////////
 /*   ColLine_Down
    ColLine_Top
    ColLine_Right
    ColLine_Left*/
    /////////////////////всё для верхней и нижней части хитбокса/////////////////////

    /////////////////////анимация/////////////////////
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
    /////////////////////анимация/////////////////////

    /////////////////////движение/////////////////////
    SpriteVy == 0 ? SpriteVy += vy : SpriteVy += 0;
    if (Sprite.getPosition().y + SpriteVy + 5 < 245.0 || SpriteVy < 0) SpriteVy += 5; //если не на земле тогда должны всегда падать вниз
    else
    {
        Sprite.setPosition(hub, 250);
        SpriteVy = 0; //если на земле то не падаем
    }
    Sprite.move(vx, SpriteVy); //двигаем на скорость по Х и У

    std::cout << Sprite.getPosition().x << ' ' << Sprite.getPosition().y << ' ' << 
        vx << ' ' << SpriteVy << '\n';
    /////////////////////движение/////////////////////
}


