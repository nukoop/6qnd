#include <iostream>
#include "weapon/Cannon.hpp"

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

Cannon::Cannon(float x, float y, int imageCount, int defaultImage) {
    // 設置圖片位置
    this->path = "data/image/Cannon2_color1/Cannon2_color1_";

    // 讀取所有圖片
    for(int i = 0; i < imageCount; i++) {
        sf::Texture texture;
        if(!texture.loadFromFile(this->path + std::to_string(i + 1) + ".png")) {
            std::cout << "[錯誤] 讀取 " << this->path << std::to_string(i + 1) << ".png 圖片時發生了錯誤" << std::endl;
        } else {
            this->textures.push_back(texture);
        }
    }

    // 把圖片設置為預設圖片
    this->texture = this->textures[defaultImage];
    this->sprite.setTexture(this->texture);

    // 設定 Sprite 中心點
    this->sprite.setOrigin(
        66,
        44
    );

    // 設置 Sprite 位置
    this->sprite.setPosition(x, y);

    // 設置動畫
    this->animation = new Animation(0.1f, imageCount, defaultImage);
}

Cannon::~Cannon() {
    
}

void Cannon::update(const sf::RenderWindow &window) {
    this->updateMouseInput(window);
    this->animation->update(this->clock.restart().asSeconds());
    if(!this->texture.loadFromFile(this->path + std::to_string(this->animation->current) + ".png")) {
        std::cout << "[錯誤] 讀取 " << this->path << std::to_string(this->animation->current) << ".png 圖片時發生了錯誤" << std::endl;
    }
}

void Cannon::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
}

void Cannon::setSpritePosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

void Cannon::setSpriteRotation(float angle) {
    this->sprite.setRotation(angle);
}