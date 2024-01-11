#include "weapon/BetaCannon.hpp"

BetaCannon::BetaCannon(float x, float y, CannonBall* cannonBallTemplate, float fireRate, bool isFaceToMouse) 
    : Cannon(x, y, cannonBallTemplate, fireRate, 4, 2, 1, isFaceToMouse) {

    // 設置中心點
    this->fireSprite.setOrigin(37, -25);  //37.-25
    
    // 讀取所有圖片
    for(int i = 0; i < 4; i++) {
        sf::Texture texture;
        sf::Texture fireTexture;
        if(!texture.loadFromFile("data/image/Cannon3_color3/Cannon3_color3_" + std::to_string(i + 1) + ".png")) {
            std::cout << "[錯誤] 讀取 " << "data/image/Cannon3_color3/Cannon3_color3_" << std::to_string(i + 1) << ".png 圖片時發生了錯誤" << std::endl;
        } else {
            this->textures.push_back(texture);
        }

        if(!fireTexture.loadFromFile("data/image/Fire2/Fire2_" + std::to_string(i + 1) + ".png")) {
            std::cout << "[錯誤] 讀取 " << "data/image/Fire2/Fire2_" << std::to_string(i + 1) << ".png 圖片時發生了錯誤" << std::endl;
        } else {
            this->fireTextures.push_back(fireTexture);
        }
    }

    // 讀取大砲音效
    if(!this->fireSoundBuffer.loadFromFile("data/sound/cannon1.wav")) {
        std::cout << "[錯誤] 讀取 data/sound/cannon1.wav 音訊時發生了錯誤" << std::endl;
    }
    this->fireSound.setBuffer(this->fireSoundBuffer);

    // 把大砲和砲火的圖片設置為預設圖片
    this->texture = this->textures[frameDefault - 1];
    this->sprite.setTexture(this->texture);
    this->fireTexture = this->textures[frameDefault - 1];
    this->fireSprite.setTexture(this->fireTexture);
}

BetaCannon::~BetaCannon() {

}

void BetaCannon::fire(const sf::RenderWindow& window) {
    CannonBall* cannonBall = new CannonBall(*cannonBallTemplate);

    //sf::Vector2f cannonCenter = sf::Vector2f(this->sprite.getPosition().x, this->sprite.getPosition().y);
    //sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
    //sf::Vector2f aimDirection = mousePosition - cannonCenter;
    //sf::Vector2f aimDirNorm = aimDirection / std::sqrt(aimDirection.x * aimDirection.x + aimDirection.y * aimDirection.y);

    this->texture = this->textures[this->animation.current - 1];
    this->fireTexture = this->fireTextures[this->animation.current - 1];

    if(this->cannonBallClock.getElapsedTime().asSeconds() > this->fireRate) {
        float angle = this->firingAngle;
        this->cannonBallClock.restart();
        cannonBall->setPosition(
            this->sprite.getPosition().x,
            this->sprite.getPosition().y
        );
        // 計算向量的x和y分量
        float angleRad = angle * M_PI / 180;
        float velocityX = std::cos(angleRad) * cannonBall->getMaxSpeed();
        float velocityY = std::sin(angleRad) * cannonBall->getMaxSpeed();

        // 設定cannonBall的當前速度
        cannonBall->setCurrentVelocity(sf::Vector2f(velocityX, velocityY));

        // 第一顆子彈
        cannonBall->setOrigin(
            200,
            -1000
        );
        this->cannonBalls.push_back(cannonBall);
        this->fireSound.play();
    }
}

void BetaCannon::setFiringAngle(float angle) {
    this->firingAngle = angle;
}