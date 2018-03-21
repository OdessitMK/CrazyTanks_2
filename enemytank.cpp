#include "enemytank.h"

EnemyTank::EnemyTank(shared_ptr<ObserverPlayer> observerIn, int xIn, int yIn, int healthPointsIn, DIRECTION directionIn, ACTION nextActionIn): Object( xIn, yIn, healthPointsIn, directionIn, nextActionIn ), SubjectOfObservation(observerIn)
{
    type = AI;
    visualizasion = 'O';
    observer.get()->updateEnemyCounterIncrease();
}

void EnemyTank::hit()
{
    --healthPoints;
    if (healthPoints < 1)
    {
        nextAction = A_DESTROY;
        observer.get()->updateEnemyCounterDecrease();
    }
}
