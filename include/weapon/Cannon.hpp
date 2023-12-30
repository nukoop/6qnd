#ifndef CANNON_HPP
#define CANNON_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "system/Animation.hpp"
#include "weapon/CannonBall.hpp"

class Cannon {
protected:
    // 大砲
    sf::Texture texture;
    std::vector<sf::Texture> textures;
    sf::Sprite sprite;
    float fireRate;

    // 砲火
    sf::Texture fireTexture;
    std::vector<sf::Texture> fireTextures;
    sf::Sprite fireSprite;
    sf::SoundBuffer fireSoundBuffer;
    sf::Sound fireSound;
    // 砲彈
    CannonBall* cannonBallTemplate;
    std::vector<CannonBall*> cannonBalls;
    sf::Clock cannonBallClock;

    // 大砲和砲火的動畫（同步）
    Animation animation;
    int frameDefault;
    sf::Clock clock;

    // 控制相關
    bool isFire;
    bool isFaceToMouse;

    void updateMouseInput(const sf::RenderWindow &window);
    virtual void fire(const sf::RenderWindow& window) = 0;
public:
    // Cannon(float x, float y, float fireRate, std::string path, float originX, float originY, std::string firePath, std::string fireSoundPath, float fireOriginX, float fireOriginY, std::string bulletPath, float bulletMaxSpeed, float bulletScale, int imageCount, int defaultImage, int animationMinimum);
    Cannon(float x, float y, CannonBall* cannonBallTemplate, float fireRate, int frameAmount, int frameMinimum, int frameDefault, bool isFaceToMouse = false);
    virtual ~Cannon() {}
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    void setOrigin(float x, float y);
    sf::Vector2f getOrigin();
    void setIsFire(bool isFire);
    bool getIsFire();
    // void setFireSpritePosition(float x, float y);
    // sf::Vector2f getFireSpritePosition();
    void update(const sf::RenderWindow& window);
    void render(sf::RenderTarget* target);
};

#endif