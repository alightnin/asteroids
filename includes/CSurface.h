#ifndef _CSURFACE_H_
#define _CSURFACE_H_

#include "../includes/includes.h"

class CSurface
{
public:
    CSurface();

public:
    static SDL_Surface* Load_bmp(const char* File);
    
    static SDL_Surface* Load_png(const char* File);

    static bool Draw(SDL_Surface* dest, SDL_Surface* src, int X, int Y);

    static bool Draw(SDL_Surface* dest, SDL_Surface * src, int X, int Y, int X2, int Y2, int W, int H);

    static bool Transparent(SDL_Surface* dest, int R, int G, int B);
};

#endif
