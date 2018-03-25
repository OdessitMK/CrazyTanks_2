#ifndef ACTIVEOBJECTS_H
#define ACTIVEOBJECTS_H

#include <memory>
#include <list>
#include <ctime>

#include "battlefield.h"
#include "observerplayer.h"
#include "inputinterface.h"

using namespace std;

class ActiveObjects
{
protected:
    list <shared_ptr<Object> > listOfObjects;
    shared_ptr<Battlefield> battlefield;
    shared_ptr<ObserverPlayer> observer;
    InputInterface inputInterface;
    clock_t time1, time2;
public:
    ActiveObjects( shared_ptr<Battlefield> battlefieldIn, shared_ptr<ObserverPlayer> observerIn );
    bool nearCheck(const int &x, const int &y, const int &distance = 3);
    void addObject(shared_ptr<Object> objIn);
    void createStronghold();
    void setup();
    void iterateActive();
    void makeAction(list<shared_ptr<Object> >::iterator &it);
};
#endif // ACTIVEOBJECTS_H
