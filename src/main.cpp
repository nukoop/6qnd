#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>

#include <system/Game.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
using namespace sf;
/*int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");  //測試子彈用
    // 初始化遊戲
    Game game;

    //子彈測試
    Bullet b1(0.1);
    std::vector<Bullet> bullets;
    bullets.push_back(Bullet(b1));

    // 只要視窗還沒關閉就一直執行
    while (game.running()) {
        // 更新遊戲
        game.update();

        // 渲染遊戲
        game.render();

    }

    return 0;
}*/

class Bullet{
public:
    sf::CircleShape shape;
    sf::Vector2f currVelocity;
    float maxSpeed;

    Bullet(float radius = 5.f)
        : currVelocity(0.f, 0.f), maxSpeed(15.f){
            this->shape.setRadius(radius);
            this->shape.setFillColor(sf::Color::Red);
        }
};

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window", sf::Style::Default);  //測試子彈用
    window.setFramerateLimit(60);

    //player
    sf::CircleShape player(25.f);
    player.setFillColor(sf::Color::White);

    //bullet
    Bullet b1;
    std::vector<Bullet> bullets;

    bullets.push_back(Bullet(b1));

    //vector
    sf::Vector2f playerCnter;
    sf::Vector2f mousePosWindow;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }

        //update
        //vectors
        playerCnter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
        mousePosWindow = Vector2f(Mouse::getPosition(window));
        aimDir = mousePosWindow - playerCnter;
        aimDirNorm = aimDir / std::sqrt(aimDir.x * aimDir.x + aimDir.y * aimDir.y);

        std::cout<<aimDirNorm.x<<" "<<aimDirNorm.y<<std::endl;
        //player
        if(Keyboard::isKeyPressed(Keyboard::A))
            player.move(-10.f, 0.f);
        if(Keyboard::isKeyPressed(Keyboard::D))
            player.move(10.f, 0.f);
        if(Keyboard::isKeyPressed(Keyboard::W))
            player.move(0.f, -10.f);
        if(Keyboard::isKeyPressed(Keyboard::S))
            player.move(0.f, 10.f);
        
        //shooting
        if(Mouse::isButtonPressed(Mouse::Left)){
            b1.shape.setPosition(playerCnter);
            b1.currVelocity = aimDirNorm * b1.maxSpeed;

            bullets.push_back(Bullet(b1));
        }

        for(size_t i = 0; i < bullets.size(); i++){
            bullets[i].shape.move(bullets[i].currVelocity);
        }

        
        //draw
        window.clear();

        window.draw(player);

        for(size_t i = 0; i < bullets.size(); i++){
            window.draw(bullets[i].shape);
        }

        window.display();
    }
}