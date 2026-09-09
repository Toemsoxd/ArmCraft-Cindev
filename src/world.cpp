#include "world.h"

static ac_bool AC_WorldInBounds(ac_s16 x, ac_s16 y, ac_s16 z)
{
    return (x >= 0 && x < AC_CHUNK_SIZE_X &&
            y >= 0 && y < AC_CHUNK_HEIGHT &&
            z >= 0 && z < AC_CHUNK_SIZE_Z) ? AC_TRUE : AC_FALSE;
}

static ac_u32 AC_WorldIndex(ac_s16 x, ac_s16 y, ac_s16 z)
{
    return (ac_u32)y * AC_CHUNK_SIZE_X * AC_CHUNK_SIZE_Z +
           (ac_u32)z * AC_CHUNK_SIZE_X + (ac_u32)x;
}

void AC_WorldInit(ACWorld* world)
{
    ac_u32 i;
    if (!world)
        return;

    for (i = 0; i < (ac_u32)(AC_CHUNK_SIZE_X * AC_CHUNK_HEIGHT * AC_CHUNK_SIZE_Z); ++i)
        world->blocks[i] = AC_BLOCK_AIR;
}

ac_u8 AC_WorldGet(const ACWorld* world, ac_s16 x, ac_s16 y, ac_s16 z)
{
    if (!world || !AC_WorldInBounds(x, y, z))
        return AC_BLOCK_AIR;
    return world->blocks[AC_WorldIndex(x, y, z)];
}

void AC_WorldSet(ACWorld* world, ac_s16 x, ac_s16 y, ac_s16 z, ac_u8 blockId)
{
    if (!world || !AC_WorldInBounds(x, y, z))
        return;
    world->blocks[AC_WorldIndex(x, y, z)] = blockId;
}

void AC_WorldGenerateFlat(ACWorld* world)
{
    ac_s16 x;
    ac_s16 z;

    if (!world)
        return;

    for (z = 0; z < AC_CHUNK_SIZE_Z; ++z) {
        for (x = 0; x < AC_CHUNK_SIZE_X; ++x) {
            AC_WorldSet(world, x, 0, z, AC_BLOCK_STONE);
            AC_WorldSet(world, x, 1, z, AC_BLOCK_DIRT);
            AC_WorldSet(world, x, 2, z, AC_BLOCK_GRASS);
        }
    }

    /* Isolated test block: one dirt cube floating in otherwise empty space. */
    AC_WorldSet(world, 7, 10, 7, AC_BLOCK_DIRT);
}
