//adxl345_driver
#ifndef accel_H
#define accel_H

#include <cstdint>
#include <gpiod.h>

#define SENSOR_ADDRESS 0x53

class Adxl345 {
    public:
    Adxl345(const char *pathname);
    ~Adxl345();

    void wake();
    //void standBy();
    void setThreshTap(uint8_t value);
    void setDur(uint8_t value);
    void setTapDetection(int xAxisDetection, int yAxisDetection, int zAxisDetection);
    //bool hasbeenTapped();
    void setInterruptEnable(uint8_t value);
    void setIntMap(uint8_t value);

    uint8_t checkIntSource();
    
    void waitForTap();

    int16_t readX();
    int16_t readY();
    int16_t readZ();

    private:
    int fd;
    struct gpiod_chip* chip;
    struct gpiod_line_request* request;
    static constexpr unsigned int gpioLineOffset = 17;
};

#endif

