#include "../../E2DE/src/core.h" // This can be made to just core.h but vs code doesn't like that for some reason

int main(){
    e2e::Engine e("Hello Window", 500, 500);

    while(e.isRunning()){
        e.update();
        e.render();
    }

    return 0;
}