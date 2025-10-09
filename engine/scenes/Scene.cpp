#include "scenes/Scene.h"
#include "nodes/VisualNode.h"

using namespace Abstract2D;

void Scene::AddNode(std::shared_ptr<AbstractNode> node) {
    m_nodes.push_back(std::move(node));
}

void Scene::Update(float deltaTime) {
    for (auto& node : m_nodes)
        node->Update(deltaTime);
}

void Scene::Render(Renderer& renderer) {
    for (auto& node : m_nodes) {
        if (auto visual = std::dynamic_pointer_cast<VisualNode>(node))
            visual->Render(renderer);
    }
}
