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

TTF_Font *loadFont(char *file, int size)
{
  TTF_Font *font = TTF_OpenFont(file, size);

  if (font == NULL)
  {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Failed to load font: %s", file);
    exit(1);
  }

  return font;
}


SDL_Texture *renderText(char *text, TTF_Font *font, SDL_Color color)
{
  SDL_Surface *surface;
  SDL_Texture *texture;

  surface = TTF_RenderText_Solid(font, text, color);

  if (surface == NULL)
  {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Failed to render text: %s", TTF_GetError());
    exit(1);
  }


  texture = SDL_CreateTextureFromSurface(app.renderer, surface);

  if (texture == NULL)
  {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Failed to create texture from surface: %s", SDL_GetError());
    exit(1);
  }

  return texture;
}


void drawText(SDL_Texture *texture, int x, int y, int w, int h)
{
  SDL_Rect dest;

  dest.x = x;
  dest.y = y;

  dest.w = w;
  dest.h = h;

  SDL_RenderCopy(app.renderer, texture, NULL, &dest);
  //SDL_DestroyTexture(texture);
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

