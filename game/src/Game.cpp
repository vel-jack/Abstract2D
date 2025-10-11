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
	auto scene = std::make_shared<Scene>();
	auto redDot = std::make_shared<CircleNode>();
	redDot->transform.position = { 400.0f, 300.0f }; // middle of window
	redDot->radius = 20.0f; // 50 pixels radius
	redDot->color = { 0.93f, 0.38f, 0.46f, 1.0f }; // 50 pixels radius
	scene->AddNode(redDot);

	auto redDot2 = std::make_shared<CircleNode>();
	redDot2->transform.position = { 400.0f+80, 300.0f }; // middle of window
	redDot2->radius = 20.0f; // 50 pixels radius
	redDot2->color = { 0.93f, 0.38f, 0.46f, 1.0f }; // 50 pixels radius
	scene->AddNode(redDot2);
	
	auto redDot3 = std::make_shared<CircleNode>();
	redDot3->transform.position = { 400.0f, 300.0f+80 }; // middle of window
	redDot3->radius = 20.0f; // 50 pixels radius
	redDot3->color = { 0.42f, 0.53f, 0.75f,1.0f }; // 50 pixels radius
	scene->AddNode(redDot3);
	
	auto redDot4 = std::make_shared<CircleNode>();
	redDot4->transform.position = { 400.0f+80, 300.0f+80 }; // middle of window
	redDot4->radius = 20.0f;
	redDot4->color = { 0.42f, 0.53f, 0.75f,1.0f }; // 50 pixels radius
	scene->AddNode(redDot4);

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
