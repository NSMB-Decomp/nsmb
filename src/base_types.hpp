#pragma once
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef signed char i8;
typedef signed short i16;
typedef signed long i32;
typedef signed long long i64;
typedef void *unknown_pointer;
#if defined(__MWERKS__)
typedef unsigned long size_t;
#else
typedef unsigned int size_t;
#endif

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;

typedef s16 fx16;
typedef s32 fx32;
typedef s64 fx64;

typedef u32 EmitterT;

// Doesn't work with objdiff
//#include <cstddef.h> // for size_t
typedef unsigned long size_t;

#define NULL (void *)0x0

// https://forum.vcfed.org/index.php?threads/c-item-size-check-at-compile-time.1244920/
#define size_assert(what, howmuch) typedef char what##_size_wrong_[(!!(sizeof(what) == howmuch)) * 2 - 1]
// #define size_assert( what, howmuch )

//
#define READ_NIBBLE(data, nybble) ((settings >> (nybble * 4)) & 0xf)

// To fix code that has weird bool logic
#define BOOL int
#define TRUE 1
#define FALSE 0

// Overlays - https://nsmbhd.net/thread/1581-nsmb-overlay-list/
#define EXTERN_OVERLAY_ID(name_or_index) extern u32 OVERLAY_##name_or_index##_ID;
#define OVERLAY_ID(name_or_index) ((u32) & OVERLAY_##name_or_index##_ID)

EXTERN_OVERLAY_ID(0);
EXTERN_OVERLAY_ID(1);
EXTERN_OVERLAY_ID(10);
EXTERN_OVERLAY_ID(11);
EXTERN_OVERLAY_ID(52);

#define OVERLAY_MISC OVERLAY_ID(0)
#define OVERLAY_BOOT OVERLAY_ID(1)
#define OVERLAY_LEVEL OVERLAY_ID(10)
#define OVERLAY_11 OVERLAY_ID(11)
#define OVERLAY_VS_MENU OVERLAY_ID(11)

// Old c++03 standard does not have 'override' keyword
#define override

// ...
#define nullptr 0

#define scast static_cast
#define rcast reinterpret_cast
#define ccast const_cast
#define dcast dynamic_cast
