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


class shape{
protected:
  float x;
  float y;
  float w;
  float h;
  bool direction;
  GLuint texture_id;

public:
  shape(const char*, float, float, float, float,bool);
  virtual ~shape();
  void setXPos(float);
  void setYPos(float);
  float getXPos()const;
  float getYPos()const;
  void draw();
};

#endif
