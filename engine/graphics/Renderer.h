#pragma once
#include "math/Vector2.h"
#include "graphics/Color.h"
#include <iostream>

namespace Abstract2D {

    class Renderer {
    public:
        bool Init() {
            std::cout << "[Renderer] Initialized.\n";
            return true;
        }

        void BeginFrame() {
            std::cout << "[Renderer] Begin Frame.\n";
        }

        void EndFrame() {
            std::cout << "[Renderer] End Frame.\n";
        }

        void DrawCircle(const Vector2& pos, float radius, const Color& color) {
            std::cout << "[Renderer] DrawCircle at (" << pos.x << ", " << pos.y
                << "), r=" << radius
                << ", color=(" << color.r << "," << color.g << "," << color.b << ")\n";
        }
    };

}
