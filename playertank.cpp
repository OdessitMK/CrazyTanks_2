#include "playertank.h"


PlayerTank::PlayerTank(shared_ptr<ObserverPlayer> observerIn, int xIn, int yIn, int healthPointsIn, DIRECTION directionIn, ACTION nextActionIn ): Object( xIn, yIn, healthPointsIn, directionIn, nextActionIn ), SubjectOfObservation(observerIn)
{
    type = PLAYER;
    visualizasion = 'T';
}
