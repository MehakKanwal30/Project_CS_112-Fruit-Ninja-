// Including the Game header file
#include "Game.h"

// Constructor
Game::Game() {
	isRunning = false;
	runMenu = false;
	b = Background();
	p = Player();
	f = Fruit_Bomb();
	m = Menu();
}

// Initializes basic components of the program
void Game::Initialization() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "Initialized" << endl;

		// Creates window for game running
		window = SDL_CreateWindow("Fruit Slicer", NULL, NULL, 1920, 1080, SDL_WINDOW_SHOWN);
		if (window) {
			cout << "Window Created" << endl;
		}
		// Creates renderer for game running
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			cout << "Renderer Created" << endl;
		}

		isRunning = true;
		runMenu = true;
		
		// Initialize font file
		TTF_Init();
		font = TTF_OpenFont("Peepo.ttf", 30);

		// Initialize music file
		SDL_Init(SDL_INIT_AUDIO);
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			cout << "Error" << endl;

		// Creates textures
		b.CreateBackgroundTexture(renderer);
		p.CreatePlayerTexture(renderer);
		f.CreateFruitBombTexture(renderer);
		m.CreateMenuTexture(renderer);

		gameBackground = MusicManager::LoadMusic("Image/gameBack.mp3");
		gameOver = MusicManager::LoadChunk("Image/GameOver.wav");
	}
	else
		isRunning = false;										// If initialization fails game quits
}

// Handles all the user input
void Game::handleEvent() {
	SDL_Event event;
	
	// Processing of read input
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)										// If window is closed, game quits
			isRunning = false;

		if (event.type == SDL_KEYDOWN) {								
			if (event.key.keysym.sym == SDLK_ESCAPE) { runMenu = true; }	// During game pressing escape pauses the game
			if (event.key.keysym.sym == SDLK_m) { 
				if (Mix_PausedMusic())									
					Mix_ResumeMusic();									// Press m to play music
				else
					Mix_PauseMusic();									// Press m to pause music
			}									
		}

		if (event.type == SDL_MOUSEMOTION) {							// All mouse interaction and input

			if (event.button.button == SDL_BUTTON_LMASK) {				// When LMB is pressed, fruit is destroyed 
				if (SDL_HasIntersection(p.getKnife(), f.getApple()))
					f.destroyApple();
				if (SDL_HasIntersection(p.getKnife(), f.getBanana()))
					f.destroyBanana();
				if (SDL_HasIntersection(p.getKnife(), f.getCherry()))
					f.destroyCherry();
				if (SDL_HasIntersection(p.getKnife(), f.getMelon()))
					f.destroyMelon();
				if (SDL_HasIntersection(p.getKnife(), f.getOrange()))
					f.destroyOrange();
				if (SDL_HasIntersection(p.getKnife(), f.getMango()))
					f.destroyMango();
				if (SDL_HasIntersection(p.getKnife(), f.getBomb1()) || SDL_HasIntersection(p.getKnife(), f.getBomb2())) {
					f.BlowBomb(renderer);
					GameOver();
				}
			}
			p.Event(event.motion.x, event.motion.y);			// Sends mouse position
		}
	}
	// Running of menu controlled here
	if (runMenu == true) {
		int run = m.showMenu(renderer);							// Displays the menu
		runMenu = false;
		if (run == 1)
			isRunning = false;
		Mix_HaltMusic();
		MusicManager::PlayMusic(gameBackground);
	}
}

// Updates program with any changes that occur
void Game::Update() {
	f.Update();
	if (f.getMissedAll())
		GameOver();
}

// Renders all visuals on the screen
void Game::Render() {
	SDL_RenderClear(renderer);
	b.Render(renderer);
	f.Render(renderer);
	p.Render(renderer);
	SDL_RenderPresent(renderer);
}

// Cleans memory after game ends
void Game::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_CloseFont(font);
	Mix_FreeMusic(gameBackground);
	Mix_FreeChunk(gameOver);
	b.Clear();
	p.Clear();
	f.Clear();
	m.Clear();
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
}

// GameOver screen displayed, along with points scored
void Game::GameOver() {
	MusicManager::PlayChunk(gameOver);
	SDL_Texture* endTex;
	endTex = TextureManager::Texture("Image/background2.jpg", renderer);
	SDL_Color color;
	SDL_Rect r;
	r.x = r.y = r.w = r.h = 0;

	// Loop for rendering Game Over screen
	for (int i = 0; i < 500; i++) {
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, endTex, NULL, NULL);
		color.r = 255, color.b = color.g = 0;
		f.write("GAME OVER", 180, color, renderer, r, (WIDTH / 2 - 450), (HEIGHT / 2 - 300));
		color.r = color.g = color.b = 255;
		f.write("POINTS", 80, color, renderer, r, (WIDTH / 2 - 140), (HEIGHT / 2 - 60));
		string score = to_string(f.getTotalScore());
		f.write(score, 50, color, renderer, r, (WIDTH / 2 - 50), (HEIGHT / 2 + 70));
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(endTex);

	// Choice for restarting or closing game
	int run = m.showMenu(renderer);
	if (run == 1)
		isRunning = false;
	else
		f.Restart();
	Mix_HaltMusic();
	MusicManager::PlayMusic(gameBackground);
}