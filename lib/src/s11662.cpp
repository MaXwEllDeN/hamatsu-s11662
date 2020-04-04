#include "s11662.h"
#include <stdlib.h> /* rand */

/* Mocking wiringPi */
#define INPUT 0
void wiringPiSetup(void) {
    return;
}
void pinMode(uint8_t pin, uint8_t mode) {
    (pin + mode);
    return;
}

uint8_t digitalRead(uint8_t pin) {
    return pin % 2;
}
/* ************** */

bool S11662::setup(void)
{
    wiringPiSetup();

    for (uint8_t i = 0; i <= 11; i++) {
        pinMode(S11662_PINS_DATA[i], INPUT);
    }

    return true;
}

uint16_t S11662::readPixel(void)
{
    uint16_t pixel = 0x0000;
    for (uint8_t i = 0; i <= 11; i++) {
        pixel = pixel | (digitalRead(S11662_PINS_DATA[i]) << i);
    }

    pixel = rand() % 4095 + 0;

    // The ADC values ranges from 0 to 4095 with 12 bit
    // but we need to convert it up to 16 bit in order to
    // generate a PNG Grayscale Frame.
    return pixel * (65535 / 4095);
}

Frame* S11662::readFrame(void)
{
    for (uint16_t x = 0; x < S11662_RES_H; x++) {
        for (uint16_t y = 0; y < S11662_RES_V; y++) {
            if (this->isNewPixelReady()) {
                this->currentFrame.setPixel(x, y, this->readPixel());
            }
        }
    }

    return &(this->currentFrame);
}
