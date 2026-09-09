#include "engine.h"

ac_bool AC_EngineInit(ACEngine* engine)
{
    if (!engine)
        return AC_FALSE;

    AC_WorldGenerateFlat(&engine->world);
    engine->running = AC_TRUE;
    return AC_TRUE;
}

void AC_EngineShutdown(ACEngine* engine)
{
    if (!engine)
        return;
    engine->running = AC_FALSE;
}

void AC_EngineTick(ACEngine* engine, ac_u32 elapsedMs)
{
    /* Gameplay and rendering will be added after the platform bootstrap. */
    (void)engine;
    (void)elapsedMs;
}
