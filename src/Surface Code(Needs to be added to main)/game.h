#ifndef _GAME_H_
    #define _GAME_H_
#include <SDL.h>
#include "CSurface.h"
#include "game_Event.h"
class Game: public game_Event{
private:
    bool Running;

    SDL_Surface* screen;

private:
    SDL_Surface* background;
    SDL_Surface* asteroidImage;
    SDL_Surface* playerShip;
    SDL_Surface* aiShip;
public:
    Game();

    int OnExecute();

public:
    bool OnInit();

    void OnEvent(SDL_Event* Event);

    void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

    void OnExit();

    void OnLoop();

    void OnRender();

    void OnCleanup();
};
#endif // _GAME_H
