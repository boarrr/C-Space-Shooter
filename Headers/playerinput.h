#ifndef PLAYERINPUTS_H
#define PLAYERINPUTS_H

#include <SDL.h>

void doKeyDown(SDL_KeyboardEvent *event);
void doKeyUp(SDL_KeyboardEvent *event);
void getGameInput(void);

#endif // PLAYERINPUTS_H