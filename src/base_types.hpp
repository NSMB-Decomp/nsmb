#pragma once
#include "nitro.h"
// TODO: Get rid of the below, s32, s8, s16 etc. should be used instead
typedef s8 i8;
typedef s16 i16;
typedef s32 i32;
typedef s64 i64;
typedef volatile i8 vi8;
typedef volatile i16 vi16;
typedef volatile i32 vi32;
typedef volatile i64 vi64;
typedef void *unknown_pointer;
//#if defined(__MWERKS__)
//typedef unsigned long size_t;
//#else
//typedef unsigned int size_t;
//#endif

typedef u32 EmitterT;

#define NULL 0

// https://forum.vcfed.org/index.php?threads/c-item-size-check-at-compile-time.1244920/
#define NITRO_SIZE_ASSERT(what, howmuch) typedef char what##_size_wrong_[(!!(sizeof(what) == howmuch)) * 2 - 1]
// #define NITRO_SIZE_ASSERT( what, howmuch )

//
#define READ_NIBBLE(data, nybble) ((settings >> (nybble * 4)) & 0xf)

// Sections
// It appears attributes can significantly effect compilation
// RW required here to get Y7QJ to match.
#pragma define_section autobss_3 ".autobss_3" ".autobss_3" RW
#pragma define_section itcm ".itcm" ".itcm"

// To fix code that has weird bool logic
// TODO: See if we can get rid of the below and use nitro's bool's instead
#define BOOL int
#define TRUE 1
#define FALSE 0

// Overlays - https://nsmbhd.net/thread/1581-nsmb-overlay-list/
FS_EXTERN_OVERLAY_ID(0);
FS_EXTERN_OVERLAY_ID(1);
FS_EXTERN_OVERLAY_ID(10);
FS_EXTERN_OVERLAY_ID(11);
FS_EXTERN_OVERLAY_ID(52);

#define OVERLAY_MISC FS_OVERLAY_ID(0)
#define OVERLAY_BOOT FS_OVERLAY_ID(1)
#define OVERLAY_LEVEL FS_OVERLAY_ID(10)
#define OVERLAY_11 FS_OVERLAY_ID(11)
#define OVERLAY_VS_MENU FS_OVERLAY_ID(11)
#define OVERLAY_52 FS_OVERLAY_ID(52)

