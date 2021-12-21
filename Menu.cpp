// Including the Menu header file
#include "Menu.h"

// Constructor to set all basic values
Menu::Menu() {
	num = 2;

	pos[0].w = 337;
	pos[0].h = 123;
	pos[1].w = 309;
	pos[1].h = 123;
	pos[2].w = 741;
	pos[2].h = 154;

	pos[0].x = pos[1].x = (WIDTH / 3) + 100;
	pos[2].x = (WIDTH / 4);
	pos[0].y = (HEIGHT / 2) + 130;
	pos[2].y = (HEIGHT / 2) + 250;
	pos[1].y = (HEIGHT / 2) + 390;

	arrow.w = arrow.h = 80;
	arrow.x = arrow.y = 10;
	musicPlay = true;
}

// Creates all the textures for the menu
void Menu::CreateMenuTexture(SDL_Renderer* ren) {
	bTex = TextureManager::Texture("Image/menuback.png", ren);
	htpbTex = TextureManager::Texture("Image/howtoplay_back.jpg", ren);
	pTex = TextureManager::Texture("Image/play.png", ren);
	eTex = TextureManager::Texture("Image/exit.png", ren);
	htpTex = TextureManager::Texture("Image/htp.png", ren);
	arrowTex = TextureManager::Texture("Image/backarrow.png", ren);
	menuSound = Mix_LoadMUS("Image/menuBack.mp3");
	if (menuSound == NULL)
		exit(0);
}

// Rendering and handling input for the menu screen
int Menu::showMenu(SDL_Renderer* ren) {
	// Stops already playing music
	Mix_HaltMusic();				

	// Mouse cursor displayed
	SDL_ShowCursor(SDL_ENABLE);
	bool flag;

	// Menu running
	while (1) {
		if (musicPlay && !Mix_PlayingMusic())
			Mix_PlayMusic(menuSound, -1);			// Plays menu music

		flag = true;
		SDL_RenderClear(ren);
		SDL_RenderCopy(ren, bTex, NULL, NULL);
		SDL_RenderCopy(ren, pTex, NULL, &pos[0]);
		SDL_RenderCopy(ren, eTex, NULL, &pos[1]);
		SDL_RenderCopy(ren, htpTex, NULL, &pos[2]);
		SDL_RenderPresent(ren);

		// Handling of input on menu screen
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
				case SDL_QUIT :							// If window is closed game ends
					return 1;
				case SDL_MOUSEBUTTONDOWN :				// Checks for input when LMB is pressed
					x = e.button.x;
					y = e.button.y;

					// Checks if mouse is over "play" or "exit" option 
					for (int i = 0; i < num; i++) {
						if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h) {
							return i;
						}
					}

					// Checks if mouse is located over "how to play" option
					if (x >= pos[2].x && x <= pos[2].x + pos[2].w && y >= pos[2].y && y <= pos[2].y + pos[2].h) {
						// Renders the "how to play" screen
						while (flag) {
							SDL_RenderClear(ren);
							SDL_RenderCopy(ren, htpbTex, NULL, NULL);
							SDL_RenderCopy(ren, arrowTex, NULL, &arrow);
							SDL_RenderPresent(ren);
							
							// Checks if user presses back arrow to go back to menu
							while (SDL_PollEvent(&e1)) {
								if (e1.type == SDL_MOUSEBUTTONDOWN) {
									x1 = e1.button.x;
									y1 = e1.button.y;
									if (x1 >= arrow.x && x1 <= arrow.x + arrow.w && y1 >= arrow.y && y1 <= arrow.y + arrow.h) {
										flag = false;
									}
								}
								if (e1.type == SDL_KEYDOWN) {
									musicPlay = !musicPlay;
									if (e1.key.keysym.sym == SDLK_m) {
										if (Mix_PausedMusic() && musicPlay)
											Mix_ResumeMusic();									// Press m to play music
										else
											Mix_PauseMusic();									// Press m to pause music
									}
								}
							}
						}
					}
					break;

				case SDL_KEYDOWN :	
					musicPlay = !musicPlay;
					if (e.key.keysym.sym == SDLK_m) {
						if (Mix_PausedMusic() && musicPlay)
							Mix_ResumeMusic();									// Press m to play music
						else
							Mix_PauseMusic();									// Press m to pause music
					}
					if (e.key.keysym.sym == SDLK_ESCAPE) { return 0; }			// Return to game by pressing escape key
			}
		}
	}
}

// Cleans memory
void Menu::Clear() {
	SDL_DestroyTexture(bTex);
	SDL_DestroyTexture(pTex);
	SDL_DestroyTexture(eTex);
	Mix_FreeMusic(menuSound);
}

