#ifndef AnimatedRect_h
#define AnimatedRect_h

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

#include "shape.h"
class AnimatedRect : public shape{

    int rows;
    int cols;

    int curr_row;
    int curr_col;

    bool complete;
    bool animating;
    bool start;
public:
    AnimatedRect (const char*, int, int, float, float, float, float);

    bool done();

    void draw();

    void advance();

    void incY();

    void reset();

    void animate();

    void stop();

    bool started(); //this is the only addition we did to this file
};

#endif
