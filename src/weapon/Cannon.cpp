#include <iostream>
#include "weapon/Cannon.hpp"

Cannon::Cannon(float& x, float& y) {
    if (!this->texture.loadFromFile("data/image/Cannon2_color1/Cannon2_color1_1.png")) {
        std::cout << "[錯誤] 讀取 data/image/Cannon2_color1/Cannon2_color1_1.png 圖片時發生了錯誤" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(1.f, 1.f);
    this->sprite.setOrigin(
        66,
        44
    );

    this->sprite.setPosition(x, y);

    this->switchTime = 0.1f;
    this->totalTime = 0.f;
    this->curretImage = 1;
    this->imageCount = 3;
}

Cannon::~Cannon() {
    std::cout << "Cannon destructor called" << std::endl;
}

// 動畫
void Cannon::animate(float deltaTime) {
    this->totalTime += deltaTime;

    if (this->totalTime >= this->switchTime) {

        this->totalTime -= this->switchTime;
        this->curretImage++;

        if (this->curretImage > this->imageCount) {
            this->curretImage = 1;
        }

        if(!this->texture.loadFromFile("data/image/Cannon2_color1/Cannon2_color1_" + std::to_string(this->curretImage) + ".png")) {
            std::cout << "[錯誤] 讀取 data/image/Cannon2_color1/Cannon2_color1_" + std::to_string(this->curretImage) + ".png 圖片時發生了錯誤" << std::endl;
        }
    }
}

// 面對滑鼠
void Cannon::updateMouseInput(const sf::RenderWindow &window) {
    sf::Vector2f curPos = this->sprite.getPosition();
    sf::Vector2i position = sf::Mouse::getPosition(window);

    const float PI = 3.14159265;

    float dx = curPos.x - position.x;
    float dy = curPos.y - position.y;

    float rotation = (atan2(dy, dx)) * 180 / PI;

    this->sprite.setRotation(rotation + 90);
}

void Cannon::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
}