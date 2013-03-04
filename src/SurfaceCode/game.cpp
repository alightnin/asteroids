#include "../includes/game.h"

using namespace std;

string music_path;

bool init(SDL_Surface* _screen) //Initialize the SDL and all of its components
{
	bool success = true;
	//init SDL_Video and SDL_Mixer
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) == -1) success = false;
	
	//init the screen
	_screen = SDL_SetVideoMode(SCREENWIDTH, SCREENHEIGHT, BPP, SDL_DOUBLEBUF|SDL_HWSURFACE);
	
	//init the mixer
	if(Mix_OpenAudio(AUDIOSAMPLERATE, AUDIO_S16SYS , STEREO, CHUNKSIZE) == -1) success = false;
	
	//check that screen_buffer was succesfully inited
	if(_screen == NULL) success = false;
	
	//init SDL_ttf
	//if(TTF_Init() == -1) success = false;
	
	//Set the window caption
	SDL_WM_SetCaption( "Asteroids_N_Stuff", NULL );
	
	return success;
}

int main(int argc, char** argv)
{
	bool quit = false;
	int i = 0;
	Mix_Music* track = NULL;
	SDL_Event event;
	SDL_Surface* screen = NULL;
	//SDL_Surface* screen_buffer;
	
	//Init audio and video
	if(init(screen) != false)
	{
		mix_yo_shit(); //do stuff
		if(load_file("../music/Toxicity.mp3") == true) cout << "File succesfully loaded\n";
		//While the user hasn't quit
		    while(quit == false)
		    {
		    	cout << i++ << " " << endl;
		        //While there's an event to handle
		        while(SDL_PollEvent( &event ))
		        {
		            //If the user has Xed out the window
		            if(event.type == SDL_QUIT)
		            {
		                //Quit the program
		                quit = true;
		            }
		            if(event.type == SDL_KEYDOWN)
		            {
		            	if(event.key.keysym.sym == SDLK_ESCAPE) quit = true;
		            	if(event.key.keysym.sym == SDLK_SPACE)
						{
								cout << " _ Keypress detected\n";
								play_audio();
						}
		            }
		        }
		        SDL_Delay(50);
		    }
		OnCleanup(); //free everything
		return 0;
	}
	else
	{
		cout << "Unable to init SDL: %s\n" << SDL_GetError();
		return 1;
	}
}
