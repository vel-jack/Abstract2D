#pragma once

#include <string>

namespace Abstract2D {

    class Window {
    public:
        virtual ~Window() = default;

        virtual bool Init(const std::string& title, int width, int height, bool vsync) = 0;
        virtual void PollEvents() = 0;
        virtual void SwapBuffers() = 0;
        virtual bool ShouldClose() const = 0;

        static Window* Create(const std::string& title, int width, int height, bool vsync);
    };

}
