#include <iostream>
#include <algorithm>

#include "Player.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

void Player::initVariables() {
    this->movementSpeed = 10.f;
    this->scale = 10.f;
}

void Player::initSprite() {
    if (!this->texture.loadFromFile("data/image/player/boat.png")) {
        std::cout << "Error: Could not load player texture" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    // this->sprite.setScale(this->scale, this->scale);
    this->sprite.setOrigin(
        this->sprite.getGlobalBounds().width / 2,
        this->sprite.getGlobalBounds().height / 2
    );
    this->sprite.setPosition(
        WINDOW_WIDTH / 2,
        WINDOW_HEIGHT / 2
    );
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->sprite.getPosition().x > (0.f + std::max(this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().height) / 2)) {
        this->sprite.move(-this->movementSpeed, 0.f);
        this->sprite.setRotation(90);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->sprite.getPosition().x < (WINDOW_WIDTH - std::max(this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().height) / 2)) {
        this->sprite.move(this->movementSpeed, 0.f);
        this->sprite.setRotation(270);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->sprite.getPosition().y > (0.f + std::max(this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().height) / 2)) {
        this->sprite.move(0.f, -this->movementSpeed);
        this->sprite.setRotation(180);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->sprite.getPosition().y < (WINDOW_HEIGHT - std::max(this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().height) / 2)) {
        this->sprite.move(0.f, this->movementSpeed);
        this->sprite.setRotation(0);
    }
}

// 面對滑鼠
void Player::updateMouseInput(const sf::RenderWindow &window) {
    sf::Vector2f curPos = this->sprite.getPosition();
    sf::Vector2i position = sf::Mouse::getPosition(window);

    const float PI = 3.14159265;

    float dx = curPos.x - position.x;
    float dy = curPos.y - position.y;

    float rotation = (atan2(dy, dx)) * 180 / PI;

    this->sprite.setRotation(rotation + 90);
}

void Player::update(const sf::RenderWindow &window) {
    this->updateInput();
    // this->updateMouseInput(window);
}

void Player::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
}