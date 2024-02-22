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
  Mix_VolumeChunk(sounds[0], MIX_MAX_VOLUME / 4);

  sounds[1] = Mix_LoadWAV("Assets/explosion.wav");
}

void playSound(int sound, int channel)
{
  Mix_PlayChannel(channel, sounds[sound], 0);
}