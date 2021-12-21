#pragma once

// Texture Manager class included
#include "TextureManager.h"

// Player (user) class
class Player {
private:
	// Basic variable declaration
	SDL_Texture* texture;
	SDL_Rect knife;
	int xpos, ypos;
public:
	// Basic function declarations
	Player();													// Construtor to initialize basic values
	void CreatePlayerTexture(SDL_Renderer* ren);				// Creating needed textures for player 
	void Event(int x, int y);									// Handling of all user input for the player
	void Render(SDL_Renderer* ren);								// Rendering knife to screen
	void Clear();												// Cleans memory

	SDL_Rect* getKnife() { return &knife; }						// Return Rect for the knife
};