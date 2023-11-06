#ifndef E2E_VECTOR_H_
#define E2E_VECTOR_H_

namespace e2e{
    struct Vector{
        Vector();
        Vector(float, float);

        float Length();

        void Normalize();

        Vector Normalized();

        Vector operator+(const Vector&);
        Vector operator-(const Vector&);
        Vector operator+(const float&);
        Vector operator-(const float&);

        Vector operator*(const float&);
        Vector operator/(const float&);

        bool operator==(const Vector&) const;

        void operator+=(const Vector&);
        void operator-=(const Vector&);
        void operator+=(const float&);
        void operator-=(const float&);
        void operator*=(const float&);
        void operator/=(const float&);

        float x, y;
    };
}

#endif