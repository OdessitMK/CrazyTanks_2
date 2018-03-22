#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include "object.h"

class PlayerInput
{
protected:
    ACTION action;
public:
    PlayerInput();
    ACTION getAction(const shared_ptr<Object> playerTankIn);
    void takeInput();

};

#endif // PLAYERINPUT_H
