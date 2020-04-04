#ifndef _S11662_CONST_H
#define _S11662_CONST_H
#include <stdint.h>

#define S11662_RES_H    640
#define S11662_RES_V    480

/* Parallel data pinout */
// {D0, D1, D2 ... D11}
const __uint8_t S11662_PINS_DATA[12] = {
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12
};

#define S11662_PIN_D0       00
#define S11662_PIN_D1       00
#define S11662_PIN_D2       00
#define S11662_PIN_D3       00
#define S11662_PIN_D4       00
#define S11662_PIN_D5       00
#define S11662_PIN_D6       00
#define S11662_PIN_D7       00
#define S11662_PIN_D8       00
#define S11662_PIN_D9       00
#define S11662_PIN_D10      00
#define S11662_PIN_D11      00

/* SPI CONFIGURATION */
#define S11662_PIN_SPI_EN   00
#define S11662_PIN_SPI_RST  00

enum S11662_ERROR {
    UNDEFINED_ERROR = -1,
    SETUP_ERROR
};

typedef struct S11662_Frame_tag {

    __uint8_t HEIGHT;
    __uint8_t WIDTH;

} S11662_Frame;

#endif /*_S11662_CONST_H*/