#include "system/Game.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

Game::Game() {
    this->window = nullptr;
    this->player = new Boat(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    this->videoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
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

void Game::update() {
    this->pollEvent();
    this->player->update(*(this->window));
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
    background.setTextureRect(sf::IntRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
    this->window->draw(background);

    this->player->render(this->window);

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