#include "engine.h"

ac_bool AC_EngineInit(ACEngine* engine, ac_u16 width, ac_u16 height)
{
    if (!engine)
        return AC_FALSE;

    engine->running = AC_FALSE;

    AC_WorldInit(&engine->world);
    AC_WorldGenerateFlat(&engine->world);

    if (!AC_RendererInit(&engine->renderer, width, height))
        return AC_FALSE;

    engine->running = AC_TRUE;
    return AC_TRUE;
}

void AC_EngineShutdown(ACEngine* engine)
{
    if (!engine)
        return;

    AC_RendererShutdown(&engine->renderer);
    engine->running = AC_FALSE;
}

void AC_EngineTick(ACEngine* engine, ac_u32 elapsedMs)
{
    (void)elapsedMs;

    if (!engine || !engine->running)
        return;

    AC_RendererClear(&engine->renderer, AC_RGB565(70, 90, 115));
    AC_RendererDrawWorldTop(&engine->renderer, &engine->world);
}
