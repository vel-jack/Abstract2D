#include "core/Window.h"
#include "core/Logger.h"

#ifdef PLATFORM_WINDOWS
//#include <GLFW/glfw3.h>
#endif

using namespace Abstract2D;

namespace {

}

class WindowsWindow : public Window {
private:
	//GLFWwindow* m_window = nullptr;
public:
	bool Init(const std::string& title, int width, int height, bool vsync) override {
		return true;
	}

	void PollEvents() override {  }

	void SwapBuffers() override {}

	bool ShouldClose() const override { return false; }

	void Shutdown() const override {
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
