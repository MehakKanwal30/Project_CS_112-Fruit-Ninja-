#pragma once

// All necessary header files
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include "TextureManager.h"
#include "MusicManager.h"
using namespace std;

// Main menu class
class Menu {
private :
	// All needed variables
	int x, y;
	int x1, y1;
	int num;
	SDL_Rect pos[3];
	SDL_Rect arrow;
	SDL_Event e;
	SDL_Event e1;
	SDL_Texture* bTex;
	SDL_Texture* htpbTex;
	SDL_Texture* pTex;
	SDL_Texture* htpTex;
	SDL_Texture* eTex;
	SDL_Texture* arrowTex;

	Mix_Music* menuSound;
	bool musicPlay;
public :
	// All needed functions
	Menu();													// Construtor to initialize basic values
	void CreateMenuTexture(SDL_Renderer* ren);				// Creating of all required textures for the menu
	int showMenu(SDL_Renderer* ren);						// Menu screen handling done in this function
	void Clear();											// Cleans memory
};