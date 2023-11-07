#ifndef E2E_VECTOR_H_
#define E2E_VECTOR_H_

namespace e2e{
    struct Vector{
        Vector();
        Vector(float, float);

        float Length();

        void Normalize();

        Vector Normalized();

        inline Vector operator+(const Vector& v) { return Vector(x + v.x, y + v.y); }
        inline Vector operator-(const Vector& v) { return Vector(x - v.x, y - v.y); }
        inline Vector operator+(const float& v) { return Vector(x + v, y + v); }
        inline Vector operator-(const float& v) { return Vector(x - v, y - v); }

        inline Vector operator*(const float& v) { return Vector(x * v, y * v); }
        inline Vector operator/(const float& v) { return Vector(x / v, y / v); }

        inline bool operator==(const Vector& v) const { return x == v.x && y == v.y; }

        inline void operator+=(const Vector& v) { x += v.x; y += v.y; }
        inline void operator-=(const Vector& v) { x -= v.x; y -= v.y; }
        inline void operator+=(const float& v) { x += v; y += v; }
        inline void operator-=(const float& v) { x -= v; y -= v; }
        inline void operator*=(const float& v) { x *= v; y *= v; }
        inline void operator/=(const float& v) { x /= v; y /= v; }

        float x, y;
    };
}

#endif