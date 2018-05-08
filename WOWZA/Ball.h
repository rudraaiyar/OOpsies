#ifndef Ball_h
#define Ball_h


//this is also bby of shape

#include "shape.h"

class Ball: public shape {
    int speed;
    float vel;
    float velX;
    float velY;
    float angle;
	int count=0;
	float r;

public:
    Ball(int,const char*,float,float,float,float,bool);
    ~Ball();
    void setVel(); //sets velocity
    void speedUp();//increases speed
    void moveBall(); //move me
    int getSpeed() const; //getty me
    void resetBall(); //resets to og position
    void animate(); //makes me look good
    void flipXVel(); //flippy flop
    void flipYVel();

};

#endif
