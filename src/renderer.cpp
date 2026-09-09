#include "renderer.h"

ac_u16 AC_RGB565(ac_u8 r, ac_u8 g, ac_u8 b)
{
    return (ac_u16)(((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3));
}

ac_bool AC_RendererInit(ACRenderer* renderer, ac_u16 width, ac_u16 height)
{
    if (!renderer || width == 0 || height == 0)
        return AC_FALSE;

    renderer->width = width;
    renderer->height = height;
    renderer->pixels = new ac_u16[(ac_u32)width * (ac_u32)height];
    renderer->initialized = renderer->pixels != 0 ? AC_TRUE : AC_FALSE;

    if (renderer->initialized)
        AC_RendererClear(renderer, AC_RGB565(70, 90, 115));

    return renderer->initialized;
}

void AC_RendererShutdown(ACRenderer* renderer)
{
    if (!renderer)
        return;

    if (renderer->pixels)
        delete[] renderer->pixels;

    renderer->pixels = 0;
    renderer->initialized = AC_FALSE;
}

void AC_RendererClear(ACRenderer* renderer, ac_u16 color)
{
    ac_u32 count;
    ac_u32 i;

    if (!renderer || !renderer->pixels)
        return;

    count = (ac_u32)renderer->width * (ac_u32)renderer->height;
    for (i = 0; i < count; ++i)
        renderer->pixels[i] = color;
}

void AC_RendererDrawWorldTop(ACRenderer* renderer, const ACWorld* world)
{
    ac_u16 x;
    ac_u16 z;
    ac_u16 sx;
    ac_u16 sz;
    ac_u8 block;
    ac_u16 color;

    if (!renderer || !renderer->pixels || !world)
        return;

    /* Temporary debug view: top-down world, one block = 8x8 pixels. */
    for (z = 0; z < AC_CHUNK_SIZE_Z; ++z) {
        for (x = 0; x < AC_CHUNK_SIZE_X; ++x) {
            block = AC_WorldGet(world, x, 2, z);

            if (block == AC_BLOCK_GRASS)
                color = AC_RGB565(90, 170, 70);
            else if (block == AC_BLOCK_DIRT)
                color = AC_RGB565(125, 85, 45);
            else if (block == AC_BLOCK_STONE)
                color = AC_RGB565(110, 110, 110);
            else
                color = AC_RGB565(30, 30, 30);

            for (sz = 0; sz < 8; ++sz) {
                for (sx = 0; sx < 8; ++sx) {
                    ac_u16 px = (ac_u16)(x * 8 + sx);
                    ac_u16 py = (ac_u16)(z * 8 + sz);
                    if (px < renderer->width && py < renderer->height)
                        renderer->pixels[(ac_u32)py * renderer->width + px] = color;
                }
            }
        }
    }
}
