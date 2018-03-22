#ifndef ENEMYTANK_H
#define ENEMYTANK_H

#include "object.h"
#include "subjectofobservation.h"

class EnemyTank : public Object, SubjectOfObservation
{
public:
    EnemyTank(shared_ptr< ObserverPlayer > observerIn, const int &xIn, const int &yIn, const int &healthPointsIn = 1, const DIRECTION &directionIn = UP, const ACTION &nextActionIn = A_STOP);
    void hit();
};

#endif // ENEMYTANK_H
