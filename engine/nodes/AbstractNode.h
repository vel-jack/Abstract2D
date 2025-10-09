#pragma once

#include "math/Vector2.h"

namespace Abstract2D {

	class AbstractNode {
	public:
		virtual ~AbstractNode() = default;

		virtual void Update(float deltaTime) {}

		struct Transform {
			Vector2 position;
		} transform;
	};

}