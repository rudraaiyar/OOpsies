#ifndef game_h
#define game_h

#include "Bar.hpp"
#include "Ball.h"
#include "TexRect.h"

class game{
    Bar* play1;
    Bar* play2;
    Bar* constBar;
    Ball* pong;
    int AI;
    int level;
public:
    game(int,int);
    ~game();

    void draw();
    void collisionCheck();
    void movePlay1(int key);
    void movePlay2(unsigned char key);
    void autoPlay2Move();
    void endGame();
    TexRect* bg;
};


#endif
