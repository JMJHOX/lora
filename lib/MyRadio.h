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
    SX1278 radio;
    static const int NSS = 10;    // Pines SPI de la Pi, ajústalos según tu conexión
    static const int DIO0 = 2;
    static const int RESET = 0;
    static const int BUSY = 0;
};

#endif

