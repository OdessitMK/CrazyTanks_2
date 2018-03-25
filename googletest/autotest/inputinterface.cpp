#include "inputinterface.h"


InputInterface::InputInterface()
{


}

ACTION InputInterface::getAction(const shared_ptr<Object> objIn)
{
    ACTION returnAction;
    if ( objIn.get()->getType() == AI )
        returnAction = aiInput.getAction(objIn);
    else
        returnAction = playerInput.getAction(objIn);
    return returnAction;
}
