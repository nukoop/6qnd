#include <iostream>
#include "GUI/main_menu.hpp"

MainMenu::MainMenu(float width, float height){
    if(!font.loadFromFile("data/AlexandriaFLF.ttf")){
        std::cout << "無法載入字型檔案" << std::endl;
    }

    //Play
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(sf::Color::White);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(70);
    mainMenu[0].setPosition(400, 200);

    //Options
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(sf::Color::White);
    mainMenu[1].setString("Options");
    mainMenu[1].setCharacterSize(70);
    mainMenu[1].setPosition(400, 300);

    //About
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(sf::Color::White);
    mainMenu[2].setString("About");
    mainMenu[2].setCharacterSize(70);
    mainMenu[2].setPosition(400, 400);

    //Exit
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(sf::Color::White);
    mainMenu[3].setString("Exit");
    mainMenu[3].setCharacterSize(70);
    mainMenu[3].setPosition(400, 500);

    MainMenuSelected = 0;
}

MainMenu::~MainMenu(){

}

void MainMenu::render(sf::RenderWindow& window){
    for(int i=0; i<Max_main_menu; i++){
        window.draw(mainMenu[i]);  //render
    }
}

void MainMenu::MoveUp(){
    if(MainMenuSelected - 1 >= 0){
        mainMenu[MainMenuSelected].setFillColor(sf::Color::White);

        MainMenuSelected--;
        if(MainMenuSelected == -1){
            MainMenuSelected = Max_main_menu - 1;
        }
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
    }
}

void MainMenu::MoveDown(){
    if(MainMenuSelected + 1 < Max_main_menu){
        mainMenu[MainMenuSelected].setFillColor(sf::Color::White);

        MainMenuSelected++;
        if(MainMenuSelected == Max_main_menu){
            MainMenuSelected = 0;
        }
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
    }
}

int MainMenu::MainMenuPressed(){
    return MainMenuSelected;
}