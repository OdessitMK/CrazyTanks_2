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
public:
    ActiveObjects( shared_ptr<Battlefield> battlefieldIn, shared_ptr<ObserverPlayer> observerIn );
    //void iterateActive(PlayerInput playerInput);
    bool nearCheck(int x, int y, int distance = 3);
    void AddObject(shared_ptr<Object> objIn);
    void createStronghold();
    void setup();

};
#endif // ACTIVEOBJECTS_H
