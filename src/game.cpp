#include "../includes/game.h"

using namespace std;

//string music_path;  not used yet

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
		mix_yo_shit(); //do stuff
		if(load_file("../music/Toxicity.mp3") == true) printf("File succesfully loaded\n");
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
        OnRender();
        SDL_Delay(50);
    }

    OnCleanup();

    return 0;
}

int main(int argc, char* argv[]){
    Game LSDasteroids;
    LSDasteroids.OnExecute();

    return 0;
}
