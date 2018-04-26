#ifndef Ball_h
#define Ball_h

//#include "TexRect.h"
#include "GlutApp.h"

class Ball {
    int speed;
    float xPos;
    float yPos;
    float vel;
    float velX;
    float velY;
    float angle;


public:
    Ball(int);
    void setVel();
    void setSpeed();
    void moveBall();
    void draw();
    float getXPos() const;
    float getYPos()const;
    void flipXVel();
    void flipYVel();
};

#endif
