#include "App.h"
#include "Bar.hpp"
#include "Ball.h"
#include <iostream>

using namespace std;

Bar play1 = *new Bar(-0.8, 0.0,0.3);
Bar play2 = *new Bar(0.8, 0.0,0.3);
Bar constBar =*new Bar(0.8, .95, 1.9);

Ball pong = *new Ball;

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    
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
    
    int AI;
    cout<< "Single or Two Player? (1 or 2)"<<endl;
    cin>>AI;
    if (AI==1) {
        play1.draw();
        constBar.draw();
        pong.draw();
    }else if(AI ==2){
        play1.draw();
        play2.draw();
        pong.draw();
    }else{
        exit(0);
    }
    
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
    switch(key) {
        case GLUT_KEY_UP:
             play1.moveU();//key up
            break;
        case GLUT_KEY_DOWN:
             play1.moveD();   // key down
            break;
        default:
              // null
            break;
    }
    redraw();
}

void App::keyPress(unsigned char key) {
   
    if (key == 119){//w
        play2.moveU();
    }
    if (key == 115){//s
        play2.moveD();
    }
    
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
    redraw();
}
