#pragma once
#include "../../src/base_types.hpp"

#define REG_DISPCNT *((u32 *)0x04000000)
#define REG_BG1CNT *((u16 *)0x0400000a)
#define REG_BLDCNT *((u16 *)0x04000050)
#define REG_KEYINPUT *((u16 *)0x04000130)
#define REG_IME *((u16 *)0x04000208)
#define REG_POWER_CNT *((u16 *)0x04000304)
#define REG_DISPCNT_SUB *((u32 *)0x04001000)
#define REG_BG1CNT_SUB *((u16 *)0x0400100a)
#define REG_BLDCNT_SUB *((u16 *)0x04001050)
#define REG_BG1HOFS *((u32 *)0x04000014)

#define KEY_A 0 << 1
#define KEY_B 1 << 1
#define KEY_SELECT 2 << 1
#define KEY_START 3 << 1
#define KEY_RIGHT 4 << 1
#define KEY_LEFT 5 << 1
#define KEY_UP 6 << 1
#define KEY_DOWN 7 << 1
#define KEY_R 8 << 1
#define KEY_L 9 << 1
#define KEY_X 10 << 1
#define KEY_Y 11 << 1
#define KEY_DEBUG 12 << 1
#define KEY_FOLD 13 << 1

// All inputs other than FOLD
#define KEYS_ALL (KEY_A | KEY_B | KEY_SELECT | KEY_START | KEY_RIGHT | KEY_LEFT | KEY_UP | KEY_DOWN | KEY_R | KEY_L | KEY_X | KEY_Y | KEY_DEBUG)

union Mat2x2 {
	struct {
		i32 m00, m01;
		i32 m10, m11;
	};
	i32 v[2][2];
	i32 a[2*2];
};

union Mat3x3 {
	struct {
		i32 m00, m01, m02;
		i32 m10, m11, m12;
		i32 m20, m21, m22;
	};
	i32 v[3][3];
	i32 a[3*3];
};

union Mat4x3 {
	struct {
		i32 m00, m01, m02;
		i32 m10, m11, m12;
		i32 m20, m21, m22;
		i32 m30, m31, m32;
	};
	i32 v[4][3];
	i32 a[4*3];
};

union Mat4x4 {
	struct {
		i32 m00, m01, m02, m03;
		i32 m10, m11, m12, m13;
		i32 m20, m21, m22, m23;
		i32 m30, m31, m32, m33;
	};
	i32 m[4][4];
	i32 a[4*4];
};

struct Vec3_32s {
	i32 x;
	i32 y;
	i32 z;
};
struct Vec3_16s {
	i16 x;
	i16 y;
	i16 z;
};

