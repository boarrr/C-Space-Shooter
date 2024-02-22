#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "defs.h"
#pragma once

typedef struct 
{
  SDL_Renderer *renderer;
  SDL_Window *window;
  SDL_Texture *background;
  TTF_Font *font;
  SDL_Texture *menutext;
  int start;
  int left;
  int right;
  int shoot;
} App;

typedef struct
{
  int x;
  int y;
  int dx;
  int dy;
  int health;
  SDL_Texture *texture;
} Entity;

extern App app;
extern Entity player;
extern Entity enemy;
extern Entity bullet;

extern Mix_Chunk *sounds[NUM_SOUNDS];
