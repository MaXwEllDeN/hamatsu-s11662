#include <stdio.h>
#include "include/s11662.h"
#include "include/frame.h"

// https://solarianprogrammer.com/2019/06/10/c-programming-reading-writing-images-stb_image-libraries/

void print16Binary(__uint16_t number)
{
    __int8_t i;
    for (i = 15; i >= 0; --i) {
        printf("%d", (number & (0x0001 << i)) >> i);
    }
}

int main(int argc, char *argv[])
{
    S11662 imageSensor;
    printf("Resolution: %d(H) x %d(V)\n", S11662_RES_H, S11662_RES_V);
    Frame frame = imageSensor.readFrame();

    return 0;
}