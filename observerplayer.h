#ifndef OBSERVERPLAYER_H
#define OBSERVERPLAYER_H

#include "PlayerInput.h"

class ObserverPlayer : public PlayerInput
{
protected:
    int enemyCounter;
    int score;
    bool gameOver;
public:
    ObserverPlayer();
    int getScore();
    void updateEnemyCounterIncrease();
    void updateEnemyCounterDecrease();
    void updateGameOver();
};

#endif // OBSERVERPLAYER_H
