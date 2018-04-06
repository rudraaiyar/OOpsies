#ifndef Circle_h
#define Circle_h

#include <math.h>

class Circle {
public:
	Circle(){}
	float x;
	float y;
	Circle(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	void draw()
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
	
};

#endif 












