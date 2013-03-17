#include "../includes/mixer.h"

//The music that will be played
Mix_Music *music = NULL; 
Mix_Chunk *engine = NULL;


//added to Init video function
/*
bool init_audio()
{
	bool success = true;
	//init SDL_Mixer
	//if(SDL_Init(SDL_INIT_AUDIO) == -1 ) success = false;
	
	if(Mix_OpenAudio(AUDIOSAMPLERATE, AUDIO_S16SYS , STEREO, CHUNKSIZE) == -1) success = false;
	
	return success;
}
*/

bool check_files() //FINISH ME
{
	return false;
}

void cleanup_audio()
{
	//Close SDL_Mixer
	Mix_FreeChunk(engine);
	Mix_CloseAudio();
}

bool load_file(char* filepath) // Loads the file passed into the fcn into memory
{
	bool success = true;
	if(engine == NULL) success = false;
	music = Mix_LoadMUS(filepath); 
	if(music == NULL) success = false;
		return success;
}
bool play_engine()
{
	bool success = true;
	engine =  Mix_LoadWAV("../sound/engine.wav");
	if(Mix_PlayChannel(-1, engine, 0) == -1) success = false;
	printf("Unable to load engine sound");
	Mix_VolumeChunk(engine, 70);
	return success;
}
bool play_audio()
{
	bool success = true;
	if(Mix_PlayMusic(music, 1) == -1) success = false;
	return success;
}

bool stop_audio() //FINISH ME
{
	Mix_HaltMusic();
	return false;
}