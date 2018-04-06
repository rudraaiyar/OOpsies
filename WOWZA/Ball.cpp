#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "Ball.h"

using namespace std;

Ball::Ball(float x, float y)
{
    this->x = x;
    this->y = y;
}
void Ball::draw()
{
    glColor3d(1.0, 1.0, 0.0);
    
    glBegin(GL_LINE_LOOP);
    for (int j = 0; j < 50;  j++)
    {
        float theta = 2.0f*3.1415926f* float(j) / float(50);
        float x = 0.25*cosf(theta);
        float y = 0.25*sinf(theta);
        glVertex3f(x + this->x, y + this->y, -0.1);
    }
    glEnd();
    
}
