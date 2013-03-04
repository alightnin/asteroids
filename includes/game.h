#ifndef ASTEROIDS_H  //double include protection
#define ASTEROIDS_H

	#include "../includes/includes.h"

	//Video settings (will change for every architecture)
	#define BPP 32
	#define SCREENWIDTH 800
	#define SCREENHEIGHT 600

	#include "../includes/mixer.h"

	//Function prototypes go here
	//bool init(SDL_Surface); //Initialize the SDL and all of its components
	
class Game{
private:
    bool Running;

    SDL_Surface* screen;

private:
    SDL_Surface* background;
    SDL_Surface* asteroidImage;
    SDL_Surface* playerShip;
    SDL_Surface* aiShip;
public:
    Game();

    int OnExecute();

public:
    bool OnInit();

    void OnEvent(SDL_Event* Event);

    //void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

    void OnExit();

    void OnRender();

    void OnCleanup();
};
	
#endif