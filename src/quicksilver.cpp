#include "quicksilver.hpp"

SDL_Window* quicksilver::window = nullptr;
SDL_Renderer* quicksilver::renderer = nullptr;

SDL_Event* quicksilver::event;

void log_error() {
    SDL_LogError(SDL_LOG_PRIORITY_ERROR, SDL_GetError());
}

int quicksilver::core_init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        log_error();
        return 1;
    }
    
    window = SDL_CreateWindow("Quicksilver", 1024, 576, SDL_WINDOW_HIGH_PIXEL_DENSITY);
    if (window == NULL) {
        log_error();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        log_error();
        return 1;
    }

    core_is_running = true;
    return 0;
}

void quicksilver::core_events() {
    while (SDL_PollEvent(event)) {
        if (event->type == SDL_EVENT_QUIT) {
            core_is_running = false;
        }
    }
}

void quicksilver::core_quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    SDL_Quit();
}

void quicksilver::graphics_set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void quicksilver::graphics_clear(uint8_t r, uint8_t g, uint8_t b) {
    quicksilver::graphics_set_color(r, g, b, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void quicksilver::graphics_present() {
    SDL_RenderPresent(renderer);
}