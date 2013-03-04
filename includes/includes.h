#ifndef INCLUDES_H  //double include protection
#define INCLUDES_H

		#ifdef __linux__
		//Linux includes go here (assumed to be 64 bit linux)
		#include <SDL/SDL.h>
		#include <SDL/SDL_mixer.h>
		//#include <../includes/linux/SDL.h>
		//#include <../includes/linux/SDL_mixer.h>
		
		#include <climits>
		#include <iostream>
		#include <fstream>
		#include <string>
		#include <vector>

		using namespace std;

	#elif defined _WIN32
		//32 bit Windows includes go here
		#include "../includes/windows/SDL.h"
		#include "../includes/windows/SDL_mixer.h"
		#include <climits>
		#include <iostream>
		#include <fstream>
		#include <string>
		#include <vector>

		using namespace std;
	#elif defined _WIN64
		//64 bit Windows includes go here
		//no compile
	#endif
#endif
