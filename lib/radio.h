#ifndef RADIO_H
#define RADIO_H

#include <RadioLib.h>

class Radio {
public:
    Radio();                       // Constructor
    bool begin();                   // Inicializa el radio
    int16_t getRSSI();              // Lee RSSI actual
    bool receive();                 // Espera a recibir un paquete
private:
    SX1278 radio;                   // Objeto radio de RadioLib
};

#endif

