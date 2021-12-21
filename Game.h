#pragma once

// All necessary header files
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include "Player.h"
#include "Background.h"
#include "Fruit_Bomb.h"
#include "Menu.h"
#include "TextureManager.h"
#include "MusicManager.h"
using namespace std;

// SDL has its own main defined so we have to undefine it first
#undef main

// Main game class
class Game {
private :
	// Basic variables required for smooth running of game
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool isRunning, runMenu;
	TTF_Font* font;
	Mix_Music* gameBackground;
	Mix_Chunk* gameOver;

	// Objects for all parts of the game
	Menu m;
	Background b;
	Player p;
	Fruit_Bomb f;
public :
	// Basic function declarations
	Game();													// Construtor to initialize basic values
	void Initialization();									// Initialize all required commands to run program
	void handleEvent();										// Handling of all user input
	void Update();											// Updating of all parts of game
	void Render();											// Rendering all parts of game
	void Clean();											// Cleans all memory after game quits

	bool running() { return isRunning; }					// Returns value to control running of game

	void GameOver();										// Game Over screen display
};