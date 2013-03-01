#include "game.h"

void Game::OnRender(){
    CSurface::OnDraw(screen, background, 0, 0);

    CSurface::OnDraw(screen, asteroidImage, 200, 100);
    CSurface::OnDraw(screen, playerShip, 512, 384);
    SDL_Flip(screen);
}
