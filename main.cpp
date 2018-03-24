#include "activeobjects.h"
#include "renderer.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    MoveWindow( GetConsoleWindow(), 300,300, 500, 500, TRUE );

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
    cout<< endl <<"---GAME OVER---"<< endl;
    int x;
    cin>>x;
    return 0;
}
