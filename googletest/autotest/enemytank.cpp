#include "enemytank.h"

EnemyTank::EnemyTank(shared_ptr<ObserverPlayer> observerIn, const int &xIn, const int &yIn, const int &healthPointsIn, const DIRECTION &directionIn, const ACTION &nextActionIn): Object( xIn, yIn, healthPointsIn, directionIn, nextActionIn ), SubjectOfObservation(observerIn)
{
    type = AI;
    visualizasion = 'O';
    observer.get()->updateEnemyCounterIncrease();
    healthPoints = 1;
}

void EnemyTank::hit()
{
    --healthPoints;
    if ((healthPoints < 1) && ( nextAction !=A_DESTROY ))
    {
        nextAction = A_DESTROY;
        observer.get()->updateEnemyCounterDecrease();
    }
}
