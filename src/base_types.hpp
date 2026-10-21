#pragma once
#include "nitro.h"
typedef void *unknown_pointer;
//#if defined(__MWERKS__)
//typedef unsigned long size_t;
//#else
//typedef unsigned int size_t;
//#endif

// https://forum.vcfed.org/index.php?threads/c-item-size-check-at-compile-time.1244920/
#define NITRO_SIZE_ASSERT(what, howmuch) typedef char what##_size_wrong_[(!!(sizeof(what) == howmuch)) * 2 - 1]
// #define NITRO_SIZE_ASSERT( what, howmuch )

// Used for reasing actor settings / attributes
#define READ_NIBBLE(data, nybble) ((settings >> (nybble * 4)) & 0xf)

// Sections
// It appears attributes can significantly effect compilation
// RW required here to get Y7QJ to match.
#pragma define_section autobss_3 ".autobss_3" ".autobss_3" RW
#pragma define_section itcm ".itcm" ".itcm"

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

