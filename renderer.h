#ifndef RENDERER_H
#define RENDERER_H

#include "battlefield.h"
#include "observerplayer.h"

class Renderer
{
protected:
    shared_ptr<Battlefield> battlefield;
    shared_ptr<ObserverPlayer> player;
public:
    Renderer(shared_ptr<Battlefield> battlefieldIn, shared_ptr<ObserverPlayer> playerIn);
    void DrawInterface();
};

#endif // RENDERER_H
