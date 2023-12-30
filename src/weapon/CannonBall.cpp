#include "weapon/CannonBall.hpp"

CannonBall::CannonBall(float maxSpeed, float scale) {
    this->maxSpeed = maxSpeed;
    this->scale = scale;
    this->currentVelocity = {0, 0};
}

void CannonBall::setOrigin(float x, float y) {
    this->sprite.setOrigin(x, y);
}

sf::Vector2f CannonBall::getOrigin() {
    return this->sprite.getOrigin();
}

void CannonBall::setCurrentVelocity(sf::Vector2f currentVelocity) {
    this->currentVelocity = currentVelocity;
}

sf::Vector2f CannonBall::getCurrentVelocity() {
    return this->currentVelocity;
}

void CannonBall::setRotation(float angle) {
    this->sprite.setRotation(angle);
}

float CannonBall::getRotation() {
    return this->sprite.getRotation();
}

void CannonBall::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

sf::Vector2f CannonBall::getPosition() {
    return this->sprite.getPosition();
}

void CannonBall::setMaxSpeed(float maxSpeed) {
    this->maxSpeed = maxSpeed;
}

float CannonBall::getMaxSpeed() {
    return this->maxSpeed;
}

void CannonBall::update() {
    this->sprite.move(this->currentVelocity);
}

void CannonBall::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
}