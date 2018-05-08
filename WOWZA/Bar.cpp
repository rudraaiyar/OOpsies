#include "Bar.hpp"

using namespace std;

Bar::Bar(const char* filename, float x1,float y1, float w, float h, bool direction=0)
  :shape(filename,x1,y1,w,h,direction) {
    score=0;
}
Bar::~Bar(){
  
}
void Bar::updateScore(){ //ups score
  score++;
}

void Bar::moveU() //moves the bby up
{
    if (y>=1.0)
        y+=0;
    else y+=.18;
}

void Bar::moveD() //moves bby down
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
int Bar::getScore() const{ //getty for score
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
