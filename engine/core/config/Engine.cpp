#include "Engine.h"

using namespace Abstract2D;

Engine* Engine::m_Engine = nullptr;

Engine::Engine(const ProjectSettings& settings) : m_ProjectSettings{ settings }
{
	m_Engine = this;
}

bool Engine::Init() {

	Logger::Init(m_ProjectSettings.Name);
	DEBUG_INFO("[Engine] Initializing...");
	m_Running = true;
	return true;
}

void Engine::Run() {
	DEBUG_INFO("[Engine] Running main loop...");
	while (m_Running) {
	}
}

void Engine::Shutdown() {
	DEBUG_INFO("[Engine] Shutting down...");
	m_Running = false;
}