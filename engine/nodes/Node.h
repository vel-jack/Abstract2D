#pragma once

#include "components/Transform.h"
#include "graphics/Renderer.h"

#include <vector>
#include <memory>
#include <ostream>

namespace Abstract2D {

	class Component;

	class Node {
	public:
		explicit Node(Node* parent = nullptr);
		Node(Node* parent, std::unique_ptr<Transform> transform);
		virtual ~Node() = default;

		virtual void Update(float deltaTime);
		virtual void Render(Renderer& renderer);

		void AddChildNode(std::unique_ptr<Node> child);
		std::unique_ptr<Node> RemoveChildNode(Node* childNodeToRemove);
		std::unique_ptr<Node> RemoveChildNode(int32_t childNodeIdToRemove);
		void AddComponent(std::unique_ptr<Component> component);

		void UpdateParentNode(Node* newParent);

		Node* GetParentNode() const { return m_parent; }
		Transform* GetTransform() const { return m_transform.get(); }
		int32_t GetUniqueId() const { return m_uniqueId; }

		std::string Name() const { return m_name; }
		void UpdateName(const std::string& name);

		friend std::ostream& operator<<(std::ostream& os, const Node& node);

	protected:
		std::vector<std::unique_ptr<Node>> m_childNodes;
		std::vector<std::unique_ptr<Component>> m_components;
		std::unique_ptr<Transform> m_transform;

	private:
		Node* m_parent = nullptr;
		int32_t m_uniqueId;
		std::string m_name = "Node_";

		static int32_t idCounter;
	};
}
