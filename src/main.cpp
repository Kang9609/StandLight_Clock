#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include <time.h>
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "I2C.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    // time_t timeSec;
    // struct tm *timedata;
    
    Button button1(27);
    ClockCheck clockCheck;
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    LCD lcd(new I2C("/dev/i2c-1", 0x27));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    ClockView clockView(&lcd);
    Service service(&view);
    ClockService clockService(&clockView);
    Controller control(&service, &clockService);
    Listener listener(&button1, &control, &clockCheck);
    
    while (1)
    {
        listener.checkEvent();
        view.lightView();
        // timeSec = time(NULL);
        // timedata = localtime(&timeSec);
        // std::cout << "timeSec : " << timeSec << std::endl;
        // std::cout << timedata->tm_hour << ":"
        //           << timedata->tm_min << ":"
        //           << timedata->tm_sec << std::endl;

         delay(50);

    }

    return 0;
}