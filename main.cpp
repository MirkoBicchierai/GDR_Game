#include <SFML/Graphics.hpp>
#include "config.cpp"
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(screen::WIDTH, screen::HEIGHT), "GDR_Game");
    window.setFramerateLimit(screen::FRAME);

    auto player = new Player();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                player->move(0,-1);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                player->move(0,1);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                player->move(-1,0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                player->move(1,0);

        }

        window.clear();
        player->draw(window);
        player->updatePhysics();
        window.display();
    }

    return 0;
}


