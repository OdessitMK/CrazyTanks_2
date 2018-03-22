#include "observerplayer.h"

ObserverPlayer::ObserverPlayer():enemyCounter(0), score(0), gameOver(false), victory(false)
{

}

int ObserverPlayer::getScore()
{
    return score;
}

bool ObserverPlayer::getGameOver()
{
    return gameOver;
}

bool ObserverPlayer::getVictory()
{
    return victory;
}

void ObserverPlayer::updateEnemyCounterIncrease()
{
    ++enemyCounter;
}

void ObserverPlayer::updateEnemyCounterDecrease()
{
    --enemyCounter;
    ++score;
    if ( enemyCounter < 1 )
    {
        victory = true;
        updateGameOver();
    }
}

void ObserverPlayer::updateHealthPoints(const int &healthPointsIn)
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
