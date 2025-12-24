typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef signed char i8;
typedef signed short i16;
typedef signed long i32;
typedef void* unknown_pointer;

#define NULL (void*)0x0

#define EXTERN_OVERLAY_ID(name_or_index) extern u32 OVERLAY_##name_or_index##_ID;
#define OVERLAY_ID(name_or_index) ((u32) & OVERLAY_##name_or_index##_ID)

EXTERN_OVERLAY_ID(0);
EXTERN_OVERLAY_ID(1);

#define OverlayId_Second OVERLAY_ID(0)
#define OverlayId_Secondd OVERLAY_ID(1)