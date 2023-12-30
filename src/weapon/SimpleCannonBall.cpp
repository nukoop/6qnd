#include "weapon/SimpleCannonBall.hpp"

SimpleCannonBall::SimpleCannonBall(float maxSpeed, float scale)
    : CannonBall(maxSpeed, scale) {
    if(!this->texture.loadFromFile("data/image/CannonBall/simple_cannon_ball.png")) {
        std::cout << "[錯誤] 讀取 " << "data/image/CannonBall/simple_cannon_ball.png" << " 圖片時發生了錯誤" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(scale, scale);
}

SimpleCannonBall::~SimpleCannonBall() {
    
}