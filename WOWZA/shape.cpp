#include "shape.h"

shape::shape(const char* filename, float x, float y, float w, float h, bool direction){ //constructor
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);

  texture_id = SOIL_load_OGL_texture (
   filename,
   SOIL_LOAD_AUTO,
   SOIL_CREATE_NEW_ID,
   SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
   );

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->direction=direction;
}
shape::~shape(){ //deconstorutretertertre

}
void shape::setXPos(float xPos){
  this->x=x;
}
void shape::setYPos(float yPos){
  this->y=y;
}
float shape::getXPos()const{
  return x;
}
float shape::getYPos()const{
  return y;
}
void shape::draw(){ //hwo we draw
  glBindTexture( GL_TEXTURE_2D, texture_id );
  glEnable(GL_TEXTURE_2D);

  glColor3d(1.0, 1.0, 1.0);
  glBegin(GL_QUADS);
  glTexCoord2f(0+direction,0);
  glVertex2f(x, y-h);

  glTexCoord2f(0+direction,1);
  glVertex2f(x, y);

  glTexCoord2f(1-direction,1);
  glVertex2f(x+w, y);

  glTexCoord2f(1-direction,0);
  glVertex2f(x+w, y-h);

  glEnd();

  glDisable(GL_TEXTURE_2D);
}

bool shape::contains(float mx,float my){
    if((mx >= x && mx <= x+w) && (my <= y && my >= y - h)){
        return true;
    }
    else{
        return false;
    }
}
