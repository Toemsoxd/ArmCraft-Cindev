#include "block.h"

static const ACBlockDef g_blocks[] = {
    { AC_BLOCK_AIR,    AC_FALSE },
    { AC_BLOCK_STONE,  AC_TRUE  },
    { AC_BLOCK_GRASS,  AC_TRUE  },
    { AC_BLOCK_DIRT,   AC_TRUE  },
    { AC_BLOCK_WOOD,   AC_TRUE  },
    { AC_BLOCK_LEAVES, AC_TRUE  },
    { AC_BLOCK_SAND,   AC_TRUE  }
};

const ACBlockDef* AC_GetBlockDef(ac_u8 id)
{
    if (id >= (sizeof(g_blocks) / sizeof(g_blocks[0])))
        return &g_blocks[AC_BLOCK_AIR];
    return &g_blocks[id];
}
