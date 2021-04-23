#pragma once

/////////////////////////////////////////
// A three-dimensional Euclidean vector.
/////////////////////////////////////////
class Vector3
{
private:
	float m_x;
	float m_y;
	float m_z;

public:
	Vector3()
		: Vector3{ 0,0,0 }
	{}

	Vector3(float x, float y, float z)
		: m_x{ x }
		, m_y{ y }
		, m_z{ z }
	{}

	~Vector3() = default;

	float GetX() const { return m_x; }
	void SetX(float value) { m_x = value; }

	float GetY() const { return m_y; }
	void SetY(float value) { m_y = value; }

	float GetZ() const { return m_z; }
	void SetZ(float value) { m_z = value; }
};