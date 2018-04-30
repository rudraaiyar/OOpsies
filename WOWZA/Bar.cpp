  #if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "Bar.hpp"

using namespace std;

Bar::Bar(float x1,float y1, float h) {
    x = x1;
    y = y1;
    height = h;
    score=0;
}

void Bar::updateScore(){
  score++;
}
void Bar::draw()
{
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+width, y);
    glVertex2f(x+width, y-height);
    glVertex2f(x, y-height);

    glEnd();

}

void Bar::moveU()
{
    if (y>=1.0)
        y+=0;
    else y+=.18;
}

void Bar::moveD()
{
    if (y-height<= -1.0)
        y-=0;
    else y-=.18;
}

float Bar::getWidth() const{
  return width;
}
float Bar::getHeight() const{
  return height;
}
int Bar::getScore() const{
  return score;
}
bool Bar::contains(float mx,float my){
  if((mx >= x && mx <= x+width) && (my <= y && my >= y - height)){
      return true;
  }
  else{
    return false;
  }
}
