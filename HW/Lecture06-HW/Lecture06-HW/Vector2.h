#pragma once
struct Vector2
{
	float _x;
	float _y;

	explicit Vector2() : _x(0), _y(0) {}
	explicit Vector2(float x, float y) : _x(x), _y(y) {}

	Vector2 operator+ (const Vector2& rhs) const
	{
		return Vector2(_x + rhs._x, _y + rhs._y);
	}
};


