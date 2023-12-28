#include <iostream>
#include <cmath>
#include "weapon/Cannon.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

void Cannon::updateMouseInput(const sf::RenderWindow &window) {
    sf::Vector2f curPos = this->sprite.getPosition();
    sf::Vector2i position = sf::Mouse::getPosition(window);

    const float PI = 3.14159265;

    float dx = curPos.x - position.x;
    float dy = curPos.y - position.y;

    float rotation = (atan2(dy, dx)) * 180 / PI;

    this->sprite.setRotation(rotation + 90);
    this->fireSprite.setRotation(rotation + 90);
    this->bullet.setRotation(rotation + 90);
}

Cannon::Cannon(float x, float y, float fireRate, std::string path, float originX, float originY, std::string firePath, std::string fireSoundPath, float fireOriginX, float fireOriginY, std::string bulletPath, float bulletMaxSpeed, float bulletScale, int imageCount, int defaultImage, int animationMinimum)
:   bullet(bulletPath),
    animation(fireRate, imageCount, animationMinimum, defaultImage) {
    // 設置大砲
    this->sprite.setPosition(x, y);
    this->fireRate = fireRate;
    this->sprite.setOrigin(originX, originY);

    // 設置砲火
    this->fireSprite.setPosition(x, y);
    if(!this->fireSoundBuffer.loadFromFile(fireSoundPath)) {
        std::cout << "[錯誤] 讀取 " << fireSoundPath << " 音訊時發生了錯誤" << std::endl;
    }
    this->fireSound.setBuffer(this->fireSoundBuffer);
    this->fireSprite.setOrigin(fireOriginX, fireOriginY);

    // 讀取所有圖片
    this->defaultImage = defaultImage;
    for(int i = 0; i < imageCount; i++) {
        sf::Texture texture;
        sf::Texture fireTexture;
        if(!texture.loadFromFile(path + std::to_string(i + 1) + ".png")) {
            std::cout << "[錯誤] 讀取 " << path << std::to_string(i + 1) << ".png 圖片時發生了錯誤" << std::endl;
        } else {
            this->textures.push_back(texture);
        }

        if(!fireTexture.loadFromFile(firePath + std::to_string(i + 1) + ".png")) {
            std::cout << "[錯誤] 讀取 " << firePath << std::to_string(i + 1) << ".png 圖片時發生了錯誤" << std::endl;
        } else {
            this->fireTextures.push_back(fireTexture);
        }
    }

    // 把大砲和砲火的圖片設置為預設圖片
    this->texture = this->textures[defaultImage - 1];
    this->sprite.setTexture(this->texture);
    this->fireTexture = this->textures[defaultImage - 1];
    this->fireSprite.setTexture(this->fireTexture);
}

Cannon::~Cannon() {

}

void Cannon::update(const sf::RenderWindow &window) {
    this->updateMouseInput(window);
    this->animation.update(this->clock.restart().asSeconds());

    // 子彈回收
    int now = 0;
    int end = this->bullets.size() - 1;
    while(now != end && end > 0) {
        if(bullets[now].getPosition().x < 0 || bullets[now].getPosition().x > WINDOW_WIDTH || bullets[now].getPosition().y < 0 || bullets[now].getPosition().y > WINDOW_HEIGHT) {
            bullets.erase(bullets.begin() + now);
            end--;
            now = 0;
            continue;
        }
        now++;
    }

    // 發射砲彈
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        this->cannonCenter = sf::Vector2f(this->sprite.getPosition().x, this->sprite.getPosition().y);
        this->mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
        this->aimDirection = this->mousePosition - this->cannonCenter;
        this->aimDirNorm = this->aimDirection / std::sqrt(this->aimDirection.x * this->aimDirection.x + this->aimDirection.y * this->aimDirection.y);

        this->texture = this->textures[this->animation.current - 1];
        this->fireTexture = this->fireTextures[this->animation.current - 1];

        if(this->bulletClock.getElapsedTime().asSeconds() > this->fireRate) {
            this->bulletClock.restart();
            this->bullet.setPosition(
                this->sprite.getPosition().x,
                this->sprite.getPosition().y
            );
            this->bullet.setCurrentVelocity(this->aimDirNorm * this->bullet.getMaxSpeed());

            // 第一顆子彈
            this->bullet.setOrigin(
                200,
                -1000
            );
            this->bullets.push_back(Bullet(this->bullet));
            
            // 第二顆子彈
            this->bullet.setOrigin(
                50,
                -1000
            );
            this->bullets.push_back(Bullet(this->bullet));
            this->fireSound.play();
        }
    } else {
        this->texture = this->textures[0];
        this->fireTexture = this->fireTextures[0];
    }

    for(size_t i = 0; i < bullets.size(); i++){
        this->bullets[i].move();
    }
}

void Cannon::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
    target->draw(this->fireSprite);

    for(size_t i = 0; i < bullets.size(); i++){
        bullets[i].render(target);
    }
}

void Cannon::setSpritePosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

void Cannon::setFireSpritePosition(float x, float y) {
    this->fireSprite.setPosition(x, y);
}