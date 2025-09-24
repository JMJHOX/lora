#include "lib/Radio.h"
#include <iostream>
#include <unistd.h>

int main() {
    Radio myRadio;
    if(!myRadio.begin(915.0)) {
        return 1;
    }

    std::cout << "Esperando paquetes..." << std::endl;

    while(true) {
        myRadio.receive();
        sleep(1);  // espera 1 segundo entre intentos
    }

    return 0;
}

