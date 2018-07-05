#include <iostream>
#include <SDL.h>

using namespace std;

#define window_w 800
#define window_h 600
#define image_cut "cut.bmp"
#define default_xy 0
#define default_wh 100

int main(
	int argc, char **argv
) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow(
		"window",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		window_w, window_h,
		SDL_WINDOW_OPENGL
	);

	SDL_Surface *surface_cut = SDL_LoadBMP("cut.bmp");
	SDL_SetColorKey(surface_cut, SDL_TRUE, SDL_MapRGB(surface_cut->format, 255, 255, 255));
	SDL_Surface *surface_window = SDL_GetWindowSurface(window);

	SDL_Rect rect; {
		rect.x = surface_cut->w / 2;
		rect.y = surface_cut->h / 2;
		rect.w = surface_cut->w;
		rect.h = surface_cut->h;
	}

	SDL_BlitSurface(surface_cut, &rect, surface_window, NULL);
	SDL_UpdateWindowSurface(window);

	SDL_Renderer *render = SDL_CreateRenderer(window, SDL_TRUE, SDL_RENDERER_ACCELERATED);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(render,surface_window);
	SDL_RenderCopy(render, texture, NULL, NULL);


	SDL_Delay(3000);

	return 0;
}