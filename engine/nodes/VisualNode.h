#pragma once

#include "nodes/AbstractNode.h"
#include "graphics/Renderer.h"
#include "graphics/Color.h"

namespace Abstract2D {

    class VisualNode : public AbstractNode {
    public:
        virtual void Render(Renderer& renderer) = 0;
    };

}