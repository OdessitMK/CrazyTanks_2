#ifndef SUBJECTOFOBSERVATION_H
#define SUBJECTOFOBSERVATION_H

#include "observerplayer.h"

class SubjectOfObservation
{
protected:
    shared_ptr< ObserverPlayer > observer;
public:
    SubjectOfObservation(shared_ptr< ObserverPlayer > observerIn);
    void notifyEnemyCounterIncrease();
    void notifyEnemyCounterDecrease();
    void notifyGameOver();
};

#endif // SUBJECTOFOBSERVATION_H
