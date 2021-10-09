#include "Player.h"
#include <iostream>
Player::Player() {
    playerTexture.loadFromFile("../run.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(sf::Vector2f(2, 2));
    playerRect.height = 16;
    playerRect.width = 16;
    playerRect.left = 0;
    playerRect.top = 0;
    playerSprite.setTextureRect(playerRect);

    this->initPhysics();
}



void Player::draw(sf::RenderWindow &window) {
    window.draw(playerSprite);
}

void Player::initPhysics() {
    this->maxVelocity = 15.f;
    this->minVelocity = 1.f;
    this->acceleration = 2.f;
    this->drag = 0.94f;
}

void Player::updatePhysics() {

    this->velocity *= drag;
    if(std::abs(this->velocity.x) < this->minVelocity)
        this->velocity.x = 0.f;
    if(std::abs(this->velocity.y) < this->minVelocity)
        this->velocity.y = 0.f;

    this->playerSprite.move(this->velocity);

}

void Player::move(float dir_x,float dir_y) {

    this->velocity.x += dir_x * this->acceleration;
    this->velocity.y += dir_y * this->acceleration;
    if(std::abs(this->velocity.x) > this->maxVelocity){
        this->velocity.x = this->maxVelocity * ( (this->velocity.x < 0.f) ? -1.f : 1.f);
    }
}