#ifndef game_h
#define game_h

#include "Bar.hpp"
#include "Ball.h"
#include "AnimatedRect.h"

class game{
    
    //they boys are objects 
    Bar* play1;
    Bar* play2;
    Bar* constBar;
    Ball* pong;
    shape* background;
    shape* startScreen;
    shape* power;
    shape* p1win;
    shape* p2win;
    AnimatedRect* p1score;
    AnimatedRect* p2score;
    int AI;
    int level;
    bool start;
    bool AIVal;
    bool levelVal;
    bool powerSpawn;
    bool gameOver;
public:
    game();
    ~game();

    void draw();
    void collisionCheck(); //boing
    void powerCheck(); //does the power up stuff
    void powerTimer(int sec); //timer that caused a ton of issues
    void movePlay1(int key); //how we move a playa
    void movePlay2(unsigned char key); //how we move anotha play
    void onClickStart(unsigned char); //start instructionnnss
    void autoPlay2Move(); //ai purposes
    void endGame();
};


#endif

//this is sthe file that we put our crap in to make sure App.cpp is clean
