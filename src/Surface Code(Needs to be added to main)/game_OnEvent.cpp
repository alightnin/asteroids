#include "game.h"
#include <iostream>
#include <fstream>

void Game::OnEvent(SDL_Event* Event){
    game_Event::OnEvent(Event);

}

void Game::OnExit(){
    Running = false;
}

void Game::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode){
    /*This is where we need to create an Event function for a key press
    Pseudo code

    if(SDLK_UP) ship.y--
    if(SDLK_DOWN) ship.y++
    if(SDLK_LEFT) ship Rotate left
    if(SDLK_RIGHT) ship. Rotate right
    if(SDLK_SPACE){
        CSurface::OnLoad("bullet")
        fire.animation();
    }

    Code not written yet*/
}
