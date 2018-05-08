#include "game.h"

game::game(int AI, int level){

  if (level>3 || level<1 || AI >2 || AI < 1){
    exit(0);
  }
  play1 = new Bar("Plank.png",-0.95, 0.0, 0.1, 0.3,0);
  if(AI==2){
    play2 = new Bar("Plank.png",0.8, 0.0,0.1,0.3,1);
  }
  else if(AI==1){

    constBar = new Bar("Plank.png",0.8, 0.0,0.1,0.3,1);
  }
  pong = new Ball(level,"ball.png", 0.0,0.0, 0.07, 0.07,0);

  background = new shape("grid.png",-1,1,5,3,0);
    
  power =new shape("power.png", 0,0,.25,.25,0);
    
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
  delete background;
  delete power;
}

void timer(int value){
  if(value == 100 || value == 75 || value==20){
    glutTimerFunc(value,timer,0);
  }
  return;
}

//calls all the appropriate draw functions
void game::draw(){

  play1->draw();
  if (AI==1) {
    this->autoPlay2Move();
    constBar->draw();
  }else if(AI ==2){
    play2->draw();
  }
  power->draw();
  pong->animate();
  background->draw();

  //since ball will always be called we do a collisionCheck at the end
  collisionCheck();
  powerCheck();
}

void game::collisionCheck(){
  //This will check if the ball makes contact with one of the bars
 if(play1->contains(pong->getXPos(), pong->getYPos()) ||
  (AI==2 && play2->contains(pong->getXPos(), pong->getYPos())) ||
  (AI==1 && constBar->contains(pong->getXPos(), pong->getYPos()))){
    pong->flipXVel();
  }
  else if(pong->getXPos() <=-1 ){
    if(AI==2){
      play2->updateScore();
      endGame();
    }
    else if(AI==1){
      constBar->updateScore();
      endGame();
    }

    pong->resetBall();
  }
  else if(pong->getXPos() >=1){
    play1->updateScore();
    endGame();
    pong->resetBall();
  }

  else if(pong->getYPos() >=1 || pong->getYPos()<=-1){
      pong->flipYVel();
  }
}
/************/
void game::powerCheck(){
    if (pong->getXPos() == power->getXPos() || pong->getYPos() == power->getYPos()){
        pong->setSpeed
        delete power;
        draw();
    }
}

void game::powerTimer(int sec) {
    clock_t endwait;
    endwait = clock () + sec * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}
/************/

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
void game::autoPlay2Move(){
  if(constBar->getYPos()-constBar->getHeight() > pong->getYPos()){
    constBar->moveD();
  }
  else if(constBar->getYPos() < pong->getYPos()){
    constBar->moveU();
  }
}
//TODO::Add some end game screen
void game::endGame(){
  if(AI==1 && constBar->getScore()==3){
    std::cout<<"Player 2 won"<<std::endl;
    this->~game();
    exit(0);
  }
  else if(AI ==2 && play2->getScore()==3){
    std::cout<<"Player 2 won"<<std::endl;
    this->~game();
    exit(0);
  }
  else if(play1->getScore()==3){
    std::cout<<"Player 1 won"<<std::endl;
    this->~game();
    exit(0);
  }
}
