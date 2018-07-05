#ifdef MAIN_0


#define DEBUG
#include "main0.h"

SDL_Window * Init_window(const char * window_name)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window * window = SDL_CreateWindow(
		window_name,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		window_width, window_hight,
		SDL_WINDOW_RESIZABLE
	);

	return window;
}

SDL_Renderer * Init_rend(SDL_Window * window)
{
	SDL_Renderer * rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderClear(rend);

	return rend;
}

void video01(SDL_Renderer * rend)
{
	SDL_Rect rect; {
		rect.x = defalt_position;
		rect.y = defalt_position;
		rect.h = image_side_length;
		rect.w = image_side_length; }

	SDL_Surface * surface_1 = SDL_LoadBMP(imagename_1);
	SDL_SetColorKey(surface_1, SDL_TRUE, SDL_MapRGB(surface_1->format, 0xFF, 0xFF, 0xFF));
	SDL_Texture *image_1 = SDL_CreateTextureFromSurface(rend, surface_1);
	SDL_SetTextureBlendMode(image_1, SDL_BLENDMODE_BLEND);

	SDL_Surface * surface_0 = SDL_LoadBMP(imagename_0);
	SDL_SetColorKey(surface_0, SDL_TRUE, SDL_MapRGB(surface_0->format, 0xFF, 0xFF, 0xFF));
	SDL_Texture *image_0 = SDL_CreateTextureFromSurface(rend, surface_0);
	SDL_SetTextureBlendMode(image_0, SDL_BLENDMODE_BLEND);

	video01_cycle(rend, rect, image_1, image_0);

	SDL_FreeSurface(surface_0);
	SDL_FreeSurface(surface_1);
	SDL_DestroyTexture(image_0);
	SDL_DestroyTexture(image_1);
}
void video01_cycle(SDL_Renderer * rend, SDL_Rect rect, SDL_Texture * image_1, SDL_Texture * image_0)
{
	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&event))
			if (event.type == SDL_QUIT)
				quit = true;

		for (int i = 0; i < window_width / image_side_length; i++)
		{
			for (int j = 0; j < window_hight / image_side_length; j++)
			{
				if (rand_truefalse)
				{
					SDL_SetTextureColorMod(image_1, rand_rgba, rand_rgba, rand_rgba);
					SDL_SetTextureAlphaMod(image_1, rand_rgba);
					SDL_RenderCopy(rend, image_1, NULL, &rect);
					rect.y += image_side_length;
				}
				else
				{
					SDL_SetTextureColorMod(image_0, rand_rgba, rand_rgba, rand_rgba);
					SDL_SetTextureAlphaMod(image_0, rand_rgba);
					SDL_RenderCopy(rend, image_0, NULL, &rect);
					rect.y += image_side_length;
				}
			}
			rect.y = defalt_position;
			rect.x += image_side_length;
		}
		rect.x = defalt_position;
		rect.y = defalt_position;

		SDL_RenderPresent(rend);
		SDL_RenderClear(rend);

		SDL_Delay(delay_time);
	}
}

void present_video01()
{
	SDL_Window * window = Init_window("window");
	SDL_Renderer * rend = Init_rend(window);

	video01(rend);

	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(window);

	SDL_Quit();
}

int main(int argc, char * argv[])
{
	present_video01();

	return 0;
}

#endif



//SDL_Renderer * rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//SDL_RenderClear(rend);

//SDL_Surface * imagesurface = SDL_LoadBMP("image.bmp");
//SDL_Surface * blacksurface = SDL_LoadBMP("black.bmp");

//SDL_Texture * image = SDL_CreateTextureFromSurface(rend, imagesurface);
//SDL_Texture * black = SDL_CreateTextureFromSurface(rend, blacksurface);

//SDL_SetTextureBlendMode(image, SDL_BLENDMODE_BLEND);
//SDL_SetTextureBlendMode(black, SDL_BLENDMODE_BLEND);

//SDL_SetTextureAlphaMod(black, 8);

