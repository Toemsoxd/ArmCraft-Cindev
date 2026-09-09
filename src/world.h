#ifndef ARMCRAFT_WORLD_H
#define ARMCRAFT_WORLD_H

#include "ce_types.h"
#include "block.h"

/* Deliberately small first target. These values can be raised after profiling. */
#define AC_CHUNK_SIZE_X 16
#define AC_CHUNK_SIZE_Z 16
#define AC_CHUNK_HEIGHT 64

struct ACWorld {
    ac_u8 blocks[AC_CHUNK_SIZE_X * AC_CHUNK_HEIGHT * AC_CHUNK_SIZE_Z];
};

void AC_WorldInit(ACWorld* world);
ac_u8 AC_WorldGet(const ACWorld* world, ac_s32 x, ac_s32 y, ac_s32 z);
void AC_WorldSet(ACWorld* world, ac_s32 x, ac_s32 y, ac_s32 z, ac_u8 id);
void AC_WorldGenerateFlat(ACWorld* world);

#endif
