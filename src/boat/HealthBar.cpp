#include "boat/HealthBar.hpp"

HealthBar::HealthBar(){
    this->health.setSize(sf::Vector2f(100, 10));
    this->health.setFillColor(sf::Color::Red);
    this->health.setOutlineColor(sf::Color::White);
    this->health.setOutlineThickness(1);
}

HealthBar::~HealthBar(){}

sf::RectangleShape& HealthBar::getHealth(){
    return this->health;
}