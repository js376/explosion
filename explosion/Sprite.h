//
//  Sprite.h
//  rect
//
//  Created by Lynn Hyerin Sohn on 2018-03-20.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#pragma once

#include <iostream>
#include "Sdl.h"

class Sprite
{
public:
    SDL_Rect rect;
    int time;
    
    Sprite(int x, int y);
    void speak() const;
};
