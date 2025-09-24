#include "lib/MyRadio.h"
#include <iostream>
#include <unistd.h>

MyRadio::MyRadio() : radio(nullptr) {}

int main() {
    MyRadio myRadio;

    if(!myRadio.begin()){
        return 1; // no continuar si falla la inicialización
    }

    std::cout << "Esperando paquetes en 433 MHz..." << std::endl;

    while(true){
        myRadio.receive();
        sleep(1); // espera 1 segundo entre intentos
    }

    return 0;
}
