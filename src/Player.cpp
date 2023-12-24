#include "Player.hpp"

void Player::initVariables() {
    this->movementSpeed = 10.f;
}

void Player::initShape() {
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(100.f, 100.f));

}

Player::Player(float x, float y) {
    this->shape.setPosition(x, y);

    this->initVariables();
    this->initShape();
}

Player::~Player() {

}

// 鍵盤輸入
void Player::updateInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->shape.move(-this->movementSpeed, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->shape.move(this->movementSpeed, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->shape.move(0.f, -this->movementSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->shape.move(0.f, this->movementSpeed);
    }
}

// 碰撞邊界
void Player::updateWindowBoundsCollision(const sf::RenderTarget* target) {
    if (this->shape.getGlobalBounds().left <= 0.f) {
        this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
    }
    if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x) {
        this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
    }
    if (this->shape.getGlobalBounds().top <= 0.f) {
        this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
    }
    if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y) {
        this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);
    }
}

void Player::update(const sf::RenderTarget* target) {
    this->updateInput();
    this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget* target) {
    target->draw(this->shape);
}