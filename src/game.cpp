#include "../includes/game.h"

using namespace std;

string music_path;
 
class Frame //Castletons frame class
{
	SDL_Surface *image2;
	SDL_Rect src, dest;
	int time;
	public:
	long getTime() { return time; }
	void init (string fname, SDL_Surface *screen, long newTime=LONG_MAX /*ms*/)
	{
		time = newTime;
		SDL_Surface *image;
		int colorKey;
		image = SDL_LoadBMP(fname.c_str());
		image2 = SDL_ConvertSurface(image,screen -> format, SDL_HWSURFACE);
		colorKey = SDL_MapRGB(screen -> format, 0,0,255);	
		SDL_SetColorKey(image2, SDL_SRCCOLORKEY,colorKey);
		SDL_FreeSurface(image);
		src.x=0; src.y=0; src.w=image2->w; src.h=image2->h;
		dest.x=0; dest.y=0; dest.w = image2 -> w; dest.h = image2 -> h;
	}
	
	void draw(SDL_Surface *screen,int x, int y)
	{
		dest.x=x; dest.y=y;
		SDL_BlitSurface(image2,&src,screen,&dest);
	}
};

class Animation //Castletons animation class
{
	vector<Frame> frames;
	long totalTime;
	public:
	void init(string fname,SDL_Surface *screen)
	{
		int n;
		ifstream in(fname.c_str());
		in >> n;
		totalTime=0;
		for(int i=0; i<n; i++)
		{
			long t;
			string f2name;
			in >> t >> f2name;
			totalTime+=t;
			Frame f;
			f.init(f2name,screen,t);
			frames.insert(frames.end(),f);
		}
		in.close();
	}
	void draw(SDL_Surface *screen,int x, int y, long elapsed) //ms
	{
		long currentFrameTime=elapsed % totalTime;
		for(int i=0; i<frames.size(); i++)
		{
			if(frames[i].getTime() > currentFrameTime)
			{
				frames[i].draw(screen,x,y);
				break;
			}
			currentFrameTime-=frames[i].getTime();
		}
	}
};

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
	SDL_WM_SetCaption( "Insert Insightful Caption Here", NULL );
	
	return success;
}

void cleanup(SDL_Surface* _Screen)
{
	cleanup_audio();
	SDL_FreeSurface(_Screen);
	SDL_Quit();
}

int main()
{
	bool quit = false;
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
		            	if(event.key.keysym.sym == SDLK_SPACE) play_audio();
		            }
		        }
		        SDL_Delay(50);
		    }
		cleanup(screen); //free everything
		return 0;
	}
	else
	{
		cout << "Unable to init SDL: %s\n" << SDL_GetError();
		return 1;
	}
}
