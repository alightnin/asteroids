#include "../includes/mixer.h" 

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
	//Mix_FreeChunk(sound);
	Mix_CloseAudio();
}

/*
bool load_file(char* filepath) // Loads the file passed into the fcn into memory
{
	bool success = true;
	
	music = Mix_LoadMUS(filepath); 
	if(music == NULL) success = false;
	return success;
}
*/
bool play_fx(Mix_Chunk* fx)
{
	if(Mix_PlayChannel(-1, fx, 0) == -1) return false;
	return true;
}

bool play_track(Mix_Music* track)
{
	if(Mix_PlayMusic(track, 1) == -1) return false;
	return true;
}

bool stop_audio() //FINISH ME
{
	Mix_HaltMusic();
	return false;
}