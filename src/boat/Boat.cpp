#include "boat/Boat.hpp"
#include "system/Animation.hpp"

Boat::Boat(float x, float y, float movementSpeed, Cannon* cannon, CannonBall* cannonBall, float frameSwitchTime, int frameAmount, int frameMinimum, int frameDefault)
    : animation(frameSwitchTime, frameAmount, frameMinimum, frameDefault) {
    
    this->sprite.setPosition(x, y);
    this->movementSpeed = movementSpeed;
    this->cannon = cannon;
    this->cannonBall = cannonBall;
    this->sprite.setOrigin(64, 64);
}

void Boat::upward() {
    this->sprite.move(0.f, -this->movementSpeed);
    this->sprite.setRotation(180);
}

void Boat::downward() {
    this->sprite.move(0.f, this->movementSpeed);
    this->sprite.setRotation(0);
}

void Boat::forward() {
    this->sprite.move(-this->movementSpeed, 0.f);
    this->sprite.setRotation(90);
}

void Boat::backward() {
    this->sprite.move(this->movementSpeed, 0.f);
    this->sprite.setRotation(270);
}

void Boat::setIsFire(bool isFire) {
    this->cannon->setIsFire(isFire);
}

bool Boat::getIsFire() {
    return this->cannon->getIsFire();
}

void Boat::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
    this->cannon->setPosition(x, y);
}

sf::Vector2f Boat::getPosition() {
    return this->sprite.getPosition();
}

sf::FloatRect Boat::getGlobalBounds() {
    return this->sprite.getGlobalBounds();
}

void Boat::update(const sf::RenderWindow &window) {
    updateRotation();
    this->animation.update(this->clock.restart().asSeconds());
    this->texture = this->textures[this->animation.current - 1];
    this->cannon->update(window);
}

void Boat::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
    this->cannon->render(target);
}