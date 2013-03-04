#ifndef _CSURFACE_H_
#define _CSURFACE_H_

#include "..\..\includes\includes.h"

class CSurface{
public:
    CSurface();

public:
    static SDL_Surface* OnLoad(const char* File);

    static bool OnDraw(SDL_Surface* dest, SDL_Surface* src, int X, int Y);

    static bool OnDraw(SDL_Surface* dest, SDL_Surface * src, int X, int Y, int X2, int Y2, int W, int H);

    static bool Transparent(SDL_Surface* dest, int R, int G, int B);
};


#endif
