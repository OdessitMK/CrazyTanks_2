#include "activeobjects.h"
#include <ctime>
#include <cmath>
#include <random>

#include "enemytank.h"
#include "wall.h"
#include "playertank.h"
#include "gold.h"

ActiveObjects::ActiveObjects(shared_ptr<Battlefield> battlefieldIn, shared_ptr<ObserverPlayer> observerIn):battlefield(battlefieldIn), observer(observerIn)
{

}

bool ActiveObjects::nearCheck(int x, int y, int distance)
{
    for (auto it: listOfObjects)
    {
        if ( (fabs( it.get()->getX() - x) < distance) && (fabs( it.get()->getY() - y) < distance) )
                return false;
    }
    return true;
}

void ActiveObjects::AddObject(shared_ptr<Object> objIn)
{
    if ( battlefield.get()->addObject(objIn) )
        listOfObjects.push_back(objIn);
}

void ActiveObjects::createStronghold()
{
    int width = battlefield.get()->getWidth();
    int height = battlefield.get()->getHeight();
    battlefield.get()->addObject( shared_ptr<Gold>( new Gold( observer, width/2, height ) ) );
    for (int i = 0; i < 3; i++ )
    {
        battlefield.get()->addObject( shared_ptr<Wall>( new Wall( width / 2 - 1 + i, height - 1 ) ) );
        battlefield.get()->addObject( shared_ptr<Wall>( new Wall( width / 2 - 1 + i, height ) ) );
    }
}

void ActiveObjects::setup()
{
    int bWidth = battlefield.get()->getWidth();
    int bHeight = battlefield.get()->getHeight();

    //Random setup
    mt19937 mersenne( static_cast<unsigned int>( time(0) ) );
    uniform_int_distribution<> dieY(1, bHeight - 2);
    uniform_int_distribution<> dieX(1, bWidth - 2);
    uniform_int_distribution<> dieW(3, 4);
    uniform_int_distribution<> dieTwo(1, 2);

    //PlayerTank
    shared_ptr<PlayerTank> playerTank( new PlayerTank( observer, bWidth / 2, bHeight - 3) );
    battlefield.get()->addObject(playerTank);

    //Initialise AI with playerTank
    aiInput.initAiInput(playerTank);

    //Enemy tanks
    for ( int i = 0; i < 3;i++)
    {
        int tankX;
        int tankY;
        do
        {
            tankX = dieX(mersenne);
            tankY = dieY(mersenne);
        } while( !nearCheck( tankX, tankY) );
        shared_ptr<EnemyTank> EnemyT( new EnemyTank( observer, tankX, tankY) );
        AddObject( EnemyT );
    }

    //Walls
    for (int i = 0; i < ( bHeight * bWidth / 40); i++)
    {
        int wallX = dieX(mersenne);
        int wallY = dieY(mersenne);
        battlefield.get()->addObject( shared_ptr<Wall>( new Wall( wallX, wallY ) ) );
        switch ( dieTwo(mersenne) )
        {
            case 1: for ( int w = 1; w < dieW(mersenne); w++)
                        battlefield.get()->addObject( shared_ptr<Wall>( new Wall( wallX, wallY + w ) ));
                break;
            case 2: for ( int w = 1; w < dieW(mersenne); w++)
                        battlefield.get()->addObject( shared_ptr<Wall>( new Wall( wallX + w, wallY ) ));
                break;
        }
    }


}
