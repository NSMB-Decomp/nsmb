#pragma once
#include "../../src/base_types.hpp"

#pragma section itcm begin
#pragma section itcm end

#define REG_DISPCNT				*((vu32 *)0x04000000)
#define REG_BG0CNT				*((vu16 *)0x04000008)
#define REG_BG1CNT				*((vu16 *)0x0400000A)
#define REG_BG2CNT				*((vu16 *)0x0400000C)
#define REG_BG3CNT				*((vu16 *)0x0400000E)
#define REG_BG0OFS				*((vu32 *)0x04000010)
#define REG_BG1OFS				*((vu32 *)0x04000014)
#define REG_BG2OFS				*((vu32 *)0x04000018)
#define REG_BG3OFS				*((vu32 *)0x0400001C)
#define REG_BG2PA				*((vu16 *)0x04000020)
#define REG_BG2PB				*((vu16 *)0x04000022)
#define REG_BG2PC				*((vu16 *)0x04000024)
#define REG_BG2PD				*((vu16 *)0x04000026)
#define REG_BG2X				*((vu32 *)0x04000028)
#define REG_BG2Y				*((vu32 *)0x0400002C)
#define REG_BG3PA				*((vu16 *)0x04000030)
#define REG_BG3PB				*((vu16 *)0x04000032)
#define REG_BG3PC				*((vu16 *)0x04000034)
#define REG_BG3PD				*((vu16 *)0x04000036)
#define REG_BG3X				*((vu32 *)0x04000038)
#define REG_BG3Y				*((vu32 *)0x0400003C)
#define REG_WIN0H				*((vu16 *)0x04000040)
#define REG_WIN1H				*((vu16 *)0x04000042)
#define REG_WIN0V				*((vu16 *)0x04000044)
#define REG_WIN1V				*((vu16 *)0x04000046)
#define REG_WININ				*((vu16 *)0x04000048)
#define REG_WINOUT				*((vu16 *)0x0400004A)
#define REG_MOSAIC				*((vu16 *)0x0400004C)
#define REG_MOSAIC_BG			*((vu8 *) 0x0400004C)
#define REG_MOSAIC_OBJ			*((vu8 *) 0x0400004D)
#define REG_BLDCNT				*((vu16 *)0x04000050)
#define REG_MASTER_BRIGHT		*((vu16 *)0x0400006C)

#define REG_DISPCNT_SUB			*((vu32 *)0x04001000)
#define REG_BG0CNT_SUB			*((vu16 *)0x04001008)
#define REG_BG1CNT_SUB			*((vu16 *)0x0400100A)
#define REG_BG2CNT_SUB			*((vu16 *)0x0400100C)
#define REG_BG3CNT_SUB			*((vu16 *)0x0400100E)
#define REG_BG0OFS_SUB			*((vu32 *)0x04001010)
#define REG_BG1OFS_SUB			*((vu32 *)0x04001014)
#define REG_BG2OFS_SUB			*((vu32 *)0x04001018)
#define REG_BG3OFS_SUB			*((vu32 *)0x0400101C)
#define REG_BG2PA_SUB			*((vu16 *)0x04001020)
#define REG_BG2PB_SUB			*((vu16 *)0x04001022)
#define REG_BG2PC_SUB			*((vu16 *)0x04001024)
#define REG_BG2PD_SUB			*((vu16 *)0x04001026)
#define REG_BG2X_SUB			*((vu32 *)0x04001028)
#define REG_BG2Y_SUB			*((vu32 *)0x0400102C)
#define REG_BG3PA_SUB			*((vu16 *)0x04001030)
#define REG_BG3PB_SUB			*((vu16 *)0x04001032)
#define REG_BG3PC_SUB			*((vu16 *)0x04001034)
#define REG_BG3PD_SUB			*((vu16 *)0x04001036)
#define REG_BG3X_SUB			*((vu32 *)0x04001038)
#define REG_BG3Y_SUB			*((vu32 *)0x0400103C)
#define REG_WIN0H_SUB			*((vu16 *)0x04001040)
#define REG_WIN1H_SUB			*((vu16 *)0x04001042)
#define REG_WIN0V_SUB			*((vu16 *)0x04001044)
#define REG_WIN1V_SUB			*((vu16 *)0x04001046)
#define REG_WININ_SUB			*((vu16 *)0x04001048)
#define REG_WINOUT_SUB			*((vu16 *)0x0400104A)
#define REG_MOSAIC_SUB			*((vu16 *)0x0400104C)
#define REG_MOSAIC_BG_SUB		*((vu8 *) 0x0400104C)
#define REG_MOSAIC_OBJ_SUB		*((vu8 *) 0x0400104D)
#define REG_BLDCNT_SUB			*((vu16 *)0x04001050)
#define REG_MASTER_BRIGHT_SUB	*((vu16 *)0x0400106C)

