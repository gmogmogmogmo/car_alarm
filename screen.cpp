#include "screen.h"

Screen::Screen(){
    start();
}
Screen::Screen(int busId, int deviceAddress,  int pinMode){
    ssd1306_i2cInitEx2(busId, useDefaultI2cPins, useDefaultI2cPins, screenAddress);
    ssd1306_128x64_init();
    ssd1306_setFixedFont(ssd1306xled_font6x8);
    clear();
}

void Screen::clear(){
    ssd1306_clearScreen();
}
void Screen::start(){
    ssd1306_i2cInitEx2(busID, useDefaultI2cPins, useDefaultI2cPins, screenAddress);
    ssd1306_128x64_init();
    ssd1306_setFixedFont(ssd1306xled_font8x16);
    clear();
    //clear ggdram so its blank
}


void Screen::print(int startPosX, int startPosY,  const std::string& text){
    ssd1306_printFixed(startPosX, startPosY, text.c_str(), STYLE_NORMAL);
}

void Screen::printLogo(uint8_t xpos, uint8_t ypos, uint8_t width, uint8_t height, const uint8_t *bitmap){
    ssd1306_drawBitmap8(xpos, ypos, width, height, bitmap);
}



int main(int argc, char const *argv[])
{
    Screen display;
    int startPosX = 0;
    int startPosY = 0;
    display.print(startPosX, startPosY, "what mode would you like to enter? ");
    sleep(3);
    display.print(startPosX, startPosY, "Press the led to continuee");
    sleep(3);
    std::cout << " this should be printing " << std::endl;
    display.printLogo(startPosX, startPosY, 128, 64, beaconLogo);
    
    
    
    return 0;
}
