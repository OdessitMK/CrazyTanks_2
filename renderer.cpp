#include "renderer.h"
#include "iostream"
#include <windows.h>

void setCurs(const int &x, const int &y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Renderer::Renderer(shared_ptr<Battlefield> battlefieldIn, shared_ptr<ObserverPlayer> playerIn):battlefield(battlefieldIn), player(playerIn)
{

}

void Renderer::DrawInterface()
{
    setCurs(0,0);
    timer = clock();
    cout <<"Game time: "<< (static_cast<long int>(timer)) / CLOCKS_PER_SEC / 60 << " minutes " << (static_cast<long int>(timer)) / CLOCKS_PER_SEC % 60 << " seconds";
    //battlefield.get()->drawField();
    setCurs(0, battlefield.get()->getHeight());
    cout << endl << " SCORE: " << player.get()->getScore() << " HP: " << player.get()->getHealthPoints() << endl;
    if ( player.get()->getVictory() == true )
        cout << "-----VICTORY-----" << endl;
}
