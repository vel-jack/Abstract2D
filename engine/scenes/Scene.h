#pragma once
#include <vector>
#include <memory>
#include "nodes/AbstractNode.h"
#include "graphics/Renderer.h"

namespace Abstract2D {

    class Scene {
    public:
        Scene() = default;
        ~Scene() = default;

        void AddNode(std::shared_ptr<AbstractNode> node);
        void Update(float deltaTime);
        void Render(Renderer& renderer);

    private:
        std::vector<std::shared_ptr<AbstractNode>> m_nodes;
    };

}
