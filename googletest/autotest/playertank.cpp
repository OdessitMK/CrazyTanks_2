#include "playertank.h"


PlayerTank::PlayerTank(shared_ptr<ObserverPlayer> observerIn,const int &xIn, const int &yIn, const int &healthPointsIn, const DIRECTION &directionIn, const ACTION &nextActionIn ): Object( xIn, yIn, healthPointsIn, directionIn, nextActionIn ), SubjectOfObservation(observerIn)
{
    type = PLAYER;
    visualizasion = 'T';
    healthPoints = 3;
    this->notifyHealthPoints();
}

void PlayerTank::hit()
{
    --healthPoints;
    this->notifyHealthPoints();
    if (healthPoints < 1)
    {
        nextAction = A_DESTROY;
        observer.get()->updateGameOver();
    }
}

void PlayerTank::notifyHealthPoints()
{
    observer.get()->updateHealthPoints( this->getHealthPoints() );
}
