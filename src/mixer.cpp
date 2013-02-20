#include "../includes/includes.h"
#include "../includes/mixer.h"

//The music that will be played
Mix_Music *music = NULL; 

//The sound effects that will be used
Mix_Chunk *scratch = NULL;
Mix_Chunk *high = NULL;
Mix_Chunk *med = NULL;
Mix_Chunk *low = NULL; 

bool init_audio()
{
	bool success = true;
	//init SDL_Mixer
	if(SDL_Init(SDL_INIT_AUDIO) == -1 ) success = false;
	
	if(Mix_OpenAudio(AUDIOSAMPLERATE, AUDIO_S16SYS , STEREO, CHUNKSIZE) == -1) success = false;
	
	return success;
}

void mix_yo_shit()
{
	cout << "Spit your game and drop your shit!\n";
}

bool check_files() //FINISH ME
{
	return false;
}
	
bool load_file() // FINISH ME
{
	return false;
}

bool play_audio() //FINISH ME
{
	return false;
}

bool stop_audio() //FINISH ME
{
	return false;
}

void cleanup_audio()
{
	//Close SDL_Mixer
	Mix_CloseAudio();
}