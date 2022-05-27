#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <string.h>
#include <map>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>

#include <windows.h>
#include <fstream>

sf::Sprite Sprite;
sf::Sprite BackImage;
sf::Sprite Platform;
int positionX_hub = 0;
int positionY_hub = 0;

/////////////////////для динамического пути папки resourse/////////////////////
std::string path()
{
    CHAR buffer[MAX_PATH] = { 0 };
    int size = GetModuleFileNameA(NULL, buffer, MAX_PATH);
    for (int i = 0; i < 2; ++i) while (buffer[--size] != L'\\');
    buffer[size + 1] = 0;
    return std::string(buffer);
}
/////////////////////для динамического пути папки resourse/////////////////////

/////////////////////части коллизии/////////////////////
auto ColLine_Right = Sprite.getGlobalBounds();//Правая часть хитбокса
auto ColLine_Left = ColLine_Right;//Левая часть хитбокса
auto ColLine_Top = Sprite.getGlobalBounds();//Верхняя часть хитбокса
auto ColLine_Down = ColLine_Top;//Нижняя часть хитбокса
/////////////////////части коллизии/////////////////////

int hub = 0;
bool falling = false;

/////////////////////функция для определения пресекается объект с ЛЮБЫМ други или нет/////////////////////
//void intersection_function()
//{
//    
//}
/////////////////////функция для определения пресекается объект с ЛЮБЫМ други или нет/////////////////////

void update(int vx, int vy, sf::IntRect& a) //через это мы должны сделать движение
{
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
    Sprite.move(vx, vy); //двигаем на скорость по Х и У
    //if (!Sprite.getPosition().y == 250.0 , ColLine_Down.intersects()) vy += 10; //если не на земле тогда должны всегда падать вниз
    //else vy = 0; //если на земле то не падаем
    /////////////////////движение/////////////////////
}

#define RESOURSE_PATH path() + "resourse\\"

int main()
{
    std::map<int, sf::Sprite&> List_Of_Subjects = { {0, Sprite}, {1, BackImage}, {2, Platform} };

    Sprite.setPosition(450, 250);
    BackImage.setPosition(0, 0);
    Platform.setPosition(550, 290);
    sf::RenderWindow window(sf::VideoMode(800, 449), "Koe-chto");

    sf::Texture PlatformTexture;
    PlatformTexture.loadFromFile(RESOURSE_PATH + "Stone.png");
    
    sf::Texture texture;
    texture.loadFromFile(RESOURSE_PATH + "spriteList.png");

    sf::Texture BackImage2;
    BackImage2.loadFromFile(RESOURSE_PATH + "BackImage.png");

    sf::Clock time;
    
    Sprite.setTexture(texture);
    BackImage.setTexture(BackImage2);
    Platform.setTexture(PlatformTexture);
    float time1 = 0;


    sf::IntRect r1(0, 298, 90, 84);
    sf::IntRect r2(0, 205, 90, 84);
    sf::IntRect r3(0, 0, 90, 84);
    sf::IntRect r4(0, 0, 800, 449);
    sf::IntRect r5(0, 0, 72, 47);

    Sprite.setTextureRect(r1);
    BackImage.setTextureRect(r4);
    Platform.setTextureRect(r5);
    while(window.isOpen())
    {
        auto time_ = time.restart().asSeconds();
        time1 += time_;
        if (time1 >= 1.0)
        {
            positionX_hub = Sprite.getPosition().x;
            positionY_hub = Sprite.getPosition().y;
        }
        auto temp = Sprite.getGlobalBounds();
        temp.top += temp.height - 1;
        temp.height = 1;
        if (time1 >= 0.050)
        {
            /////////////////////движение/////////////////////
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                update(0, -10, r3); //при прыжке должны увеличивать скорость по Y
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    update(0, -10, r1); //при прыжке должны увеличивать скорость по Y
                }
                update(10, 0, r1); //когда ходим должны увеличивать скорость по X и умножать её на 1  или -1 чтобы менять направление
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    update(0, -10, r2);//при прыжке должны увеличивать скорость по Y
                }
                update(-10, 0, r2);//когда ходим должны увеличивать скорость по X и умножать её на 1  или -1 чтобы менять направление
            }
            else
            {
                update(0, 0, r3);
            }
            /////////////////////движение/////////////////////

            time1 = 0;
        }
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(BackImage);
        window.draw(Platform);
        window.draw(Sprite);
        window.display();
    }


    return 0;
}
