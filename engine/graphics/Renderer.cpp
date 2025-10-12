#include "core/Logger.h"
#include "graphics/Renderer.h"

#include <iostream>
#include <chrono>

using namespace Abstract2D;

bool Renderer::Init(int width, int height) {
    m_width = width;
    m_height = height;

    // Background color
    //color(srgb 0.97 0.95 0.94)
    glClearColor(0.97f, 0.95f, 0.94f, 1.0f);

    // Set viewport and orthographic projection
    glViewport(0, 0, m_width, m_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set origin at top-left (y increases downward)
    glOrtho(0, m_width, m_height, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    return true;
}

void Renderer::BeginFrame() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
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
    // todo: delete buf, vert, program..
    // delete vao, vbo, framebuffer
    glFinish();
    DEBUG_INFO("Renderer Shutdown complete..");
}

void Renderer::DrawCircle(const Vector2& pos, float radius, const Color& color) {
    const int segments = 64;
    const float PI = 3.1415926f;

    glColor4f(color.r, color.g, color.b, color.a);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(pos.x, pos.y);

    for (int i = 0; i <= segments; ++i) {
        float angle = i * 2.0f * PI / segments;
        float x = pos.x + radius * std::cos(angle);
        float y = pos.y + radius * std::sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}
