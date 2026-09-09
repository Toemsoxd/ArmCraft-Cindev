#ifndef ARMCRAFT_ENGINE_H
#define ARMCRAFT_ENGINE_H

#include "ce_types.h"
#include "world.h"

struct ACEngine {
    ACWorld world;
    ac_bool running;
};

ac_bool AC_EngineInit(ACEngine* engine);
void AC_EngineShutdown(ACEngine* engine);
void AC_EngineTick(ACEngine* engine, ac_u32 elapsedMs);

#endif
