#ifndef _FRAME_H
#define _FRAME_H

#include "const.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <stdint.h>

class Frame {
private:
    cv::Mat frame;

public:
    Frame(void): frame((uint16_t) S11662_RES_V, (uint16_t) S11662_RES_H, CV_16UC1){
        this->clear();
    };

    ~Frame() {
        this->frame.release();
    }

    void saveAsPNG(const char* file)
    {
        imwrite(file, this->frame);
    }
    
    cv::Mat getMatrix()
    {
        return this->frame;
    }

    void setPixel(uint16_t x, int16_t y, uint16_t grayScaleIntensity) {
        this->frame.at<uint16_t>(y, x) = grayScaleIntensity;
    };
    
    void clear(void) {
        for (uint16_t x = 0; x < this->frame.cols; x++) {
            for (int y = 0; y < this->frame.rows; y++) {
                this->frame.at<uint16_t>(y, x) = 65535;
            }
        }
    };
};

#endif /*_FRAME_H*/