#include "gold.h"

Gold::Gold(shared_ptr<ObserverPlayer> observerIn, int xIn, int yIn, int healthPointsIn, DIRECTION directionIn, ACTION nextActionIn ): Object( xIn, yIn, healthPointsIn, directionIn, nextActionIn ), SubjectOfObservation(observerIn)
{
    type = GOLD;
    visualizasion = '$';
}

void Gold::hit()
{
    --healthPoints;
    if (healthPoints < 1)
    {
        nextAction = A_DESTROY;
        observer.get()->updateGameOver();
    }
}
