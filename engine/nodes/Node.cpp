#include "nodes/Node.h"
#include "components/Component.h"

#include <algorithm>

using namespace Abstract2D;

int32_t Node::idCounter = 0;

Node::Node(Node* parent) :
	m_parent(parent),
	m_uniqueId(idCounter++),
	m_transform(std::make_unique<Transform>()) {
	if (m_transform) {
		m_transform->SetParent(*this);
	}
}


Node::Node(Node* parent, std::unique_ptr<Transform> t)
	: m_parent(parent), m_transform(std::move(t)), m_uniqueId(idCounter++) {
	if (m_transform) {
		m_transform->SetParent(*this);
	}
}

void Node::AddChildNode(std::unique_ptr<Node> child) {
	if (child) {
		child->m_parent = this; // assign parent pointer
		m_childNodes.push_back(std::move(child));
	}
}

std::unique_ptr<Node> Node::RemoveChildNode(Node* childNodeToRemove) {
	for (auto it = m_childNodes.begin(); it != m_childNodes.end(); ++it) {
		if (it->get() == childNodeToRemove) {
			std::unique_ptr<Node> removedNode = std::move(*it);
			m_childNodes.erase(it);
			removedNode->m_parent = nullptr;
			return removedNode;
		}
	}
	return nullptr;
}

std::unique_ptr<Node> Node::RemoveChildNode(int32_t childNodeIdToRemove) {
	for (auto it = m_childNodes.begin(); it != m_childNodes.end(); ++it) {
		if ((*it)->m_uniqueId == childNodeIdToRemove) {
			std::unique_ptr<Node> removedNode = std::move(*it);
			m_childNodes.erase(it);
			removedNode->m_parent = nullptr;
			return removedNode;
		}
	}
	return nullptr;
}

void Node::UpdateParentNode(Node* newParent) {
	if (!m_parent || !newParent || m_parent == newParent)
		return;

	std::unique_ptr<Node> thisNode = m_parent->RemoveChildNode(this);
	if (!thisNode) return;

	thisNode->m_parent = newParent;

	newParent->AddChildNode(std::move(thisNode));
}

void Abstract2D::Node::UpdateName(const std::string& name)
{
	m_name = name;
}

void Node::AddComponent(std::unique_ptr<Component> component) {
	if (component) {
		component->SetParent(*this);
		m_components.push_back(std::move(component));
	}
}

void Node::Update(float deltaTime) {
	for (auto& component : m_components)
		component->Update(deltaTime);

	for (auto& child : m_childNodes)
		child->Update(deltaTime);
}

void Node::Render(Renderer& renderer) {
	for (auto& child : m_childNodes)
		child->Render(renderer);
}

std::ostream& Abstract2D::operator<<(std::ostream& os, const Node& node)
{
	os << node.m_name << node.m_uniqueId;
	return os;
}
