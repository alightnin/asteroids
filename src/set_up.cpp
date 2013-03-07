#include "../includes/set_up.h"

void Game::Cleanup() //Free all SDL resources
{
	cleanup_audio();
    SDL_FreeSurface(background);
    SDL_FreeSurface(asteroidImage);
    SDL_FreeSurface(playerShip);
    SDL_FreeSurface(aiShip);

    SDL_FreeSurface(screen);

    SDL_Quit();
}

void Game::Event(SDL_Event* _Event) //Check for events
{
    if(_Event->type == SDL_QUIT)
    {
		Running = false;
	}
	if(_Event->type == SDL_KEYDOWN)
		{
			switch (_Event->key.keysym.sym)
			{
				case SDLK_ESCAPE: Running = false;
					break;
				case SDLK_SPACE: play_audio(); //will be replaced later
					break;
				case SDLK_w: cout << "w\n"; //Move ship forward
					break;
				case SDLK_a: cout << "a\n"; //Rotate ship anti clockwise
					break;
				case SDLK_s: cout << "s\n"; //Rotate ship clockwise
					break;
				case SDLK_d: cout << "d\n"; //Reverse /slow down ship
					break;	
				default://do nothing;
					break;
			}
			/*
			if(_Event->key.keysym.sym == SDLK_ESCAPE) Running = false;
			if(_Event->key.keysym.sym == SDLK_SPACE)
		{
			play_audio();
		}
		*/
	}

}

void Game::Exit()
{
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

void Game::Render() //Draw the main ship and background
{
    CSurface::Draw(screen, background, 0, 0);

    CSurface::Draw(screen, asteroidImage, SCREENWIDTH / 4, SCREENHEIGHT / 6);
    CSurface::Draw(screen, playerShip, SCREENWIDTH / 2 , SCREENHEIGHT / 2);
    SDL_Flip(screen);
}

bool Game::Init() //Set up the SDL and load resources
{
	//fft set up will go here too
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("Unable to init");
        return false;
    }
    if((screen = SDL_SetVideoMode(SCREENWIDTH, SCREENHEIGHT, BPP, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL){
        printf("Unable to set Video");
        return false;
    }
	
	if((background = CSurface::Load_bmp("../Images/star.bmp")) == NULL){
		printf("Unable to load background");
		return false;
	}
    if((asteroidImage = CSurface::Load_bmp("../Images/asteroid.bmp")) == NULL){
        printf("Unable to load asteroid");
        return false;
    }
    if((playerShip = CSurface::Load_bmp("../Images/ship1.bmp")) == NULL){
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
