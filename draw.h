#ifndef DRAW_H
#define DRAW_H

#include <SDL_image.h>

void prepareScene(void);
void presentScene(void);
void menuScene(void);
void cleanup(void);
SDL_Texture *loadTexture(char *file);
void draw(SDL_Texture *texture, int x, int y, int angle, int w, int h);

#endif // DRAW_H
