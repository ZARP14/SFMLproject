#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <string.h>
#include <map>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <fstream>



/////////////////////Это нужно для всякого разного с путями/////////////////////
#define CONFIG_PATH path() + "resourse\\config\\"
#define TEXTURE_PATH path() + "resourse\\textures\\"
/////////////////////Это нужно для всякого разного с путями/////////////////////

class Programm
{
public:
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

    /////////////////////функция для удобного использования конфигов/////////////////////
    struct result //в зависимости от типа данных которомуты присваиваешь функцию он возвращает необходимый тип данных, но их надо прописывать в этой структуре
    { //то есть если я int bebra = getConfigFunction() мне вернётся int а если буду присваивать переменной типа стринг то мне вернётся стринг
        std::string res;

        operator int()
        {
            return std::stoi(res);
        }

        operator std::string()
        {
            return res;
        }
    };

    result getConfigFunction(std::ifstream& file)
    {
        std::string s;
        std::getline(file, s, ':');


        result r;
        file >> r.res;
        return r;
    }
    /////////////////////функция для удобного использования конфигов/////////////////////
};
Programm mainProgramm;

class BackImage
{
public:
    sf::Sprite BackImageSprite;
    sf::IntRect BackImageRectangle;
    sf::Texture BackImageTexture;
    BackImage() :
        BackImageRectangle(0, 0, 800, 449)
    {
        BackImageSprite.setTextureRect(BackImageRectangle);
        BackImageTexture.loadFromFile(mainProgramm.TEXTURE_PATH + "BackImage.png");
        BackImageSprite.setTexture(BackImageTexture);
    }
};
BackImage mainBackImage;

class Platform
{
public:
    sf::Texture PlatformTexture;
    sf::IntRect PlatformRectangle;
    sf::Sprite PlatformSprite;
    Platform() :
        PlatformRectangle(0, 0, 72, 47)
    {
        PlatformTexture.loadFromFile(mainProgramm.TEXTURE_PATH + "Stone.png");
        PlatformSprite.setTexture(PlatformTexture);
    }
};
std::vector<Platform> PlatformVector(10);

class Player
{
    public:

        int CFG_JumpStrength; //загружаемые из файла значения для указания силы прыжка
        int CFG_WalkingSpeed; //загружаемые из файла значения для указания скорости ходьбы

        /////////////////////спрайт/////////////////////
        sf::Sprite Sprite;
        /////////////////////спрайт/////////////////////

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

        /////////////////////map для функции intersection/////////////////////
        std::map<int, sf::Sprite&> List_Of_Subjects;
        /////////////////////map для функции intersection/////////////////////

        Player() :

            RightWalkingRectanle    (0, 298, 90, 84), 
            LeftWalkingRectanle     (0, 205, 90, 84), 
            WaitingRectanle         (0, 0, 90, 84)
        {
            /////////////////////загружаем переменные скорости из файла/////////////////////
            std::ifstream config_file(mainProgramm.CONFIG_PATH + "config.cfg");
            CFG_JumpStrength = mainProgramm.getConfigFunction(config_file);
            CFG_WalkingSpeed = mainProgramm.getConfigFunction(config_file);
            /////////////////////загружаем переменные скорости из файла/////////////////////

            /////////////////////задаём текстуру для персонажа/////////////////////
            sf::Texture SpriteTexture;
            SpriteTexture.loadFromFile(mainProgramm.TEXTURE_PATH + "SpriteList.png");
            /*Sprite.setTextureRect(RightWalkingRectanle);*/
            Sprite.setTexture(SpriteTexture);
            /////////////////////задаём текстуру для персонажа/////////////////////

            /////////////////////части коллизии спрайта/////////////////////
            ColLine_Right = Sprite.getGlobalBounds();//Правая часть хитбокса
            ColLine_Left = ColLine_Right;//Левая часть хитбокса
            ColLine_Top = Sprite.getGlobalBounds();//Верхняя часть хитбокса
            ColLine_Down = ColLine_Top;//Нижняя часть хитбокса
            /////////////////////части коллизии спрайта/////////////////////

            /////////////////////map для функции intersection/////////////////////
            List_Of_Subjects = { {0, Sprite}, {1, mainBackImage.BackImageSprite}, {2, PlatformVector[0].PlatformSprite} };
            /////////////////////map для функции intersection/////////////////////
        }

        /////////////////////функция для определения пресекается объект с ЛЮБЫМ други или нет/////////////////////
        void intersection_function()
        {

        }
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
    
};
Player mainPlayer;
 
int main()
{ 

    mainBackImage.BackImageSprite.setPosition(0, 0);
    PlatformVector[0].PlatformSprite.setPosition(550, 290);
    mainPlayer.Sprite.setPosition(150, 250);
    sf::RenderWindow window(sf::VideoMode(800, 449), "Koe-chto");

    sf::Clock time;
    float time1 = 0;

    while(window.isOpen())
    {
        auto time_ = time.restart().asSeconds();
        time1 += time_;
        if (time1 >= 0.050)
        {
            /////////////////////движение/////////////////////
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                mainPlayer.update(0, mainPlayer.CFG_JumpStrength, mainPlayer.WaitingRectanle); //при прыжке должны увеличивать скорость по Y
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    mainPlayer.update(0, mainPlayer.CFG_JumpStrength, mainPlayer.RightWalkingRectanle); //при прыжке должны увеличивать скорость по Y 
                }
                mainPlayer.update(mainPlayer.CFG_WalkingSpeed, 0, mainPlayer.RightWalkingRectanle); //когда ходим должны увеличивать скорость по X и умножать её на 1  или -1 чтобы менять направление
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    mainPlayer.update(0, mainPlayer.CFG_JumpStrength, mainPlayer.LeftWalkingRectanle);//при прыжке должны увеличивать скорость по Y
                }
                mainPlayer.update(mainPlayer.CFG_WalkingSpeed * -1, 0, mainPlayer.LeftWalkingRectanle);//когда ходим должны увеличивать скорость по X и умножать её на 1  или -1 чтобы менять направление
            }
            else
            {
                mainPlayer.update(0, 0, mainPlayer.WaitingRectanle);
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
        window.draw(mainBackImage.BackImageSprite);
        window.draw(PlatformVector[0].PlatformSprite);
        window.draw(mainPlayer.Sprite);
        window.display();
    }

    return 0;
}
