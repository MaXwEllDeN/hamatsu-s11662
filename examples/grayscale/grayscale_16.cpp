// Requirement: opencv
// grayscale_16.cpp: does something cool

#include <iostream>
#include <opencv2/core/core.hpp>
#include <unistd.h> /* usleep */
#include <stdlib.h> /* srand */
#include <time.h> /* time */
#include "frame.h"
#include "s11662.h"

const char* FRAME_LOCATION = (char *) "output.png";

void print16Binary(int16_t number);

int main(int argc, char* argv[])
{
    srand (time(NULL));
    S11662 imageSensor;    
    Frame* frame = imageSensor.readFrame();

    printf("Frame resolution: %d(H) x %d(V).\n", S11662_RES_H, S11662_RES_V);

    cv::namedWindow("Frame", CV_WINDOW_AUTOSIZE);
    cv::imshow("Frame", frame->getMatrix());

    int property = cv::getWindowProperty("Frame", 1);

    while (property > 0) {
        if (!cvGetWindowHandle("Frame") or cv::waitKey(4) == 27) {
            break;
        }

        // WND_PROP_AUTOSIZE = 1
        property = cv::getWindowProperty("Frame", 1);

        // Updates visualization to the newest frame read by the sensor
        frame = imageSensor.readFrame();
        cv::imshow("Frame", frame->getMatrix());
    }
    
    frame->saveAsPNG(FRAME_LOCATION);
    return 0;
}

void print16Binary(int16_t number)
{
    for (uint8_t i = 15; i >= 0; --i) {
        printf("%d", (number & (0x0001 << i)) >> i);
    }
}