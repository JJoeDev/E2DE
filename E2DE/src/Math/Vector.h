#ifndef E2E_VECTOR_H_
#define E2E_VECTOR_H_

namespace e2e{
    struct Vector{
        Vector() : x(0.0f), y(0.0f) { }
        Vector(float X, float Y) : x(X), y(Y) { }

        const float Length() const;

        void Normalize();

        const Vector Normalized() const;

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

    struct Vector4{
        Vector4() : x(0.0f), y(0.0f), w(0.0f), h(0.0f) { }
        Vector4(float X, float Y, float W, float H) : x(X), y(Y), w(W), h(H) { }

        inline Vector4 operator+(const Vector4& v) { return Vector4(x + v.x, y + v.y, w + v.w, h + v.h); }
        inline Vector4 operator-(const Vector4& v) { return Vector4(x - v.x, y - v.y, w - v.w, h - v.h); }
        inline Vector4 operator+(const float& v) { return Vector4(x + v, y + v, w + v, h + v); }
        inline Vector4 operator-(const float& v) { return Vector4(x - v, y - v, w - v, h - v); }

        inline Vector4 operator*(const float& v) { return Vector4(x * v, y * v, w * v, h * v); }
        inline Vector4 operator/(const float& v) { return Vector4(x / v, y / v, w / v, h / v); }

        inline bool operator==(const Vector4& v) { return x == v.x && y == v.y && w == v.w && h == v.h; }

        inline void operator+=(const Vector4& v) { x += v.x; y += v.y; w += v.w; h += v.h; }
        inline void operator-=(const Vector4& v) { x -= v.x; y -= v.y; w -= v.w; h -= v.h; }
        inline void operator+=(const float&& v) { x += v; y += v; w += v; h += v; }
        inline void operator-=(const float& v) { x -= v; y -= v; w -= v; h -= v; }
        inline void operator*=(const float& v) { x *= v; y *= v; w *= v; h *= v; }
        inline void operator/=(const float& v) { x /= v; y /= v; w /= v; h /= v; }

        float x, y;
        float w, h;
    };
}

#endif