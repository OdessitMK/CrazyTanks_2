#ifndef GOLD_H
#define GOLD_H

#include "object.h"
#include "subjectofobservation.h"

class Gold : public Object, SubjectOfObservation
{
public:
    Gold(shared_ptr< ObserverPlayer > observerIn, int xIn, int yIn,  int healthPointsIn = 1, DIRECTION directionIn = UP, ACTION nextActionIn = A_STOP);
    void hit();
};

#endif // GOLD_H
