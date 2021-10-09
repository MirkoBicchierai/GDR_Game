#ifndef GDR_GAME_PLAYER_H
#define GDR_GAME_PLAYER_H

#include <SFML/Graphics.hpp>

class Player {

    public:
        Player();
        void move(float dir_x,float dir_y);
        void draw(sf::RenderWindow &window);
        void updatePhysics();
    private:
        sf::Texture playerTexture;
        sf::Sprite playerSprite;
        sf::IntRect playerRect;

        //Physics
        sf::Vector2f velocity;
        float maxVelocity;
        float minVelocity;
        float acceleration;
        float drag;
        void initPhysics();
};

#endif
