#include "../includes/game.h"
#include "../includes/CSurface.h"

using namespace std;

void Game::OnCleanup(){
	cleanup_audio();
    SDL_FreeSurface(background);
    SDL_FreeSurface(asteroidImage);
    SDL_FreeSurface(playerShip);
    SDL_FreeSurface(aiShip);

    SDL_FreeSurface(screen);

    SDL_Quit();
}

void Game::OnEvent(SDL_Event* Event){
    if(Event->type == SDL_QUIT){
		Running = false;
	}
	if(Event->type == SDL_KEYDOWN){
		if(Event->key.keysym.sym == SDLK_ESCAPE)
			Running = false;
		if(Event->key.keysym.sym == SDLK_SPACE){
			cout << " _ Keypress detected\n";
			play_audio();
		}
	}

}

void Game::OnExit(){
    Running = false;
}
/*This is where we need to create an Event function for a key press
void Game::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode){
    
    Pseudo code

    if(SDLK_UP) ship.y--
    if(SDLK_DOWN) ship.y++
    if(SDLK_LEFT) ship Rotate left
    if(SDLK_RIGHT) ship. Rotate right
    if(SDLK_SPACE){
        CSurface::OnLoad("bullet")
        fire.animation();
    }


}    Code not written yet*/

void Game::OnRender(){
    CSurface::OnDraw(screen, background, 0, 0);

    CSurface::OnDraw(screen, asteroidImage, SCREENWIDTH / 4, SCREENHEIGHT / 6);
    CSurface::OnDraw(screen, playerShip, SCREENWIDTH / 2 , SCREENHEIGHT / 2);
    SDL_Flip(screen);
}

bool Game::OnInit(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("Unable to init");
        return false;
    }
    if((screen = SDL_SetVideoMode(SCREENWIDTH, SCREENHEIGHT, BPP, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL){
        printf("Unable to set Video");
        return false;
    }
	
	if((background = CSurface::OnLoad("Images/star.bmp")) == NULL){
		printf("Unable to load background");
		return false;
	}
    if((asteroidImage = CSurface::OnLoad("Images/asteroid.bmp")) == NULL){
        printf("Unable to load asteroid");
        return false;
    }
    if((playerShip = CSurface::OnLoad("Images/ship1.bmp")) == NULL){
        printf("Unable to load player ship");
        return false;
    }
	if(Mix_OpenAudio(AUDIOSAMPLERATE, AUDIO_S16SYS , STEREO, CHUNKSIZE) == -1){
		printf("Unable to play audio");
		return false;
	}
    /*if((aiShip = CSurface::OnLoad("aiShip.bmp")) == NULL){
        printf("Unable to load AI Ship");
        return false;
    }*/

	SDL_WM_SetCaption( "Asteroids_N_Stuff", NULL ); 
	
    CSurface::Transparent(asteroidImage, 0, 0, 255);
    CSurface::Transparent(playerShip, 0, 0, 255);

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    return true;

}
