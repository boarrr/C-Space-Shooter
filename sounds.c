#include "defs.h"
#include "structs.h"

static void loadSounds();
void playSound(int sound, int channel);

void initSound()
{
  memset(sounds, 0, sizeof(Mix_Chunk*) * NUM_SOUNDS);

  loadSounds();
}

static void loadSounds()
{
  sounds[0] = Mix_LoadWAV("Assets/blaster.wav");
}

void playSound(int sound, int channel)
{
  Mix_PlayChannel(channel, sounds[sound], 0);
}