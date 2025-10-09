#pragma once

#include <memory>
#include "core/config/Engine.h"

class Game {
public:
    Game();
    ~Game();

    bool Init();
    void Run();

private:
    Abstract2D::Engine* m_engine = nullptr;
};
