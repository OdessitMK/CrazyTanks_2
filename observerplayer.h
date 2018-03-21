#ifndef OBSERVERPLAYER_H
#define OBSERVERPLAYER_H

#include "PlayerInput.h"

class ObserverPlayer : public PlayerInput
{
protected:
    int healthPoints;
    int enemyCounter;
    int score;
    bool gameOver;
public:
    ObserverPlayer();
    int getScore();
    void updateEnemyCounterIncrease();
    void updateEnemyCounterDecrease();
    void updateHealthPoints(int healthPointsIn);
    void updateGameOver();
    int getHealthPoints();
};

#endif // OBSERVERPLAYER_H
