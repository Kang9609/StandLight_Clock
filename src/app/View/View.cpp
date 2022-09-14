#include "View.h"
#include <wiringPi.h>

View::View(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5, LCD *Lcd)
{
    light1 = led1;
    light2 = led2;
    light3 = led3;
    light4 = led4;
    light5 = led5;
    lightState = LIGHT_OFF;
    this->lcd = Lcd;
}

View::~View()
{

}

void View::setState(int state)
{
    lightState = state;
}

void View::lightView()      // main 함수 while 안에서 무한 roupe로 실행되는 중
{
    switch (lightState)
    {
        case LIGHT_OFF:
            lightOff();
            lightDisplayoff();
        break;

        case LIGHT_1:
            lightOn_1();
            lightDisplay1();
        break;

        case LIGHT_2:
            lightOn_2();
            lightDisplay2();
        break;

        case LIGHT_3:
            lightOn_3();
            lightDisplay3();
        break;

        case LIGHT_4:
            lightOn_4();
            lightDisplay4();
        break;

        case LIGHT_5:
            lightOn_5();
            lightDisplay5();
        break;
    }
}

void View::lightOn_1()
{
    light1->On();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn_2()
{
    light1->Off();
    light2->On();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn_3()
{
    light1->Off();
    light2->Off();
    light3->On();
    light4->Off();
    light5->Off();
}

void View::lightOn_4()
{
    light1->Off();
    light2->Off();
    light3->Off();
    light4->On();
    light5->Off();
}

void View::lightOn_5()
{
    light1->Off();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->On();
}


void View::lightOff()
{
    light1->Off();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightDisplayoff()
{
    char buff[30];
    sprintf(buff, "POWER : OFF");

    lcd->WriteStringXY(0, 0, buff);
}

void View::lightDisplay1()
{
    char buff[30];
    sprintf(buff, "POWER : 1  ");

    lcd->WriteStringXY(0, 0, buff);
}

void View::lightDisplay2()
{
    char buff[30];
    sprintf(buff, "POWER : 2  ");

    lcd->WriteStringXY(0, 0, buff);
}

void View::lightDisplay3()
{
    char buff[30];
    sprintf(buff, "POWER : 3  ");

    lcd->WriteStringXY(0, 0, buff);
}

void View::lightDisplay4()
{
    char buff[30];
    sprintf(buff, "POWER : 4  ");

    lcd->WriteStringXY(0, 0, buff);
}

void View::lightDisplay5()
{
    char buff[30];
    sprintf(buff, "POWER : 5  ");

    lcd->WriteStringXY(0, 0, buff);
}