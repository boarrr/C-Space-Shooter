/*
  Description: A simple space shooting game coded in C using the SDL library.
  Author: Ryan Pitman
*/

#include "draw.h"
#include "enemy.h"
#include "initialise.h"
#include "inputs.h"
#include "sounds.h"
#include "structs.h"
#include <stdlib.h>
#include <string.h>

App app;
Entity player;
Entity bullet;
Entity enemy;

Mix_Chunk *sounds[NUM_SOUNDS];

int main(void) {
  memset(&app, 0, sizeof(App));
  memset(&player, 0, sizeof(Entity));
  memset(&bullet, 0, sizeof(Entity));
  memset(&enemy, 0, sizeof(Entity));

  // Initialise the window
  initWindow();

  // Initialise the sound
  initSound();

  // Load the background texture
  app.background = loadTexture("Assets/space.jpeg");

  // Set the start parameter to 0
  app.start = 0;

  // Load the player texture and set the player's position
  player.x = (SCREEN_WIDTH / 2) - 100;
  player.y = (SCREEN_HEIGHT)-150;
  player.health = 1;
  player.texture = loadTexture("Assets/player.png");

  // Load the bullet texture
  bullet.texture = loadTexture("Assets/bullet.png");

  // Load the enemy texture
  enemy.texture = loadTexture("Assets/meteor.png");
  enemy.health = 0;

  // Clean up when the program exits
  atexit(cleanup);

  // Main game loop
  while (1) {
    prepareScene();
    getInput();

    draw(player.texture, player.x, player.y, 0, PLAYER_WIDTH, PLAYER_HEIGHT);

    if (bullet.health > 0) draw(bullet.texture, bullet.x, bullet.y, -90, BULLET_WIDTH, BULLET_HEIGHT);

    spawnEnemy();

    if (enemy.health > 0) draw(enemy.texture, enemy.x, enemy.y, 0, ENEMY_WIDTH, ENEMY_HEIGHT);
    
    if (player.health == 0) break;

    presentScene();

    SDL_Delay(16); // 16 milliseconds is roughly 60 frames per second
  }

  return 0;
}
