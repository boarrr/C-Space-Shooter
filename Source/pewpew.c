/*
  Description: A simple space shooting game coded in C using the SDL library.
  Author: Ryan Pitman
*/

#include "draw.h"
#include "enemy.h"
#include "initialise.h"
#include "menuinputs.h"
#include "playerinput.h"
#include "sounds.h"
#include "structs.h"
#include <stdlib.h>
#include <string.h>

App app;
Entity player;
Entity bullet;
Entity enemy;

Mix_Chunk *sounds[NUM_SOUNDS];

int main(void)
{
  memset(&app, 0, sizeof(App));
  memset(&player, 0, sizeof(Entity));
  memset(&bullet, 0, sizeof(Entity));
  memset(&enemy, 0, sizeof(Entity));

  char scoreStr[10];

  // Initialise the window
  initWindow();

  // Initialise the sound
  initSound();

  // Load the game textures
  app.background = loadTexture("Assets/space.jpeg");
  player.texture = loadTexture("Assets/player.png");
  player.death = loadTexture("Assets/explosion.png");
  bullet.texture = loadTexture("Assets/bullet.png");
  enemy.texture = loadTexture("Assets/meteor.png");
  enemy.death = loadTexture("Assets/explosion.png");

  // Load the font and create the surface for the menu text
  app.font = loadFont("Assets/white-rabbit.ttf", 24);
  app.menutext = renderText(MENU_TEXT, app.font, (SDL_Color){255, 255, 255, 255});
  app.scoreText = renderText(SCORE_TEXT, app.font, (SDL_Color){255, 255, 255, 255});
  app.deathText = renderText(DEAD_TEXT, app.font, (SDL_Color){255, 255, 255, 255});

  
  // Clean up when the program exits
  atexit(cleanup);


  restart: 
    // Set the start parameters
    app.start = 0;
    player.x = (SCREEN_WIDTH / 2) - 100;
    player.y = (SCREEN_HEIGHT)-150;
    player.health = 1;
    player.score = 0;
    player.scoreDigits = 1;
    enemy.health = 0;

    // Create the surface for the score text
    sprintf(scoreStr, "%d", player.score);
    player.curScore = renderText(scoreStr, app.font, (SDL_Color){255, 255, 255, 255});


  // Main game loop
  while (1) 
  {
    prepareScene();

    if (app.death > 0)
    {
      drawText(app.deathText, (SCREEN_WIDTH / 2) - (MENU_TXT_WIDTH / 2), SCREEN_HEIGHT / 2, MENU_TXT_WIDTH, MENU_TXT_HEIGHT);
      presentScene();
      SDL_Delay(1500);
      app.death = 0;
      continue;
    }

    if (app.start == 0) 
    {
      drawText(app.menutext, (SCREEN_WIDTH / 2) - (MENU_TXT_WIDTH / 2), SCREEN_HEIGHT / 2, MENU_TXT_WIDTH, MENU_TXT_HEIGHT);
      getMenuInput();
      presentScene();
      continue;
    }

    getGameInput();

    // Draw the score text
    drawText(app.scoreText, 10, 10, SCORE_TXT_WIDTH, SCORE_TXT_HEIGHT);
    drawText(player.curScore, 150, 10, (DIGIT_WIDTH * player.scoreDigits), SCORE_TXT_HEIGHT);

    // Draw the player
    draw(player.texture, player.x, player.y, 0, PLAYER_WIDTH, PLAYER_HEIGHT);

    // If the bullet is alive, draw it
    if (bullet.health > 0) draw(bullet.texture, bullet.x, bullet.y, -90, BULLET_WIDTH, BULLET_HEIGHT);

    // Spawn the enemy
    spawnEnemy();

    // Draw the enemy if it is alive, otherwise draw the death texture
    if (enemy.health > 0) draw(enemy.texture, enemy.x, enemy.y, 0, ENEMY_WIDTH, ENEMY_HEIGHT);
    else draw(enemy.death, enemy.x, enemy.y, 0, ENEMY_WIDTH, ENEMY_HEIGHT);
    
    // If the player is dead, end the game
    if (player.health == 0) 
    {
      app.death = 1;
      goto restart;
    }

    presentScene();

    SDL_Delay(16); // 16 milliseconds is roughly 60 frames per second
  }

  return 0;
}
