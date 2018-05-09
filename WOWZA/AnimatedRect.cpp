#include "AnimatedRect.h"
//same as angelo almost

AnimatedRect::AnimatedRect (const char* map_filename, int rows, int cols, float x=0, float y=0, float w=0.5, float h=0.5)
  :shape(map_filename,x,y,w,h,0){

    this->rows = rows;
    this->cols = cols;

    curr_row = 1;
    curr_col = 1;

    complete = false;
    animating = false;
    start = false;
}

bool AnimatedRect::done() {
    return complete;
}


void AnimatedRect::draw(){
    if (animating){
        glBindTexture( GL_TEXTURE_2D, texture_id );
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


        float xinc = 1.0/cols;
        float yinc = 1.0/rows;


        float top = 1 - yinc * (curr_row - 1);
        float bottom = 1 - yinc * curr_row;

        float left = xinc * (curr_col - 1);
        float right = xinc * curr_col;


        glBegin(GL_QUADS);

        glTexCoord2f(left, bottom);
        glVertex2f(x, y - h);

        glTexCoord2f(left, top);
        glVertex2f(x, y);

        glTexCoord2f(right, top);
        glVertex2f(x+w, y);

        glTexCoord2f(right, bottom);
        glVertex2f(x+w, y - h);

        glEnd();

        glDisable(GL_TEXTURE_2D);

	start = true;
    }
}

void AnimatedRect::incY(){
    y+=0.01;
}

void AnimatedRect::advance(){
    if (curr_col < cols){
        curr_col++;
    }
    else {
        if (curr_row < rows){
            curr_row++;
            curr_col = 1;
        }
        else{
            curr_row = 1;
            curr_col = 1;
        }
    }

    if (curr_row == rows && curr_col == cols){
        complete = true;
    }
}

void AnimatedRect::reset(){
    complete = false;
}

void AnimatedRect::animate(){
    animating = true;
}

void AnimatedRect::stop(){
    animating = false;
}

bool AnimatedRect::started(){ //this starts and ye
    return start;
}
