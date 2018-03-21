#ifndef ACTIVEOBJECTS_H
#define ACTIVEOBJECTS_H

#include <memory>
#include <list>
//#include "playerinput.h"
//#include "aiinput.h"

#include "battlefield.h"
#include "observerplayer.h"
#include "aiinput.h"

using namespace std;

class ActiveObjects
{
protected:
    list <shared_ptr<Object> > listOfObjects;
    shared_ptr<Battlefield> battlefield;
    shared_ptr<ObserverPlayer> observer;
    AiInput aiInput;
    PlayerInput playerInput;
public:
    ActiveObjects( shared_ptr<Battlefield> battlefieldIn, shared_ptr<ObserverPlayer> observerIn );
    bool nearCheck(int x, int y, int distance = 3);
    void addObject(shared_ptr<Object> objIn);
    void createStronghold();
    void setup();
    void iterateActive(bool input);

};
#endif // ACTIVEOBJECTS_H
