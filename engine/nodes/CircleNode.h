#pragma once
#include "nodes/Node.h"

namespace Abstract2D {

	class CircleNode : public Node {
	public:
		CircleNode(Node* parent = nullptr) : Node(parent) {
			UpdateName("Circle_");
		}
		float radius = 1.0f;
		Color color{ 1.0f, 0.0f, 1.0f, 1.0f };
		void Render(Renderer& renderer) override {
			renderer.DrawCircle(GetTransform()->position, radius, color);
		}
	};

}
