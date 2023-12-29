#include <iostream>
#include "weapon/Cannon.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <cmath>

// 面對滑鼠
void Cannon::updateMouseInput(const sf::RenderWindow &window) {
    sf::Vector2f curPos = this->sprite.getPosition();
    sf::Vector2i position = sf::Mouse::getPosition(window);

    const float PI = 3.14159265;

    float dx = curPos.x - position.x;
    float dy = curPos.y - position.y;

    float rotation = (atan2(dy, dx)) * 180 / PI;

    this->sprite.setRotation(rotation + 90);
    this->fireSprite.setRotation(rotation + 90);
    this->bullet.sprite.setRotation(rotation + 90);
}

Cannon::Cannon(float x, float y, int imageCount, int defaultImage) {
    // 設置大砲圖片位置
    this->path = "data/image/Cannon2_color1/Cannon2_color1_";

    // 設置砲火圖片位置
    this->firePath = "data/image/Fire1/Fire1_";

    // 設置預設圖片
    this->defaultImage = defaultImage;

    // 讀取所有圖片
    for(int i = 0; i < imageCount; i++) {
        sf::Texture texture;
        sf::Texture fireTexture;
        if(!texture.loadFromFile(this->path + std::to_string(i + 1) + ".png")) {
            std::cout << "[錯誤] 讀取 " << this->path << std::to_string(i + 1) << ".png 圖片時發生了錯誤" << std::endl;
        } else {
            this->textures.push_back(texture);
        }

        if(!fireTexture.loadFromFile(this->firePath + std::to_string(i + 1) + ".png")) {
            std::cout << "[錯誤] 讀取 " << this->firePath << std::to_string(i + 1) << ".png 圖片時發生了錯誤" << std::endl;
        } else {
            this->fireTextures.push_back(fireTexture);
        }
    }

    // 把圖片設置為預設圖片
    this->texture = this->textures[defaultImage - 1];
    this->sprite.setTexture(this->texture);
    this->fireTexture = this->textures[defaultImage - 1];
    this->fireSprite.setTexture(this->fireTexture);

    // 設定 Sprite 中心點
    this->sprite.setOrigin(
        66,
        44
    );
    this->fireSprite.setOrigin(
        34,
        -36
    );

    // 設置 Sprite 位置
    this->sprite.setPosition(x, y);
    this->fireSprite.setPosition(x, y);

    // 設置動畫
    this->animation = new Animation(0.1f, imageCount, 2, defaultImage);

    // 把開火中設為否
    this->fire = false;

    // 設置射速
    this->fireRate = 0.1f;

    // 設置開火音效
    this->fireSoundBuffer.loadFromFile("data/sound/cannon1.wav");
    this->fireSound.setBuffer(this->fireSoundBuffer);
}

Cannon::~Cannon() {
    
}

void Cannon::update(const sf::RenderWindow &window) {
    sf::Vector2f playerCenter = sf::Vector2f(this->sprite.getPosition().x, this->sprite.getPosition().y);
    this->mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
    this->aimDir = this->mousePosWindow - playerCenter;
    this->aimDirNorm = this->aimDir / std::sqrt(this->aimDir.x * this->aimDir.x + this->aimDir.y * this->aimDir.y);

    this->updateMouseInput(window);
    this->animation->update(this->clock.restart().asSeconds());
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        fire = true;
        this->texture = this->textures[this->animation->current - 1];
        this->fireTexture = this->fireTextures[this->animation->current - 1];

        if(bulletClock.getElapsedTime().asSeconds() > fireRate) {
            bulletClock.restart();

            this->bullet.sprite.setPosition(
                this->sprite.getPosition().x,
                this->sprite.getPosition().y
            );
            this->bullet.currVelocity = this->aimDirNorm * this->bullet.maxSpeed;

            // 第一顆子彈
            this->bullet.sprite.setOrigin(
                200,
                -1000
            );
            this->bullets.push_back(Bullet(this->bullet));
            
            // 第二顆子彈
            this->bullet.sprite.setOrigin(
                50,
                -1000
            );
            this->bullets.push_back(Bullet(this->bullet));

            this->fireSound.play();
        }
    } else {
        fire = false;
        this->texture = this->textures[0];
        this->fireTexture = this->fireTextures[0];
    }

    for(size_t i = 0; i < bullets.size(); i++){
        this->bullets[i].sprite.move(this->bullets[i].currVelocity);
    }
}

void Cannon::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
    target->draw(this->fireSprite);

    for(size_t i = 0; i < bullets.size(); i++){
        target->draw(bullets[i].sprite);
    }
}

void Cannon::setSpritePosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

void Cannon::setFireSpritePosition(float x, float y) {
    this->fireSprite.setPosition(x, y);
}