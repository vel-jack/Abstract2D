#pragma once

#include <memory>
#include <string>
#include "core/Logger.h"
#include "graphics/Renderer.h"
#include "core/Window.h"
#include "nodes/Node.h"

namespace Abstract2D {

	struct ProjectSettings {
		std::string name = "Abstract2D Game";
		int width = 800;
		int height = 600;
		bool vsync = true;
	};

	class Engine {
	public:
		static Engine& GetInstance() {
			static Engine instance;
			return instance;
		}

		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;

		// Life cycle
		bool Init();
		void Run();
		void Shutdown();

		// Project Settings
		void SetProjectSettings(const ProjectSettings& settings);
		const ProjectSettings& GetProjectSettings() const { return m_settings; }

		// Scene Management
		void SetActiveScene(std::unique_ptr<Node> scene) { m_activeScene = std::move(scene); }


	private:
		Engine() = default;
		~Engine() = default;

	private:
		bool m_isRunning = false;
		ProjectSettings m_settings;
		std::unique_ptr<Renderer> m_renderer;
		std::unique_ptr<Node> m_activeScene;
		std::unique_ptr<Window> m_window;

	};

} // namespace Abstract2D
