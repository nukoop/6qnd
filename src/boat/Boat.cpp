#include <iostream>
#include <algorithm>
#include <cmath>
#include "boat/Boat.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

void Boat::initVariables() {
    this->movementSpeed = 2.f;
    this->scale = 10.f;
    this->totalTime = 0.f;
    this->switchTime = 0.2f;
    this->curretImage = 1;
    this->imageCount = 4;
}

void Boat::initSprite() {
    if (!this->texture.loadFromFile("data/image/Boat1_water_animation_color1/Boat1_water_frame1.png")) {
        std::cout << "[錯誤] 讀取 data/image/Boat1_water_animation_color1/Boat1_water_frame1.png 圖片時發生了錯誤" << std::endl;
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

Boat::Boat(float x, float y) {
    this->sprite.setPosition(x, y);
    this->cannon = new Cannon(x, y);

    this->initVariables();
    this->initSprite();
}

Boat::~Boat() {

}

// 動畫
void Boat::animate(float deltaTime) {
    this->totalTime += deltaTime;

    if (this->totalTime >= this->switchTime) {
        this->totalTime -= this->switchTime;
        this->curretImage++;

        if (this->curretImage > this->imageCount) {
            this->curretImage = 1;
        }

        if(!this->texture.loadFromFile("data/image/Boat1_water_animation_color1/Boat1_water_frame" + std::to_string(this->curretImage) + ".png")) {
            std::cout << "[錯誤] 讀取 data/image/Boat1_water_animation_color1/Boat1_water_frame" + std::to_string(this->curretImage) + ".png 圖片時發生了錯誤" << std::endl;
        }
    }
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
        this->cannon->sprite.setPosition(this->sprite.getPosition().x + 2, this->sprite.getPosition().y - 20);
    } else if(this->sprite.getRotation() == 90) {
        this->cannon->sprite.setPosition(this->sprite.getPosition().x + 20, this->sprite.getPosition().y + 2);
    } else if(this->sprite.getRotation() == 180) {
        this->cannon->sprite.setPosition(this->sprite.getPosition().x + 2, this->sprite.getPosition().y + 20);
    } else if(this->sprite.getRotation() == 270) {
        this->cannon->sprite.setPosition(this->sprite.getPosition().x - 20, this->sprite.getPosition().y - 2);
    }
    
    // this->cannon->sprite.setRotation(this->sprite.getRotation());
}

// 面對滑鼠
void Boat::updateMouseInput(const sf::RenderWindow &window) {
    sf::Vector2f curPos = this->sprite.getPosition();
    sf::Vector2i position = sf::Mouse::getPosition(window);

    const float PI = 3.14159265;

    float dx = curPos.x - position.x;
    float dy = curPos.y - position.y;

    float rotation = (atan2(dy, dx)) * 180 / PI;

    this->sprite.setRotation(rotation + 90);
}


void Boat::update(const sf::RenderWindow &window) {
    this->updateInput();
    this->cannon->updateMouseInput(window);
    this->animate(this->clock.restart().asSeconds());
    this->cannon->animate(this->clock2.restart().asSeconds());
    // this->updateMouseInput(window);
}

void Boat::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
    target->draw(this->cannon->sprite);
}