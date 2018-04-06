//
//  Bar.hpp
//  glutapp
//
//  Created by Rudra Aiyar on 3/17/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Bar_hpp
#define Bar_hpp

#include <stdio.h>
#include <iostream>


class Bar{
    //four float values
public:
    float x;
    float y =0;
    float width=.1;
    float height=.3;
    bool click;
    
public:
    Bar(float x1);
    //contains which checks if in or nah
    bool hit(float xx, float yy);
    void draw();
    void moveU();
    void moveD();
};

#endif /* Bar_hpp */
