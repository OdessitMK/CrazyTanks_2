#ifndef SUBJECTOFOBSERVATION_H
#define SUBJECTOFOBSERVATION_H

#include "observerplayer.h"
#include <memory>

using namespace std;

class SubjectOfObservation
{
protected:
    shared_ptr< ObserverPlayer > observer;
public:
    SubjectOfObservation(shared_ptr< ObserverPlayer > observerIn);
    void notifyEnemyCounterIncrease();
    void notifyEnemyCounterDecrease();
    void notifyGameOver();
    virtual void notifyHealthPoints(){}
};

#endif // SUBJECTOFOBSERVATION_H
