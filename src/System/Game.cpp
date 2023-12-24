#include "System/Game.hpp"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

void Game::initVariables() {
    this->window = nullptr;
}

void Game::initWindow() {
    this->videoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->window = new sf::RenderWindow(videoMode, "6qnd", sf::Style::Default);
    this->window->setFramerateLimit(60);
}

Game::Game() {
    this->initVariables();
    this->initWindow();
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
    this->player.update(this->window);
}

void Game::render() {
    this->window->clear(sf::Color::Black);

    this->player.render(this->window);

    this->window->display();
}