//SDL_Rect imagerect;
//imagerect.x = 0;
//imagerect.y = 0;
//imagerect.w = imagesurface->w;
//imagerect.h = imagesurface->h;

//SDL_Rect blackrect;
//blackrect.x = 0;
//blackrect.y = 0;
//blackrect.w = 800;
//blackrect.h = 600;

////int alpha = 0;
////int condition = 1;

//SDL_Event event;
//bool quit = false;
//while (!quit)
//{
//	while (SDL_PollEvent(&event))
//	{
//		if (event.type == SDL_QUIT)
//			quit = true;
//		else if (event.type == SDL_MOUSEMOTION)
//		{
//			imagerect.x = event.motion.x - imagerect.w / 2;
//			imagerect.y = event.motion.y - imagerect.h / 2;
//		}
//	}


//	//SDL_SetTextureAlphaMod(image, alpha % 255);
//	//switch (condition)
//	//{
//	//case 1: {alpha++; break; }
//	//case 2: {alpha--; break; }
//	//}
//	//if (alpha == 255)
//	//	condition = 2;
//	//else if (alpha == 0)
//	//	condition = 1;

//	//SDL_RenderClear(rend);
//	SDL_RenderCopy(rend, black, NULL, &blackrect);
//	SDL_RenderCopy(rend, image, NULL, &imagerect);
//	SDL_RenderPresent(rend);

//	SDL_Delay(1);
//}




////u,d,l,r
////condition = rd 1 ,ru 2 ,ld 3 ,lu 4 ;
//int condition = 1;//condition0 = 1

//while (!quit)
//{
//	while (SDL_PollEvent(&event))
//	{
//		if (event.type == SDL_QUIT)
//			quit = true;
//	}
//	switch (condition)
//	{
//	case 1:
//	{
//		rect.x += 1;
//		rect.y += 1;
//		break;
//	}
//	case 2:
//	{
//		rect.x += 1;
//		rect.y -= 1;
//		break;
//	}
//	case 3:
//	{
//		rect.x -= 1;
//		rect.y += 1;
//		break;
//	}
//	case 4:
//	{
//		rect.x -= 1;
//		rect.y -= 1;
//		break;
//	}
//	}
//	if (rect.x + rect.w < 800 && rect.y + rect.h > 600 && rect.x > 0 && rect.y > 0)
//		break;
//	else
//	{
//		if ((condition == 3 && rect.x <= 0) || (condition == 2 && rect.y <= 0))
//			condition = 1;
//		else if ((condition == 4 && rect.x <= 0) || (condition == 1 && rect.y + rect.h >= 600))
//			condition = 2;
//		else if ((condition == 4 && rect.y <= 0) || (condition == 1 && rect.x + rect.w >= 800))
//			condition = 3;
//		else if ((condition == 3 && rect.y + rect.h >= 600) || (condition == 2 && rect.x + rect.w >= 800))
//			condition = 4;
//	}
//	SDL_RenderClear(rend);
//	SDL_RenderCopy(rend, image, NULL, &rect);
//	SDL_RenderPresent(rend);
//	SDL_Delay(50);
//}

//SDL_Event event;

//bool quit = false;
//while (quit == false)
//{
//	while (SDL_PollEvent(&event))
//	{
//		if (event.type == SDL_QUIT)
//			quit = true;
//		if (event.type == SDL_MOUSEMOTION)
//		{
//			rect.x = event.motion.x - rect.w / 2;
//			rect.y = event.motion.y - rect.h / 2;
//			SDL_RenderClear(rend);
//			SDL_RenderCopy(rend, image, NULL, &rect);
//		}
//	}
//	SDL_Delay(5);
//	SDL_RenderPresent(rend);
//}

//for (int j = 0; j < 3; j++)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		SDL_BlitSurface(image, NULL, surface, &rect);
//		rect.x += 270;
//		SDL_UpdateWindowSurface(window);
//		SDL_Delay(50);

//	}
//	rect.x = 0;
//	rect.y += 200;
//	SDL_UpdateWindowSurface(window);
//}