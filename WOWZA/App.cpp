#include "App.h"
#include "Bar.hpp"
#include "Ball.h"

Bar play1 = *new Bar(-0.8);
Bar play2 = *new Bar(0.8);

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
    
    play1.draw();
    play2.draw();
    
    pong.draw();
    

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

void App::keyPress(unsigned char key) {
    if (key == 119){//w
        play1.moveU();
        redraw();
    }
    if (key == 115){//s
        play1.moveD();
        redraw();
    }
    if (key == 105){//i
        play2.moveU();
        redraw();
    }
    if (key == 107){//k
        play2.moveD();
        redraw();
    }
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}