// TODO: Seperate out files.
namespace Nitro
{
// FS - FileSystem
void FS_Init();
void FS_InitFile();
void FS_OpenFile();
void FS_SeekFile();
void FS_ReadFile();
void FS_IsFile();
void FS_CloseFile();
void FS_SeekFileToBegin();
// OS - Operating System
void OS_Init();
void OS_InitTick();
void OS_InitAlarm();
void OS_SetIrqFunction();
void OS_SetIrqCheckFlag();
void OS_EnableIrqMask();
void OS_EnableIrq();
void OS_WaitVBlankIntr();
void OS_Panic();
void OS_LockMutex();
void OS_UnlockMutex();
void OS_InitMutex();
void OS_TPrintf();
void OS_ResetSystem();
void OS_InitAlloc();
void OS_Free();
void OS_CreateThread();
void OS_WakeupThreadDirect();
void OS_ReceiveMessage();
void OS_ReceiveMessage();
void OS_SendMessage();
void OS_SetPeriodicAlarm();
void OS_CreateAlarm();
void OS_GetConsoleType();
void OS_CheckStack();
void OS_Sleep();
void OS_KillThread();
void OS_IsThreadTerminated();
void OS_CancelAlarm();
void OS_GetResetParameter();
void OS_KillThread();
void OS_IsThreadTerminated();
// FX
void FX_Init();
// GX - Graphics
void GX_SetPower();
void GX_DispOff();
void GX_VBlankIntr();
void GX_HBlankIntr();
void GX_SetVisiblePlane();
void GX_SetDispSelect();
void GX_SetBankForLCDC();
void GX_SetOBJVRamModeChar();
void GX_SetBGCharOffset();
void GX_SetBankForBG();
void GX_SetBankForOBJ();
void GX_SetBankForSubBG();
void GX_SetBankForSubOBJ();
void GX_SetGraphicsMode();
// G2
void G2_SetBG0Priority();
void G2_SetBG1Priority();
void G2_SetBG2Priority();
void G2_SetBG3Priority();
// G2S
void G2S_SetBG0Priority();
void G2S_SetBG1Priority();
void G2S_SetBG2Priority();
void G2S_SetBG3Priority();
void MI_DmaFill32();
// GXS
void GXS_DispOff();
void GXS_SetVisiblePlane();
void GXS_SetGraphicsMode();
void GXS_SetOBJVRamModeChar();
// SND - Sound
void SND_Init();
// TP
void TP_Init();
// RTC - Real Time Clock
void RTC_Init();
// SND - Sound
void SND_LockChannel();
void SND_SetupChannelPcm();
void SND_SetupAlarm();
void SND_StartTimer();
void SND_StopTimer();
void SND_UnlockChannel();
void SND_FlushCommand();
// DC
void DC_StoreRange();
// G2
void G2_GetBG3ScrPtr();
// MO
void MO_BlitFrameImage();
void MO_GetNbFrame();
void MO_GetAudioFrequency();
// MI
void MI_CpuFillFast();
void MI_CpuClearFast();
void MI_CpuCopy8(void *, void *, u32); // std::copy
void MI_CpuCopy16(void *, void *, u32);
void MI_CpuCopy32(void *, void *, u32);

//
void Math_AddVec3_32s(Vec3_32s &, Vec3_32s &, Vec3_32s &);
void MultiThread_Init();
void Exception_SetHandler(void *, void *);
void Graphics_ResetOAM();
bool Graphics_Step();
inline void Graphics_SwapBuffer(u32 a, u32 b)
{
	u32 *GFX_FIFO_SWAP_BUFFERS = (u32 *)0x04000540;
	*GFX_FIFO_SWAP_BUFFERS = (a << 1) | b;
}
void Math__stub();
void func_02061588(u32);
void EnableDisplay();
void func_01ff8128(u32);
void func_01ffa5ec(u32, u16);
void func_02060e38(u32);
void func_0206d554();
void MainInit();
void func_0206f3cc(void (*)());
void func_02063fd4();
void func_02066fe8(void *, u32, u32);
void func_01ff9010();
void func_01ff80e0(u32);
void func_01ff9010();
void FS_init();
bool Wifi_isMultiBootCart();
void FS_Overlays_loadOverlay(u32);
void FS_Overlays_unload(u32);
void FS_Archive_loadMainGameArchives();
void func_02061ac4(u32);
void func_020613c8(u32);

} // namespace Nitro

