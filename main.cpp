#include "alarm_controller.h"

int main(int argc, char const *argv[])
{
    while (true){
        systemArmed();
        trigger();
        systemOffline();   
    }

    return 0;
}

