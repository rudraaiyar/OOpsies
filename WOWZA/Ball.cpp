#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "Ball.h"
#include <math.h>
#include <stdlib.h>

#define PI 3.141592653
#include<iostream>
using namespace std;


Ball::Ball(int speed){
  x=0;
  y=((rand() % 100)/100.0);
  //yPos=(rand() % 100)/100.0;
  vel=((speed * 0.01) + 0.02);
  //generates radom angle
  do{
    angle=(rand() % 36000)/100.0;
  }while(angle == 0 || angle == 90 || angle == 180 || angle == 360);
  cout<<"speed "<<speed<<" angle "<<angle<<endl;
  velX=vel*cosf((angle * PI /180.0));
  velY=vel*sinf((angle * PI /180.0));
  cout<<"vel, velX velY "<< vel<<" "<<velX<<" "<<velY<<endl;

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

void Ball::draw()
{
    glColor3d(1.0, 1.0, 0.0);
        glBegin(GL_LINE_LOOP);
        for (int j = 0; j < 50;  j++)
        {
            float theta = 2.0f*3.1415926f* float(j) / float(50);
            float x = 0.05*cosf(theta);
            float y = 0.05*sinf(theta);
            glVertex3f(x + this->x, y + this->y, -0.1);
        }
        glEnd();
        moveBall();
        //collisionCheck();
}
void Ball::flipXVel(){
  velX*=-1;
}
void Ball::flipYVel(){
  velY*=-1;
}
