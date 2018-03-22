#include "activeobjects.h"
#include "renderer.h"
#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    MoveWindow( GetConsoleWindow(), 500,500, 400, 400, TRUE );

    shared_ptr<Battlefield> battlefield( new Battlefield(20, 20) );
    shared_ptr<ObserverPlayer> observerPlayer( new ObserverPlayer );
    Renderer renderer(battlefield, observerPlayer);
    ActiveObjects activeObjects(battlefield, observerPlayer);
    activeObjects.setup();

    clock_t time1, time2;
    time1 = clock();

    while( !observerPlayer.get()->getGameOver() )
    {
        time2 = clock();
        if ((time2 - time1) > (CLOCKS_PER_SEC / 2))
        {
            activeObjects.iterateActive(false);
            renderer.DrawInterface();
            activeObjects.iterateActive(true);
            renderer.DrawInterface();
            time1 = time2;
        }
    }

    cout<< endl <<"---GAME OVER---"<< endl;
    int x;
    cin>>x;
    return 0;
}
