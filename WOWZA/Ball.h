#ifndef Ball_h
#define Ball_h

//#include "TexRect.h"
#include "GlutApp.h"
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
    Ball(int);
    void setVel();
    void setSpeed();
    void moveBall();
    int getSpeed() const;
    void resetBall();
    void draw();
    void flipXVel();
    void flipYVel();
	void powerUp();
	void powerTimer(int sec);
	void draw(float r);
};

#endif
