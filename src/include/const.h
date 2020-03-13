#ifndef _S11662_CONST_H
#define _S11662_CONST_H

/* Parallel data pinout */
// {D0, D1, D2 ... D11}
const uint8_t S11662_PINS_DATA[12] = {0};

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
}

#endif /*_S11662_CONST_H*/