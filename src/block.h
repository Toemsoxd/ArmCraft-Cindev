#ifndef ARMCRAFT_BLOCK_H
#define ARMCRAFT_BLOCK_H

#include "ce_types.h"

enum ACBlockId {
    AC_BLOCK_AIR = 0,
    AC_BLOCK_STONE = 1,
    AC_BLOCK_GRASS = 2,
    AC_BLOCK_DIRT = 3,
    AC_BLOCK_WOOD = 4,
    AC_BLOCK_LEAVES = 5,
    AC_BLOCK_SAND = 6
};

struct ACBlockDef {
    ac_u8 id;
    ac_bool solid;
};

const ACBlockDef* AC_GetBlockDef(ac_u8 id);

#endif
