#ifndef MIXER_H  //double include protection
#define MIXER_H
	
	#include "../includes/includes.h"

	//constants used for the audio settings
	#define AUDIOSAMPLERATE 44100
	#define CHUNKSIZE 4096
	#define STEREO 2
	
//Classify me later

//function prototypes go here
	bool init_audio(); //Init the SDL_Audio stuff and set up SDL Mixer

	void mix_yo_shit(); //Stub function to put audio playback in
	
	bool check_files(); //Will search the path specified by the user and all subdirectories for recognized audio files and build a list of these files
	
	bool load_file(char* filepath); //Randomly selects a file in the list generated by check file and loads it
	
	bool play_audio(); //plays audio
	
	bool stop_audio(); //stops audio
	
	void cleanup_audio(); //Cleanup (frees everything)
	
#endif