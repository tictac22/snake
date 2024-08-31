#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int const BLOCK_SIZE = 40;
int const WINDOW_HEIGHT = 400;
int const WINDOW_WIDTH = 400;
int main()
{ 
    SDL_Window* window = SDL_CreateWindow("A line", 10, 10, 1200, 600, false);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetWindowSize(window, WINDOW_WIDTH, WINDOW_HEIGHT);

    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (int i = 0; i < WINDOW_WIDTH; i += BLOCK_SIZE) {
            for (int j = 0; j < WINDOW_HEIGHT; j += BLOCK_SIZE) {
                SDL_Rect rect;
                rect.w = BLOCK_SIZE;
                rect.h = BLOCK_SIZE;
                rect.x = i;
                rect.y = j;
                SDL_RenderDrawRect(renderer, &rect);
            }
        }
        SDL_RenderPresent( renderer );
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}