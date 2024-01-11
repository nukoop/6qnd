#include <iostream>
#include <cstdlib>
#include <system/Game.hpp>
#include "GUI/MainMenu.hpp"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

int main()
{
    // 設置環境變數
    char widthEnv[] = "WINDOW_WIDTH=800";
    char heightEnv[] = "WINDOW_HEIGHT=800";
    putenv(widthEnv);
    putenv(heightEnv);

    // 初始化遊戲
    Game game;

    bool inMainMenu = true;
    MainMenu mainMenu(WINDOW_WIDTH, WINDOW_HEIGHT);
    // 只要視窗還沒關閉就一直執行
    while (game.running()) {
        
        if (inMainMenu) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                mainMenu.MoveUp();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                mainMenu.MoveDown();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                int selection = mainMenu.MainMenuPressed();
                // 根據選擇的項目執行相應的操作
                if (selection == 0) {
                    // 開始遊戲
                    inMainMenu = false;
                    game.start();
                }
                else if (selection == 1) {
                    // 顯示遊戲選項
                }
                else if (selection == 2) {
                    // 顯示關於遊戲的資訊
                }
                else if (selection == 3) {
                    // 退出遊戲
                    game.quit();
                }
            }
            // 渲染主選單
            sf::RenderWindow* window = game.getWindow();
            mainMenu.render(*window);
            window->display();
        }
        else {
            // 更新遊戲
            game.update();

            // 渲染遊戲
            game.render();
        }
    }

    return 0;
}