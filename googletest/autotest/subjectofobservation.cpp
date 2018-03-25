#include "subjectofobservation.h"
#include <iostream>


SubjectOfObservation::SubjectOfObservation(shared_ptr<ObserverPlayer> observerIn):observer(observerIn)
{

}

void SubjectOfObservation::notifyEnemyCounterIncrease()
{
    observer.get()->updateEnemyCounterIncrease();
}

void SubjectOfObservation::notifyEnemyCounterDecrease()
{
    observer.get()->updateEnemyCounterDecrease();
}

void SubjectOfObservation::notifyGameOver()
{
    observer.get()->updateGameOver();
}
