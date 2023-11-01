#include "core.h"

int main(){ // Simple test to see if library is working right
    Core::Engine* Engine = new Core::Engine();

    while(true){
        Engine->HelloFunc();
    }

    delete Engine;
    return 0;
}