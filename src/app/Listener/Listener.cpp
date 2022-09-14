#include "Listener.h"

Listener::Listener(Button *button, Controller *control, ClockCheck *clock)
{
    powerButton = button;
    controller = control;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if (powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }

    if (clockCheck->isUpdate())   // 이것이 true 이면  || timeClock = 시간 감시
    {
        controller->updateEvent("clockUpdate");
    } 
}