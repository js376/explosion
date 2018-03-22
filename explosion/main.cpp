//
//  main.cpp
//  explosion
//
//  Created by Lynn Hyerin Sohn on 2018-03-21.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#include "Sdl.h"
#include "Input.h"
#include "Sprite.h"
#include "Sops.h"

int main()
{
    // TODO:
    // Assign xres and yres to internal fields within SDL so we can access them as sdl.xres and sdl.yres later on.
    Sdl sdl(800, 400);

    std::deque<Sprite> sprites;

    // TODO:
    // Load the Explosion_Sprite.bmp into RAM using an SDL_Surface (I added the surface loading function to the Util namespace).
    //
    //      SDL_Surface* surface = Util::load(char* path, uint32_t r, uint32_t g, uint32_t b);
    //
    //      For the path, use "art/Explosion_Sprites.bmp" in this folder.
    //      For R,G,B, select the color that you want to be transparent when the sprites are copied to the window.
    //      If you look at the sprite sheet, the background is black (0, 0, 0 for RGB) so use this.
    //
    // SDL_Surfaces are slow when copying to the window. Convert the SDL_Surface to an SDL_Texture so that it lives in Video Memory (VRAM).
    //
    //      SDL_Texture* texture = SDL_CreateTextureFromSurface(sdl.renderer, surface);
    //
    // We will pass this texture and surface to Sops :: draw(...).
    //
    // We must pass in both the surface and texture because the surface contains width and height
    // information of the sprite surface (as well as un-optimized memory data which we don't care about),
    // and the texture contains the optimized video memory data we need for fast window transfer.

    while(true)
    {
        std::cout << sprites.size() << std::endl;

        Input input;
        if(input.done())
            break;

        // Left click.
        if(input.button == 1)
            sprites.push_front(Sprite(input.x, input.y));

        // TODO:
        // On right click (when input.button == 4) don't use input.x and input.y and
        // push to the front 10 sprites in random locations.
        // You can randomize the x and y position of the sprite by doing:
        //
        // int x = std::rand() % sdl.xres;
        // int y = std::rand() % sdl.yres;

        Sops :: update_timeouts(sprites);

        // TODO:
        // Timeouts must be removed before the sprites are drawn.
        //
        // There are 12 frames for the explosion. We will draw:
        //
        //   Frame  0 when time is   0 -  10 (not including  10).
        //   Frame  1 when time is  10 -  20 (not including  20).
        //   ...
        //   Frame 11 when time is 110 - 120 (not including 120).
        //
        // So if update_timeouts() is 120 at the back of the deque it must be removed.
        //
        // Swap the order of draw() and remove_timeouts().

        // TODO:
        // Pass the Surface and Texture to this draw() function. Don't forget to add the function arguments to the .h file.
        Sops :: draw(sprites, sdl);

        Sops :: remove_timeouts(sprites);
    }
}
