#include "game.h"

Game::Game(){
    background = NULL;
    asteroidImage = NULL;
    playerShip = NULL;
    aiShip = NULL;


    screen = NULL;

    Running = true;
}

int Game::OnExecute(){
    if(OnInit() == false){
        return -1;
    }

    SDL_Event Event;

    while(Running){
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
        SDL_Delay(1);
    }

    OnCleanup();

    return 0;
}

int main(int argc, char* argv[]){
    Game LSDasteroids;
    LSDasteroids.OnExecute();

    return 0;
}
