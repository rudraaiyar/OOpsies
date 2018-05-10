#ifndef shape_h
#define shape_h

#if defined WIN32
#include <freeglut.h>
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <SOIL.h>
#else
#include <GL/freeglut.h>
#include <SOIL.h>
#endif

//this is class is the parent of ball and bar


class shape{
protected:
  float x;
  float y;
  float w;
  float h;
  bool direction;
  GLuint texture_id; //soil purposes

public:
  shape(const char*, float, float, float, float,bool);
  virtual ~shape();
// getters and setter
  void setXPos(float);
  void setYPos(float);
  float getXPos()const;
  float getYPos()const;
  void changePos();
  virtual void draw();
  bool contains(float, float); //checks whether or not obj hits thingy

};

#endif

//can we have the A, we didnt use your template for the animations :) we did it from scratch
