#include "gold.h"

Gold::Gold(shared_ptr<ObserverPlayer> observerIn, const int &xIn, const int &yIn, const int &healthPointsIn, const DIRECTION &directionIn, const ACTION &nextActionIn ): Object( xIn, yIn, healthPointsIn, directionIn, nextActionIn ), SubjectOfObservation(observerIn)
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
