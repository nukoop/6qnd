#include <iostream>

#include <System/Game.hpp>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

int main()
{
    // 初始化遊戲
    Game game;

    // 只要視窗還沒關閉就一直執行
    while (game.running()) {
        // 更新遊戲
        game.update();

        // 渲染遊戲
        game.render();
    }

    return 0;
}