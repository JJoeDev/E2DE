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

e2e::Vector e2e::Vector::operator+(const Vector& v){
    return Vector(x + v.x, y + v.y);
}

e2e::Vector e2e::Vector::operator+(const float& v){
    return Vector(x + v, y + v);
}

e2e::Vector e2e::Vector::operator-(const Vector& v){
    return Vector(x - v.x, y - v.y);
}

e2e::Vector e2e::Vector::operator-(const float& v){
    return Vector(x - v, y - v);
}

e2e::Vector e2e::Vector::operator*(const float& v){
    return Vector(x * v, y * v);
}

e2e::Vector e2e::Vector::operator/(const float& v){
    return Vector(x / v, y / v);
}

bool e2e::Vector::operator==(const Vector& v) const {
    return x == v.x && y == v.y;
}

void e2e::Vector::operator+=(const Vector& v){
    x += v.x;
    y += v.y;
}

void e2e::Vector::operator+=(const float& v){
    x += v;
    y += v;
}

void e2e::Vector::operator-=(const Vector& v){
    x -= v.x;
    y -= v.y;
}

void e2e::Vector::operator-=(const float& v){
    x -= v;
    y -= v;
}

void e2e::Vector::operator*=(const float& v){
    x *= v;
    y *= v;
}

void e2e::Vector::operator/=(const float& v){
    x /= v;
    y /= v;
}