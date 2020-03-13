#ifndef _DRIVER_S11662_H
#define _DRIVER_S11662_H
#include "const.h"

class S11662
{
public:
    S11662(void) {
        this->setup();
    }

private:
    bool setup(void);
};

#endif /*_DRIVER_S11662_H*/