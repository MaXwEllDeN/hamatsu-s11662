#include "include/s11662.h"

/* Mocking wiringPi */
#define INPUT 0
void wiringPiSetup(void) {
    return;
}
void pinMode(uint8_t pin, uint8_t mode) {
    return;
}

uint8_t digitalRead(uint8_t pin) {
    return pin % 2;
}
/* ************** */
bool S11662::setup(void)
{
    wiringPiSetup();

    uint8_t i = 0;
    for (i = 0; i <= 11; i++) {
        pinMode(S11662_PINS_DATA[i], INPUT);
    }

    return true;
}

uint16_t S11662::readPixel(void)
{
    uint16_t pixel = 0x00;
    uint8_t i = 0;

    for (i = 0; i < 11; i++) {
        pixel = pixel | (digitalRead(S11662_PINS_DATA[i]) << i);
    }

    return pixel;
}