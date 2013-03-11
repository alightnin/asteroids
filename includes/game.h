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
    
    ////////////////////////// timer attributes to keep track of movement
    long int start, end;
    double deltaTime;
    //////////////////////////
public:
    Game();

    int Execute();
        
    double a_theta; //Acceleration
    double v_x, v_y, v_theta; //velocity
    double p_x, p_y, theta; //Position
    
public:
    bool Init();

    void Event(SDL_Event* _Event);

    //void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

    void Exit();
    
    //////////////////// //update function (redraws ship)
    void Update(double dt);
    ////////////////////

    void Render();

    void Cleanup();
};
	
#endif