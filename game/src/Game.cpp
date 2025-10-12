#include "Game.h"
#include "core/Logger.h"
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

    // Create a root node to act as the scene root
    std::unique_ptr<Node> rootNode = std::make_unique<Node>(nullptr);
    rootNode->UpdateName("RootNode");

    // Create circle nodes with unique_ptr and add as children
    auto c1 = std::make_unique<CircleNode>(rootNode.get());
    c1->GetTransform()->position = { 10.0f, 20.0f };
    c1->radius = 20.0f;
    c1->color = { 0.93f, 0.38f, 0.46f, 1.0f };
    rootNode->AddChildNode(std::move(c1));

    auto c2 = std::make_unique<CircleNode>(rootNode.get());
    c2->GetTransform()->position = { 10.0f + 80, 20.0f };
    c2->radius = 20.0f;
    c2->color = { 0.93f, 0.38f, 0.46f, 1.0f };
    rootNode->AddChildNode(std::move(c2));

    auto c3 = std::make_unique<CircleNode>(rootNode.get());
    c3->GetTransform()->position = { 10.0f, 20.0f + 80 };
    c3->radius = 20.0f;
    c3->color = { 0.42f, 0.53f, 0.75f, 1.0f };
    rootNode->AddChildNode(std::move(c3));

    auto c4 = std::make_unique<CircleNode>(rootNode.get());
    c4->GetTransform()->position = { 10.0f + 80, 20.0f + 80 };
    c4->radius = 20.0f;
    c4->color = { 0.42f, 0.53f, 0.75f, 1.0f };
    rootNode->AddChildNode(std::move(c4));

    // Pass ownership of rootNode to engine as active scene node
    m_engine->SetActiveScene(std::move(rootNode));

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

void Game::Shutdown()
{
    m_engine->Shutdown();
}
