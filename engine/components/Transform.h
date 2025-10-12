#pragma once

#include "components/Component.h"
#include "math/Vector2.h"

namespace Abstract2D {
	class Transform : public Component {
	public:
		Vector2 position{0,0};
	};
}
