#include <iostream>

#include "Player.hpp"

void Player::initVariables() {
    this->movementSpeed = 10.f;
}

void Player::initSprite() {
    if (!this->texture.loadFromFile("data/image/player/1.png")) {
        std::cout << "Error: Could not load player texture" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(5.f, 5.f);
}

Player::Player(float x, float y) {
    this->sprite.setPosition(x, y);

    this->initVariables();
    this->initSprite();
}

Player::~Player() {

}

// 鍵盤輸入
void Player::updateInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->sprite.move(-this->movementSpeed, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->sprite.move(this->movementSpeed, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->sprite.move(0.f, -this->movementSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->sprite.move(0.f, this->movementSpeed);
    }
}

// 碰撞邊界
void Player::updateWindowBoundsCollision(const sf::RenderTarget* target) {
    if (this->sprite.getGlobalBounds().left <= 0.f) {
        this->sprite.setPosition(0.f, this->sprite.getGlobalBounds().top);
    }
    if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= target->getSize().x) {
        this->sprite.setPosition(target->getSize().x - this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().top);
    }
    if (this->sprite.getGlobalBounds().top <= 0.f) {
        this->sprite.setPosition(this->sprite.getGlobalBounds().left, 0.f);
    }
    if (this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height >= target->getSize().y) {
        this->sprite.setPosition(this->sprite.getGlobalBounds().left, target->getSize().y - this->sprite.getGlobalBounds().height);
    }
}

void Player::update(const sf::RenderTarget* target) {
    this->updateInput();
    this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
}