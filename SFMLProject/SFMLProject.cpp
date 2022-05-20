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

sf::Sprite sprite; 
sf::Sprite BackImage;
sf::Sprite Platform;
std::vector<int> v(500);
int eyes;

void moving(sf::IntRect& a) //функция принимает значение типа IntRect и кладёт его в 'a'
{
    sprite.setTextureRect(a);
    if (a.top != 0)
    {
        a.left += 100.0;
    }
    else
    {
        a.left = 0;
    }
    auto temp1 = sprite.getGlobalBounds();
    auto temp2 = temp1;
    temp1.left += temp1.width - 1;
    temp1.width = 1;
    temp2.width = 1;

    //sprite.getGlobalBounds().left + sprite.getGlobalBounds().width != 
    if (eyes == 1 && !temp1.intersects(Platform.getGlobalBounds()))
    {
       sprite.move(10, 0);
    }
    else if (eyes == 2 && !temp2.intersects(Platform.getGlobalBounds()))
    {
        sprite.move(10 * -1, 0);
    }
    
    if (a.left > 950)
    {
        a.left = 0;
    }
}

int main()
{
    sprite.setPosition(450, 250);
    BackImage.setPosition(0, 0);
    Platform.setPosition(550, 290);
    sf::RenderWindow window(sf::VideoMode(800, 449), "Koe-chto");

    sf::Texture PlatformTexture;
    PlatformTexture.loadFromFile("Stone.png");
    
    sf::Texture texture;
    texture.loadFromFile("spriteList.png");

    sf::Texture BackImage2;
    BackImage2.loadFromFile("BackImage.png");

    sf::Clock time;
    
    sprite.setTexture(texture);
    BackImage.setTexture(BackImage2);
    Platform.setTexture(PlatformTexture);
    float time1 = 0;

    sf::IntRect r1(0, 300, 100, 100);
    sf::IntRect r2(0, 200, 100, 100);
    sf::IntRect r3(0, 0, 100, 100);
    sf::IntRect r4(0, 0, 800, 449);

    sprite.setTextureRect(r1);
    BackImage.setTextureRect(r4);
    while(window.isOpen())
    {
        auto time_ = time.restart().asSeconds();
        time1 += time_;

        if (time1 >= 0.050)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                eyes = 1;
                moving(r1);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                eyes = 2;
                moving(r2);
            }
            else
            {
                eyes = 0;
                moving(r3);
            }
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
        window.draw(sprite);
        window.display();
    }


    return 0;
}
