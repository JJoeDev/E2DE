#include "core.h"

Core::Engine::Engine(){
    std::cout << "Engine constructor called!\n";
}

Core::Engine::~Engine(){
    std::cout << "Engine Deconstructor Called!\n";
}

void Core::Engine::HelloFunc(){
    std::cout << "\nHELLO FROM HELLO FUNCTION\n\n";
}