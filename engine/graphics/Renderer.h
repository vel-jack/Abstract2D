#pragma once

#include <Windows.h>
#include <vector>
#include <cmath>
#include "math/Vector2.h"
#include "graphics/Color.h"

namespace Abstract2D {

    class Renderer {
    public:
        bool Init(int width, int height);
        void BeginFrame();
        void EndFrame();
        void Shutdown();
        void DrawCircle(const Vector2& pos, float radius, const Color& color);

    private:
        int m_width = 800;
        int m_height = 600;
    };

}
