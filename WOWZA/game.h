#ifndef game_h
#define game_h

#include "Bar.hpp"
#include "Ball.h"
#include "AnimatedRect.h"

class game{
    Bar* play1;
    Bar* play2;
    Bar* constBar;
    Ball* pong;
    shape* background;
    shape* startScreen;
    shape* power;
    AnimatedRect* p1score;
    AnimatedRect* p2score;
    int AI;
    int level;
    bool start;
    bool AIVal;
    bool levelVal;
    bool powerSpawn;
public:
    game();
    ~game();

    void draw();
    void collisionCheck();
    void powerCheck();
    void powerTimer(int sec);
    void movePlay1(int key);
    void movePlay2(unsigned char key);
    void onClickStart(unsigned char);
    void autoPlay2Move();
    void endGame();
};


#endif
