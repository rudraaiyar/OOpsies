#include "game.h"
#include "time.h"
#include <iostream>
#include "math.h"


game::game(){ //this boy helps us init the stuff

  power =new shape("power.png", 0,0,.25,.25,0);

  p1score = new AnimatedRect("numbers-600.png", 3, 3, -0.2, 1, 0.2, 0.2);

  p2score = new AnimatedRect("numbers-600.png", 3, 3, 0, 1, 0.2, 0.2);
  start=0;
  AIVal=0;
  levelVal=0;

  powerSpawn=0;
  gameOver=0;

  powerSpawn=1;

  startScreen = new shape("instruction_text.png",-1,0.5,2,1,0);
  p1win = new shape("p1win.png", -1, 0.5, 2.0, 0.5, 0);
  p2win = new shape("p2win.png", -1, 0.5, 2.0, 0.5, 0);

}
game::~game(){ //this boy helps us prevent memory leaks
  delete play1;
  if(AI==2){
    delete play2;
  }
  else if(AI==1){
    delete constBar;
  }
  delete pong;
  delete background;

  if(powerSpawn == 1){
    delete power;
  }
  delete p1score;
  delete p2score;
}

void timer(int value){ //this boy is a timer
  if(value == 100 || value == 75 || value==20){
    glutTimerFunc(value,timer,0);
  }
  return;
}

//calls all the appropriate draw functions
void game::draw(){ //this boy draws our scene
  if(start == 0){
    startScreen->draw(); //for your knowledge to play game
  }
  else{

    if(gameOver){
        //this->~game();
        if(play2->getScore() == 4 || constBar->getScore() == 4)
          p2win->draw();
        else if(play1->getScore() ==4){
          p1win->draw();
        }
	      powerTimer(1);
         //exit(0);
	       //this->~game();
         //powerTimer(5);

    }

    if(play1->getScore() > 0){
      p1score->animate();
      p1score->draw();
    }
    play1->draw();
    if((AI==2 && play2->getScore() > 0) || (AI==1 && constBar->getScore() > 0)){
      p2score->animate();
      p2score->draw();
    }
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
    powerCheck(); //power boy makes you go 1.5 speedo
  }
}

void game::collisionCheck(){ //this boy helps us find which playa gonna make bank and win
  //This will check if the ball makes contact with one of the bars
 if(play1->contains(pong->getXPos(), pong->getYPos()) ||
  (AI==2 && play2->contains(pong->getXPos(), pong->getYPos())) ||
  (AI==1 && constBar->contains(pong->getXPos(), pong->getYPos()))){
    pong->flipXVel();
  }
  else if(pong->getXPos() <=-1 ){
    if(AI==2){
      play2->updateScore();
    }
    else if(AI==1){
      constBar->updateScore();
    }
    if(p2score->started()){
       p2score->advance();
    }
    endGame();
    pong->resetBall();
  }
  else if(pong->getXPos() >=1){
    play1->updateScore();
    if(p1score->started()){
       p1score->advance();
    }
    endGame();
    pong->resetBall();
  }

  else if(pong->getYPos() >=1 || pong->getYPos()<=-1){
      pong->flipYVel();
  }
}
/************/
void game::powerCheck(){ //this boy deals with tide pods and tells us whether we get the goods or nah
    if(powerSpawn == 0){
        powerSpawn=1;
        power = new shape("power.png", ((rand() % 190)/100.0 - 0.9),((rand() % 190)/100.0 - 0.9),.2,.2,0);
        //delete power;
    }
        power->draw();
    if(power->contains(pong->getXPos(), pong->getYPos())){
        pong->speedUp();
        powerSpawn=0;
        //pong->setSpeed();
        delete power;
    }

}

void game::powerTimer(int sec) { //this boy ruined our game, but in progress
    clock_t endwait;
    endwait = clock () + (sec) * CLOCKS_PER_SEC ;
    while (clock() < endwait) {
    }
}
/************/

void game::movePlay2(unsigned char key){ //move me with special keys upsie and downsies
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
void game::autoPlay2Move(){ //this boy fancy and he do the ai, but he a winner all the time
  if(constBar->getYPos()-constBar->getHeight() > pong->getYPos()){
    constBar->moveD();
  }
  else if(constBar->getYPos() < pong->getYPos()){
    constBar->moveU();
  }
}

void game::onClickStart(unsigned char key){ //helps with user input
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
void game::endGame(){ //this boy determines who wins the lottery and tells who the winner is
  if(AI==1 && constBar->getScore()==4){
    gameOver = true;
//    std::cout<<"Player 2 won"<<std::endl;
//    this->~game();
//    exit(0);
  }
  else if(AI ==2 && play2->getScore()==4){
    std::cout<<"Player 2 won"<<std::endl;
    this->~game();
    exit(0);
  }
  else if(play1->getScore()==4){
    std::cout<<"Player 1 won"<<std::endl;
    this->~game();
    exit(0);
  }
}
