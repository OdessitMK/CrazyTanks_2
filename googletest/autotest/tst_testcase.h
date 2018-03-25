#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "bullet.h"
#include "enemytank.h"
#include "activeobjects.h"
#include "renderer.h"
#include <iostream>
#include <windows.h>

using namespace testing;
using namespace std;


TEST(TestCaseObject, TestNameProgram)
{
    MoveWindow( GetConsoleWindow(), 300,300, 500, 500, TRUE );

    shared_ptr<Battlefield> battlefield( new Battlefield(20, 20) );
    shared_ptr<ObserverPlayer> observerPlayer( new ObserverPlayer );
    Renderer renderer(battlefield, observerPlayer);
    ActiveObjects activeObjects(battlefield, observerPlayer);
    activeObjects.setup();

    while( !observerPlayer.get()->getGameOver() )
    {
            activeObjects.iterateActive();
            renderer.DrawInterface();
            EXPECT_LT(observerPlayer.get()->getScore(), 4);
            EXPECT_LT(observerPlayer.get()->getHealthPoints(), 4);
    }
    cout<< endl <<"---GAME OVER---"<< endl;
    system("cls");
}



TEST(TestCaseObject, TestNameCreateObject)
{
    shared_ptr<Object> testObject( new Object( 5, 10) ) ;
    EXPECT_EQ( testObject.get()->getAction() , A_STOP );
    testObject.get()->changeDirection(LEFT);
    testObject.get()->changeAction(A_DOWN);
    EXPECT_EQ( testObject.get()->getAction() , A_DOWN );
    EXPECT_EQ( testObject.get()->getAction() , A_STOP );
}

TEST(TestCaseObject, TestNameEnemyTankShoot)
{
    shared_ptr<ObserverPlayer> observer(new ObserverPlayer() );
    shared_ptr<EnemyTank> testTank( new EnemyTank( observer, 5, 10, 9999) ) ;
    testTank.get()->changeDirection(LEFT);
    shared_ptr<Bullet> testBullet( new Bullet(testTank) ) ;
    EXPECT_EQ( testBullet.get()->getX() , 4 );
    EXPECT_EQ( testBullet.get()->getY() , 10 );
    EXPECT_EQ( testBullet.get()->getVisualization() , 'o' );
    EXPECT_EQ( testBullet.get()->getType() , AI_BULLET );
    EXPECT_EQ( testBullet.get()->getHealthPoints() , 0 );
    EXPECT_EQ( testBullet.get()->getAction() , A_LEFT );
    EXPECT_EQ( testBullet.get()->getAction() , A_LEFT );
}
