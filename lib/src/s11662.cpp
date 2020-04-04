#include "../include/s11662.h"

/* Mocking wiringPi */
#define INPUT 0
void wiringPiSetup(void) {
    return;
}
void pinMode(__uint8_t pin, __uint8_t mode) {
    (pin + mode);
    return;
}

__uint8_t digitalRead(__uint8_t pin) {
    return pin % 2;
}
/* ************** */

bool S11662::setup(void)
{
    wiringPiSetup();

    __uint8_t i = 0;
    for (i = 0; i <= 11; i++) {
        pinMode(S11662_PINS_DATA[i], INPUT);
    }

    return true;
}

__uint16_t S11662::readPixel(void)
{
    __uint16_t pixel = 0x0000;
    __uint8_t i = 0;

    for (i = 0; i <= 11; i++) {
        pixel = pixel | (digitalRead(S11662_PINS_DATA[i]) << i);
    }

    this->setNewPixelFlag(false);
    return pixel;
}

Frame S11662::readFrame(void)
{
    __uint16_t i;
    __uint16_t j;

    for (i = 0; i < S11662_RES_H; i++) {
        for (j = 0; j < S11662_RES_V; j++) {
            if (this->isNewPixelReady()) {
                this->currentFrame.setPixel(i, j, this->readPixel());
            }
        }
    }

    return this->currentFrame;
}
