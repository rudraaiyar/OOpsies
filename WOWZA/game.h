#ifndef game_h
#define game_h

#include "Bar.hpp"
#include "Ball.h"

class game{
    Bar* play1;
    Bar* play2;
    Bar* constBar;
    Ball* pong;
    shape* background;
    shape* startScreen;
    int AI;
    int level;
    bool start;
    bool AIVal;
    bool levelVal;
public:
    game();
    ~game();

    void draw();
    void collisionCheck();
    void movePlay1(int);
    void movePlay2(unsigned char);
    void onClickStart(unsigned char);
    void autoPlay2Move();
    void endGame();
};


#endif
