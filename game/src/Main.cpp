#include "Game.h"

int main() {
    Game game;

    if (!game.Init()) {
        return -1;
    }

    game.Run();

    game.Shutdown();
    return 0;
}
