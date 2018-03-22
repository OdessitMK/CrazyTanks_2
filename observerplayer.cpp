#include "observerplayer.h"

ObserverPlayer::ObserverPlayer():enemyCounter(0), score(0), gameOver(false)
{

}

int ObserverPlayer::getScore()
{
    return score;
}

int ObserverPlayer::getEnemyCounter()
{
    return enemyCounter;
}

bool ObserverPlayer::getGameOver()
{
    return gameOver;
}

void ObserverPlayer::updateEnemyCounterIncrease()
{
    ++enemyCounter;
}

void ObserverPlayer::updateEnemyCounterDecrease()
{
    --enemyCounter;
    ++score;
    if ( enemyCounter < 1 ) updateGameOver();
}

void ObserverPlayer::updateHealthPoints(int healthPointsIn)
{
    healthPoints = healthPointsIn;
}

void ObserverPlayer::updateGameOver()
{
    gameOver = true;
}

int ObserverPlayer::getHealthPoints()
{
    return healthPoints;
}
