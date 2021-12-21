#pragma once

// Necessary header files
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;

// Dimentions of game screen
#define WIDTH 1920
#define HEIGHT 1080

// Class for loading textures
class TextureManager {
public :
	// Texture loading function
	static SDL_Texture* Texture(const char* title, SDL_Renderer* ren);		// Loading and returning of texture
};