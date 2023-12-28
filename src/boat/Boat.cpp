#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include "boat/Boat.hpp"
#include "system/Animation.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

Boat::Boat(float x, float y, float movementSpeed, float switchTime, std::string path, int imageCount, int defaultImage)
:   cannon(x, y, 0.1f, "data/image/Cannon2_color3/Cannon2_color3_", 66, 44, "data/image/Fire1/Fire1_", "data/sound/cannon1.wav", 34, -36, "data/image/Bullet/bullet.png", 15.f, 0.07f, 4, 1, 2),
    animation(switchTime, imageCount, defaultImage, defaultImage) {
    this->movementSpeed = movementSpeed;
    this->defaultImage = defaultImage;

    this->sprite.setPosition(x, y);

    // 讀取所有圖片
    for(int i = 0; i < imageCount; i++) {
        sf::Texture texture;
        sf::Texture fireTexture;
        if(!texture.loadFromFile(path + std::to_string(i + 1) + ".png")) {
            std::cout << "[錯誤] 讀取 " << path << std::to_string(i + 1) << ".png 圖片時發生了錯誤" << std::endl;
        } else {
            this->textures.push_back(texture);
        }
    }

    // 把圖片設置為預設圖片
    this->texture = this->textures[defaultImage - 1];
    this->sprite.setTexture(this->texture);

    this->sprite.setOrigin(
        this->sprite.getGlobalBounds().width / 2,
        this->sprite.getGlobalBounds().height / 2
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
        this->cannon.setSpritePosition(this->sprite.getPosition().x + 2, this->sprite.getPosition().y - 20);
        this->cannon.setFireSpritePosition(this->sprite.getPosition().x + 2, this->sprite.getPosition().y - 20);
    } else if(this->sprite.getRotation() == 90) {
        this->cannon.setSpritePosition(this->sprite.getPosition().x + 20, this->sprite.getPosition().y + 2);
        this->cannon.setFireSpritePosition(this->sprite.getPosition().x + 20, this->sprite.getPosition().y + 2);
    } else if(this->sprite.getRotation() == 180) {
        this->cannon.setSpritePosition(this->sprite.getPosition().x + 2, this->sprite.getPosition().y + 20);
        this->cannon.setFireSpritePosition(this->sprite.getPosition().x + 2, this->sprite.getPosition().y + 20);
    } else if(this->sprite.getRotation() == 270) {
        this->cannon.setSpritePosition(this->sprite.getPosition().x - 20, this->sprite.getPosition().y - 2);
        this->cannon.setFireSpritePosition(this->sprite.getPosition().x - 20, this->sprite.getPosition().y - 2);
    }
}

void Boat::update(const sf::RenderWindow &window) {
    this->updateInput();
    
    this->animation.update(this->clock.restart().asSeconds());
    this->texture = this->textures[this->animation.current - 1];
    
    this->cannon.update(window);
}

void Boat::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
    this->cannon.render(target);
}