#pragma once

/////////////////////////////////////////
// A three-dimensional Euclidean vector.
/////////////////////////////////////////
class Vector3
{
private:
    float m_vs[3];

public:
    Vector3() : Vector3{ 0,0,0 } {}

    Vector3(float x, float y, float z)
    {
        m_vs[0] = x;
        m_vs[1] = y;
        m_vs[2] = z;
    }

    float GetX() const { return m_vs[0]; }
    void SetX(float value) { m_vs[0] = value; }

    float GetY() const { return m_vs[1]; }
    void SetY(float value) { m_vs[1] = value; }

    float GetZ() const { return m_vs[2]; }
    void SetZ(float value) { m_vs[2] = value; }

    float operator[](int index) const {
        return m_vs[index];
    }

    Vector3 operator+(const Vector3& other) {
        return Vector3(
            GetX() + other.GetX(),
            GetY() + other.GetY(),
            GetZ() + other.GetZ());
    }
};