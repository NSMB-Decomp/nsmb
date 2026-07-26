#pragma once

#include "../../../src/base_types.hpp"
#include <nds/filesystem.hpp>

class Heap;

namespace FS {

u16 getFileID(const char *path);
u16 toFileID(u32 extendedFileID);
void setFileIDOffset(u32 mode, u16 offset);
bool setFileCount(u16 count);
void init();
u32 getLZ77DecompressedSize(void *header);

u32 loadFileLZ77(u32 extendedFileID, void *destination);
void *loadFileLZ77(u32 extendedFileID);
void unloadFile(void *file);
void *loadFile(u16 fileID);
void *loadFile(u16 fileID, bool storeCache);
u32 loadFile(const char *path, void *destination, s32 maximumSize);
u32 loadFile(
	NDS::Filesystem::FileId fileId, void *destination, s32 maximumSize);
void *loadExtFile(u32 extendedFileID);
void *loadExtFileUnflushed(u32 extendedFileID);
void *loadExtFile(u32 extendedFileID, bool flush);
u32 loadExtFile(u32 extendedFileID, void *destination, s32 maximumSize);
u32 loadExtFile(u32 extendedFileID, void *destination);
void *readFile(NDS::Filesystem::File *file, bool storeCache);
u32 readFile(
	NDS::Filesystem::File *file, void *destination, s32 maximumSize);
bool hasLZ77Header(const void *data);
NDS::Filesystem::FileId getFileID(u32 fileID);
bool openFile(NDS::Filesystem::File *file, u16 fileID);

enum ReadMode {
	ReadMode0 = 0,
	ReadMode1 = 1
};

typedef void *(*ReadFunction)(NDS::Filesystem::File *file, bool storeCache);

extern ReadFunction readFunctionTable[2];
extern ReadMode readMode;

void setReadModeFast();
void setReadModeSafe();
void setReadMode(ReadMode mode);
void *readFileMode1(NDS::Filesystem::File *file, bool storeCache);
void *readFileMode0(NDS::Filesystem::File *file, bool storeCache);

namespace Internal {

extern const char *assertSource;

bool pathToFileID(NDS::Filesystem::FileId *fileId, const char *path);
bool unloadOverlay(u32 processor, u32 overlayID);
bool loadOverlay(u32 processor, u32 overlayID);
bool loadOverlayInfo(NDS::Filesystem::OverlayInfo *info, u32 processor, u32 overlayID);
s32 readFile(NDS::Filesystem::File *file, void *destination, s32 length);
bool openFile(NDS::Filesystem::File *file, const char *path);
bool openFile(NDS::Filesystem::File *file, NDS::Filesystem::FileId fileId);
void setAssertion(const char *source);

}

namespace Overlay {

struct Entry {
	u32 id;
	u32 address;
	u32 size;
	u32 references;
};

NITRO_SIZE_ASSERT(Entry, 0x10);
NITRO_OFFSET_ASSERT(Entry, id, 0x0);
NITRO_OFFSET_ASSERT(Entry, address, 0x4);
NITRO_OFFSET_ASSERT(Entry, size, 0x8);
NITRO_OFFSET_ASSERT(Entry, references, 0xc);

extern Entry loadedOverlays[16];

void initLoadedOverlayTable();
void load(u32 overlayID);
void untrack(u32 overlayID);
bool trackAndLoad(u32 overlayID);
void flush(const NDS::Filesystem::OverlayInfo *info);

}

namespace Archive {

struct Entry {
	void *archive;
	Heap *heap;
	u16 firstFileID;
	u16 endFileID;
	const char *name;
	const char *path;
	const void *image;
};

NITRO_SIZE_ASSERT(Entry, 0x18);
NITRO_OFFSET_ASSERT(Entry, archive, 0x0);
NITRO_OFFSET_ASSERT(Entry, heap, 0x4);
NITRO_OFFSET_ASSERT(Entry, firstFileID, 0x8);
NITRO_OFFSET_ASSERT(Entry, endFileID, 0xa);
NITRO_OFFSET_ASSERT(Entry, name, 0xc);
NITRO_OFFSET_ASSERT(Entry, path, 0x10);
NITRO_OFFSET_ASSERT(Entry, image, 0x14);

extern Entry archives[48];
extern s8 currentArchiveID;
extern const u32 mainGameArchives[3];
extern const u32 minigameArchives[4];

void *getFile(u16 fileID);
void unmountCurrent();
bool unmountAndMountLists(
	const u32 *wanted, const u32 *current, bool allocateFromFront, Heap *heap);
void unmountAll();
void unmountList(const u32 *archives);
void unmount(u32 archiveID);
bool mountList(const u32 *archives, bool allocateFromFront, Heap *heap);
bool mountFront(u32 archiveID, Heap *heap);
bool mountBack(u32 archiveID, Heap *heap);
bool mount(u32 archiveID, s32 allocateFromFront, Heap *heap);
void unmount(void *archive, Heap *heap);
void *mount(
	const char *name, const char *path, Heap *heap, s32 alignment);
bool loadMainGameArchives();
void unloadMinigameArchives();
bool loadMinigameArchives();

}

namespace Cache {

class CacheEntry {
public:
	CacheEntry();
	virtual ~CacheEntry();

