#include "Ball.h"
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <time.h>
#include <unistd.h>

#define PI 3.141592653
#include<iostream>
using namespace std;


Ball::Ball(int speed, const char*filename,float x,float y, float w, float h, bool direction=0)
  :shape(filename,x,y,w,h,direction){
  resetBall();
  vel=((speed * 0.01) + 0.02);
  velX=vel*cosf((angle * PI /180.0));
  velY=vel*sinf((angle * PI /180.0));
}
Ball::~Ball(){
}
void Ball::setSpeed(){
  vel=(speed * 0.02)+0.04;
}
//Ball(float x, float y);
void Ball::setVel(){
    velX=vel*cos((angle * PI /180.0));
    velX=vel*sin((angle * PI /180.0));
}
void Ball::moveBall(){
    x+=velX;
    y+=velY;
}
int Ball::getSpeed() const{
  return speed;
}
void Ball::resetBall(){
  x=0;
  y=((rand() % 100)/100.0);
  //generates radom angle
  do{
    angle=(rand() % 36000)/100.0;
  }while(angle == 0 || angle == 90 || angle == 180 || angle == 360);
  flipXVel();
}

void Ball::animate()
{
  draw();
  moveBall();
}


void Ball::flipXVel(){
  velX*=-1;
}
void Ball::flipYVel(){
  velY*=-1;
}

void Ball::powerUp(){
	powerTimer(15);
	//draw(0.09);
	powerTimer(5);
	draw();
	powerTimer(15);
	//draw(0.03);
	powerTimer(5);
	draw();
	powerUp();
}

void Ball::powerTimer(int sec) {
  clock_t endwait;
  endwait = clock () + sec * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}
