#pragma once

#include <SDL_mixer.h>

class MusicManager
{
public :
	static Mix_Music* LoadMusic(const char* title);
	static Mix_Chunk* LoadChunk(const char* title);
	static void PlayMusic(Mix_Music* music);
	static void PlayChunk(Mix_Chunk* chunk);
};

