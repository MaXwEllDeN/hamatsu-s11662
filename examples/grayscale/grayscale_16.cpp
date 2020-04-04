// Requirement: opencv
// pixel-value.cpp: does something cool

#include <iostream>
#include <opencv2/core/core.hpp>
#include "frame.h"
#include "s11662.h"

const char* FRAME_LOCATION = (char *) "output.png";

int main(int argc, char* argv[])
{
    Frame myFrame;

    cv::namedWindow("Frame", CV_WINDOW_AUTOSIZE);
    cv::imshow("Frame", myFrame.getMatrix());

    int lastX = 0;
    int lastY = 0;

    while (true) {
        int readKey = cv::waitKey(1);

        if (readKey == 27) {
            std::cout << "ESC PRESSED. Bye bye" << std::endl;
            myFrame.saveAsPNG(FRAME_LOCATION);
            break;
        }

        myFrame.setPixel(lastX, lastY, 65535 / 2);
        cv::imshow("Frame", myFrame.getMatrix());

        //printf("(%d, %d)\n", lastX, lastY);        
        lastX++;

        if (lastX > 640) {
            lastX = 0;
            lastY++;
        }
    }

    return 0;
}
