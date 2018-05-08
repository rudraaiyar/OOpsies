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

//build me up
Ball::Ball(int speed, const char*filename,float x,float y, float w, float h, bool direction=0)
  :shape(filename,x,y,w,h,direction){
  resetBall();
  vel=((speed * 0.01) + 0.02);
  velX=vel*cosf((angle * PI /180.0));
  velY=vel*sinf((angle * PI /180.0));
}
//tear me down
Ball::~Ball(){
}

//sets a nice pace
void Ball::setSpeedo(float sec){
    vel=(sec * 0.02)+0.04;
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

