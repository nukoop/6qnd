#include <iostream>
#include <algorithm>
#include <cmath>
#include "boat/Boat.hpp"
#include "system/Animation.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

Boat::Boat(float x, float y) {
    this->movementSpeed = 2.f;
    this->path = "data/image/Boat1_water_animation_color1/Boat1_water_frame";

    this->sprite.setPosition(x, y);
    this->cannon = new Cannon(x, y, 3, 1);
    this->animation = new Animation(0.2f, 4, 1);

    if (!this->texture.loadFromFile("data/image/Boat1_water_animation_color1/Boat1_water_frame1.png")) {
        std::cout << "[錯誤] 讀取 data/image/Boat1_water_animation_color1/Boat1_water_frame1.png 圖片時發生了錯誤" << std::endl;
    }

    this->sprite.setTexture(this->texture);
    this->sprite.setOrigin(
        this->sprite.getGlobalBounds().width / 2,
        this->sprite.getGlobalBounds().height / 2
    );
    this->sprite.setPosition(
        WINDOW_WIDTH / 2,
        WINDOW_HEIGHT / 2
    );
}

Boat::~Boat() {

}

// 鍵盤輸入
void Boat::updateInput() {
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

    if(this->sprite.getRotation() == 0) {
        this->cannon->setSpritePosition(this->sprite.getPosition().x + 2, this->sprite.getPosition().y - 20);
    } else if(this->sprite.getRotation() == 90) {
        this->cannon->setSpritePosition(this->sprite.getPosition().x + 20, this->sprite.getPosition().y + 2);
    } else if(this->sprite.getRotation() == 180) {
        this->cannon->setSpritePosition(this->sprite.getPosition().x + 2, this->sprite.getPosition().y + 20);
    } else if(this->sprite.getRotation() == 270) {
        this->cannon->setSpritePosition(this->sprite.getPosition().x - 20, this->sprite.getPosition().y - 2);
    }
}

void Boat::update(const sf::RenderWindow &window) {
    this->updateInput();
    
    this->animation->update(this->clock.restart().asSeconds());
    if(!this->texture.loadFromFile(this->path + std::to_string(this->animation->current) + ".png")) {
        std::cout << "[錯誤] 讀取 " << this->path << std::to_string(this->animation->current) << ".png 圖片時發生了錯誤" << std::endl;
    }
    
    this->cannon->update(window);
}

void Boat::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
    this->cannon->render(target);
}