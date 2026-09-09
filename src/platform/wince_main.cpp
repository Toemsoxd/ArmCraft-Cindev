#include <windows.h>
#include "../engine.h"

static ACEngine g_engine;
static HWND g_window = NULL;

static LRESULT CALLBACK AC_WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC dc = BeginPaint(hwnd, &ps);
            RECT r;
            GetClientRect(hwnd, &r);
            FillRect(dc, &r, (HBRUSH)(COLOR_BLACK + 1));
            EndPaint(hwnd, &ps);
        }
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

static ac_bool AC_PlatformCreateWindow(HINSTANCE instance)
{
    WNDCLASS wc;
    ZeroMemory(&wc, sizeof(wc));
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = AC_WndProc;
    wc.hInstance = instance;
    wc.hbrBackground = (HBRUSH)(COLOR_BLACK + 1);
    wc.lpszClassName = TEXT("ArmCraftCE");

    if (!RegisterClass(&wc) && GetLastError() != ERROR_CLASS_ALREADY_EXISTS)
        return AC_FALSE;

    g_window = CreateWindow(
        TEXT("ArmCraftCE"),
        TEXT("ArmCraft CIndev"),
        WS_VISIBLE,
        0, 0, 320, 240,
        NULL, NULL, instance, NULL);

    return g_window != NULL ? AC_TRUE : AC_FALSE;
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous, LPTSTR commandLine, int show)
{
    MSG msg;
    DWORD lastTick;

    (void)previous;
    (void)commandLine;
    (void)show;

    if (!AC_EngineInit(&g_engine))
        return 1;

    if (!AC_PlatformCreateWindow(instance)) {
        AC_EngineShutdown(&g_engine);
        return 1;
    }

    lastTick = GetTickCount();

    while (g_engine.running) {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                g_engine.running = AC_FALSE;
                break;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        {
            DWORD now = GetTickCount();
            DWORD elapsed = now - lastTick;
            lastTick = now;
            AC_EngineTick(&g_engine, (ac_u32)elapsed);
        }

        Sleep(1);
    }

    AC_EngineShutdown(&g_engine);
    return 0;
}
