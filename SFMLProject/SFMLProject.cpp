#include <iostream>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <string.h>
#include <vector>
#include "config.hpp"
#include "program.hpp"
//#include "objects.hpp"
#include "player.hpp"
#include "backimage.hpp"
#include "platform.hpp"

Program mainProgram;
BackImage mainBackImage;
Player mainPlayer;
std::vector<Platform> PlatformVector (10);
 
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
            std::cout << mainPlayer.Sprite.getPosition().x << ' ' << mainPlayer.Sprite.getPosition().y << ' ' << mainPlayer.SpriteVx << ' ' << mainPlayer.SpriteVy << '\n';
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
