#include "App.h"
//#include "Bar.hpp"
//#include "Ball.h"

#include <iostream>

using namespace std;

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;

  /*  cout<< "Single Player: use up and down arrow keys to move bar."<<endl;
    cout<< "Two Player: player 1 (up and down arrow keys), player 2 (w and s keyboard keys)."<<endl;
    cout<< "Single or Two Player (1 or 2): ";
    cin>>AI;
    cout<<"Level (1,2,3): ";
    cin>>level;
    */
    g=new game();
    //bg = new TexRect("pg.bmp", 1, 1, -1.0, 1.0, 2, 2);
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set Color
    glColor3d(1.0, 1.0, 1.0);
    g->draw();

    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;

    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;

    // Redraw the scene
    redraw();
}

void App::specialKeyPress(int key){
    //use key to see how play2 should move if at all
    g->movePlay2(key);
    redraw();
}
//This funciton is called all the time, which is why ball is able to move
void App::idle(){
  //g->draw();
  draw();
}

void App::keyPress(unsigned char key) {
  //use key to see how play1 should move if at all
    g->onClickStart(key);
    g->movePlay1(key);
    if (key == 27){
        // Exit the app when Esc key is pressed
        delete g;
        exit(0);
    }
    redraw();
}
