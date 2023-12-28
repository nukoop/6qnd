#ifndef CANNON_HPP
#define CANNON_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "system/Animation.hpp"
#include "weapon/Bullet.hpp"

class Cannon {
private:
    // 大砲
    sf::Texture texture;
    std::vector<sf::Texture> textures;
    sf::Sprite sprite;
    float fireRate;
    sf::Vector2f cannonCenter;
    sf::Vector2f mousePosition;
    sf::Vector2f aimDirection;
    sf::Vector2f aimDirNorm;

    // 砲火
    sf::Texture fireTexture;
    std::vector<sf::Texture> fireTextures;
    sf::Sprite fireSprite;
    sf::SoundBuffer fireSoundBuffer;
    sf::Sound fireSound;
    // 砲彈
    Bullet bullet;
    std::vector<Bullet> bullets;
    sf::Clock bulletClock;

    // 大砲和砲火的動畫（同步）
    Animation animation;
    sf::Clock clock;
    int defaultImage;

    void updateMouseInput(const sf::RenderWindow &window);
public:
    Cannon(float x, float y, float fireRate, std::string path, float originX, float originY, std::string firePath, std::string fireSoundPath, float fireOriginX, float fireOriginY, std::string bulletPath, float bulletMaxSpeed, float bulletScale, int imageCount, int defaultImage, int animationMinimum);
    ~Cannon();
    void update(const sf::RenderWindow &window);
    void render(sf::RenderTarget* target);
    void setSpritePosition(float x, float y);
    void setFireSpritePosition(float x, float y);
};

#endif