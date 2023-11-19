#include "Vector.h"
#include <cmath>

namespace e2e{
    const float Vector::Length() const {
        return std::sqrt(x * x + y * y);
    }

    void Vector::Normalize(){
        float l = Length();
        if(l > 0.0f){
            x /= l;
            y /= l;
        }
    }

    const Vector Vector::Normalized() const {
        float l = Length();
        if(l > 0.0f)
            return Vector(x / l, y / l);
        else
            return Vector(0.0f, 0.0f); 
    }
}
