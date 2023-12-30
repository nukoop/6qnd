#include "weapon/Cannon.hpp"

void Cannon::updateMouseInput(const sf::RenderWindow &window) {
    sf::Vector2f curPos = this->sprite.getPosition();
    sf::Vector2i position = sf::Mouse::getPosition(window);

    const float PI = 3.14159265;

    float dx = curPos.x - position.x;
    float dy = curPos.y - position.y;

    float rotation = (atan2(dy, dx)) * 180 / PI;

    this->sprite.setRotation(rotation + 90);
    this->fireSprite.setRotation(rotation + 90);
    this->cannonBallTemplate->setRotation(rotation + 90);
}

Cannon::Cannon(float x, float y, CannonBall* cannonBallTemplate, float fireRate, int frameAmount, int frameMinimum, int frameDefault, bool isFaceToMouse) 
    : animation(fireRate, frameAmount, frameMinimum, frameDefault) {
    this->sprite.setPosition(x, y);
    this->fireSprite.setPosition(x, y);
    this->cannonBallTemplate = cannonBallTemplate;
    this->fireRate = fireRate;
    this->frameDefault = frameDefault;
    this->isFaceToMouse = isFaceToMouse;
}

void Cannon::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
    this->fireSprite.setPosition(x, y);
}

sf::Vector2f Cannon::getPosition() {
    return this->sprite.getPosition();
}

void Cannon::setOrigin(float x, float y) {
    this->sprite.setOrigin(x, y);
}

sf::Vector2f Cannon::getOrigin() {
    return this->sprite.getOrigin();
}

void Cannon::setIsFire(bool isFire) {
    this->isFire = isFire;
}

bool Cannon::getIsFire() {
    return this->isFire;
}

void Cannon::update(const sf::RenderWindow& window) {
    if(this->isFaceToMouse) {
        this->updateMouseInput(window);
    }
    this->animation.update(this->clock.restart().asSeconds());

    // 子彈回收
    int now = 0;
    int end = this->cannonBalls.size() - 1;
    while(now != end && end > 0) {
        if(cannonBalls[now]->getPosition().x < 0 || cannonBalls[now]->getPosition().x > std::stoi(getenv("WINDOW_WIDTH")) || cannonBalls[now]->getPosition().y < 0 || cannonBalls[now]->getPosition().y > std::stoi(getenv("WINDOW_HEIGHT"))) {
            cannonBalls.erase(cannonBalls.begin() + now);
            end--;
            now = 0;
            continue;
        }
        now++;
    }

    // 發射砲彈
    if(isFire) {
        fire(window);
    } else {
        this->texture = this->textures[this->frameDefault - 1];
        this->fireTexture = this->fireTextures[this->frameDefault - 1];
    }

    // 更新砲彈
    for(CannonBall* cannonBallPtr : this->cannonBalls){
        cannonBallPtr->update();
    }
}

void Cannon::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
    target->draw(this->fireSprite);

    // 渲染砲彈
    for(CannonBall* cannonBallPtr : this->cannonBalls){
        cannonBallPtr->render(target);
    }
}