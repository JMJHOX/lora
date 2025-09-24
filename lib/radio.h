#ifndef RADIO_H
#define RADIO_H

#include "../../RadioLib/src/RadioLib.h"  // ruta a RadioLib.h
#include "../../RadioLib/src/modules/SX127x/SX1278.h"

class Radio {
public:
    Radio();
    bool begin(double freq = 915.0);  // MHz
    bool receive();

private:
    SX1278 radio;
};

#endif

