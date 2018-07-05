#pragma once

#ifdef DEBUG
#include <SDL.h>
#include <iostream>

using namespace std;

#define window_width 800
#define window_hight 600
#define image_side_length 20
#define defalt_position 0
#define delay_time 50
#define rand_rgba rand() % 255 + 1
#define rand_truefalse rand() % 2
#define imagename_1 "1.bmp" 
#define imagename_0 "0.bmp" 

SDL_Window * Init_window(const char * window_name);
SDL_Renderer * Init_rend(SDL_Window * window);
void video01(SDL_Renderer * rend);
void video01_cycle(SDL_Renderer * rend, SDL_Rect rect, SDL_Texture * image_1, SDL_Texture * image_0);
void present_video01();

#endif