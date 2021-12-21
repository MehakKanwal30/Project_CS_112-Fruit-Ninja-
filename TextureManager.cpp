// Including the TextureManager header file
#include "TextureManager.h"

// Loads, creates and returns a texture
SDL_Texture* TextureManager::Texture(const char* title,  SDL_Renderer* ren) {
	SDL_Surface* surface = IMG_Load(title);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, surface);
	SDL_FreeSurface(surface);
	return texture;
}