#pragma once

#include "core/config/Logger.h"

#include <string>

namespace Abstract2D {

	struct ProjectSettings {
		std::string Name = "A2D Game";
	};

	class Engine {
	public:
		Engine() : Engine(ProjectSettings{}) {}
		Engine(const ProjectSettings& settings);
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;

		Engine(const Engine&&) = delete;
		Engine operator = (Engine&&) = delete;

		bool Init();
		void Run();
		void Shutdown();

		static Engine& Get() { return *m_Engine; }

	private:
		static Engine* m_Engine;
		bool m_Running = false;

		ProjectSettings m_ProjectSettings;

	};

}
