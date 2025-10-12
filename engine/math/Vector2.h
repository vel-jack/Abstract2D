#pragma once
#include <cmath>
#include <ostream>
// TODO:
// ==, != operator overloading..
// perpendicular, cross product
// clamping..
namespace Abstract2D {

	struct Vector2 {
		float x{ 0.0f };
		float y{ 0.0f };

		// Constructors
		constexpr Vector2() noexcept = default;
		constexpr Vector2(float _x, float _y) noexcept : x(_x), y(_y) {}

		// Convenience
		static constexpr Vector2 Zero() noexcept { return { 0.0f, 0.0f }; }
		static constexpr Vector2 One() noexcept { return { 1.0f, 1.0f }; }

		// Arithmetic
		constexpr Vector2 operator+(const Vector2& o) const noexcept { return { x + o.x, y + o.y }; }
		constexpr Vector2 operator-(const Vector2& o) const noexcept { return { x - o.x, y - o.y }; }
		constexpr Vector2 operator*(float s) const noexcept { return { x * s, y * s }; }
		constexpr Vector2 operator/(float s) const noexcept { return { x / s, y / s }; }

		Vector2& operator+=(const Vector2& o) noexcept { x += o.x; y += o.y; return *this; }
		Vector2& operator-=(const Vector2& o) noexcept { x -= o.x; y -= o.y; return *this; }
		Vector2& operator*=(float s) noexcept { x *= s; y *= s; return *this; }
		Vector2& operator/=(float s) noexcept { x /= s; y /= s; return *this; }

		// Vector ops
		constexpr float Dot(const Vector2& o) const noexcept { return x * o.x + y * o.y; }
		float Length() const noexcept { return std::sqrt(x * x + y * y); }
		float LengthSquared() const noexcept { return x * x + y * y; }

		Vector2 Normalized() const noexcept {
			const float len = Length();
			return (len > 1e-6f) ? Vector2{ x / len, y / len } : Vector2::Zero();
		}

		void Normalize() noexcept {
			const float len = Length();
			if (len > 1e-6f) { x /= len; y /= len; }
		}

		static constexpr Vector2 Lerp(const Vector2& a, const Vector2& b, float t) noexcept {
			return { a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t };
		}

		static float Distance(const Vector2& a, const Vector2& b) noexcept {
			const float dx = a.x - b.x;
			const float dy = a.y - b.y;
			return std::sqrt(dx * dx + dy * dy);
		}

		// ostream helper for debug printing
		friend std::ostream& operator<<(std::ostream& os, const Vector2& v) {
			os << "(" << v.x << ", " << v.y << ")";
			return os;
		}
	};

	// scalar * vector
	inline constexpr Vector2 operator*(float s, const Vector2& v) noexcept { return v * s; }

}
