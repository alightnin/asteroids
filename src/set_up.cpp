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
    else if(_Event->type == SDL_KEYDOWN)
	{
		switch (_Event->key.keysym.sym)
		{
			case SDLK_ESCAPE: Running = false;
				break;
			case SDLK_SPACE: play_audio(); //will be replaced later
				break;
			case SDLK_w: cout << "w\n"; //speed up
				thrust = true;
				m_y += 1;//just a test value to get ship moving
				break;
			case SDLK_a: cout << "a\n"; //turn -theta
				theta_r += 0.1;
				break;
			case SDLK_s: cout << "s\n"; //slow down
				decel = true;
				m_y -= 1;//just a test value to get ship moving
				break;
			case SDLK_d: cout << "d\n"; //turn +theta
				theta_r -= 0.1;
				break;		
			default://do nothing;
				break;
		}
	}
    else if(_Event->type == SDL_KEYUP)
	{
		switch (_Event->key.keysym.sym)
		{
			case SDLK_w: 
				thrust = false;
				break;
			case SDLK_s: 
				decel = false;
				break;
			default://do nothing;
				break;
		}
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

void Game::Update(double dt)
{
	if(thrust)
	{
		v_x -= sin(theta_r) * accel * dt; 
		v_y -= cos(theta_r) * accel * dt;
	}
	else if(decel)
	{
		v_x += sin(theta_r) * accel * dt; 
		v_y += cos(theta_r) * accel * dt;
	}

	if(v_x > 300)
		v_x = 300;
	else if(v_x < -300)
		v_x = -300;

	if(v_y > 300)
		v_y = 300;
	else if(v_y < -300)
		v_y = -300;


	p_x += v_x * dt;
	p_y += v_y * dt;
	
	if(p_x < 0) p_x = SCREENWIDTH;
	if(p_x > SCREENWIDTH) p_x = 0;
	if(p_y < 0) p_y = SCREENHEIGHT;
	if(p_y > SCREENHEIGHT) p_y = 0;
	
}

void Game::Render() //Draw the main ship and background
{
    CSurface::Draw(screen, background, 0, 0);

    CSurface::Draw(screen, asteroidImage, SCREENWIDTH / 4, SCREENHEIGHT / 6);
    CSurface::Draw(screen, playerShip, p_x, p_y, m_x, m_y, SCREENWIDTH, SCREENHEIGHT);
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
    
    ////////////////////////
    accel = 0; //init acceleration 
    thrust = decel = false;
    v_x = 0, v_y = 0, v_theta_r = 0; //init velocity
    theta_r = 0; //init angle
    p_r = 0; //init radius
    p_x = 0, p_y = 0; //init for the canvas
	m_x = -400 , m_y = -300;//init position for the ship for movement purpose
    start = end = 0;
    ////////////////////////

    return true;

}
