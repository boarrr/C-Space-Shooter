#ifndef DRAW_H
#define DRAW_H

#include <SDL_image.h>
#include <SDL_ttf.h>

void prepareScene(void);
void presentScene(void);
void menuScene(void);
void cleanup(void);
SDL_Texture *loadTexture(char *file);
TTF_Font *loadFont(char *file, int size);
void draw(SDL_Texture *texture, int x, int y, int angle, int w, int h);
SDL_Texture *renderText(char *text, TTF_Font *font, SDL_Color color);
void drawText(SDL_Texture *texture, int x, int y, int w, int h);

#endif // DRAW_H
