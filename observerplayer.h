#ifndef OBSERVERPLAYER_H
#define OBSERVERPLAYER_H

class ObserverPlayer
{
protected:
    int healthPoints;
    int enemyCounter;
    int score;
    bool gameOver;
public:
    ObserverPlayer();
    int getScore();
    int getEnemyCounter();
    bool getGameOver();
    void updateEnemyCounterIncrease();
    void updateEnemyCounterDecrease();
    void updateHealthPoints(int healthPointsIn);
    void updateGameOver();
    int getHealthPoints();
};

#endif // OBSERVERPLAYER_H
