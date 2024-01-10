#pragma once
#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

#define Max_main_menu 4
class MainMenu{
public:
    MainMenu(float width, float height);
    ~MainMenu();

    void render(RenderWindow& window);
    void MoveUp();
    void MoveDown();

    int MainMenuPressed();
private:
    int MainMenuSelected;
    Font font;
    Text mainMenu[Max_main_menu];
};

#endif