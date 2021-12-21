#pragma once

// Texture Manager class included
#include "TextureManager.h"

// Background class for main game
class Background {
private :
	// Basic required varible
	SDL_Texture* texture;
public :
	// All needed functions
	void CreateBackgroundTexture(SDL_Renderer* ren);		// Creates background texture
	void Render(SDL_Renderer* ren);							// Rendering of background texture
	void Clear();											// Cleans memory
};