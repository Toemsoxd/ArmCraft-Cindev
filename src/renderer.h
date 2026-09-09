#ifndef ARMCRAFT_RENDERER_H
#define ARMCRAFT_RENDERER_H

#include "ce_types.h"
#include "world.h"

struct ACRenderer {
    ac_u16 width;
    ac_u16 height;
    ac_u16* pixels;
    ac_bool initialized;
};

ac_bool AC_RendererInit(ACRenderer* renderer, ac_u16 width, ac_u16 height);
void AC_RendererShutdown(ACRenderer* renderer);
void AC_RendererClear(ACRenderer* renderer, ac_u16 color);
void AC_RendererDrawWorldTop(ACRenderer* renderer, const ACWorld* world);
ac_u16 AC_RGB565(ac_u8 r, ac_u8 g, ac_u8 b);

#endif
