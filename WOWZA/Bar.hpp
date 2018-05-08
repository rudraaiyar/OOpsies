//
//  Bar.hpp
//  glutapp
//
//  Created by Rudra Aiyar on 3/17/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Bar_hpp
#define Bar_hpp

#include <iostream>
#include "shape.h"

class Bar : public shape{
    //four float values
    int score;
public:

public:
    Bar(const char*, float, float, float, float, bool);
    ~Bar();
    //contains which checks if in or nah
    void updateScore();
    //void draw();
    void moveU();
    void moveD();
    float getWidth() const;
    float getHeight() const;
    int getScore() const;
    bool contains(float, float);
};

#endif /* Bar_hpp */
