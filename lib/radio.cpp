#include "Radio.h"

Radio::Radio() : radio(10, 2, 0, 0) {} // SPI pins: NSS=10, DIO0=2, RESET=0, BUSY=0

bool Radio::begin() {
    int state = radio.begin(433.0, 125.0, 7, 1, 8, 0, true); // freq=433MHz, BW=125kHz, CR=4/7
    return (state == RADIOLIB_ERR_NONE);
}

bool Radio::receive() {
    int state = radio.receive();
    return (state == RADIOLIB_ERR_NONE);
}


int16_t Radio::getRSSI() {
    return radio.getRSSI();
}

