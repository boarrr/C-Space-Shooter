#include <SDL.h>
#include <stdlib.h>
#include "defs.h"
#include "structs.h"
#include "sounds.h"
#include "draw.h"


void spawnEnemy(void)
{
  // Spawn a new enemy if the current one is dead
  if (enemy.health == 0)
  {
    enemy.y = 0 - 100;
    enemy.x = rand() % (SCREEN_WIDTH - ENEMY_WIDTH);
    enemy.health = 1;
  }

  // Move the enemy
  if (enemy.health > 0)
  {
    enemy.y += ENEMY_SPEED;

    if (enemy.y > SCREEN_HEIGHT)
    {
      enemy.health = 0;
    }
  }

   // Check for a collision between the bullet and the enemy
  if (bullet.x < enemy.x + ENEMY_WIDTH && bullet.x + BULLET_WIDTH > enemy.x) 
  {
    if (bullet.y < enemy.y + ENEMY_HEIGHT && bullet.y + BULLET_HEIGHT > enemy.y) 
    {
      bullet.health = 0;
      enemy.health = 0;

      player.score += 1;

      char scoreStr[10];
      sprintf(scoreStr, "%d", player.score);

      player.scoreDigits = strlen(scoreStr);
      
      SDL_DestroyTexture(player.curScore);
      player.curScore = renderText(scoreStr, app.font, (SDL_Color){255, 255, 255, 255});

      playSound(1, 1);
    }
  }


  // Check for a collision between the player and the enemy
  if (player.x < enemy.x + ENEMY_WIDTH && player.x + PLAYER_WIDTH > enemy.x)
  {
    if (player.y < enemy.y + ENEMY_HEIGHT && player.y + PLAYER_HEIGHT > enemy.y)
    {
      player.health = 0;
    }
  }
}
