#include "include/Rendertest.h"
#include "include/core.h"

e2e::dev::Renderable::Renderable(const e2e::Vector& pos){
    r.x = pos.x;
    r.y = pos.y;
    r.w = 10;
    r.h = 10;
}

e2e::dev::Renderable::~Renderable(){

}

void e2e::dev::Renderable::render(e2e::Engine& e){
    e.DrawRect(r);
}