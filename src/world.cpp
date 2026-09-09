#include "world.h"

static ac_bool AC_InBounds(ac_s32 x, ac_s32 y, ac_s32 z)
{
    return x >= 0 && x < AC_CHUNK_SIZE_X &&
           y >= 0 && y < AC_CHUNK_HEIGHT &&
           z >= 0 && z < AC_CHUNK_SIZE_Z;
}

static ac_u32 AC_Index(ac_s32 x, ac_s32 y, ac_s32 z)
{
    return (ac_u32)((y * AC_CHUNK_SIZE_Z + z) * AC_CHUNK_SIZE_X + x);
}

void AC_WorldInit(ACWorld* world)
{
    ac_u32 i;
    for (i = 0; i < (ac_u32)(AC_CHUNK_SIZE_X * AC_CHUNK_HEIGHT * AC_CHUNK_SIZE_Z); ++i)
        world->blocks[i] = AC_BLOCK_AIR;
}

ac_u8 AC_WorldGet(const ACWorld* world, ac_s32 x, ac_s32 y, ac_s32 z)
{
    if (!AC_InBounds(x, y, z))
        return AC_BLOCK_AIR;
    return world->blocks[AC_Index(x, y, z)];
}

void AC_WorldSet(ACWorld* world, ac_s32 x, ac_s32 y, ac_s32 z, ac_u8 id)
{
    if (!AC_InBounds(x, y, z))
        return;
    world->blocks[AC_Index(x, y, z)] = id;
}

void AC_WorldGenerateFlat(ACWorld* world)
{
    ac_s32 x, y, z;
    AC_WorldInit(world);

    for (x = 0; x < AC_CHUNK_SIZE_X; ++x) {
        for (z = 0; z < AC_CHUNK_SIZE_Z; ++z) {
            AC_WorldSet(world, x, 0, z, AC_BLOCK_STONE);
            AC_WorldSet(world, x, 1, z, AC_BLOCK_DIRT);
            AC_WorldSet(world, x, 2, z, AC_BLOCK_GRASS);
        }
    }
}
