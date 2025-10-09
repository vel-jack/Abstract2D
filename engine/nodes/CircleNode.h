#pragma once
#include "nodes/VisualNode.h"

namespace Abstract2D {

    class CircleNode : public VisualNode {
    public:
        float radius = 0.1f;
        Color color{ 1.0f, 0.0f, 0.0f, 1.0f };

        void Render(Renderer& renderer) override {
            renderer.DrawCircle(transform.position, radius, color);
        }
    };

}
