// Including the Player header file
#include "Player.h"

// Constructor
Player::Player() {
	knife.w = knife.h = 80;
}

// Creates knife texture
void Player::CreatePlayerTexture(SDL_Renderer* ren) {
	texture = TextureManager::Texture("Image/knife.png", ren);
}

// Handles mouse input
void Player::Event(int x, int y) {
	knife.y = y - (knife.w / 2);
	knife.x = x - (knife.h / 2);
}

// Rendering of player texture to screen
void Player::Render(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, texture, NULL, &knife);
}

// Cleans memory
void Player::Clear() {
	SDL_DestroyTexture(texture);
}
