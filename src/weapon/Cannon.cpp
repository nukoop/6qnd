#include <iostream>
#include "weapon/Cannon.hpp"

Cannon::Cannon(float& x, float& y) {
    std::cout << "Cannon constructor called" << std::endl;

    if (!this->texture.loadFromFile("data/image/Cannon2_color1/Cannon2_color1_1.png")) {
        std::cout << "[錯誤] 讀取 data/image/Cannon2_color1/Cannon2_color1_1.png 圖片時發生了錯誤" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(1.f, 1.f);
    this->sprite.setOrigin(
        this->sprite.getGlobalBounds().width / 2,
        this->sprite.getGlobalBounds().height / 2
    );

    this->sprite.setPosition(x, y);
}

Cannon::~Cannon() {
    std::cout << "Cannon destructor called" << std::endl;
}

void Cannon::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
}