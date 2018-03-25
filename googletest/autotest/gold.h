#ifndef GOLD_H
#define GOLD_H

#include "object.h"
#include "subjectofobservation.h"

class Gold : public Object, SubjectOfObservation
{
public:
    Gold(shared_ptr< ObserverPlayer > observerIn, const int &xIn, const int &yIn, const int &healthPointsIn = 1, const DIRECTION &directionIn = UP, const ACTION &nextActionIn = A_STOP);
    void hit();
};

#endif // GOLD_H
