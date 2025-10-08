#pragma once
#include <memory>
#include "core/config/Engine.h"

class Game {
public:
    Game();
    ~Game();

    bool init();
    void run();

private:
    std::unique_ptr<Abstract2D::Engine> engine;
};
