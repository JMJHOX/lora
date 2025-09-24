#ifndef MYRADIO_H
#define MYRADIO_H

#include "../RadioLib/src/RadioLib.h"
#include "../RadioLib/src/modules/SX127x/SX1278.h"

class MyRadio {
public:
    MyRadio();
    bool begin();      // Inicializa el radio
    bool receive();    // Intenta recibir un paquete y muestra RSSI

private:
    
    // Pines SPI0 y conexiones del SX1278
    static const int NSS = 8;    // CE0
    static const int DIO0 = 25;
    static const int RESET = 17;
    static const int BUSY = 24;  // si tu módulo no tiene BUSY, poner 0
    SX1278 radio;
};

#endif
