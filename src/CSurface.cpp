#include "../includes/CSurface.h"

CSurface::CSurface() {} //primary constructor

SDL_Surface* CSurface::Load_bmp(const char* File)
{
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;

    if((Surf_Temp = SDL_LoadBMP(File)) == NULL){
    	cerr << "Unable to Load BMP\n";
        return NULL;
    }

    Surf_Return = SDL_DisplayFormat(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);


    return Surf_Return;
}

SDL_Surface* CSurface::Load_png(const char* File)
{
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;

    if((Surf_Temp = IMG_Load(File)) == NULL){
    	cerr << "Unable to Load BMP\n";
        return NULL;
    }

    Surf_Return = SDL_DisplayFormat(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);


    return Surf_Return;
}

bool CSurface::Draw(SDL_Surface* dest, SDL_Surface* src, int X, int Y){
    if(dest == NULL || src == NULL){
        cerr << "Unable to draw\n";
        return false;
    }

    SDL_Rect DestR;

    DestR.x = X;
    DestR.y = Y;

    SDL_BlitSurface(src, NULL, dest, &DestR);

    return true;
}

bool CSurface::Draw(SDL_Surface* dest, SDL_Surface* src, int X, int Y, int X2, int Y2, int W, int H){
    if(dest == NULL || src == NULL){
        return false;
    }
    SDL_Rect DestR;

    DestR.x = X;
    DestR.y = Y;

    SDL_Rect SrcR;

    SrcR.x = X2;
    SrcR.y = Y2;
    SrcR.w = W;
    SrcR.h = H;

    SDL_BlitSurface(src, &SrcR, dest, &DestR);

    return true;
}

bool CSurface::Transparent(SDL_Surface* dest, int R, int G, int B){
    if(dest == NULL){
        return false;
    }

    SDL_SetColorKey(dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(dest->format, R, G, B));

    return true;
}
