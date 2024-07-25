#include <SDL2/SDL.h>
#include <iostream>

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow(
        "SDL2 Window",            // Window title
        SDL_WINDOWPOS_CENTERED,   // Initial x position
        SDL_WINDOWPOS_CENTERED,   // Initial y position
        640,                      // Width
        480,                      // Height
        SDL_WINDOW_SHOWN          // Window flags
    );

    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Event loop
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        // You could add rendering code here
    }

    // Clean up
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
