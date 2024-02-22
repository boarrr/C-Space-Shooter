#include "defs.h"
#include "sounds.h"
#include "structs.h"
#include <SDL.h>

void doKeyDown(SDL_KeyboardEvent *);
void doKeyUp(SDL_KeyboardEvent *);

void getMenuInput(void) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) 
  {
    switch (event.type) 
    {
      case SDL_QUIT: 
      {
        exit(0);
        break;
      }

      case SDL_KEYDOWN: 
      {
        if(event.key.keysym.sym == SDLK_ESCAPE) exit(0);

        if (event.key.keysym.sym == SDLK_SPACE && !app.start) app.start = 1;
      }

      default: 
      {
        break;
      }
    }
  }
}
