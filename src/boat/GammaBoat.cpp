#include "boat/GammaBoat.hpp"

GammaBoat::GammaBoat(float x, float y, float movementSpeed, Cannon* cannon, CannonBall* cannonBall)
    : Boat(x, y, movementSpeed, cannon, cannonBall, 0.2f, 4, 1, 1) {
    
    // 設置大砲中心點
    if(const GammaCannon* gammaCannonPtr = dynamic_cast<const GammaCannon*>(cannon)) {
        cannon->setOrigin(33, 22);
    } else {
        cannon->setOrigin(33, 22);
    }

    // 讀取所有圖片
    for(int i = 0; i < 4; i++) {
        sf::Texture texture;
        if(!texture.loadFromFile("data/image/Boat3_water_animation_color3/Boat3_water_frame" + std::to_string(i + 1) + ".png")) {
            std::cout << "[錯誤] 讀取 " << "data/image/Boat3_water_animation_color3/Boat3_water_frame" << std::to_string(i + 1) << ".png 圖片時發生了錯誤" << std::endl;
        } else {
            this->textures.push_back(texture);
        }
    }

    // 把圖片設置為預設圖片
    this->texture = this->textures[0];
    this->sprite.setTexture(this->texture);
}

GammaBoat::~GammaBoat() {

}

void GammaBoat::updateRotation() {
    if(const GammaCannon* alphaCannonPtr = dynamic_cast<const GammaCannon*>(cannon)) {
        if(this->sprite.getRotation() == 0) {
            this->cannon->setPosition(this->sprite.getPosition().x + 2, this->sprite.getPosition().y - (-20));
        } else if(this->sprite.getRotation() == 90) {
            this->cannon->setPosition(this->sprite.getPosition().x + (-20), this->sprite.getPosition().y + 2);
        } else if(this->sprite.getRotation() == 180) {
            this->cannon->setPosition(this->sprite.getPosition().x - 2, this->sprite.getPosition().y + (-20));
        } else if(this->sprite.getRotation() == 270) {
            this->cannon->setPosition(this->sprite.getPosition().x - (-20), this->sprite.getPosition().y - 2);
        }
    } else {

    }
}