	void unload();
	void *loadData(u32 size);
	void *loadFileToOverlay(u32 extendedFileID, bool compressed);
	void *loadFile(u32 extendedFileID, bool compressed);

	u16 entryID;
	s16 references;
	u16 fileID;
	bool compressed;
	u8 reserved_0B;
	u32 size;
	void *heap;
	void *data;
};

NITRO_SIZE_ASSERT(CacheEntry, 0x18);
NITRO_OFFSET_ASSERT(CacheEntry, entryID, 0x4);
NITRO_OFFSET_ASSERT(CacheEntry, references, 0x6);
NITRO_OFFSET_ASSERT(CacheEntry, fileID, 0x8);
NITRO_OFFSET_ASSERT(CacheEntry, compressed, 0xa);
NITRO_OFFSET_ASSERT(CacheEntry, size, 0xc);
NITRO_OFFSET_ASSERT(CacheEntry, heap, 0x10);
NITRO_OFFSET_ASSERT(CacheEntry, data, 0x14);

extern u32 activeFileCache;
extern void *overlayFileDestination;
extern u32 overlayFileRemaining;
extern CacheEntry fileCache0[128];
extern CacheEntry fileCache1[128];

namespace Internal {

CacheEntry *findFile(u32 extendedFileID);
void clear(CacheEntry *entries, u32 count);
bool unloadFile(u32 extendedFileID, CacheEntry *entries, u32 count);
void *loadData(u32 size, CacheEntry *entries, u32 count);
bool setup3DFile(void *file, bool unloadTextures);
void *loadFileToOverlay(
	u32 extendedFileID, CacheEntry *entries, u32 count, bool compressed);
void *loadFile(u32 extendedFileID, CacheEntry *entries, u32 count, bool compressed);
CacheEntry *getData(u32 size, CacheEntry *entries, u32 count);
CacheEntry *getFileInOverlay(
	u32 extendedFileID, CacheEntry *entries, u32 count, bool allowUnused, bool compressed);
CacheEntry *getFile(
	u32 extendedFileID, CacheEntry *entries, u32 count, bool allowUnused, bool compressed);

}

void clear();
bool unloadFile(u32 extendedFileID);
void *loadData(u32 size);
void *loadFileToOverlay(u32 extendedFileID, bool compressed);
void *loadFile(u32 extendedFileID, bool compressed);
void *getFile(u32 extendedFileID);
void setupCacheEntries();

}

void loadBGSubPalette(u32 extendedFileID, u32 offset);
void loadBGExtPaletteCached(u32 extendedFileID, u32 offset);
void loadBGPalette(u32 extendedFileID, u32 offset, bool compressed);
void loadOBJExtPaletteCached(u32 extendedFileID, u32 offset);
void loadOBJExtPalette(u32 extendedFileID, u32 offset, bool compressed);
void loadOBJPalette(u32 extendedFileID, u32 offset, bool compressed);
void loadFileToOBJVram(u32 extendedFileID, u32 offset);
u32 getDecompressedFileSize(u32 extendedFileID);
u32 getFileSize(u32 extendedFileID);

extern "C" void func_0200984c();
extern "C" void *func_0200981c(u16 fileID);
extern "C" void func_02009828(void *object, u32 extendedFileID);
extern "C" void *func_02009864(void *object, u32 extendedFileID);
}
