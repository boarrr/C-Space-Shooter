#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "structs.h"
#include "defs.h"

void initWindow(void)
{
  int rendererFlags, windowFlags;
 
  rendererFlags = SDL_RENDERER_ACCELERATED;
  windowFlags = 0;

  IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not intialise! SDL_Error: %s\n", SDL_GetError());
    exit(1);
  }

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
		printf("Couldn't initialize SDL Mixer\n");
		exit(1);
	}

	Mix_AllocateChannels(MAX_SND_CHANNELS);

  app.window = SDL_CreateWindow("Rooty Tooty Point and Shooty", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

  if (!app.window)
  {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    exit(1);
  }

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

  if (!app.renderer)
  {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    exit(1);
  }

  if (TTF_Init() == -1)
  {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(1);
  }
}
