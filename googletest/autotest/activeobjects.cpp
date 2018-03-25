#include "activeobjects.h"
#include <ctime>
#include <cmath>
#include <random>

#include "enemytank.h"
#include "wall.h"
#include "playertank.h"
#include "gold.h"
#include "bullet.h"
#include <iostream>

ActiveObjects::ActiveObjects(shared_ptr<Battlefield> battlefieldIn, shared_ptr<ObserverPlayer> observerIn):battlefield(battlefieldIn), observer(observerIn)
{
    time1 = clock();
    time2 = clock();
}

bool ActiveObjects::nearCheck(const int &x, const int &y, const int &distance)
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
    addObject( shared_ptr<Gold>( new Gold( observer, width/2, height - 2 ) ) );
    for (int i = 0; i < 3; i++ )
    {
        addObject( shared_ptr<Wall>( new Wall( width / 2 - 1 + i, height - 3 ) ) );
        addObject( shared_ptr<Wall>( new Wall( width / 2 - 1 + i, height - 2 ) ) );
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

    this->createStronghold();

    //PlayerTank
    shared_ptr<PlayerTank> playerTank( new PlayerTank( observer, bWidth / 2, bHeight - 4) );
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
    battlefield.get()->drawField();
}

void ActiveObjects::iterateActive()
{
inputInterface.playerInput.takeInput();
time2 = clock();
    if ((time2 - time1) > (CLOCKS_PER_SEC / 2))
    {
        auto it = listOfObjects.begin();
        auto itt = it;
        while (it != listOfObjects.end())
        {
            advance( itt, 1 );
            if ( ( it->get()->getType() == PLAYER ) || ( it->get()->getType() == AI ) )
            {
                it->get()->changeAction( inputInterface.getAction( *it ) );
            }
        makeAction(it);
        it = itt;
        }
    time1 = time2;
    }
}

void ActiveObjects::makeAction(list<shared_ptr<Object> >::iterator &it)
{
    switch ( it->get()->getAction() )
    {
    case A_UP:    it->get()->changeDirection(UP); if (!battlefield.get()->moveObject( it->get()->getX(), it->get()->getY(), it->get()->getX(), it->get()->getY() - 1 ) ) makeAction(it);
        break;
    case A_DOWN:  it->get()->changeDirection(DOWN); if (!battlefield.get()->moveObject( it->get()->getX(), it->get()->getY(), it->get()->getX(), it->get()->getY() + 1 ) ) makeAction(it);
        break;
    case A_LEFT:  it->get()->changeDirection(LEFT); if (!battlefield.get()->moveObject( it->get()->getX(), it->get()->getY(), it->get()->getX() - 1, it->get()->getY() ) )makeAction(it);
        break;
    case A_RIGHT: it->get()->changeDirection(RIGHT); if (!battlefield.get()->moveObject( it->get()->getX(), it->get()->getY(), it->get()->getX() + 1, it->get()->getY() ) ) makeAction(it);
        break;
    case A_SHOOT: { shared_ptr<Bullet> bullet( new Bullet( *it ) );
                      this->addObject( bullet );}
        break;
    case A_STOP:
        break;
    case A_HIT: it->get()->hit(); makeAction(it);
       break;
    case A_DESTROY: battlefield.get()->deleteObject( it->get()->getX(), it->get()->getY() );
                        listOfObjects.erase(it);
        break;
    default:
        break;
    }
}
