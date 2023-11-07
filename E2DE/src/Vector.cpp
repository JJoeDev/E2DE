#include "include/Vector.h"
#include <cmath>

e2e::Vector::Vector() : x(0.0f), y(0.0f) {

}

e2e::Vector::Vector(float X, float Y) : x(X), y(Y) {

}

float e2e::Vector::Length(){
    return std::sqrt(x * x + y * y);
}

void e2e::Vector::Normalize(){
    float l = Length();
    if(l > 0.0f){
        x /= l;
        y /= l;
    }
}

e2e::Vector e2e::Vector::Normalized(){
    float l = Length();
    if(l > 0.0f)
        return Vector(x / l, y / l);
    else
        return Vector(0.0f, 0.0f); 
}