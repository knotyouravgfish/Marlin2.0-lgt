#pragma once

#include "../feature/touch/xpt2046.h"

#define TOUCH_VERSION   V01

struct TouchCalibration
{
    char Version[4];   // Vxx/0
    int16_t xCalibration;
    int16_t yCalibration;
    int16_t xOffset;
    int16_t yOffset;
};

class LgtTouch
{
private:
    TouchCalibration calib;
private:
    uint8_t readTouchXY(uint16_t &x,uint16_t &y);
    uint8_t readTouchXY2(uint16_t &x,uint16_t &y);
public:
    LgtTouch();
    inline bool isTouched() { return touch.isTouched(); }
    inline void waitForRelease() { touch.waitForRelease();}
    // inline void waitForTouch(uint16_t &x, uint16_t &y) { touch.waitForTouch(x, y); }
    uint8_t readTouchPoint(uint16_t &x, uint16_t &y);
    uint8_t calibrate();
};

extern LgtTouch lgtTouch;

