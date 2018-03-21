#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include "object.h"


class PlayerInput
{
protected:
    ACTION action;
public:
    PlayerInput();
    ACTION getAction();
    void takeInput();

};

#endif // PLAYERINPUT_H
