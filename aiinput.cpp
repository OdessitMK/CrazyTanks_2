#include "aiinput.h"

#include <cmath>
#include <random>
#include <ctime>


AiInput::AiInput()
{

}

void AiInput::initAiInput(shared_ptr<PlayerTank> playerTankIn)
{
    playerTank = playerTankIn;
}

ACTION AiInput::getAction(const shared_ptr<Object> objIn)
{
    ACTION returnAction = objIn.get()->getAction();
    switch ( returnAction )
    {
        case A_HIT: //dont change
            break;
        case A_DESTROY: //dont change
            break;
        default:
    mt19937 mersenne( static_cast<unsigned int>( time(0) ) );
    uniform_int_distribution<> die(1, 3);

    if ( objIn.get()->getX() == playerTank.get()->getX() )
    {
        if ( objIn.get()->getY() > playerTank.get()->getY() )
        {
            if ( die(mersenne) == 1)
            {
                objIn.get()->changeDirection( UP );
                returnAction = A_SHOOT;
            }
            else returnAction = A_UP;
        }
        else
        {
            if ( die(mersenne) == 1)
            {
                objIn.get()->changeDirection( DOWN );
                returnAction = A_SHOOT;
            }
            else returnAction = A_DOWN;
        }

    } else
    if ( objIn.get()->getY() == playerTank.get()->getY() )
    {
        if ( objIn.get()->getX() > playerTank.get()->getX() )
        {
            if ( die(mersenne) == 1)
            {
                objIn.get()->changeDirection( LEFT );
                returnAction = A_SHOOT;
            }
            else returnAction = A_LEFT;
        }
        else
        {
            if ( die(mersenne) == 1)
            {
                objIn.get()->changeDirection( RIGHT );
                returnAction = A_SHOOT;
            }
            else returnAction = A_RIGHT;
        }

    } else
    if ( fabs( objIn.get()->getY() - playerTank.get()->getY() ) < ( objIn.get()->getX() - playerTank.get()->getX() ) )
    {
        if ( die(mersenne) > 1)
        {
            if ( objIn.get()->getY() < playerTank.get()->getY() )
                returnAction = A_DOWN;
            else returnAction = A_UP;
        }
        else
            if ( die(mersenne) > 1)
                returnAction = A_RIGHT;
            else returnAction = A_LEFT;

    }
    else
    {
        if ( die(mersenne) > 1)
        {
            if ( objIn.get()->getX() < playerTank.get()->getX() )
                returnAction = A_RIGHT;
            else returnAction = A_LEFT;
        }
        else
            if ( die(mersenne) > 1)
                returnAction = A_UP;
            else returnAction = A_DOWN;
    }
  break;
}
    return returnAction;
}
