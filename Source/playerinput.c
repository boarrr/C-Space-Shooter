#include "defs.h"
#include "structs.h"
#include "sounds.h"
#include <SDL.h>

void doKeyDown(SDL_KeyboardEvent *);
void doKeyUp(SDL_KeyboardEvent *);

void getGameInput(void) 
{
  SDL_Event gameEvent;

  while (SDL_PollEvent(&gameEvent)) 
  {
    switch (gameEvent.type) 
    {

      case SDL_QUIT: 
      {
        exit(0);
        break;
      }

      case SDL_KEYDOWN: 
      {
        doKeyDown(&gameEvent.key);
        break;
      }

      case SDL_KEYUP: 
      {
        doKeyUp(&gameEvent.key);
        break;
      }

      default: 
      {
        break;
      }
    }
  }

  // Move the player left or right
  if (app.left) player.x -= SPEED;

  if (app.right) player.x += SPEED;
  
  // Keep the player within the screen
  if (player.x < 0) player.x = 0;

  else if (player.x > SCREEN_WIDTH - PLAYER_WIDTH) player.x = SCREEN_WIDTH - PLAYER_WIDTH;
  

  // Create a bullet if the player is shooting
  if (app.shoot && bullet.health == 0) 
  {
    bullet.x = player.x;
    bullet.y = player.y;
    bullet.health = 1;

    playSound(0, 0);
  }

  // Move the bullet
  if (bullet.health > 0) 
  {
    bullet.y -= BULLET_SPEED;

    // If the bullet goes off the screen, kill it
    if (bullet.y < 0) bullet.health = 0;
  }
}

void doKeyDown(SDL_KeyboardEvent *event) 
{

  if (event->repeat == 0) 
  {
    switch (event->keysym.scancode) 
    {
      case SDL_SCANCODE_LEFT: 
      {
        app.left = 1;
        break;
      }

      case SDL_SCANCODE_RIGHT: 
      {
        app.right = 1;
        break;
      }

      case SDL_SCANCODE_SPACE: 
      {
        Mix_PlayChannel(-1, sounds[0], 0);
        app.shoot = 1;
        break;
      }

      case SDL_SCANCODE_ESCAPE: 
      {
        exit(0);
        break;
      }

      default:
      {
        break;
      }
    }
  }
}

void doKeyUp(SDL_KeyboardEvent *event) 
{
  switch (event->keysym.scancode) 
  {
    case SDL_SCANCODE_LEFT: 
    {
      app.left = 0;
      break;
    }

    case SDL_SCANCODE_RIGHT:
    {
      app.right = 0;
      break;
    }

    case SDL_SCANCODE_SPACE: 
    {
      app.shoot = 0;
      break;
    }

    default: 
    {
      break;
    }
  }
}
