#ifndef SIM_H
#define SIM_H


class Sim
{
private:
    int fd;
    void configre 
public:
    Sim(const char* device);
    void readData();
    //~Sim();
};


#endif





























//lsuusb
// -> what USB devices are currently connected to me?


//ls /dev/ttyUSB*

// what is listed is device files that linux creates on the Pi represetning one of the modems usb communication channels

//our c++ rpogram needs somethig it can open and read/write to

//this is the doorway that linux creates for you programs to access the modem 

// theses are 5 different serial interfaces that linux has exposed 
//different channels can be used for different modem functions 

//we need the channel that accepts AT commands 

// so now lets figure out which one is the modem's AT-command channel

//test to see which channel is a AT-command channel


//download minicom/picocom - its a terminal program for communicating with serial devices 
//temporary way for you to talk directly to the SIM7000G


//USB2 is the AT-command channel


//$GNGGA is one of the NMEA sentences that contains the core postion/fix information

//pretty much GNGGG is the summary but all other ones are gps satellite information like what was used and which ones were used 