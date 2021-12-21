#include "MusicManager.h"

Mix_Music* MusicManager::LoadMusic(const char* title) {
	Mix_Music* music = Mix_LoadMUS(title);
	return music;
}
Mix_Chunk* MusicManager::LoadChunk(const char* title) {
	Mix_Chunk* chunk = Mix_LoadWAV(title);
	return chunk;
}
void MusicManager::PlayMusic(Mix_Music* music) {
	Mix_PlayMusic(music, -1);
}
void MusicManager::PlayChunk(Mix_Chunk* chunk) {
	Mix_PlayChannel(-1, chunk, 0);
}