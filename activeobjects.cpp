#include "activeobjects.h"
#include <ctime>
#include <cmath>
#include <random>

#include "enemytank.h"
#include "wall.h"
#include "playertank.h"
#include "gold.h"
#include "bullet.h"

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

void ActiveObjects::addObject(shared_ptr<Object> objIn)
{
    if ( battlefield.get()->addObject(objIn) )
        listOfObjects.push_back(objIn);
}

void ActiveObjects::createStronghold()
{
    int width = battlefield.get()->getWidth();
    int height = battlefield.get()->getHeight();
    addObject( shared_ptr<Gold>( new Gold( observer, width/2, height ) ) );
    for (int i = 0; i < 3; i++ )
    {
        addObject( shared_ptr<Wall>( new Wall( width / 2 - 1 + i, height - 1 ) ) );
        addObject( shared_ptr<Wall>( new Wall( width / 2 - 1 + i, height ) ) );
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
    addObject(playerTank);

    //Initialise AI with playerTank
    inputInterface.aiInput.initAiInput(playerTank);

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
        addObject( EnemyT );
    }

    //Walls
    for (int i = 0; i < ( bHeight * bWidth / 40); i++)
    {
        int wallX = dieX(mersenne);
        int wallY = dieY(mersenne);
        addObject( shared_ptr<Wall>( new Wall( wallX, wallY ) ) );
        switch ( dieTwo(mersenne) )
        {
            case 1: for ( int w = 1; w < dieW(mersenne); w++)
                        addObject( shared_ptr<Wall>( new Wall( wallX, wallY + w ) ));
                break;
            case 2: for ( int w = 1; w < dieW(mersenne); w++)
                        addObject( shared_ptr<Wall>( new Wall( wallX + w, wallY ) ));
                break;
        }
    }
}

void ActiveObjects::iterateActive(bool input)
{

    auto it = listOfObjects.begin();
    while (it != listOfObjects.end())
    {
        auto itt = it;
        advance( itt, 1 );
        if ( input )
        {
            if ( ( it->get()->getType() == PLAYER ) || ( it->get()->getType() == AI ) )
            {
                it->get()->changeAction( inputInterface.getAction( *it ) );
            }
        }
        switch ( it->get()->getAction() )
        {
        case A_UP:    battlefield.get()->moveObject( it->get()->getX(), it->get()->getY(), it->get()->getX(), it->get()->getY() - 1 ); it->get()->changeDirection(UP);
            break;
        case A_DOWN:  battlefield.get()->moveObject( it->get()->getX(), it->get()->getY(), it->get()->getX(), it->get()->getY() + 1 ); it->get()->changeDirection(DOWN);
            break;
        case A_LEFT:  battlefield.get()->moveObject( it->get()->getX(), it->get()->getY(), it->get()->getX() - 1, it->get()->getY() ); it->get()->changeDirection(LEFT);
            break;
        case A_RIGHT: battlefield.get()->moveObject( it->get()->getX(), it->get()->getY(), it->get()->getX() + 1, it->get()->getY() ); it->get()->changeDirection(RIGHT);
            break;
        case A_SHOOT: { shared_ptr<Bullet> bullet( new Bullet( *it ) );
                          this->addObject( bullet );}
            break;
        case A_STOP:
            break;
        case A_HIT: it->get()->hit();
           break;
        case A_DESTROY: battlefield.get()->deleteObject( it->get()->getX(), it->get()->getY() );
                            listOfObjects.erase(it);
            break;
        default:
            break;
        }
        it = itt;
    }
}
