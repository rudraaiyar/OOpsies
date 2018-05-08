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
    shape* power;
    AnimatedRect* p1score;
    AnimatedRect* p2score;
    int AI;
    int level;
public:
    game(int,int);
    ~game();

    void draw();
    void collisionCheck();
    void powerCheck();
    void powerTimer(int sec);
    void movePlay1(int key);
    void movePlay2(unsigned char key);
    void autoPlay2Move();
    void endGame();
};


#endif
