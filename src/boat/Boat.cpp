#include "boat/Boat.hpp"

Boat::Boat(float x, float y, float movementSpeed, Cannon* cannon, CannonBall* cannonBall, float frameSwitchTime, int frameAmount, int frameMinimum, int frameDefault)
    : animation(frameSwitchTime, frameAmount, frameMinimum, frameDefault) {
    
    this->sprite.setPosition(x, y);
    this->movementSpeed = movementSpeed;
    this->cannon = cannon;
    this->cannonBall = cannonBall;
    this->sprite.setOrigin(64, 64);

    this->healthBar.setSize(sf::Vector2f(100, 10));
    this->healthBar.setFillColor(sf::Color::Red);
    this->healthBarOutline.setSize(sf::Vector2f(100, 10));
    this->healthBarOutline.setFillColor(sf::Color::Transparent);
    this->healthBarOutline.setOutlineColor(sf::Color::White);
    this->healthBarOutline.setOutlineThickness(1);
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

    this->healthBarOutline.setPosition(this->sprite.getPosition().x -50, this->sprite.getPosition().y - 80);//更新血條外框位置
    this->healthBar.setPosition(this->sprite.getPosition().x -50, this->sprite.getPosition().y - 80);//更新血條位置
}

void Boat::render(sf::RenderTarget* target) {
    target->draw(this->healthBarOutline);
    target->draw(this->healthBar);//渲染血條
    target->draw(this->sprite);
    this->cannon->render(target);
}


float Boat::getMovementSpeed() const {
    return movementSpeed;
}

void Boat::moveTowardsPlayer(const sf::Vector2f& playerPosition) {
    sf::Vector2f direction = playerPosition - getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    // 正規化方向向量
    if (length != 0) {
        direction /= length;
    }

    float speed = getMovementSpeed();
    this->sprite.move(direction.x * speed, direction.y * speed);
    float angle = std::atan2(direction.y, direction.x) * (180.0 / M_PI);
    this->sprite.setRotation(angle - 90);
}
