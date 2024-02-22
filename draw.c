#include <SDL_image.h>
#include <SDL_ttf.h>
#include "structs.h"


void prepareScene(void)
{
  SDL_RenderClear(app.renderer);
  SDL_RenderCopy(app.renderer, app.background, NULL, NULL);
}


void presentScene(void)
{
  SDL_RenderPresent(app.renderer);
}

void menuScene(void)
{
  
}

void cleanup(void)
{
  if (app.renderer != NULL)
  {
    SDL_DestroyRenderer(app.renderer);
  }

  if (app.window != NULL)
  {
    SDL_DestroyWindow(app.window);
  }

  SDL_Quit();
}

SDL_Texture *loadTexture(char *file)
{
  SDL_Texture *texture;

  SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", file);

  texture = IMG_LoadTexture(app.renderer, file);

  if (texture == NULL)
  {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Failed to load texture: %s", file);
    exit(1);
  }

  return texture;
}


void draw(SDL_Texture *texture, int x, int y, int angle, int w, int h)
{
  SDL_Rect dest;

  dest.x = x;
  dest.y = y;

  dest.w = w;
  dest.h = h;

  SDL_QueryTexture(texture, NULL, NULL, NULL, NULL);

  SDL_RenderCopyEx(app.renderer, texture, NULL, &dest, angle, NULL, SDL_FLIP_NONE);
}

