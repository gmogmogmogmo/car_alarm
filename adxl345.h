//adxl345_driver
#ifndef accel_H
#define accel_H
#include <cstdint>
#include <gpiod.h>

constexpr uint8_t sensorAddress = 0x53;
constexpr uint8_t tapThreshold = 0x20;
constexpr uint8_t duration = 0x20; //20,000 us / 625 us = 3x 0x20;
constexpr uint8_t usingIntOnePin = 0x00; //00000000
constexpr uint8_t tapinterrupt = 0x40;

constexpr int xAxisDetectionOn = 1;
constexpr int yAxisDetectionOn = 1;
constexpr int zAxisDetectionOn = 1;
constexpr int gpioPinSeventeen = 17;
constexpr int setIndefinitely = -1;
constexpr int edgeEventBufferCapacity = 10;

class Adxl345 {
    public:
    Adxl345(const char *pathname);
    ~Adxl345();

    void wake();
    void setThreshTap(uint8_t value);
    void setDur(uint8_t value);
    void setAxes(int xAxisDetection, int yAxisDetection, int zAxisDetection);
    void setInterruptEnable(uint8_t value);
    void setIntMap(uint8_t value);
    void setUpSingleTapDetection();
    void lineSetupSignalDetection();
    uint8_t checkIntSource();
    int16_t readX();
    int16_t readY();
    int16_t readZ();

    private:
    int fd;
    gpiod::
};

#endif