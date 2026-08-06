#include <iostream>
#include "adxl345.h"
#include <cstdint>
#include <unistd.h>
#include <string>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <bitset>
#include <linux/i2c-dev.h>
#include <cstdlib>
#include <gpiod.h>

Adxl345::Adxl345(const char* device){
    fd = open(device, O_RDWR);
    ioctl(fd, I2C_SLAVE, SENSOR_ADDRESS);
}

Adxl345::~Adxl345(){
    close(fd);
}

void Adxl345::wake(){
    uint8_t buffer[2] = {0x2D, 0x08};
    write(fd, buffer, 2);
}

int16_t Adxl345::readX(){
    //0x32 and 0x33
    uint8_t dataXo = 0x32;
    uint8_t dataX1 = 0x33;
       
    write(fd, &dataXo, 1);
    read(fd, &dataXo, 1);

    write(fd, &dataX1, 1);
    read(fd, &dataX1, 1);

    int16_t fullSixteenBitValueX = (dataX1 << 8) | dataXo;

    return fullSixteenBitValueX;
}

int16_t Adxl345::readY(){
    //0x34 and 0x35
    uint8_t dataYo = 0x34;
    uint8_t dataY1 = 0x35;
    write(fd, &dataYo, 1);
    read(fd, &dataYo, 1);

    write(fd, &dataY1, 1);
    read(fd, &dataY1, 1);

    int16_t fullSixteenBitValueY = (dataY1 << 8) | dataYo;

    return fullSixteenBitValueY;
}

int16_t Adxl345::readZ(){
     //0x36 0x37
    uint8_t dataZo = 0x36;
    uint8_t dataZ1 = 0x37;

    write(fd, &dataZo, 1);
    read(fd, &dataZo, 1);

    write(fd, &dataZ1, 1);
    read(fd, &dataZ1, 1);

    int16_t fullSixteenBitValueZ = (dataZ1 << 8) | dataZo;

    return fullSixteenBitValueZ;
}

void Adxl345::setThreshTap(uint8_t value){
    //value must be set at before runtime in hexadecimal value
    uint8_t threshTapAddr[2] = {0x1D, value}; 
    write(fd, threshTapAddr, 2);
}

void Adxl345::setDur(uint8_t value){
    uint8_t durAddress[2] = {0x21, value};
    write(fd, durAddress, 2);
}

void Adxl345::setTapDetection(int xAxisDetection, int yAxisDetection, int zAxisDetection){
    //if value is set to 1 if detection is enabled for an axis 0 if not
    if(xAxisDetection == 1 && yAxisDetection == 1 && zAxisDetection == 1){
        uint8_t tap[2] = {0x2A, 0x07};
        write(fd, tap, 2);
    }
}

void Adxl345::setInterruptEnable(uint8_t value){
    uint8_t buffer[2] = {0x2E, value};
    write(fd, buffer, 2);
}

uint8_t Adxl345::checkIntSource(){
    uint8_t addr = 0x30;
    uint8_t status = 0;

    write(fd, &addr, 1);
    read(fd, &status, 1);

    return status;
}

void Adxl345::setIntMap(uint8_t value){
    uint8_t intMapAddr[2] = {0x2F, value};
    write(fd, intMapAddr, 2);
}

void Adxl345::waitForTap(){
    struct gpiod_edge_event_buffer *buffer = gpiod_edge_event_buffer_new(1);

    int ret = gpiod_line_request_read_edge_events(request, buffer, 1); // blocks until event
    if (ret <= 0) {
        gpiod_edge_event_buffer_free(buffer);
        return;
    }

    gpiod_edge_event_buffer_free(buffer);
}

void playSound(const std::string& filepath){
    std::string command = "aplay " + filepath + " &";
    system(command.c_str());
}
int main(int argc, char const *argv[])
{
    uint8_t tapThreshold = 0x64; // 100 * 62.5 mg = 6250
    uint8_t duration = 0x20; //20,000 us / 625 us = 3x 0x20;
    uint8_t usingIntOnePin = 0x00; //00000000
    uint8_t tapinterrupt = 0x40;

    int timeStep = 100000;
    
    Adxl345 accel("/dev/i2c-1");

    accel.setThreshTap(tapThreshold);
    accel.setDur(duration);
    accel.setTapDetection(1,1,1);
    accel.setInterruptEnable(tapinterrupt);
    accel.setIntMap(usingIntOnePin);

    accel.wake();

    std::cout << " Waiting for tap..." << std::endl;
    while(true){
        uint8_t source = accel.checkIntSource();

        std::cout << "INT_SOURCE: " << std::bitset<8>(source) << std::endl;

        if (source & 0x40) {
            std::cout << "SINGLE TAP DETECTED!" << std::endl;
            playSound("/home/gmo/sounds/Alarm_Sound_Effect.wav");
        }

        usleep(timeStep);
        
    }

    return 0;
}
