#include "game.h"

void Game::OnCleanup(){
    SDL_FreeSurface(background);
    SDL_FreeSurface(asteroidImage);
    SDL_FreeSurface(playerShip);
    SDL_FreeSurface(aiShip);

    SDL_FreeSurface(screen);

    SDL_Quit();
}
