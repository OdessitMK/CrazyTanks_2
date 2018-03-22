#include "renderer.h"
#include "windows.h"
#include "ctime"
#include "iostream"


Renderer::Renderer(shared_ptr<Battlefield> battlefieldIn, shared_ptr<ObserverPlayer> playerIn):battlefield(battlefieldIn), player(playerIn)
{

}

void Renderer::DrawInterface()
{
    system("CLS");
    auto timer = clock();
    cout <<"Game time: "<< (static_cast<long int>(timer)) / CLOCKS_PER_SEC / 60 << " minutes " << (static_cast<long int>(timer)) / CLOCKS_PER_SEC % 60 << " seconds";
    battlefield.get()->drawField();
    cout << endl << " SCORE: " << player.get()->getScore() << " HP: " << player.get()->getHealthPoints() << endl;
    //cout << "-----VICTORY-----" << endl;
}