extern "C" {

	/* 3D geometry commands (from gbatek) */

	enum GE_CMD {

		GE_NOP = 0x0,

		// Matrix commands
		GE_MTX_MODE = 0x10,
		GE_MTX_PUSH,
		GE_MTX_POP,
		GE_MTX_STORE,
		GE_MTX_RESTORE,
		GE_MTX_IDENTITY,
		GE_MTX_LOAD_4x4,
		GE_MTX_LOAD_4x3,
		GE_MTX_MULT_4x4,
		GE_MTX_MULT_4x3,
		GE_MTX_MULT_3x3,
		GE_MTX_SCALE,
		GE_MTX_TRANS,

		// Polygon commands
		GE_COLOR = 0x20,
		GE_NORMAL,
		GE_TEXCOORD,
		GE_VTX_16,
		GE_VTX_10,
		GE_VTX_XY,
		GE_VTX_XZ,
		GE_VTX_YZ,
		GE_VTX_DIFF,
		GE_POLYGON_ATTR,
		GE_TEXIMAGE_PARAM,
		GE_TEXPLTT_BASE,

		// Material commands
		GE_DIF_AMB = 0x30,
		GE_SPE_EMI,
		GE_LIGHT_VECTOR,
		GE_LIGHT_COLOR,
		GE_SHININESS,

		GE_BEGIN_VTXS = 0x40,
		GE_END_VTXS,

		GE_SWAP_BUFFERS = 0x50,

		GE_VIEWPORT = 0x60,

		// Test commands
		GE_BOX_TEST = 0x70,
		GE_POS_TEST,
		GE_VEC_TEST

	};

	void CopyMat3x3(const void*, void*);

	void ConcatMat4x3(const void*, const void*, void*);

	typedef void (*Ns3dCmdFunc)(void* p);


	/* Data headers */

	struct Ns3dFileHeader {
		u32 magic;
		u16 bom;
		u16 version;
		u32 size;
		u16 headerSize;
		u16 dataCount;
	};
	size_assert(Ns3dFileHeader, 0x10);

	struct Ns3dDataHeader {
		u32 magic;
		u32 size;
	};
	size_assert(Ns3dDataHeader, 0x8);


	/* Resource dictionaries */

	struct Ns3dStringData {
		char c[16];
	};
	size_assert(Ns3dStringData, 0x10);

	struct Ns3dDictionaryData {
		u16 itemSize;
		u16 _2;
		u8 data[];
	};
	size_assert(Ns3dDictionaryData, 0x4);

	struct Ns3dDictionary {
		u8 version;
		u8 itemCount;
		u16 _2;
		u16 _4;
		u16 dataOffset;
	};
	size_assert(Ns3dDictionary, 0x8);

	i32 Ns_3dGetDictionaryIndex(Ns3dDictionary* d, const Ns3dStringData* name);

	inline void* Ns_3dGetDictionaryData(Ns3dDictionary* d, u32 index) {
		Ns3dDictionaryData* h = rcast<Ns3dDictionaryData*>(rcast<u8*>(d) + d->dataOffset);
		return h->data + (h->itemSize * index);
	}


	/* Material resource */

	enum Ns3dMaterialFlags {
		NS_3D_MAT_DIFFUSE = 0x40,
		NS_3D_MAT_AMBIENT = 0x80,
		NS_3D_MAT_SPECULAR = 0x200,
		NS_3D_MAT_EMISSION = 0x400,
	};

	struct Ns3dMaterialData {
		u16 _0;
		u16 size;
		u32 diffAmb;
		u32 specEmi;
		u32 polyAttr;
		u32 polyAttrMask;
		u32 textureParam;
		u32 textureParamMask;
		u16 paletteParam;
		u16 flags;
		u16 width;
		u16 height;
		i32 _24;
		i32 _28;
	};
	size_assert(Ns3dMaterialData, 0x2C);

	struct Ns3dMaterialList {
		u16 _0;
		u16 _2;
		Ns3dDictionary dict;
	};
	size_assert(Ns3dMaterialList, 0xC);

	inline Ns3dMaterialData* Ns_3dGetMaterial(Ns3dMaterialList* list, u32 index) {
		u32* data = rcast<u32*>(Ns_3dGetDictionaryData(&list->dict, index));
		return rcast<Ns3dMaterialData*>(rcast<u8*>(list) + *data);
	}


	/* Node resource */

	enum Ns3dNodeFlags {
		NS_3D_NODE_MTX_INDEX_SHIFT = 11,
		NS_3D_NODE_MTX_INDEX_MASK  = 0x1F << 11,
	};

	struct Ns3dNodeData {
		u16 flags;
		i16 p[0]; // 1 or more
	};
	size_assert(Ns3dNodeData, 0x2);

	struct Ns3dNodeList {
		Ns3dDictionary dict;
	};
	size_assert(Ns3dNodeList, 0x8);

	inline Ns3dNodeData* Ns_3dGetNode(Ns3dNodeList* list, u32 index) {
		u32* data = rcast<u32*>(Ns_3dGetDictionaryData(&list->dict, index));
		return rcast<Ns3dNodeData*>(rcast<u8*>(list) + *data);
	}


	/* Animation resource */

	struct Ns3dAnimationData {
		u32 _0;
		u16 frameCount;
		u16 _6;
	};

	Ns3dAnimationData* Ns_3dGetAnimation(Ns3dFileHeader* animFile, u32 index);


	/* Model resource */

	struct Ns3dModelData {
		u32 size;
		u32 commandOffset;
		u32 materialOffset;
		u32 unkAOffset;
		u32 unkBOffset;
		u8 _2C;
		u8 _2D;
		u8 _2E;
		u8 nodeCount;
		u8 materialCount;
		u8 unkACount;
		u8 _6[0x26];
		Ns3dNodeList nodes;
	};
	size_assert(Ns3dModelData, 0x48);

	struct Ns3dModelList {
		Ns3dDataHeader hdr;
		Ns3dDictionary dict;
	};
	size_assert(Ns3dModelList, 0x10);

	Ns3dModelList* Ns_3dGetModelList(Ns3dFileHeader* file);

	inline Ns3dModelData* Ns_3dGetModel(Ns3dModelList* list, u32 index) {
		u32* data = rcast<u32*>(Ns_3dGetDictionaryData(&list->dict, index));
		return rcast<Ns3dModelData*>(rcast<u8*>(list) + *data);
	}

	inline Ns3dMaterialList* Ns_3dGetMaterials(Ns3dModelData* m) {
		return rcast<Ns3dMaterialList*>(rcast<u8*>(m) + m->materialOffset);
	}

	inline Ns3dNodeList* Ns_3dGetNodes(Ns3dModelData* m) {
		return &m->nodes;
	}

	void Ns_3dModelSetAllPolygonID(Ns3dModelData* m, u32 polygonID);

	void Ns_3dModelSetMaterialFlag(Ns3dModelData* m, bool set, u32 mask);

	inline void Ns_3dModelUseModelDiffuse(Ns3dModelData* m) {
		Ns_3dModelSetMaterialFlag(m, true, NS_3D_MAT_DIFFUSE);
	}

	inline void Ns_3dModelUseModelAmbient(Ns3dModelData* m) {
		Ns_3dModelSetMaterialFlag(m, true, NS_3D_MAT_AMBIENT);
	}

	inline void Ns_3dModelUseModelSpecular(Ns3dModelData* m) {
		Ns_3dModelSetMaterialFlag(m, true, NS_3D_MAT_SPECULAR);
	}

	inline void Ns_3dModelUseModelEmission(Ns3dModelData* m) {
		Ns_3dModelSetMaterialFlag(m, true, NS_3D_MAT_EMISSION);
	}

	inline void Ns_3dModelUseGlobalDiffuse(Ns3dModelData* m) {
		Ns_3dModelSetMaterialFlag(m, false, NS_3D_MAT_DIFFUSE);
	}

	inline void Ns_3dModelUseGlobalAmbient(Ns3dModelData* m) {
		Ns_3dModelSetMaterialFlag(m, false, NS_3D_MAT_AMBIENT);
	}

	inline void Ns_3dModelUseGlobalSpecular(Ns3dModelData* m) {
		Ns_3dModelSetMaterialFlag(m, false, NS_3D_MAT_SPECULAR);
	}

	inline void Ns_3dModelUseGlobalEmission(Ns3dModelData* m) {
		Ns_3dModelSetMaterialFlag(m, false, NS_3D_MAT_EMISSION);
	}


	/* Texture resource */

	struct Ns3dTextureData {};

	Ns3dTextureData* Ns_3dGetTexture(Ns3dFileHeader* file);


	/* Drawable class */

	struct Ns3dAnimation;

	struct Ns3dDrawable {
		u32 flags;
		Ns3dModelData* modelData;
		void* materialAnim;
		void* materialAnimFunc;
		void* skeletalAnim;
		void* skeletalAnimFunc;
		void* visibilityAnim;
		void* visibilityAnimFunc;
		void* cmdFunc;
		u8 cmdNo;
		u8 cmdTiming;
		u16 _26;
		void* _28;
		void* userData;
		void* _30;
		u32 _34;
		u32 _38;
		u32 _3C[6];
	};
	size_assert(Ns3dDrawable, 0x54);

	void Ns_3dDrawableInit(Ns3dDrawable* d, Ns3dModelData* model);

	void Ns_3dDrawableDraw(Ns3dDrawable* d);

	void Ns_3dDrawableLinkAnimation(Ns3dDrawable* d, Ns3dAnimation* anim);

	void Ns_3dDrawableUnlinkAnimation(Ns3dDrawable* d, Ns3dAnimation* anim);

	void Ns_3dDrawableSetCmdFunc(Ns3dDrawable* d, Ns3dCmdFunc func, u8* address, u32 cmd, u32 timing);

	inline void Ns_3dDrawableSetUserData(Ns3dDrawable* d, void* data) {
		d->userData = data;
	}


	/* Animation class */

	struct Ns3dAnimation {
		i32 frame;
		i32 scale;
		void* data;
		void* func;
		Ns3dAnimation* next;
		Ns3dTextureData* texture;
		u8 _18;
		u8 _19;
		u16 _1A;
	};
	size_assert(Ns3dAnimation, 0x1C);

	void Ns_3dAnimationInit(Ns3dAnimation* a, void* anim, Ns3dModelData* model, Ns3dTextureData* texture);

	u32 Ns_3dAnimationGetSize(Ns3dAnimationData* anim, Ns3dModelData* model);

	inline void Ns_3dAnimationSetFrame(Ns3dAnimation* a, i32 frame) {
		a->frame = frame;
	}


	/* 3D renderer global state */

	struct Ns3dGlobalState {
		u32 _0;
		u32 matrixModeProj;
		Mat4x4 matrixProj;
		u32 matrixModePosVec;
		Mat4x3 matrixCamera;
		u32 _7C;
		u32 lightVector[4];
		u32 _90;
		u32 materialColorA;
		u32 materialColorB;
		u32 polyAttr;
		u32 viewPort;
		u32 _A4;
		u32 lightColor[4];
		u32 _B8;
		Mat3x3 rotation;
		Vec3_32s trans;
		Vec3_32s scale;
		u32 textureParam;
		u32 flags;
		Mat4x3 mat100;
		Mat4x3 mat130;
		Mat4x3 mat160;
		Mat4x3 mat190;
		Mat4x4 mat1C0;
		Mat4x4 mat200;
		Vec3_32s cameraPos;
		Vec3_32s cameraUp;
		Vec3_32s cameraTarget;
	};
	size_assert(Ns3dGlobalState, 0x264);

	extern Ns3dGlobalState Ns_3dGs;


	inline void Ns_3dSetRotation(const Mat3x3* mat) {
		CopyMat3x3(mat, &Ns_3dGs.rotation);
		Ns_3dGs.flags &= ~0xA4;
	}

	void Ns_3dSetTrans(const Vec3_32s* trans);

	void Ns_3dSetScale(const Vec3_32s* scale);

	Mat4x3* Ns_3dGetInvCameraMatrix();

	void Ns_3dFlushProj();

	inline void Ns_3dFlush() {
		Ns_3dFlushProj();
	}


	/* Direct 3D engine operations */

	void Ns_3dGetCurrentMatrices(Mat4x3* clipMat, Mat3x3* vectorMat);

	void Ns_3dSendCmd(u32 cmd, u32* params, u32 paramCount);

	inline void Ns_3dStoreMatrix(u32 slot) {
		Ns_3dSendCmd(GE_MTX_STORE, &slot, 1);
	}

	inline void Ns_3dRestoreMatrix(u32 slot) {
		Ns_3dSendCmd(GE_MTX_RESTORE, &slot, 1);
	}

}
