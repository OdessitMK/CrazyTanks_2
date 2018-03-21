#ifndef ENEMYTANK_H
#define ENEMYTANK_H

#include "object.h"
#include "subjectofobservation.h"

class EnemyTank : public Object, SubjectOfObservation
{
public:
    EnemyTank(shared_ptr< ObserverPlayer > observerIn, int xIn, int yIn,  int healthPointsIn = 1, DIRECTION directionIn = UP, ACTION nextActionIn = A_STOP);
    void hit();
};

#endif // ENEMYTANK_H
