#ifndef OBSERVERPLAYER_H
#define OBSERVERPLAYER_H

class ObserverPlayer
{
protected:
    int healthPoints;
    int enemyCounter;
    int score;
    bool gameOver;
    bool victory;
public:
    ObserverPlayer();
    int getScore();
    bool getGameOver();
    bool getVictory();
    void updateEnemyCounterIncrease();
    void updateEnemyCounterDecrease();
    void updateHealthPoints(int healthPointsIn);
    void updateGameOver();
    int getHealthPoints();
};

#endif // OBSERVERPLAYER_H
