#include "core/Window.h"
#include "core/Logger.h"

#ifdef PLATFORM_WINDOWS
#include <GLFW/glfw3.h>
#endif

using namespace Abstract2D;

namespace {

}

class WindowsWindow : public Window {
private:
	GLFWwindow* m_window = nullptr;
public:
	bool Init(const std::string& title, int width, int height, bool vsync) override {
		if (!glfwInit()) {
			DEBUG_ERROR("Failed to initialize GLFW");
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		//glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);

		m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (!m_window) {
			DEBUG_ERROR("Failed to create window.");
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(m_window);
		glfwSwapInterval(vsync ? 1 : 0);

		//DEBUG_INFO("GLFW window created with OpenGL ES 2.0 context");
		return true;
	}

	void PollEvents() override { glfwPollEvents(); }

	void SwapBuffers() override { glfwSwapBuffers(m_window); }

	bool ShouldClose() const override { return glfwWindowShouldClose(m_window); }

	void Shutdown() const override {
		if (m_window) {
			glfwDestroyWindow(m_window);
			DEBUG_INFO("GLFW Window destroyed..");
		}
		glfwTerminate();
		DEBUG_INFO("Window shutdown completed..");

	}
};

std::unique_ptr<Window> Window::Create() {
#if defined(PLATFORM_WINDOWS) 
	return std::make_unique<WindowsWindow>();
#elif defined(PLATFORM_ANDROID)
	return std::make_unique<AndroidWindow>();
#else
	static_assert(false, "Unsupported platform!");
#endif
}
