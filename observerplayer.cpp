#include "observerplayer.h"

ObserverPlayer::ObserverPlayer():enemyCounter(0), score(0), gameOver(false)
{

}

int ObserverPlayer::getScore()
{
    return score;
}

void ObserverPlayer::updateEnemyCounterIncrease()
{
    ++enemyCounter;
}

void ObserverPlayer::updateEnemyCounterDecrease()
{
    --enemyCounter;
    ++score;
}

void ObserverPlayer::updateGameOver()
{
    gameOver = true;
}
