#ifndef INCLUDES_H  //double include protection
#define INCLUDES_H

	#ifdef __linux__
		//Linux includes go here (assumed to be 64 bit linux)
		#include "SDL.h"
		#include "SDL_mixer.h"
		#include <climits>
		#include <iostream>
		#include <fstream>
		#include <string>
		#include <vector>

		using namespace std;

	#elif defined _WIN32
		//32 bit Windows includes go here
		#include "SDL.h"

	#elif defined _WIN64
		//64 bit Windows includes go here
		#include "SDL.h"
	#endif
#endif