#include <iostream>
#include <cstdlib>
#include <system/Game.hpp>

int main()
{
    // 設置環境變數
    setenv("WINDOW_WIDTH", "800", 1);
    setenv("WINDOW_HEIGHT", "800", 1);
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