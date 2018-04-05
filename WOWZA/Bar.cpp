#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "Bar.hpp"

using namespace std;

Bar::Bar(float x1, float y1, float w, float h) {
    x = x1;
    y = y1;
    height = h;
    width = w;
}

//contains which checks if in or nah
bool Bar::hit(float xx, float yy)
{
    if (xx >= x && xx <= x + width && yy <= y && yy >= y - height)
        return true;
    else
        return false;
}
void Bar::draw()
{

    glColor3d(1.0, 0.6, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+width, y);
    glVertex2f(x+width, y-height);
    glVertex2f(x, y-height);
    
    glEnd();
    
}

void Bar::moveR(float xx)
{
    xx++;
}
void Bar::moveL(float xx)
{
    xx--;
}
