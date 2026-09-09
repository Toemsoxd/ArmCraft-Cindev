#ifndef ARMCRAFT_CE_TYPES_H
#define ARMCRAFT_CE_TYPES_H

/* Keep the core independent of platform-specific integer typedefs. */
typedef unsigned char  ac_u8;
typedef signed char    ac_s8;
typedef unsigned short ac_u16;
typedef signed short   ac_s16;
typedef unsigned long  ac_u32;
typedef signed long    ac_s32;

typedef int ac_bool;
#define AC_FALSE 0
#define AC_TRUE  1

#endif
