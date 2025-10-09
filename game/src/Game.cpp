#include "Game.h"
#include "core/config/Logger.h"
#include "nodes/CircleNode.h"

using namespace Abstract2D;

Game::Game() = default;
Game::~Game() = default;

bool Game::Init() {
    ProjectSettings settings{ "My Game" };

    m_engine = &Engine::GetInstance();
    m_engine->SetProjectSettings(settings);

    if (!m_engine->Init()) {
        DEBUG_ERROR("Engine initialization failed!");
        return false;
    }
    auto scene = std::make_shared<Scene>();
    auto redDot = std::make_shared<CircleNode>();
    redDot->transform.position = { 0.0f, 0.0f };
    redDot->radius = 0.25f;

    scene->AddNode(redDot);
    m_engine->SetActiveScene(scene);

    DEBUG_INFO("Game initialized successfully.");
    return true;
}

void Game::Run() {
    if (!m_engine) {
        DEBUG_ERROR("Engine not initialized!");
        return;
    }
    m_engine->Run();
}
