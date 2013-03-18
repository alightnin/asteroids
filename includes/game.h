#ifndef ASTEROIDS_H  //double include protection
#define ASTEROIDS_H

	#include "../includes/includes.h"
	#include "../includes/mixer.h"
	#include "../includes/ship.h"

	//Function prototypes go here
	//bool init(SDL_Surface); //Initialize the SDL and all of its components
	
class Game{
private:
    bool Running;
    SDL_Surface* screen;
    ship player_ship; //create player ship

private:
    SDL_Surface* background;
    SDL_Surface* asteroidImage;
    //SDL_Surface* playerShip;
    SDL_Surface* aiShip;
	//SDL_Surface* rotate;
	
	Mix_Chunk* engine;
	Mix_Chunk* bulletSound;
    
    ////////////////////////// timer attributes to keep track of movement
    long int start, end;
    double deltaTime;
    //////////////////////////
public:
    Game();

    int Execute();
    
    /*
    double a_theta; //Acceleration
    double v_x, v_y, v_theta; //velocity
    double p_x, p_y, theta; //Position
	*/
    
    bool playing;
    
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