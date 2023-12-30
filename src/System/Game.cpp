#include "system/Game.hpp"

Game::Game()
    : alphaCannon(0, 0, &simpleCannonBall, 0.1f, true),
      player(std::stoi(getenv("WINDOW_WIDTH")) / 2, std::stoi(getenv("WINDOW_HEIGHT")) / 2, 2.f, &alphaCannon, &simpleCannonBall) {
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

    this->window->display();
}