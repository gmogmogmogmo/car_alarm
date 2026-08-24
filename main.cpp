#include "alarm_controller.h"

int main(int argc, char const *argv[])
{
    
    bool ledMode = ledModeSetup();
    systemArmed(ledMode);
    trigger();
    systemOffline();   
    
    return 0;
}

