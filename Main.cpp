#include "Game.h"

// Object for the game controlling class
Game* g = new Game();

int main() {
	// To control FPS of game
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	
	// The main running process of the game starts here
	g->Initialization();

	while (g->running()) {
		SDL_ShowCursor(SDL_DISABLE);
		frameStart = SDL_GetTicks();

		g->handleEvent();
		g->Update();
		g->Render();

		// Controls FPS
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
	}
	// Cleans memory after game finishes
	g->Clean();
	
	return 0;
}