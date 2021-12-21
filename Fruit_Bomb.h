#pragma once

// Necessary header files included
#include "TextureManager.h"
#include "MusicManager.h"
#include <SDL_ttf.h>
#include <cstdlib>
#include <time.h>
#include <sstream>

// All tasks related to fuits and bombs are done in this class
class Fruit_Bomb {
private :
	// Basic variables required
	SDL_Texture* aTex;
	SDL_Texture* bTex;
	SDL_Texture* cTex;
	SDL_Texture* mTex;
	SDL_Texture* oTex;
	SDL_Texture* manTex;
	SDL_Texture* bom1Tex;
	SDL_Texture* bom2Tex;
	SDL_Texture* bom3Tex;
	SDL_Texture* bom4Tex;
	SDL_Texture* bom5Tex;
	SDL_Texture* bom6Tex;
	SDL_Texture* bom7Tex;
	SDL_Texture* activeTex;
	SDL_Texture* passiveTex;
	SDL_Texture* sTex;
	SDL_Texture* oneTex;
	SDL_Texture* twoTex;
	SDL_Texture* threeTex;
	SDL_Texture* fourTex;
	SDL_Texture* fiveTex;

	SDL_Rect one, two, three, four, five;
	SDL_Rect apple, banana, cherry, melon, orange, mango, bomb1, bomb2, scoreFruit, scoreBoard;

	TTF_Font* font;
	SDL_Color color;
	Mix_Chunk* cutSound;
	Mix_Chunk* dropSound;
	Mix_Chunk* bombSound;
	Mix_Chunk* mangoCut;

	int aSpeed, bSpeed, cSpeed, mSpeed, oSpeed, manSpeed, bom1Speed, bom2Speed;
	int aPoint, bPoint, cPoint, mPoint, oPoint, manPoint;
	int aX, bX, cX, mX, oX, manX, bom1X, bom2X;
	signed int a, b, c, m, o, man, bom1, bom2;
	int man1, bom11, bom21;
	int fall;

	int totalPoints;
	int missed;
	bool missedAll;

	string score;
public:
	// Basic functions required
	Fruit_Bomb();												// Construtor to initialize basic values
	void write(string text, int SIZE, SDL_Color color, SDL_Renderer* ren, SDL_Rect board, int x, int y);	// Displaying text on screeneeeeeeeeeeeee
	void CreateFruitBombTexture(SDL_Renderer* ren);				// Creates all fruit and bomb textures
	void Update();												// Updating the program with any new input
	void Render(SDL_Renderer* ren);								// Rendering of fruits and bombs
	void Clear();												// Cleans memory

	void Restart();												// Restarts needed variables to reset game
	void Bomb(SDL_Renderer* ren, SDL_Texture* texture);			// Rendering of bomb texture
	void BlowBomb(SDL_Renderer* ren);							// Blowing bomb animation

	int getTotalScore() { return totalPoints; }					// Returns total score of player
	bool getMissedAll() { return missedAll; }					// Returns value if all 5 lives have been lost
	
	SDL_Rect* getApple() { return &apple; }						// *		
	SDL_Rect* getBanana() { return &banana; }					// *	
	SDL_Rect* getCherry() { return &cherry; }					// *
	SDL_Rect* getMelon() { return &melon; }						// Returns respective Rect address
	SDL_Rect* getOrange() { return &orange; }					// *
	SDL_Rect* getMango() { return &mango; }						// *
	SDL_Rect* getBomb1() { return &bomb1; }						// *
	SDL_Rect* getBomb2() { return &bomb2; }						// *

	void destroyApple();										// *
	void destroyBanana();										// *
	void destroyCherry();										// Destroys respective fruit
	void destroyMelon();										// *
	void destroyOrange();										// *
	void destroyMango();										// *
};