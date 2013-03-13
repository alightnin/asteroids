#include "../includes/set_up.h"
#include "../includes/game.h"

void Game::Cleanup() //Free all SDL resources
{
	cleanup_audio();
    SDL_FreeSurface(background);
    SDL_FreeSurface(asteroidImage);
    SDL_FreeSurface(playerShip);
    SDL_FreeSurface(aiShip);
	SDL_FreeSurface(rotate);
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
			case SDLK_SPACE: 
				if(playing == false)
				{
					play_audio(); //will be replaced later
					playing = true;
				}
				else
				{
					stop_audio();
					playing = false;
				}
				break;
			case SDLK_w: //cout << "w\n"; //speed up
				a_theta += .05;
				p_x-=sin(angle*PI/180.0)*(a_theta); 
				p_y-=cos(angle*PI/180.0)*(a_theta);
				
				break;
			case SDLK_a: //cout << "a\n"; //turn -theta
				angle+=1;				
				break;
			case SDLK_s: //cout << "s\n"; //slow downdddd
				//a_theta -= .01;
				p_x+= sin(angle*PI/180.0)*2;
				p_y+= cos(angle*PI/180.0)*2;
				break;
			case SDLK_d: //cout << "d\n"; //turn +theta
				angle-=1;
				break;		
			default: //do nothing;
				break;
		}
		
	}
    else if(_Event->type == SDL_KEYUP)
	{
		switch (_Event->key.keysym.sym)
		{
			case SDLK_w:
				//cout << "W UP\n";
				a_theta = 0;
				break;
			case SDLK_s:
				//cout << "S UP\n";
				a_theta = 0;
				break;
			default: //do nothing;
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

void Game::Update(double dt) //updates the ship position and physics for it to be redrawn
{
	rotate = rotozoomSurface(playerShip, angle, 1.0, 0); //call to update the rotation of the ship

	
	if(angle > 360)
		angle -= 360; //keep our angle below 360
	v_theta += a_theta * dt; //Calculate velocity as the integral of accelaration
	v_x = sin(theta) * v_theta; //Calculate x-axis velocity
	v_y = cos(theta) * v_theta; //Calculate y-axis velocity
	p_x += v_x * dt; //convert velocity to position x-axis
	p_y += v_y * dt; //convert velocity to position y-axis
	
	//Check that the ship is on screen if not move it to the other side
	if(p_x < 0) p_x = SCREENWIDTH;
	if(p_x > SCREENWIDTH) p_x = 0;
	if(p_y < 0) p_y = SCREENHEIGHT;
	if(p_y > SCREENHEIGHT) p_y = 0;
	if(a_theta == 0) //slow the ship down over time
	{
			if(v_theta > 0) v_theta -= DRAG;
			else if(v_theta < 0) v_theta += DRAG;
			cout << "V: " << v_theta << endl;
	}
	
	if(v_theta > 300) v_theta = 300; //limit the velocity
	else if(v_theta < -300) v_theta = -300;
	cout << "A: " << a_theta << endl;
}

void Game::Render() //Draw the main ship and background
{
    CSurface::Draw(screen, background, 0, 0);
    CSurface::Draw(screen, asteroidImage, SCREENWIDTH / 4, SCREENHEIGHT / 6);
    CSurface::Draw(screen, rotate, p_x, p_y);
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
	
	if((background = CSurface::Load_png("../Images/background001.png")) == NULL){
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
	
    CSurface::Transparent(asteroidImage, 255, 0, 255);
    CSurface::Transparent(playerShip, 255, 0, 255);

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);
    
	playing = false;
    ////////////////////////

    a_theta = 0; //init acceleration 
    v_x = 0, v_y = 0, v_theta = 0; //init velocity
    theta = PI; // pi = move straight up (not sure why this works but it does)
	angle = 0; //angle to update which way the ship is facing
    p_x = SCREENWIDTH / 2, p_y = SCREENHEIGHT / 2; //init position
    start = end = 0;
    ////////////////////////

    return true;

}
