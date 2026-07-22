#pragma once
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef signed char i8;
typedef signed short i16;
typedef signed long i32;
typedef signed long long i64;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile i8 vi8;
typedef volatile i16 vi16;
typedef volatile i32 vi32;
typedef volatile i64 vi64;
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

typedef volatile u8  vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8  su8;
typedef volatile s16 su16;
typedef volatile s32 su32;
typedef volatile s64 su64;

typedef s16 fx16;
typedef s32 fx32;
typedef s64 fx64;

typedef u32 EmitterT;

#define NULL 0

// https://forum.vcfed.org/index.php?threads/c-item-size-check-at-compile-time.1244920/
#define NITRO_SIZE_ASSERT(what, howmuch) typedef char what##_size_wrong_[(!!(sizeof(what) == howmuch)) * 2 - 1]
// #define NITRO_SIZE_ASSERT( what, howmuch )

//
#define READ_NIBBLE(data, nybble) ((settings >> (nybble * 4)) & 0xf)

// Sections
#pragma define_section autobss_3 ".autobss_3" ".autobss_3"
#pragma define_section itcm ".itcm" ".itcm"

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
EXTERN_OVERLAY_ID(20);
EXTERN_OVERLAY_ID(22);
EXTERN_OVERLAY_ID(32);
EXTERN_OVERLAY_ID(42);
EXTERN_OVERLAY_ID(52);
EXTERN_OVERLAY_ID(53);

#define OVERLAY_MISC OVERLAY_ID(0)
#define OVERLAY_BOOT OVERLAY_ID(1)
#define OVERLAY_LEVEL OVERLAY_ID(10)
#define OVERLAY_11 OVERLAY_ID(11)
#define OVERLAY_VS_MENU OVERLAY_ID(11)
#define OVERLAY_52 OVERLAY_ID(52)
