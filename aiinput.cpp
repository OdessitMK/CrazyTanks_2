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

ACTION AiInput::getAction(shared_ptr<Object> objIn)
{
    ACTION returnAction = objIn.get()->getAction();
    switch ( returnAction )
    {
        case A_HIT: return returnAction;
            break;
        case A_DESTROY: return returnAction;
            break;
        default:
            break;
    }

    mt19937 mersenne( static_cast<unsigned int>( time(0) ) );
    uniform_int_distribution<> die(1, 3);

    if ( objIn.get()->getX() == playerTank.get()->getX() )
    {
        if ( objIn.get()->getY() > playerTank.get()->getY() )
        {
            if ( die(mersenne) == 1)
            {
                objIn.get()->changeDirection( UP );
                return A_SHOOT;
            }
            else return A_UP;
        }
        else
        {
            if ( die(mersenne) == 1)
            {
                objIn.get()->changeDirection( DOWN );
                return A_SHOOT;
            }
            else return A_DOWN;
        }

    }
    if ( objIn.get()->getY() == playerTank.get()->getY() )
    {
        if ( objIn.get()->getX() > playerTank.get()->getX() )
        {
            if ( die(mersenne) == 1)
            {
                objIn.get()->changeDirection( LEFT );
                return A_SHOOT;
            }
            else return A_LEFT;
        }
        else
        {
            if ( die(mersenne) == 1)
            {
                objIn.get()->changeDirection( RIGHT );
                return A_SHOOT;
            }
            else return A_RIGHT;
        }

    }
    if ( fabs( objIn.get()->getY() - playerTank.get()->getY() ) < ( objIn.get()->getX() - playerTank.get()->getX() ) )
    {
        if ( die(mersenne) > 1)
        {
            if ( objIn.get()->getY() < playerTank.get()->getY() )
                return A_DOWN;
            else return A_UP;
        }
        else if ( die(mersenne) > 1)return A_RIGHT; else return A_LEFT;

    }
    else
    {
        if ( die(mersenne) > 1)
        {
            if ( objIn.get()->getX() < playerTank.get()->getX() )
                return A_RIGHT;
            else return A_LEFT;
        }
        else if ( die(mersenne) > 1)return A_UP; else return A_DOWN;
    }


    return A_STOP;
}
