#include "weapon/DeltaCannon.hpp"

DeltaCannon::DeltaCannon(float x, float y, CannonBall* cannonBallTemplate, float fireRate, bool isFaceToMouse) 
    : Cannon(x, y, cannonBallTemplate, fireRate, 4, 2, 1, isFaceToMouse) {

    // 設置開炮火光中心點
    this->fireSprite.setOrigin(60, -68);
    
    // 讀取所有圖片
    for(int i = 0; i < 4; i++) {
        sf::Texture texture;
        sf::Texture fireTexture;
        if(!texture.loadFromFile("data/image/Cannon1_color3/Cannon1_color3_" + std::to_string(i + 1) + ".png")) {
            std::cout << "[錯誤] 讀取 " << "data/image/Cannon1_color3/Cannon1_color3_" << std::to_string(i + 1) << ".png 圖片時發生了錯誤" << std::endl;
        } else {
            this->textures.push_back(texture);
        }

        if(!fireTexture.loadFromFile("data/image/Fire4/Fire4_" + std::to_string(i + 1) + ".png")) {
            std::cout << "[錯誤] 讀取 " << "data/image/Fire4/Fire4_" << std::to_string(i + 1) << ".png 圖片時發生了錯誤" << std::endl;
        } else {
            this->fireTextures.push_back(fireTexture);
        }
    }

    // 讀取大砲音效
    if(!this->fireSoundBuffer.loadFromFile("data/sound/cannon1.wav")) {
        std::cout << "[錯誤] 讀取 data/sound/cannon3.wav 音訊時發生了錯誤" << std::endl;
    }
    this->fireSound.setBuffer(this->fireSoundBuffer);

    // 把大砲和砲火的圖片設置為預設圖片
    this->texture = this->textures[frameDefault - 1];
    this->sprite.setTexture(this->texture);
    this->fireTexture = this->textures[frameDefault - 1];
    this->fireSprite.setTexture(this->fireTexture);
}

DeltaCannon::~DeltaCannon() {

}

void DeltaCannon::fire(const sf::RenderWindow& window) {
    CannonBall* cannonBall = new CannonBall(*cannonBallTemplate);

    sf::Vector2f cannonCenter = sf::Vector2f(this->sprite.getPosition().x, this->sprite.getPosition().y);
    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
    sf::Vector2f aimDirection = mousePosition - cannonCenter;
    sf::Vector2f aimDirNorm = aimDirection / std::sqrt(aimDirection.x * aimDirection.x + aimDirection.y * aimDirection.y);

    this->texture = this->textures[this->animation.current - 1];
    this->fireTexture = this->fireTextures[this->animation.current - 1];

    if(this->cannonBallClock.getElapsedTime().asSeconds() > this->fireRate) {
        this->cannonBallClock.restart();
        cannonBall->setPosition(
            this->sprite.getPosition().x,
            this->sprite.getPosition().y
        );
        cannonBall->setCurrentVelocity(aimDirNorm * cannonBall->getMaxSpeed());

        cannonBall->setOrigin( //設置子彈出現點
            100,
            -2300
        );
        this->cannonBalls.push_back(cannonBall);
        this->fireSound.play();
    }
}