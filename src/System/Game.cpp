#include "system/Game.hpp"

Game::Game()
    : alphaCannon(0, 0, &simpleCannonBall, 0.1f, true),
      player(std::stoi(getenv("WINDOW_WIDTH")) / 2, std::stoi(getenv("WINDOW_HEIGHT")) / 2, 2.f, &alphaCannon, &simpleCannonBall),
      enemy(std::stoi(getenv("WINDOW_WIDTH")) / 2, std::stoi(getenv("WINDOW_HEIGHT")) / 2, 2.f, &alphaCannon, &simpleCannonBall) 
{  //test
    this->window = nullptr;

    this->videoMode = sf::VideoMode(std::stoi(getenv("WINDOW_WIDTH")), std::stoi(getenv("WINDOW_HEIGHT")));
    this->window = new sf::RenderWindow(videoMode, "6qnd", sf::Style::Default);
    this->window->setFramerateLimit(60);
}

Game::~Game() {
    delete this->window;
}

const bool Game::running() const {
    return this->window->isOpen();
}

void Game::pollEvent() {
    while (this->window->pollEvent(this->event)) {
        if(this->event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->window->close();
        }
    }
}

void Game::updateInput() {

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        this->player.setIsFire(true);
        // 計算發射角度
        sf::Vector2f cannonCenter = sf::Vector2f(this->alphaCannon.getPosition().x, this->alphaCannon.getPosition().y);
        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*this->window));
        sf::Vector2f localMousePosition = mousePosition - cannonCenter;

        float angle = std::atan2(localMousePosition.y, localMousePosition.x) * 180 / M_PI;

        // 在 AlphaCannon 中設置發射角度
        this->alphaCannon.setFiringAngle(angle);
    } else {
        this->player.setIsFire(false);
    }
    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->player.getPosition().x > (0.f + std::max(this->player.getGlobalBounds().width, this->player.getGlobalBounds().height) / 2)) {
        this->player.forward();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->player.getPosition().x < (std::stoi(getenv("WINDOW_WIDTH")) - std::max(this->player.getGlobalBounds().width, this->player.getGlobalBounds().height) / 2)) {
        this->player.backward();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->player.getPosition().y > (0.f + std::max(this->player.getGlobalBounds().width, this->player.getGlobalBounds().height) / 2)) {
        this->player.upward();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->player.getPosition().y < (std::stoi(getenv("WINDOW_HEIGHT")) - std::max(this->player.getGlobalBounds().width, this->player.getGlobalBounds().height) / 2)) {
        this->player.downward();
    }
}

void Game::update() {
    this->pollEvent();
    this->updateInput();
    this->player.update(*(this->window));
    this->enemy.update(*(this->window));
}

void Game::render() {
    this->window->clear();

    // 設定背景
    sf::Texture texture;
    texture.setRepeated(true);
    if(!texture.loadFromFile("data/image/Tileset/tile_0084_water11.png")) {
        std::cout << "[錯誤] 讀取 data/image/Tileset/tile_0084_water11.png 圖片時發生了錯誤" << std::endl;
    }
    sf::Sprite background(texture);
    background.setTextureRect(sf::IntRect(0, 0, std::stoi(getenv("WINDOW_WIDTH")), std::stoi(getenv("WINDOW_HEIGHT"))));
    this->window->draw(background);

    this->player.render(this->window);
    
   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
        this->renderEnemy = false;
    }
    if(this->renderEnemy==true){
        this->enemy.render(this->window);
    }

    this->window->display();
}


//GUI test
void Game::quit() {
    // 做一些清理工作或其他必要的操作
    window->close();
}

sf::RenderWindow* Game::getWindow() {
    return window;
}

void Game::start() {
    // 執行遊戲開始的相關邏輯
    // 例如初始化遊戲狀態、載入資源等

    // 開始遊戲的主迴圈
    while (running()) {
        // 更新遊戲邏輯
        update();

        // 渲染遊戲畫面
        render();
    }
}