#pragma once
#include <SDL3/SDL.h>

namespace quicksilver
{
    extern SDL_Window* window;
    extern SDL_Renderer* renderer;

    extern SDL_Event* event;

    int core_init();
    bool core_is_running;
    void core_events();
    void core_quit();
    
    void graphics_set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    void graphics_clear(uint8_t r, uint8_t g, uint8_t b);
    void graphics_present();
}