#include "game.h"
#include <iostream>
#include <fstream>

using namespace std;

bool Game::OnInit(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("Unable to init");
        return false;
    }
    if((screen = SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL){
        printf("Unable to set Video");
        return false;
    }
    if((background = CSurface::OnLoad("star.bmp")) == NULL){
        printf("Unable to load background");
        return false;
    }
    if((asteroidImage = CSurface::OnLoad("asteroid.bmp")) == NULL){
        printf("Unable to load asteroid");
        return false;
    }
    if((playerShip = CSurface::OnLoad("ship1.bmp")) == NULL){
        printf("Unable to load player ship");
        return false;
    }
    /*if((aiShip = CSurface::OnLoad("aiShip.bmp")) == NULL){
        printf("Unable to load AI Ship");
        return false;
    }*/

    CSurface::Transparent(asteroidImage, 0, 0, 255);
    CSurface::Transparent(playerShip, 0, 0, 255);

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    return true;

}
