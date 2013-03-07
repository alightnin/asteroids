#include "../includes/game.h"

using namespace std;

//string music_path;  not used yet

Game::Game()
{
    background = NULL;
    asteroidImage = NULL;
    playerShip = NULL;
    aiShip = NULL;
    screen = NULL;

    Running = true;
}


int Game::Execute() //main game function
{ 
    if(Init() == false) //if SDL isn't initialized then fail
    {  
        return -1;
    }

    SDL_Event _Event;

    while(Running) //Main game loop
    {
		if(load_file("../music/Toxicity.mp3") == true) printf("File succesfully loaded\n");
        while(SDL_PollEvent(&_Event)) //poll loop
        {
            Event(&_Event);
        }
        Render();
        SDL_Delay(50);
    }

    Cleanup();

    return 0;
}

int main(int argc, char* argv[]){
    Game LSDasteroids;
    LSDasteroids.Execute();

    return 0;
}
