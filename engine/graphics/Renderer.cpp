#include "core/Logger.h"
#include "graphics/Renderer.h"

#include <iostream>
#include <chrono>

using namespace Abstract2D;

bool Renderer::Init(int width, int height) {
    m_width = width;
    m_height = height;

    return true;
}

void Renderer::BeginFrame() {

}

void Renderer::EndFrame() {
    // --- FPS counter ---
    static int frameCount = 0;
    static auto lastTime = std::chrono::high_resolution_clock::now();

    frameCount++;

    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = now - lastTime;

    if (elapsed.count() >= 1.0f) { // once per second
        float fps = frameCount / elapsed.count();
        std::cout << "[Renderer] FPS: " << fps << "\n";
        frameCount = 0;
        lastTime = now;
    }
}

void Abstract2D::Renderer::Shutdown()
{

    DEBUG_INFO("Renderer Shutdown complete..");
}

void Renderer::DrawCircle(const Vector2& pos, float radius, const Color& color) {
}
