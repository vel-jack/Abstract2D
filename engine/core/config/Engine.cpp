#include "core/config/Engine.h"

#include <chrono>
#include <thread>

using namespace Abstract2D;

bool Engine::Init() {

    Logger::Init(m_settings.name);
    DEBUG_INFO("Engine initializing...");

    DEBUG_INFO("Project Name: {}", m_settings.name);
    DEBUG_INFO("Resolution: {}x{}", m_settings.width, m_settings.height);
    DEBUG_INFO("VSync: {}", m_settings.vsync ? "Enabled" : "Disabled");

    m_renderer = std::make_unique<Renderer>();
    if (!m_renderer->Init()) {
        DEBUG_ERROR("Renderer failed to initialize.");
        return false;
    }

    // Initialize core systems (placeholder)
    // TODO: Window::Init(), Input::Init()

    m_isRunning = true;
    DEBUG_INFO("Engine initialized successfully.");
    return true;
}

void Engine::Run() {
    DEBUG_INFO("Engine main loop started.");

    using clock = std::chrono::high_resolution_clock;
    auto lastTime = clock::now();

    while (m_isRunning) {
        auto now = clock::now();
        std::chrono::duration<float> elapsed = now - lastTime;
        float deltaTime = elapsed.count();
        lastTime = now;

        if (m_activeScene)
            m_activeScene->Update(deltaTime);

        // Render Scene
        m_renderer->BeginFrame();
        if (m_activeScene)
            m_activeScene->Render(*m_renderer);
        m_renderer->EndFrame();

        std::this_thread::sleep_for(std::chrono::milliseconds(16));

        // Temporary quit condition (for debug)
        static int frameCount = 0;
        if (++frameCount > 300) { // Run ~5 seconds
            Shutdown();
        }
    }
}

void Engine::Shutdown() {
    DEBUG_INFO("Shutting down engine...");
    m_isRunning = false;

    // TODO: Cleanup renderer, window, etc.
    DEBUG_INFO("Engine shutdown complete.");
}

void Engine::SetProjectSettings(const ProjectSettings& settings) {
    m_settings = settings;
}
