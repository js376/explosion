//
//  Input.h
//  rect
//
//  Created by Lynn Hyerin Sohn on 2018-03-20.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#pragma once

#include "Sdl.h"


class Input
{
public:
    int x;
    int y;
    const uint8_t* key;
    SDL_Event event;
    uint32_t button;
    
    Input();

    bool done();
};
