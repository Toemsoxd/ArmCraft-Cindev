# ArmCraft CIndev

An experimental Minecraft Indev-inspired voxel game written from scratch for Windows CE / Windows Mobile 6-era ARM devices.

## Current foundation

- Platform-neutral voxel/world code in `src/`
- Compact block IDs and definitions
- One 16 x 16 x 64 prototype chunk
- Flat-world generator for early renderer testing
- Windows CE / Win32 application bootstrap in `src/platform/wince_main.cpp`
- 320 x 240 initial target window
- No PSP-specific code

## Assets

The repository root currently contains the initial Indev-era artwork supplied for the project, including `terrain.png`, `items.png`, GUI textures, icons, and the logo. The runtime asset loader is intentionally not implemented yet.

## Development order

1. Get the Windows CE executable booting.
2. Add a tiny software/OpenGL ES renderer abstraction.
3. Render the prototype chunk.
4. Add first-person camera and movement.
5. Add block selection, breaking, and placement.
6. Add procedural terrain.
7. Add save/load.
8. Add the early Indev UI and inventory.
9. Profile memory and CPU usage on real ARM hardware.

The first milestone deliberately favors simple, old-device-friendly code over modern C++ features.
