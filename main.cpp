#include "Radio.h"
#include <iostream>
#include <unistd.h>

int main() {
    Radio myRadio;

    if(!myRadio.begin()){
        return 1; // error inicializando
    }

    std::cout << "Esperando paquetes en 433 MHz..." << std::endl;

    while(true){
        myRadio.receive();
        sleep(1); // espera 1 segundo entre intentos
    }

    return 0;
}

