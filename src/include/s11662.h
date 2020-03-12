#ifndef _DRIVER_S11662_H
#define _DRIVER_S11662_H
#include "const.h"
#include "frame.h"
#include <stdint.h>

class S11662
{
private:
    bool newPixelFlag;
    Frame currentFrame;
public:
    S11662(void) {
        this->setNewPixelFlag(true);
        this->setup();
    }

    Frame readFrame(void);
private:
    bool setup(void);

    __uint16_t readPixel(void);
    
    void setNewPixelFlag(bool available) {
        this->newPixelFlag = available;
    };

    bool isNewPixelReady(void) {
        return this->newPixelFlag;
    };
};

#endif /*_DRIVER_S11662_H*/