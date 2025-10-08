#include "Game.h"

using namespace Abstract2D;

Game::Game() = default;
Game::~Game() = default;

bool Game::init() {
    Abstract2D::ProjectSettings settings;
    settings.Name = "My Game"; // Optional: customize the name
    engine = std::make_unique<Engine>(settings);

    if (!engine->Init())
        return false;
    return true;
}

void Game::run() {
    engine->Run();
}
