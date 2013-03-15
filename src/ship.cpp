#include "../includes/ship.h"

ship::ship()
{
	
}

ship::~ship()
{
	SDL_FreeSurface(ship_img); 
	SDL_FreeSurface(ship_buf);
}

void ship::accelerate(double accel)
{
	friction = 1.0;
	a_0 = accel;
}

void ship::drift() //Sets a_theta to zero so the shift can drift and bleed of velocity
{
	a_0 = 0;
	friction = .99;
}

void ship::init()
{
	ok = true; //set ok to true
	
	a_0 = 0; //init acceleration 
	v_x = 0, v_y = 0, //init velocity
	theta_rad = pi/2; // pi = move straight up (not sure why this works but it does)
	friction = 1.0;
	p_x = SCREENWIDTH / 2; //init position
	p_y = SCREENHEIGHT / 2; //init position
	
	if(((ship_buf = CSurface::Load_bmp("../Images/ship1.bmp")) == NULL)) ok = false;
	CSurface::Transparent(ship_buf, 255, 0, 255);
}

bool ship::is_ok()
{
	if(ok == true) return true;
	else return false;
}

void ship::render(SDL_Surface* screen)
{
	//update me
	CSurface::Draw(screen, ship_img, p_x, p_y);
}

void ship::rotate(double theta_n_stuff)
{
	theta_rad+= theta_n_stuff;
}

void ship::update(double dt)
{
	ship_img = rotozoomSurface(ship_buf,theta_deg, 1.0, 0); //call to update the rotation of the ship

	/*
	v_theta_rad+= a_theta_rad* dt; //Calculate velocity as the integral of accelaration
	v_x = sin(theta) * v_theta; //Calculate x-axis velocity
	v_y = cos(theta) * v_theta; //Calculate y-axis velocity
	p_x += v_x * dt; //convert velocity to position x-axis
	p_y += v_y * dt; //convert velocity to position y-axis
	*/
	
	p_x += v_x * dt;
	p_y += v_y * dt;
	v_x += cos(theta_rad) * a_0 * dt;
	v_y += sin(theta_rad+pi) * a_0 * dt;
	v_x *= friction;
	v_y *= friction;
	theta_deg = (theta_rad * pi) / 180; //Convert to degree pi for rotozoom
	
	cout << "theta: " << theta_deg<< " v_x: " << v_x << " v_y: " << v_y << " a_0: " << a_0 <<  " fric: " << friction << endl;
	//Check that the ship is on screen if not move it to the other side
	if(p_x < 0) p_x = SCREENWIDTH;
	if(p_x > SCREENWIDTH) p_x = 0;
	if(p_y < 0) p_y = SCREENHEIGHT;
	if(p_y > SCREENHEIGHT) p_y = 0;
	//if(theta_rad> 2 * PI) theta_rad= 0;
	//else if(theta_rad< 0) theta_rad= 2 * PI;
	/*
	if(a_0 == 0) //slow the ship down over time
	{
		cout << "V: " << v_x << ", " << v_y  << endl;
		if(v_theta_rad> 0) v_theta_rad-= DRAG;
		else if(v_theta_rad< 0) v_theta_rad+= DRAG;
	}*/
	
	/*
	if((cos(theta) * v_y) + (sin(theta) * v_x) > 300)
	{
		v_y = (300 * cos(theta));
		v_x = (300 * sin(theta));
	}
	else if((cos(theta) * v_y) + (sin(theta) * v_x) < -300)
	{
		v_y = (-300 * cos(theta));
		v_x = (-300 * sin(theta));
	}
	*/
}