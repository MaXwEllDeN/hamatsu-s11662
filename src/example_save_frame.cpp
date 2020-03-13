#include <stdio.h>
#include <string.h>

#include "s11662.h"
#include "frame.h"
#include "bitmap_image.hpp"

void print16Binary(__uint16_t number)
{
    __int8_t i;

    for (i = 15; i >= 0; --i) {
        printf("%d", (number & (0x0001 << i)) >> i);
    }
}

bool checkParameters(int argc, char *argv[])
{
    if (argc < 2) {
        return false;
    }
    else if (strlen(argv[1]) < 1) {
        return false;
    }
    

    return true;
}

int main(int argc, char *argv[])
{
    if (!checkParameters(argc, argv)) {
        printf("Please specify the bmp output file name.\n");
        return 0;
    }

    printf("Resolution: %d(H) x %d(V).\n", S11662_RES_H, S11662_RES_V);

    char filename[50];
    sprintf(filename, "%s.bmp", argv[1]);

    S11662 imageSensor;
    Frame frame = imageSensor.readFrame();
    bitmap_image bmp = frame.getBitmap();
    bmp.save_image(filename);

    printf("%s saved.\n", filename);
    return 0;
}