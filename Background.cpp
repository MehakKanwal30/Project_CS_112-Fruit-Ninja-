// Including the Background header file
#include "Background.h"

// Constructor
void Background::CreateBackgroundTexture(SDL_Renderer* ren) {
	texture = TextureManager::Texture("Image/background.png", ren);
}

// Rendering of game background
void Background::Render(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, texture, NULL, NULL);
}

// Clears memory
void Background::Clear() {
	SDL_DestroyTexture(texture);
}
