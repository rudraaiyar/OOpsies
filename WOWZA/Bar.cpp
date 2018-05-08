#include "Bar.hpp"

using namespace std;

Bar::Bar(const char* filename, float x1,float y1, float w, float h, bool direction=0)
  :shape(filename,x1,y1,w,h,direction) {
    score=0;
}
Bar::~Bar(){
  
}
void Bar::updateScore(){
  score++;
}

void Bar::moveU()
{
    if (y>=1.0)
        y+=0;
    else y+=.18;
}

void Bar::moveD()
{
    if (y-h<= -1.0)
        y-=0;
    else y-=.18;
}

float Bar::getWidth() const{
  return w;
}
float Bar::getHeight() const{
  return h;
}
int Bar::getScore() const{
  return score;
}
bool Bar::contains(float mx,float my){
  if((mx >= x && mx <= x+w) && (my <= y && my >= y - h)){
      return true;
  }
  else{
    return false;
  }
}
