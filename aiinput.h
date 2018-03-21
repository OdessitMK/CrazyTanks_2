#ifndef AIINPUT_H
#define AIINPUT_H

#include "object.h"
#include "playertank.h"

class AiInput
{
protected:
    shared_ptr<PlayerTank> playerTank;
public:
    AiInput();
    void initAiInput(shared_ptr<PlayerTank> playerTankIn);
    ACTION GetAction(shared_ptr<Object> objIn);

};

#endif // AIINPUT_H
