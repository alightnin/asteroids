#include "../includes/CSurface.h"

CSurface::CSurface(){
}

SDL_Surface* CSurface::OnLoad(const char* File){
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;

    if((Surf_Temp = SDL_LoadBMP(File)) == NULL){
        printf("Unable to Load BMP");
        return NULL;
    }

    Surf_Return = SDL_DisplayFormat(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);


    return Surf_Return;
}

bool CSurface::OnDraw(SDL_Surface* dest, SDL_Surface* src, int X, int Y){
    if(dest == NULL || src == NULL){
        printf("Unable to draw");
        return false;
    }

    SDL_Rect DestR;

    DestR.x = X;
    DestR.y = Y;

    SDL_BlitSurface(src, NULL, dest, &DestR);

    return true;
}

bool CSurface::OnDraw(SDL_Surface* dest, SDL_Surface* src, int X, int Y, int X2, int Y2, int W, int H){
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
