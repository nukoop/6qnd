#include "boat/OriginalEnemyBoat.hpp"
#include "boat/AlphaBoat.hpp"

OriginalEnemyBoat::OriginalEnemyBoat(float x, float y, float movementSpeed, Cannon* cannon, CannonBall* cannonBall)
    : Boat(x, y, movementSpeed, cannon, cannonBall, 0.2f, 4, 1, 1) {
    
    // 設置大砲中心點
    if(const AlphaCannon* alphaCannonPtr = dynamic_cast<const AlphaCannon*>(cannon)) {
        cannon->setOrigin(66, 44);
    } else {
        cannon->setOrigin(64, 64);
    }
    
    // 讀取所有圖片
    for(int i = 0; i < 4; i++) {
        sf::Texture texture;
        if(!texture.loadFromFile("data/image/Boat1_water_animation_color3/Boat1_water_frame" + std::to_string(i + 1) + ".png")) {
            std::cout << "[錯誤] 讀取 " << "data/image/Boat1_water_animation_color3/Boat1_water_frame" << std::to_string(i + 1) << ".png 圖片時發生了錯誤" << std::endl;
        } else {
            this->textures.push_back(texture);
        }
    }

    // 把圖片設置為預設圖片
    this->texture = this->textures[0];
    this->sprite.setTexture(this->texture);
}

void OriginalEnemyBoat::updateRotation() {
    // 更新敵人船的旋轉行為
    // 可以根據需要添加自定義的旋轉邏輯
    // 例如，根據玩家船的位置追蹤和旋轉敵人船
    // 或是使用隨機的旋轉方向等
}