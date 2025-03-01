#pragma once
#include <SDL.h>
#include <string>
#include <stdexcept>

// Example setup and teardown for SDL in a unit test
class SDLTestFixture {
public:
    SDLTestFixture() {
        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            throw std::runtime_error("SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));
        }
    }

    ~SDLTestFixture() {
        // Clean up SDL
        SDL_Quit();
    }
};