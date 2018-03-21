#include "inputinterface.h"


InputInterface::InputInterface()
{


}

ACTION InputInterface::getAction(shared_ptr<Object> objIn)
{
    if ( objIn.get()->getType() == AI )
        return aiInput.getAction(objIn);
    else
        return playerInput.getAction(objIn);
}
