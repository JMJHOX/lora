#include "lib/MyRadio.h"
#include <iostream>
#include <unistd.h>

int main() {
    MyRadio myRadio;

    if(!myRadio.begin()){
        return 1;
    }

    std::cout << "Esperando paquetes en 433 MHz..." << std::endl;

    while(true){
        myRadio.receive();
        sleep(1);
    }

    return 0;
}

