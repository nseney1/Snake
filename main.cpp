#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <cstdio>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 600

#define WHITE 0xffffffff
#define YELLOW 0xffffff00
#define BLACK 0x00000000
#define RED 0xFF4B33
/*
* Load in Data that defines the state
*
* */

struct Coordinate {
	int x;
	int y;
};

class Food {
public:
	Coordinate coordinate;
	void logInformation() {
		printf("x: %i, y: %i\n", coordinate.x, coordinate.y);
	};
};

class Snake {
public:
	Coordinate headLocation;
	int direction;
	int speed;
	int length;
};

int main() {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	SDL_Surface* surface = SDL_GetWindowSurface(window);

	int isSimulationRunning = 1;
	SDL_Event event;

	SDL_Rect eraseRect = (SDL_Rect) { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };

	srand(time(NULL));
	Food fruit = {(int)(rand() % 56) * 16, (int)(rand() % 37) * 16};
	fruit.logInformation();

	Snake snake = {{16, 16}, 1, 1, 1};

	while (isSimulationRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				isSimulationRunning = 0;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				// Replace with collision detection. add size and speed to length of snake
				srand(time(NULL));
				fruit = {(int)(rand() % 56) * 16, (int)(rand() % 37) * 16};
				fruit.logInformation();
			}
		}

		SDL_FillRect(surface, &eraseRect, BLACK);

		for (int y=0; y<WINDOW_HEIGHT; y++) {
			for (int x=0; x<WINDOW_WIDTH; x++) {
				int x_pos = x * 16;
				int y_pos = y * 16;

				if (fruit.coordinate.x == x_pos && fruit.coordinate.y == y_pos) {
					SDL_Rect foodRect = (SDL_Rect) { x_pos, y_pos, 8, 8 };
					SDL_FillRect(surface, &foodRect, WHITE);
				}
			}
		}

		SDL_UpdateWindowSurface(window);
		SDL_Delay(5);
	}
}

