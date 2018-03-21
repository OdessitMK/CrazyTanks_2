#ifndef PLAYERTANK_H
#define PLAYERTANK_H

#include "object.h"
#include "subjectofobservation.h"

class PlayerTank : public Object, SubjectOfObservation
{
public:
    PlayerTank(shared_ptr< ObserverPlayer > observerIn, int xIn, int yIn,  int healthPointsIn = 1, DIRECTION directionIn = UP, ACTION nextActionIn = A_STOP);
    void hit();
    void notifyHealthPoints();
};

#endif // PLAYERTANK_H
