// Including the Fruit_Bomb header file
#include "Fruit_Bomb.h"

// Constructor for starting values
Fruit_Bomb::Fruit_Bomb() {
	// Setting fruit speed
	aSpeed = 7; bSpeed = 8; cSpeed = 9; mSpeed = 10; oSpeed = 11; manSpeed = 18; bom1Speed = 7; bom2Speed = 9;
	// Setting fruit points
	aPoint = 5; bPoint = 8; cPoint = 12; mPoint = 15; oPoint = 20; manPoint = 50;
	fall = 50;

	color.r = color.b = color.g = 255;

	// Setting width and height of fruits and bombs
	apple.w = banana.w = apple.h = banana.h = 75;
	cherry.w = melon.w = cherry.h = melon.h = 80;
	orange.w = mango.w = orange.h = mango.h = 85;
	bomb1.w = bomb2.w = bomb1.h = bomb2.h = 80;
	// Setting width and height of scoreboard
	scoreFruit.x = scoreFruit.y = 10;
	scoreFruit.w = scoreFruit.h = 70;
	// Setting width and height of crosses (lives)
	one.w = two.w = three.w = four.w = five.w = one.h = two.h = three.h = four.h = five.h = 80;
	one.y = two.y = three.y = four.y = five.y = 10;
	five.x = WIDTH - 90; four.x = WIDTH - 180; three.x = WIDTH - 270; two.x = WIDTH - 360; one.x = WIDTH - 450;

	Restart();
}

// Function to restart the game on command
void Fruit_Bomb::Restart() {
	srand(time(0));

	// All the variables needed to be reset on restart command
	missedAll = false;
	missed = 0;
	totalPoints = 0;

	man1 = 15000; bom11 = 1000; bom21 = 2000;

	a = -60; b = -860; c = -1360; m = -1760; o = -2060; man = -((rand() % 500) + man1);
	bom1 = -((rand() % 500) + bom11); bom2 = -((rand() % 500) + bom21);

	aX = (rand() % (WIDTH - 300)) + 100;
	bX = (rand() % (WIDTH - 300)) + 100;
	cX = (rand() % (WIDTH - 300)) + 100;
	mX = (rand() % (WIDTH - 300)) + 100;
	oX = (rand() % (WIDTH - 300)) + 100;
	manX = (rand() % (WIDTH - 300)) + 100;
	bom1X = (rand() % (WIDTH - 300)) + 100;
	bom2X = (rand() % (WIDTH - 300)) + 100;

	apple.x = aX;
	banana.x = bX;
	cherry.x = cX;
	melon.x = mX;
	orange.x = oX;
	mango.x = manX;
	bomb1.x = bom1X;
	bomb2.x = bom2X;

	apple.y = a; banana.y = b; cherry.y = c; melon.y = m; orange.y = o; mango.y = man;
	bomb1.y = bom1; bomb2.y = bom2;
	
	oneTex = twoTex = threeTex = fourTex = fiveTex = passiveTex;
}

// Creates all textures required in this class
void Fruit_Bomb::CreateFruitBombTexture(SDL_Renderer* ren) {
	aTex = TextureManager::Texture("Image/apple.png", ren);
	bTex = TextureManager::Texture("Image/banana.png", ren);
	cTex = TextureManager::Texture("Image/cherry.png", ren);
	mTex = TextureManager::Texture("Image/melon.png", ren);
	oTex = TextureManager::Texture("Image/orange.png", ren);
	manTex = TextureManager::Texture("Image/mango.png", ren);
	bom1Tex = TextureManager::Texture("Image/bomb1.png", ren);
	bom2Tex = TextureManager::Texture("Image/bomb.2png", ren);
	bom3Tex = TextureManager::Texture("Image/bomb3.png", ren);
	bom4Tex = TextureManager::Texture("Image/bomb4.png", ren);
	bom5Tex = TextureManager::Texture("Image/bomb5.png", ren);
	bom6Tex = TextureManager::Texture("Image/bomb6png", ren);
	bom7Tex = TextureManager::Texture("Image/bomb7.png", ren);
	activeTex = TextureManager::Texture("Image/active.png", ren);
	passiveTex = TextureManager::Texture("Image/passive.png", ren);
	sTex = TextureManager::Texture("Image/score.png", ren);
	oneTex = twoTex = threeTex = fourTex = fiveTex = passiveTex;
	cutSound = MusicManager::LoadChunk("Image/cut.wav");
	dropSound = MusicManager::LoadChunk("Image/dropped.wav");
	bombSound = MusicManager::LoadChunk("Image/bomb.wav");
	mangoCut = MusicManager::LoadChunk("Image/mangoCut.wav");
}

