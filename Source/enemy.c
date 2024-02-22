#include <SDL.h>
#include "defs.h"
#include "structs.h"

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

  // Check for a collision between the player and the enemy
  if (player.x < enemy.x + ENEMY_WIDTH && player.x + PLAYER_WIDTH > enemy.x)
  {
    if (player.y < enemy.y + ENEMY_HEIGHT && player.y + PLAYER_HEIGHT > enemy.y)
    {
      player.health = 0;
    }
  }
}
