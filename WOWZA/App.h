#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "game.h"
//#include "TexRect.h"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    game* g;
    int AI;
    int level;

    // These are the events we want to handle
    void draw();
    void idle();
    void keyPress(unsigned char key); //for the user
    void mouseDown(float x, float y);//not used
    void mouseDrag(float x, float y);//not used
    void specialKeyPress(int key);//adds some special feats to this game boy



};

#endif