// All updates are controlled in this function
void Fruit_Bomb::Update() {
	// Moving of fruits and bombs by increasing "y" value
	apple.y += aSpeed;
	banana.y += bSpeed;
	cherry.y += cSpeed;
	melon.y += mSpeed;
	orange.y += oSpeed;
	mango.y += manSpeed;
	bomb1.y += bom1Speed;
	bomb2.y += bom2Speed;

	// Changing of cross texture
	if (missed > 0) {
		oneTex = activeTex;
		if (missed > 1) {
			twoTex = activeTex;
			if (missed > 2) {
				threeTex = activeTex;
				if (missed > 3) {
					fourTex = activeTex;
					if (missed > 4) {
						fiveTex = activeTex;
						missedAll = true;
					}
					else
						fiveTex = passiveTex;
				}
				else
					fourTex = passiveTex;
			}
			else
				threeTex = passiveTex;
		}
		else
			twoTex = passiveTex;
	}
	else
		oneTex = passiveTex;

	// If object falls below the screen it is reset
	if (apple.y > HEIGHT) {
		missed += 1;
		apple.x = (rand() % (WIDTH - 300)) + 100; apple.y = a;
		MusicManager::PlayChunk(dropSound);
	}
	if (banana.y > HEIGHT) {
		missed += 1;
		banana.x = (rand() % (WIDTH - 300)) + 100; banana.y = b;
		if (b < -60)
			b += 50;
		MusicManager::PlayChunk(dropSound);
	}
	if (cherry.y > HEIGHT) {
		missed += 1;
		cherry.x = (rand() % (WIDTH - 300)) + 100; cherry.y = c;
		if (c < -60)
			c += 50;
		MusicManager::PlayChunk(dropSound);
	}
	if (melon.y > HEIGHT) {
		missed += 1;
		melon.x = (rand() % (WIDTH - 300)) + 100; melon.y = m;
		if (m < -60)
			m += 50;
		MusicManager::PlayChunk(dropSound);
	}
	if (orange.y > HEIGHT) {
		missed += 1;
		orange.x = (rand() % (WIDTH - 300)) + 100; orange.y = o;
		if (o < -60)
			o += 50;
		MusicManager::PlayChunk(dropSound);
	}
	if (mango.y > HEIGHT) {
		mango.x = (rand() % (WIDTH - 300)) + 100; mango.y = -((rand() % 500) + man1);
		if (man1 > 5000)
			man1 -= fall;
	}
	if (bomb1.y > HEIGHT) {
		bomb1.x = (rand() % (WIDTH - 300)) + 100;
		bomb1.y = -((rand() % 50) + bom11);
		if (bom11 > 50)
			bom11 -= fall;
	}
	if (bomb2.y > HEIGHT) {
		bomb2.x = (rand() % (WIDTH - 300)) + 100;
		bomb2.y = -((rand() % 50) + bom21);
		if (bom11 > 150)
			bom11 -= fall;
	}
	
	// Updates score according to the new score
	score = to_string(totalPoints);
}

// Function to display text on screen
// Took help from a youtube video for this function but changed it as needed in my game
void Fruit_Bomb::write(string text, int SIZE, SDL_Color color, SDL_Renderer* ren, SDL_Rect board, int x, int y) {
	font = TTF_OpenFont("Peepo.ttf", SIZE);
	SDL_Surface* surface;
	SDL_Texture* texture;
	const char* t = text.c_str();
	surface = TTF_RenderText_Solid(font, t, color);
	texture = SDL_CreateTextureFromSurface(ren, surface);
	board.w = surface->w;
	board.h = surface->h;
	board.x = x;
	board.y = y;
	SDL_FreeSurface(surface);
	SDL_RenderCopy(ren, texture, NULL, &board);
	SDL_DestroyTexture(texture);
}

// Rendering of all objects handled here
void Fruit_Bomb::Render(SDL_Renderer* ren) {
	// Rendering of all crosses
	SDL_RenderCopy(ren, oneTex, NULL, &one);
	SDL_RenderCopy(ren, twoTex, NULL, &two);
	SDL_RenderCopy(ren, threeTex, NULL, &three);
	SDL_RenderCopy(ren, fourTex, NULL, &four);
	SDL_RenderCopy(ren, fiveTex, NULL, &five);
	SDL_RenderCopy(ren, sTex, NULL, &scoreFruit);
	
	// Rendering of fruits and bombs
	if (!missedAll) {
		SDL_RenderCopy(ren, aTex, NULL, &apple);
		SDL_RenderCopy(ren, bTex, NULL, &banana);
		SDL_RenderCopy(ren, cTex, NULL, &cherry);
		SDL_RenderCopy(ren, mTex, NULL, &melon);
		SDL_RenderCopy(ren, oTex, NULL, &orange);
		SDL_RenderCopy(ren, manTex, NULL, &mango);
		SDL_RenderCopy(ren, bom1Tex, NULL, &bomb1);
		SDL_RenderCopy(ren, bom1Tex, NULL, &bomb2);
	}

	// Displaying current score
	write(score, 45, color, ren, scoreBoard, 90, 10);
}

