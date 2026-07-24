#pragma once

#include "../../src/base_types.hpp"

namespace NDS {
namespace Filesystem {

struct FileId {
	u32 archive;
	u32 index;
};

struct File {
	u8 reserved_00_13[0x14];
	u32 status;
	u8 reserved_18_23[0xc];
	u32 start;
	u32 end;
	u8 reserved_2C_47[0x1c];
};

struct OverlayInfo {
	u32 id;
	void *address;
	u32 fileSize;
	u32 zeroFillSize;
	u32 initializerStart;
	u32 initializerEnd;
	u32 fileId;
	u8 reserved_1C_2F[0x14];
};

NITRO_SIZE_ASSERT(FileId, 0x8);
NITRO_SIZE_ASSERT(File, 0x48);
NITRO_SIZE_ASSERT(OverlayInfo, 0x30);
NITRO_OFFSET_ASSERT(FileId, index, 0x4);
NITRO_OFFSET_ASSERT(File, status, 0x14);
NITRO_OFFSET_ASSERT(File, start, 0x24);
NITRO_OFFSET_ASSERT(File, end, 0x28);
NITRO_OFFSET_ASSERT(OverlayInfo, address, 0x4);
NITRO_OFFSET_ASSERT(OverlayInfo, fileSize, 0x8);
NITRO_OFFSET_ASSERT(OverlayInfo, zeroFillSize, 0xc);

void initialize(s32 dmaChannel);
void *findArchive(const char *name, u32 length);
void getOverlayFileId(FileId *fileId, const OverlayInfo *info);
bool unloadOverlay(u32 processor, u32 overlayID);
bool loadOverlay(u32 processor, u32 overlayID);
bool loadOverlayInfo(OverlayInfo *info, u32 processor, u32 overlayID);
s32 readFile(File *file, void *destination, s32 length);
bool openFile(File *file, const char *path);
bool openFile(File *file, FileId fileId);
bool pathToFileId(FileId *fileId, const char *path);
void initializeFile(File *file);
void closeFile(File *file);
void *getArchiveFile(void *archive, u32 index);
bool openArchiveFile(File *file, void *archive, u32 index);
void unmountArchive(void *archive);
bool mountMemoryArchive(void *work, const char *name, const void *image);
bool changeDirectory(const char *path);

}
}
