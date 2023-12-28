#include <iostream>
#include "weapon/Bullet.hpp"

Bullet::Bullet(std::string path, float maxSpeed, float scale, sf::Vector2f currentVelocity) {
    if(!this->texture.loadFromFile(path)) {
        std::cout << "[錯誤] 讀取 " << path << " 圖片時發生了錯誤" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(scale, scale);
    this->path = path;
    this->maxSpeed = maxSpeed;
    this->scale = scale;
    this->currentVelocity = currentVelocity;
}

Bullet::~Bullet() {

}

void Bullet::setOrigin(float x, float y) {
    this->sprite.setOrigin(x, y);
}

void Bullet::setCurrentVelocity(sf::Vector2f currentVelocity) {
    this->currentVelocity = currentVelocity;
}

void Bullet::setRotation(float angle) {
    this->sprite.setRotation(angle);
}

void Bullet::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

float Bullet::getMaxSpeed() {
    return this->maxSpeed;
}

sf::Vector2f Bullet::getPosition() {
    return this->sprite.getPosition();
}

void Bullet::move() {
    this->sprite.move(this->currentVelocity);
}

void Bullet::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
}