// Clears memory
void Fruit_Bomb::Clear() {
	SDL_DestroyTexture(aTex);
	SDL_DestroyTexture(bTex);
	SDL_DestroyTexture(cTex);
	SDL_DestroyTexture(mTex);
	SDL_DestroyTexture(oTex);
	SDL_DestroyTexture(manTex);
	SDL_DestroyTexture(bom1Tex);
	SDL_DestroyTexture(bom2Tex);
	SDL_DestroyTexture(bom3Tex);
	SDL_DestroyTexture(bom4Tex);
	SDL_DestroyTexture(bom5Tex);
	SDL_DestroyTexture(bom6Tex);
	SDL_DestroyTexture(bom7Tex);
	SDL_DestroyTexture(activeTex);
	SDL_DestroyTexture(passiveTex);
	SDL_DestroyTexture(sTex);
	SDL_DestroyTexture(oneTex);
	SDL_DestroyTexture(twoTex);
	SDL_DestroyTexture(threeTex);
	SDL_DestroyTexture(fourTex);
	SDL_DestroyTexture(fiveTex);
	TTF_CloseFont(font);
	Mix_FreeChunk(cutSound);
	Mix_FreeChunk(bombSound);
	Mix_FreeChunk(dropSound);
	Mix_FreeChunk(mangoCut);
}

// Function to destroy apple when it is cut by knife
void Fruit_Bomb::destroyApple() {
	totalPoints += aPoint;
	apple.x = (rand() % (WIDTH - 300)) + 100; apple.y = a;
	MusicManager::PlayChunk(cutSound);
}
// Function to destroy banana when it is cut by knife
void Fruit_Bomb::destroyBanana() {
	totalPoints += bPoint;
	banana.x = (rand() % (WIDTH - 300)) + 100; banana.y = b;
	if (b < -60)
		b += fall;
	MusicManager::PlayChunk(cutSound);
}
// Function to destroy cherry when it is cut by knife
void Fruit_Bomb::destroyCherry() {
	totalPoints += cPoint;
	cherry.x = (rand() % (WIDTH - 300)) + 100; cherry.y = c;
	if (c < -60)
		c += fall;
	MusicManager::PlayChunk(cutSound);
}
// Function to destroy melon when it is cut by knife
void Fruit_Bomb::destroyMelon() {
	totalPoints += mPoint;
	melon.x = (rand() % (WIDTH - 300)) + 100; melon.y = m;
	if (m < -60)
		m += fall;
	MusicManager::PlayChunk(cutSound);
}
// Function to destroy orange when it is cut by knife
void Fruit_Bomb::destroyOrange() {
	totalPoints += oPoint;
	orange.x = (rand() % (WIDTH - 300)) + 100; orange.y = o;
	if (o < -60)
		o += fall;
	MusicManager::PlayChunk(cutSound);
}
// Function to destroy mango when it is cut by knife
void Fruit_Bomb::destroyMango() {
	totalPoints += manPoint;
	if(missed > 0)
		missed -= 1;
	mango.x = (rand() % (WIDTH - 300)) + 100; mango.y = -((rand() % 500) + man1);
	if (man1 > 5000)
		man1 -= fall;
	MusicManager::PlayChunk(mangoCut);
}

// Displaying texture on screen
void Fruit_Bomb::Bomb(SDL_Renderer* ren, SDL_Texture* texture) {
	for (int i = 0; i < 100; i++) {
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren, 50, 50, 50, 255);
		SDL_RenderCopy(ren, texture, NULL, NULL);
		SDL_RenderPresent(ren);
	}
}
// If bomb is cut, the blowing animation is played
void Fruit_Bomb::BlowBomb(SDL_Renderer* ren) {
	MusicManager::PlayChunk(bombSound);
	Bomb(ren, bom1Tex);
	Bomb(ren, bom2Tex);
	Bomb(ren, bom3Tex);
	Bomb(ren, bom4Tex);
	Bomb(ren, bom5Tex);
	Bomb(ren, bom6Tex);
	Bomb(ren, bom7Tex);
}