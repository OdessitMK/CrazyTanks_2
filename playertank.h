#ifndef PLAYERTANK_H
#define PLAYERTANK_H

#include "object.h"
#include "subjectofobservation.h"

class PlayerTank : public Object, SubjectOfObservation
{
public:
    PlayerTank(shared_ptr< ObserverPlayer > observerIn, const int &xIn, const int &yIn,  const int &healthPointsIn = 1, const DIRECTION &directionIn = UP, const ACTION &nextActionIn = A_STOP);
    void hit();
    void notifyHealthPoints();
};

#endif // PLAYERTANK_H
