#include "game.h"

game::game(){

  start=0;
  AIVal=0;
  levelVal=0;
  startScreen = new shape("instruction_text.png",-1,0.5,2,1,0);

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
  delete startScreen;
}

void timer(int value){
  if(value == 100 || value == 75 || value==20){
    glutTimerFunc(value,timer,0);
  }
  return;
}

//calls all the appropriate draw functions
void game::draw(){
  if(start == 0){
    startScreen->draw();
  }
  else{
  play1->draw();
    if (AI==1) {  
      this->autoPlay2Move();
      constBar->draw();
    }else if(AI ==2){
      play2->draw();
    }
    //bg->draw();
    pong->animate();
    background->draw();

    //since ball will always be called we do a collisionCheck at the end
    collisionCheck();
  }
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
void game::movePlay2(unsigned char key){
  if(key == GLUT_KEY_UP){
    play2->moveU();
  }
  else if(key == GLUT_KEY_DOWN){
    play2->moveD();
  }
}
void game::movePlay1(int key){
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

void game::onClickStart(unsigned char key){
  if(AIVal == 0){
    if(key == '1' || key == '2'){
      AI=key-48;
      std::cout<<"AI "<<AI<<std::endl;
      AIVal=1;
    }
    else{
      delete startScreen;
      exit(0);
    }
  }
  else if(levelVal == 0){
    if(key == '1' || key == '2'  || key == '3'){
      level = key-48;
      std::cout<<"level "<<level<<std::endl;
      levelVal = 1;
    }
    else{
      delete startScreen;
      exit(0);
    }
    if(levelVal == 1 && AIVal ==1){
      start=1;
      play1 = new Bar("Plank.png",-0.95, 0.0, 0.1, 0.3,0);
      if(AI==2){
        play2 = new Bar("Plank.png",0.8, 0.0,0.1,0.3,1);
      }
      else if(AI==1){
        constBar = new Bar("Plank.png",0.8, 0.0,0.1,0.3,1);
      }
      background = new shape("grid.png",-1,1,5,3,0);
      pong = new Ball(level,"ball.png", 0.0,0.0, 0.07, 0.07,0);
    }
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
