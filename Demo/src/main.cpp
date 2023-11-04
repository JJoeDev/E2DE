#include "../../E2DE/src/include/core.h"

int main(){
    e2e::Engine app("Hello Engine", 500, 500);

    while(1){
        app.update();
        app.render();
    }
}