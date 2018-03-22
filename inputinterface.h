#ifndef INPUTINTERFACE_H
#define INPUTINTERFACE_H

#include "aiinput.h"
#include "playerinput.h"

class InputInterface
{
protected:
    public:
    AiInput aiInput;
    PlayerInput playerInput;
    InputInterface();
    ACTION getAction(const shared_ptr<Object> objIn);
};

#endif // INPUTINTERFACE_H
