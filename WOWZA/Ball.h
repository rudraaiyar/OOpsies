#ifndef Ball_h
#define Ball_h


class Ball {
    int speed;
    float xPos;
    float yPos;
    float vel;
    float velX;
    float velY;
    float angle;


public:
    Ball(int speed);
    void setVel();
    void moveBall();
    void collisionCheck();
    void draw();
};

#endif
