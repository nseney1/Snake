#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>

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

	Food fruit = {256, 256};

	while (isSimulationRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				isSimulationRunning = 0;
			}
		}

		for (int y=0; y<WINDOW_HEIGHT; y++) {
			for (int x=0; x<WINDOW_WIDTH; x++) {
				int x_pos = x * 16;
				int y_pos = y * 16;
				if (fruit.coordinate.x == x_pos && fruit.coordinate.y == y_pos) {
					SDL_Rect eraseRect = (SDL_Rect) { x_pos, y_pos, 8, 8 };
					SDL_FillRect(surface, &eraseRect, WHITE);
				}
			}
		}

		SDL_UpdateWindowSurface(window);
		SDL_Delay(5);
	}
}

