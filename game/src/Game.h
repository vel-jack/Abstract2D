#pragma once

#include <memory>
#include "core/config/Engine.h"

class Game {
public:
    Game();
    ~Game();

    bool Init();
    void Run();
    void Shutdown();

private:
    Abstract2D::Engine* m_engine = nullptr;
};
