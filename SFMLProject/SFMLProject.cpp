#include <iostream>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <string.h>
#include <vector>

#include "config.hpp"
#include "program.hpp"
#include "player.hpp"
#include "backimage.hpp"
#include "platform.hpp"

std::vector<Objects> ObjVec;
Program mainProgram;
BackImage mainBackImage;
Player mainPlayer;
std::vector<Platform> PlatformVector (10);

struct IntersectionBool
{
    bool LeftIntersection = false;
    bool RightIntersection = false;
    bool TopIntersection = false;
    bool DownIntersection = false;
};

IntersectionBool intersectionFunction(Intersectable_Objects AliveObject)
{
    IntersectionBool InSec;
    for (int i = ObjVec.size(); i > 0; i--)
    {
        if (AliveObject.ColLine_Left.intersects(ObjVec[i].Sprite.getGlobalBounds())) InSec.LeftIntersection = true;
        if (AliveObject.ColLine_Right.intersects(ObjVec[i].Sprite.getGlobalBounds())) InSec.RightIntersection = true;
        if (AliveObject.ColLine_Top.intersects(ObjVec[i].Sprite.getGlobalBounds())) InSec.TopIntersection = true;
        if (AliveObject.ColLine_Down.intersects(ObjVec[i].Sprite.getGlobalBounds())) InSec.DownIntersection = true;
    }
    return InSec;
}
 
int main()
{
    sf::Event event;
    mainBackImage.BackImageSprite.setPosition(0, 0);
    PlatformVector[0].Sprite.setPosition(550, 290);
    sf::RenderWindow window(sf::VideoMode(800, 449), "Koe-chto");

    sf::Clock time;
    float time1 = 0;

    while(window.isOpen())
    {
        auto time_ = time.restart().asSeconds();
        time1 += time_;
        mainPlayer.update(time1);
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::D)
                    mainPlayer.moving_right = true;
                else if (event.key.code == sf::Keyboard::A)
                    mainPlayer.moving_left = true;
                else if (event.key.code == sf::Keyboard::W)
                    mainPlayer.jump = true;

                break;
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::D)
                    mainPlayer.moving_right = false;
                else if (event.key.code == sf::Keyboard::A)
                    mainPlayer.moving_left = false;
                break;
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
              
        }
        time1 = 0;
        window.clear();
        window.draw(mainBackImage.BackImageSprite);
        window.draw(PlatformVector[0].Sprite);
        window.draw(mainPlayer.Sprite);
        window.display();
    }

    return 0;
}

/////////////////////движение/////////////////////
//if (event.type == sf::Event::Closed) window.close();
//
//if (event.type == sf::Event::KeyPressed)
//{
//    switch (event.key.code)
//    {
//    case sf::Keyboard::W:
//        mainPlayer.update('W', time1); //при прыжке должны увеличивать скорость по Y
//        mainPlayer.animation(time1, 'W');
//        std::cout << 'W' << std::endl;
//        break;
//
//    case sf::Keyboard::D:
//        mainPlayer.update('D', time1); //когда ходим должны увеличивать скорость по X и умножать её на 1  или -1 чтобы менять направление
//        mainPlayer.animation(time1, 'D');
//        std::cout << 'D' << std::endl;
//        break;
//
//    case sf::Keyboard::A:
//        mainPlayer.update('A', time1);//когда ходим должны увеличивать скорость по X и умножать её на 1  или -1 чтобы менять направление
//        mainPlayer.animation(time1, 'A');
//        std::cout << 'A' << std::endl;
//        break;
//
//    default:
//        break;
//    }
//
//}
/////////////////////движение/////////////////////  