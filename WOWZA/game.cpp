#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "game.h"

game::game(int AI, int level){
  if (level>3 || level<1 || AI >2 || AI < 1){
    exit(0);
  }
  play1 = new Bar(-0.95, 0.0,0.3);
  if(AI==2){
    play2 = new Bar(0.8, 0.0,0.3);
  }
  else if(AI==1){
    constBar = new Bar(0.9, 1, 2);
  }
  pong = new Ball(level);
  this->AI=AI;
  this->level=level;
}
game::~game(){
  delete play1;
  if(AI==2){
    delete play2;
  }
  else if(AI==1){
    delete constBar;
  }
  delete pong;
}

//calls all the appropriate draw functions
void game::draw(){
  if (AI==1) {
      if (level ==1){
          play1->draw();
          constBar->draw();
          pong->draw();
      }else if(level==2){
          play1->draw();
          constBar->draw();
          pong->draw();
      }else if(level ==3){
          play1->draw();
          constBar->draw();
          pong->draw();
      }
      else{
          exit(0);
      }
  }else if(AI ==2){
      if (level ==1){
          play1->draw();
          play2->draw();
          pong->draw();
      }else if(level==2){
          play1->draw();
          play2->draw();
          pong->draw();
      }else if(level ==3){
          play1->draw();
          play2->draw();
          pong->draw();
      }
      else{
          exit(0);
      }
  }
  //since ball will always be called we do a collisionCheck at the end
  collisionCheck();
}

void game::collisionCheck(){
  //This will check if the ball makes contact with one of the bars
 if(play1->contains(pong->getXPos(), pong->getYPos()) ||
  (AI==2 && play2->contains(pong->getXPos(), pong->getYPos())) ||
  (AI==1 && constBar->contains(pong->getXPos(), pong->getYPos()))){
    pong->flipXVel();
  }
  //comment out once scoring system is made/ball respawn is done
  /*if(pong->getXPos() >=1 || pong->getXPos()<=-1){
      pong->flipXVel();
  }
*/
  else if(pong->getXPos() >=1 && AI==2){
    play2->updateScore();
    pong->resetBall();
  }
  else if(pong->getXPos() <=-1){
    play1->updateScore();
    pong->resetBall();
  }

  if(pong->getYPos() >=1 || pong->getYPos()<=-1){
      pong->flipYVel();
  }
}
void game::movePlay1(int key){
  if(key == GLUT_KEY_UP){
    play2->moveU();
  }
  else if(key == GLUT_KEY_DOWN){
    play2->moveD();
  }
}
void game::movePlay2(unsigned char key){
  if(key == 119){
    play1->moveU();
  }
  else if(key == 115){
    play1->moveD();
  }
}
