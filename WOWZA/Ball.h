#ifndef Ball_h
#define Ball_h

#include <math.h>

class Ball {
public:
    int speed;
public:
    Ball(int speed){}
	float x =0;
	float y =0;
    Ball(float x, float y);
    void draw();
};

#endif 