#define REG_CAPCNT				*((vu32 *)0x04000064)

#define REG_KEYINPUT			*((vu16 *)0x04000130)
#define REG_IME					*((vu16 *)0x04000208)
#define REG_POWER_CNT			*((vu16 *)0x04000304)

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
	struct _ {
		i32 m00, m01;
		i32 m10, m11;
	} s;
	i32 v[2][2];
	i32 a[2*2];
};

union Mat3x3 {
	struct _ {
		i32 m00, m01, m02;
		i32 m10, m11, m12;
		i32 m20, m21, m22;
	} s;
	i32 v[3][3];
	i32 a[3*3];
};

union Mat4x3 {
	struct _ {
		i32 m00, m01, m02;
		i32 m10, m11, m12;
		i32 m20, m21, m22;
		i32 m30, m31, m32;
	} s;
	i32 v[4][3];
	i32 a[4*3];
};

union Mat4x4 {
	struct _ {
		i32 m00, m01, m02, m03;
		i32 m10, m11, m12, m13;
		i32 m20, m21, m22, m23;
		i32 m30, m31, m32, m33;
	} s;
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

typedef void (*IrqFunction)();

typedef void* HeapHandle;

struct ArmContext {

};
//NITRO_SIZE_ASSERT(ArmContext, 0x18);

struct Mutex {
	u8 _[0x18];
};
NITRO_SIZE_ASSERT(Mutex, 0x18);

struct Thread {
	u8 _[0xC0];
};
NITRO_SIZE_ASSERT(Thread, 0xC0);

struct ThreadQueue {
	Thread* head;
	Thread* tail;
};
NITRO_SIZE_ASSERT(ThreadQueue, 0x8);

typedef void(*SwitchThreadCallback)(Thread*, Thread*);

extern "C" {


}

extern "C" {

	/* 3D texture formats (from gbatek) */

	enum TEX_FMT {
		TEX_FMT_NONE = 0x0,
		TEX_FMT_A3I5,
		TEX_FMT_PLTT4,
		TEX_FMT_PLTT16,
		TEX_FMT_PLTT256,
		TEX_FMT_COMP4x4,
		TEX_FMT_A5I3,
		TEX_FMT_DIRECT
	};

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

	i32 FixedDiv(i32, i32);

	void CopyMat3x3(const void*, void*);

	void ConcatMat4x3(const void*, const void*, void*);

	typedef void (*Ns3dCmdFunc)(void* p);


	void Ns_3dInitialize();


	/* Data headers */

	struct Ns3dFileHeader {
		u32 magic;
		u16 bom;
		u16 version;
		u32 size;
		u16 headerSize;
		u16 dataCount;
	};
	NITRO_SIZE_ASSERT(Ns3dFileHeader, 0x10);

	struct Ns3dDataHeader {
		u32 magic;
		u32 size;
	};
	NITRO_SIZE_ASSERT(Ns3dDataHeader, 0x8);


	/* Resource dictionaries */

	struct Ns3dStringData {
		char c[16];
	};
	NITRO_SIZE_ASSERT(Ns3dStringData, 0x10);

	struct Ns3dDictionaryData {
		u16 itemSize;
		u16 _2;
		u8 data[];
	};
	NITRO_SIZE_ASSERT(Ns3dDictionaryData, 0x4);

	struct Ns3dDictionary {
		u8 version;
		u8 itemCount;
		u16 _2;
		u16 _4;
		u16 dataOffset;
	};
	NITRO_SIZE_ASSERT(Ns3dDictionary, 0x8);

	i32 Ns_3dGetDictionaryIndex(Ns3dDictionary* d, const Ns3dStringData* name);

	inline void* Ns_3dGetDictionaryData(Ns3dDictionary* d, u32 index) {
		Ns3dDictionaryData* h = reinterpret_cast<Ns3dDictionaryData*>(reinterpret_cast<u8*>(d) + d->dataOffset);
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
	NITRO_SIZE_ASSERT(Ns3dMaterialData, 0x2C);

	struct Ns3dMaterialList {
		u16 _0;
		u16 _2;
		Ns3dDictionary dict;
	};
	NITRO_SIZE_ASSERT(Ns3dMaterialList, 0xC);

	inline Ns3dMaterialData* Ns_3dGetMaterial(Ns3dMaterialList* list, u32 index) {
		u32* data = reinterpret_cast<u32*>(Ns_3dGetDictionaryData(&list->dict, index));
		return reinterpret_cast<Ns3dMaterialData*>(reinterpret_cast<u8*>(list) + *data);
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
	NITRO_SIZE_ASSERT(Ns3dNodeData, 0x2);

	struct Ns3dNodeList {
		Ns3dDictionary dict;
	};
	NITRO_SIZE_ASSERT(Ns3dNodeList, 0x8);

	inline Ns3dNodeData* Ns_3dGetNode(Ns3dNodeList* list, u32 index) {
		u32* data = reinterpret_cast<u32*>(Ns_3dGetDictionaryData(&list->dict, index));
		return reinterpret_cast<Ns3dNodeData*>(reinterpret_cast<u8*>(list) + *data);
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
	NITRO_SIZE_ASSERT(Ns3dModelData, 0x48);

	struct Ns3dModelList {
		Ns3dDataHeader hdr;
		Ns3dDictionary dict;
	};
	NITRO_SIZE_ASSERT(Ns3dModelList, 0x10);

	Ns3dModelList* Ns_3dGetModelList(Ns3dFileHeader* file);

	inline Ns3dModelData* Ns_3dGetModel(Ns3dModelList* list, u32 index) {
		u32* data = reinterpret_cast<u32*>(Ns_3dGetDictionaryData(&list->dict, index));
		return reinterpret_cast<Ns3dModelData*>(reinterpret_cast<u8*>(list) + *data);
	}

	inline Ns3dMaterialList* Ns_3dGetMaterials(Ns3dModelData* m) {
		return reinterpret_cast<Ns3dMaterialList*>(reinterpret_cast<u8*>(m) + m->materialOffset);
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

	struct Ns3dTexImageData {
		u32 textureParam;
		u32 _4;
	};
	NITRO_SIZE_ASSERT(Ns3dTexImageData, 0x8);

	struct Ns3dTexPaletteData {
		u16 paletteParam;
		u16 _4;
	};
	NITRO_SIZE_ASSERT(Ns3dTexPaletteData, 0x4);

	struct Ns3dTextureData {
		/* 00 */ Ns3dDataHeader hdr;
		/* 08 */ u32 textureVramOffset;
		/* 0C */ u16 textureSize;
		/* 0E */ u16 textureDictOffset;
		/* 10 */ u16 _10;
		/* 12 */ u16 _12;
		/* 14 */ u32 textureOffset;
		/* 18 */ u32 comp4x4VramOffset;
		/* 1C */ u16 comp4x4Size;
		/* 1E */ u16 comp4x4DictOffset;
		/* 20 */ u16 _20;
		/* 22 */ u16 _22;
		/* 24 */ u32 comp4x4Offset;
		/* 28 */ u32 comp4x4IndexOffset;
		/* 2C */ u32 paletteVramOffset;
		/* 30 */ u16 paletteSize;
		/* 32 */ u16 _32;
		/* 34 */ u16 paletteDictOffset;
		/* 36 */ u16 _36;
		/* 38 */ u32 paletteOffset;
		/* 3C */ Ns3dDictionary dict;
		//u8 data[];
	};
	NITRO_SIZE_ASSERT(Ns3dTextureData, 0x3C + 0x8);

	Ns3dTextureData* Ns_3dGetTexture(Ns3dFileHeader* file);

	inline Ns3dTexImageData* Ns_3dGetTexImageData(Ns3dTextureData* tex, u32 index) {
		return reinterpret_cast<Ns3dTexImageData*>(Ns_3dGetDictionaryData(&tex->dict, index));
	}

	inline Ns3dTexPaletteData* Ns_3dGetTexPaletteData(Ns3dTextureData* tex, u32 index) {
		Ns3dDictionary* dict = reinterpret_cast<Ns3dDictionary*>(reinterpret_cast<u8*>(tex) + tex->paletteDictOffset);
		return reinterpret_cast<Ns3dTexPaletteData*>(Ns_3dGetDictionaryData(dict, index));
	}


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
	NITRO_SIZE_ASSERT(Ns3dDrawable, 0x54);

	void Ns_3dDrawableInit(Ns3dDrawable* d, Ns3dModelData* model);

	void Ns_3dDrawableDraw(Ns3dDrawable* d);

	void Ns_3dDrawableAttachAnimation(Ns3dDrawable* d, Ns3dAnimation* anim);

	void Ns_3dDrawableDetachAnimation(Ns3dDrawable* d, Ns3dAnimation* anim);

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
	NITRO_SIZE_ASSERT(Ns3dAnimation, 0x1C);

	void Ns_3dAnimationInit(Ns3dAnimation* a, void* anim, Ns3dModelData* model, Ns3dTextureData* texture);

	u32 Ns_3dAnimationGetSize(Ns3dAnimationData* anim, Ns3dModelData* model);

	inline void Ns_3dAnimationSetFrame(Ns3dAnimation* a, i32 frame) {
		a->frame = frame;
	}

	inline i32 Ns_3dAnimationGetRatio(Ns3dAnimation* a) {
		return a->scale;
	}

	inline void Ns_3dAnimationSetRatio(Ns3dAnimation* a, i32 ratio) {
		a->scale = ratio;
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
	//NITRO_SIZE_ASSERT(Ns3dGlobalState, 0x264);

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
