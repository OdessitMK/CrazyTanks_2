#include "activeobjects.h"
#include "renderer.h"

using namespace std;

int main()
{
    shared_ptr<Battlefield> battlefield( new Battlefield(20, 20) );
    shared_ptr<ObserverPlayer> observerPlayer( new ObserverPlayer );
    Renderer renderer(battlefield, observerPlayer);
    ActiveObjects activeObjects(battlefield, observerPlayer);
    activeObjects.setup();

    while( !observerPlayer.get()->getGameOver() )
    {
        activeObjects.iterateActive(false);
        renderer.DrawInterface();
        activeObjects.iterateActive(true);
        renderer.DrawInterface();
    }

    return 0;
}
