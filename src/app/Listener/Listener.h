#ifndef __LISTENER_H__
#define __LISTENER_H__

#include "Button.h"
#include "ClockCheck.h"
#include "Controller.h"


class Listener
{
private :
    Button *powerButton;
    ClockCheck *clockCheck;
    Controller *controller;

public:
    Listener(Button *button, Controller *control, ClockCheck *clock);
    virtual ~Listener();
    void checkEvent();
};

#endif /* __LISTENER_H__ */
