#ifndef SHIP_H
#define SHIP_H

	#include "../includes/CSurface.h"
	#include "../includes/includes.h"

	#define pi M_PI

	class ship
	{
		private:
			
		bool ok;
		
		double a_0; //acceleration
		double v_x, v_y; //velocity
		double p_x, p_y; //position
		double theta_rad, theta_deg; //rotation
		double friction;
		
		SDL_Surface* ship_img; //ship image
		SDL_Surface* ship_buf; //rotate_buffer
		
		public:
		
			ship();
		
			~ship();
			
			void accelerate(double accel); //changes the acceleration vector
			
			void drift(); //Sets acceleration to zero so the ship can drift
			
			void init();
			
			bool is_ok(); //Returns true if the ship was succesfully loaded
			
			void rotate(double theta_rad); //change the ships angle in radians by the angle passed into the function
			
			void render(SDL_Surface* screen); //Draw the ship
						
			void update(double dt); //Update the ships movement and position
	};
	
#endif