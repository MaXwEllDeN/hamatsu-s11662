#ifndef _FRAME_H
#define _FRAME_H
#include "const.h"
#include <stdint.h>

class Frame {
private:
    __uint16_t frame[S11662_RES_H][S11662_RES_V];
public:
    Frame(void) {
        this->clear();
    };

    void getBitmap(void);

    void setPixel(__uint16_t x, __uint16_t y, __uint16_t grayScaleIntensity) {
        this->frame[x][y] = grayScaleIntensity;
    };
    
    void clear(void) {
        __uint16_t i;
        __uint16_t j;

        for (i = 0; i < S11662_RES_H; i++) {
            for (j = 0; j < S11662_RES_V; j++) {
                this->setPixel(0, 0, 0);
            }
        }
    };
};

#endif /*_FRAME_H*/