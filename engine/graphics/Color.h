#pragma once
#include <algorithm>
#include <ostream>

namespace Abstract2D {

	struct Color {
		float r{ 1.0f };
		float g{ 1.0f };
		float b{ 1.0f };
		float a{ 1.0f };

		constexpr Color() noexcept = default;
		constexpr Color(float _r, float _g, float _b, float _a = 1.0f) noexcept
			: r(_r), g(_g), b(_b), a(_a) {
		}

		static constexpr Color White() noexcept { return { 1,1,1,1 }; }
		static constexpr Color Black() noexcept { return { 0,0,0,1 }; }
		static constexpr Color Red() noexcept { return { 1,0,0,1 }; }
		static constexpr Color Green() noexcept { return { 0,1,0,1 }; }
		static constexpr Color Blue() noexcept { return { 0,0,1,1 }; }

		// Clamp channels to [0,1]
		void Clamp() noexcept {
			r = std::clamp(r, 0.0f, 1.0f);
			g = std::clamp(g, 0.0f, 1.0f);
			b = std::clamp(b, 0.0f, 1.0f);
			a = std::clamp(a, 0.0f, 1.0f);
		}

		// Arithmetic
		Color operator*(float s) const noexcept { return { r * s, g * s, b * s, a * s }; }
		Color operator+(const Color& o) const noexcept { return { r + o.r, g + o.g, b + o.b, a + o.a }; }

		Color& operator*=(float s) noexcept { r *= s; g *= s; b *= s; a *= s; return *this; }
		Color& operator+=(const Color& o) noexcept { r += o.r; g += o.g; b += o.b; a += o.a; return *this; }

		// Helper for OpenGL uniforms (array of 4 floats)
		void ToFloatArray(float out[4]) const noexcept {
			out[0] = r; out[1] = g; out[2] = b; out[3] = a;
		}

		// ostream helper
		friend std::ostream& operator<<(std::ostream& os, const Color& c) {
			os << "Color(" << c.r << ", " << c.g << ", " << c.b << ", " << c.a << ")";
			return os;
		}
	};

}
