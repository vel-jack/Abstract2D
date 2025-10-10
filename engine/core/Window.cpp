#include "core/Window.h"
#include "core/Logger.h"

#ifdef PLATFORM_WINDOWS
	#include <GLFW/glfw3.h>
#endif

using namespace Abstract2D;

namespace {
	GLFWwindow* g_window = nullptr;
}

class GLFWWindow : public Window {
public:
	bool Init(const std::string& title, int width, int height, bool vsync) override {
		if (!glfwInit()) {
			DEBUG_ERROR("Failed to initialize GLFW");
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		//glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);

		g_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (!g_window) {
			DEBUG_ERROR("Failed to create window.");
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(g_window);
		glfwSwapInterval(vsync ? 1 : 0);

		DEBUG_INFO("GLFW window created with OpenGL ES 2.0 context");
		return true;
	}

	void PollEvents() override { glfwPollEvents(); }

	void SwapBuffers() override { glfwSwapBuffers(g_window); }

	bool ShouldClose() const override { return glfwWindowShouldClose(g_window); }
};

Window* Window::Create(const std::string& title, int width, int height, bool vsync) {
	return new GLFWWindow();
}
