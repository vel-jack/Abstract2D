#pragma once

namespace Abstract2D {
	class Node;

	class Component {
	public:
		virtual ~Component() = default;

		virtual void Update(float deltaTime) {}

		Node* GetParentNode() const { return m_parent; }
		void SetParent(Node& node) { m_parent = &node; }

	protected:
		Node* m_parent = nullptr;
	};
}
