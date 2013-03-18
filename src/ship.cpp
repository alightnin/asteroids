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
	theta_rad = 0; // pi = move straight up (not sure why this works but it does)
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
	CSurface::Draw(screen, ship_img, p_x-(ship_img->w/2), p_y-(ship_img->h/2));
}

void ship::rotate(double theta_n_stuff)
{
	theta_rad+= theta_n_stuff;
}

void ship::update(double dt)
{
	if(theta_rad > (2 * pi)) theta_rad = 0; //keep theta between 0 and 2 pi
	else if(theta_rad < 0) theta_rad = 2 * pi;
	theta_deg = (theta_rad * 180) / pi; //Convert to degree pi for rotozoom
	ship_img = rotozoomSurface(ship_buf,theta_deg, 1.0, 0); //call to update the rotation of the ship
	
	p_x += v_x * dt;
	p_y += v_y * dt;
	v_x += cos(theta_rad+pi/2) * a_0 * dt;
	v_y += -sin(theta_rad+pi/2) * a_0 * dt;
	v_x *= friction;
	v_y *= friction;
	
	cout << "theta: " << theta_deg<< " v_x: " << v_x << " v_y: " << v_y << " a_0: " << a_0 <<  " fric: " << friction << endl;
	//Check that the ship is on screen if not move it to the other side
	if(p_x < 0) p_x = SCREENWIDTH;
	if(p_x > SCREENWIDTH) p_x = 0;
	if(p_y < 0) p_y = SCREENHEIGHT;
	if(p_y > SCREENHEIGHT) p_y = 0;
	
	/*
	if((-sin(theta_rad) * v_y) + (cos(theta_rad) * v_x) > 500)
	{
		v_y = (500 * -sin(theta_rad));
		v_x = (500 * cos(theta_rad));
	}
	else if((-sin(theta_rad) * v_y) + (cos(theta_rad) * v_x) < 500)
	{
		v_y = (-500 * -sin(theta_rad));
		v_x = (-500 * cos(theta_rad));
	}
	*/
}