#include <conio.h> //_getch()
#include <windows.h>

#include "playerinput.h"

PlayerInput::PlayerInput():action(A_STOP)
{

}

ACTION PlayerInput::getAction(const shared_ptr<Object> playerTankIn)
{
    takeInput();
    ACTION returnAction = playerTankIn.get()->getAction();
    if ( (returnAction != A_HIT) && (returnAction != A_DESTROY) )
    {
        returnAction = action;
        action = A_STOP;
    }
    return returnAction;
}

void PlayerInput::takeInput()
{
    if ( _kbhit() )
    {
        int ch;
        ch = _getch();
        if (ch == 0 || ch == 224) // for arrow keys It returns either 0 (0x00) or 224 (0xE0) first, and then returns a code identifying the key that was pressed.
            switch (_getch())
            {
                case 72: action = A_UP; //up arrow
                    break;
                case 80: action = A_DOWN; //down arrow
                    break;
                case 75: action = A_LEFT; //left arrow
                    break;
                case 77: action = A_RIGHT; //right arrow
                    break;
            }
        else switch (ch)
        {
            //case 'x': gameOver = true; //exit game on press 'x'
                //break;
            case 32: action = A_SHOOT; //spacebar
                break;
            default:
                break;
        }
    }
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}
