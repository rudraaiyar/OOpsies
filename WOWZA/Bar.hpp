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
    float x,y, width, height;
    bool click;
    
public:
    Bar(float x1, float y1, float w, float h);
    //contains which checks if in or nah
    bool hit(float xx, float yy);
    void draw();
    void moveR(float xx);
    void moveL(float xx);

};

#endif /* Bar_hpp */
