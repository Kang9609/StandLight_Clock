#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ)
{
    service = serv;
    clockService = clockServ;
    lightState = LIGHT_OFF;

}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton") 
    {   
        service->updateState("modeButton");         //service에서 
    }
   
   if (strBtn == "clockUpdate") 
    {   
        clockService->updateEvent();      // ("clockUpdate") = 1초 간격으로 신호 => 없어도 된다
    }
}