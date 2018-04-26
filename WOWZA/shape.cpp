#include "shape.h"

shape::shape(){
  x=0;
  y=0;
}
shape::shape(float x, float y){
  this->x=x;
  this->y=y;
}
void shape::setXPos(float xPos){
  this->x=x;
}
void shape::setYPos(float yPos){
  this->y=y;
}
float shape::getXPos()const{
  return x;
}
float shape::getYPos()const{
  return y;
}
