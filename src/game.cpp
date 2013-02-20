#include "../includes/game.h"
#include "../includes/includes.h"

using namespace std;

const string music_path;

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

void init() //Initialize the SDL and all of its components
{
	
}

int main(int argc, char** argv)
{
	int SCREENWIDTH = 640;
	int SCREENHEIGHT = 480;

	SDL_Init(SDL_INIT_VIDEO); //init SDL Video and Audio
	mix_yo_shit();
	SDL_Quit();
	return 0;
}