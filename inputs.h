#ifndef INPUTS_H
#define INPUTS_H

#include <SDL.h>

void doKeyDown(SDL_KeyboardEvent *event);
void doKeyUp(SDL_KeyboardEvent *event);
void getInput(void);

#endif // INPUTS_H
