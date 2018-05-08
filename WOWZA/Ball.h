#ifndef Ball_h
#define Ball_h

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
    void setVel();
    void setSpeed();
    void moveBall();
    int getSpeed() const;
    void resetBall();
    void animate();
    void flipXVel();
    void flipYVel();
	void powerUp();
	void powerTimer(int sec);
	//void draw(float r);
};

#endif
