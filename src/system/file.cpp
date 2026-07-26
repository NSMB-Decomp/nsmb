#include "../Heap.hpp"
#include <nds/filesystem.hpp>
#include <nds/graphics.hpp>
#include <nds/memory.hpp>
#include <nds/system.hpp>
#include <nds/system_boot.hpp>
#include <nsmb/arm9/functions.hpp>
#include <nsmb/arm9/symbols.hpp>
#include <nsmb/core/filesystem.hpp>
#include <nsmb/core/game.hpp>
#include <nsmb/core/memory.hpp>
#include <nsmb/core/net/state.hpp>
#include <nsmb/core/wifi.hpp>
#include <nsmb/file_ids.hpp>

namespace FS {

namespace Internal {

static char openFileCrash[] = "dFS_OpenFile";
static char readFileCrash[] = "dFS_ReadFile";
static char readFileFastCrash[] = "dFS_OpenFileFast";
static char convertPathToFileIDCrash[] = "dFS_ConvertPathToFileID";

#pragma section autobss_3 begin

const char *assertSource;

#pragma section autobss_3 end



}

namespace Archive {

const u32 mainGameArchives[3] = {
	8, 10, 47
};

const u32 minigameArchives[4] = {
	27, 24, 11, 47
};

s8 currentArchiveID = -1;

}

#pragma section autobss_3 begin

ReadMode readMode;
u16 fileCount;
s16 fileIDOffset;
void *romArchive;

namespace Overlay {

Entry loadedOverlays[16];

}

namespace Cache {

u32 activeFileCache;
void *overlayFileDestination;
u32 overlayFileRemaining;
CacheEntry fileCache0[128];
CacheEntry fileCache1[128];

}

#pragma section autobss_3 end

ReadFunction readFunctionTable[2] = {
	readFileMode0,
	readFileMode1
};

#define FILE_CPP_ARCHIVE_SLOT_SHIFT 8
#define FILE_CPP_ARCHIVE_SLOT_BASE(slot) \
	(NSMB_ARC_FID_Dat_2D_A_J_jyotyu_bin \
		+ ((slot) << FILE_CPP_ARCHIVE_SLOT_SHIFT))
#define FILE_CPP_ARCHIVE_MENU_COMMON_FIRST FILE_CPP_ARCHIVE_SLOT_BASE(8)
#define FILE_CPP_ARCHIVE_MENU_COMMON_FILE_COUNT 0x0f
#define FILE_CPP_ARCHIVE_MESSAGE_COMMON_FIRST FILE_CPP_ARCHIVE_SLOT_BASE(10)
#define FILE_CPP_ARCHIVE_MESSAGE_COMMON_FILE_COUNT 0x06
#define FILE_CPP_ARCHIVE_TERMINATOR_ID \
	(NSMB_ARC_FID_wrecking_crew_d_2d_mg_bg_wrecking_crew_down_nsc_bin \
		+ NSMB_ARC_FILE_COUNT_ARCHIVE_wrecking_crew + 1)

Archive::Entry Archive::archives[48] = {
	{
		NULL,
		NULL,
		NSMB_ARC_FID_Dat_2D_A_J_jyotyu_bin,
		NSMB_ARC_FID_Dat_2D_A_J_jyotyu_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_Dat_2D,
		"a00",
		"Dat_2D.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_Dat_Basement_ChiKa3MainUnitChangeData_bin,
		NSMB_ARC_FID_Dat_Basement_ChiKa3MainUnitChangeData_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_Dat_Basement,
		"a01",
		"Dat_Basement.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_Dat_Field_I_M_nohara_bin,
		NSMB_ARC_FID_Dat_Field_I_M_nohara_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_Dat_Field,
		"a02",
		"Dat_Field.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_Dat_Fort_I_M_yakata_bin,
		NSMB_ARC_FID_Dat_Fort_I_M_yakata_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_Dat_Fort,
		"a03",
		"Dat_Fort.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_Dat_Ice_I_M_setsugen2_bin,
		NSMB_ARC_FID_Dat_Ice_I_M_setsugen2_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_Dat_Ice,
		"a04",
		"Dat_Ice.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_Dat_Init_A_OBJ_item_fontM_01_ncg_bin,
		NSMB_ARC_FID_Dat_Init_A_OBJ_item_fontM_01_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_Dat_Init,
		"a05",
		"Dat_Init.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_Dat_Pipe_DoKaNSoToMainUnitChangeData_bin,
		NSMB_ARC_FID_Dat_Pipe_DoKaNSoToMainUnitChangeData_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_Dat_Pipe,
		"a06",
		"Dat_Pipe.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_Dat_enemy_I_TEST_toge_l_nsbtx,
		NSMB_ARC_FID_Dat_enemy_I_TEST_toge_l_nsbtx
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_Dat_enemy,
		"a07",
		"Dat_enemy.narc",
		NULL
	},
	{
		NULL,
		NULL,
		FILE_CPP_ARCHIVE_MENU_COMMON_FIRST,
		FILE_CPP_ARCHIVE_MENU_COMMON_FIRST
			+ FILE_CPP_ARCHIVE_MENU_COMMON_FILE_COUNT,
		"a08",
		"menu_common.narc",
		data_02026ce0
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_menu_title_UE_title_ncg_bin,
		NSMB_ARC_FID_menu_title_UE_title_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_menu_title,
		"a09",
		"menu_title.narc",
		NULL
	},
	{
		NULL,
		NULL,
		FILE_CPP_ARCHIVE_MESSAGE_COMMON_FIRST,
		FILE_CPP_ARCHIVE_MESSAGE_COMMON_FIRST
			+ FILE_CPP_ARCHIVE_MESSAGE_COMMON_FILE_COUNT,
		"a0A",
		"message_common.narc",
		data_0203267c
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_ARC0_shadow_cylinder_nsbmd,
		NSMB_ARC_FID_ARC0_shadow_cylinder_nsbmd
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_ARC0,
		"m00",
		"ARC0.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_bomthrow_d_2d_elevator_nsc_bin,
		NSMB_ARC_FID_bomthrow_d_2d_elevator_nsc_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_bomthrow,
		"m01",
		"bomthrow.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_card_d_2d_mg_bg_card2_ncg_bin,
		NSMB_ARC_FID_card_d_2d_mg_bg_card2_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_card,
		"m02",
		"card.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_casino_casino_back_nsbmd,
		NSMB_ARC_FID_casino_casino_back_nsbmd
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_casino,
		"m03",
		"casino.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_flower_yoshi_f_parts_nsbmd,
		NSMB_ARC_FID_flower_yoshi_f_parts_nsbmd
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_flower_yoshi,
		"m04",
		"flower_yoshi.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_hanasagase_d_2d_mg_bg_hana_sagase1_ncg_bin,
		NSMB_ARC_FID_hanasagase_d_2d_mg_bg_hana_sagase1_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_hanasagase,
		"m05",
		"hanasagase.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_jump_d_2d_mg_bg_jump_ncg_bin,
		NSMB_ARC_FID_jump_d_2d_mg_bg_jump_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_jump,
		"m06",
		"jump.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_luigi_model_mg_kino_d_nsbmd,
		NSMB_ARC_FID_luigi_model_mg_kino_d_nsbmd
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_luigi_model_mg,
		"m07",
		"luigi_model_mg.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_mario_model_mg_2jmp1_nsbca,
		NSMB_ARC_FID_mario_model_mg_2jmp1_nsbca
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_mario_model_mg,
		"m08",
		"mario_model_mg.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_mg_common_d_2d_mg_bg_pause_ncg_bin,
		NSMB_ARC_FID_mg_common_d_2d_mg_bg_pause_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_mg_common,
		"m09",
		"mg_common.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_mg_entry_d_2d_mgvs_bg_layer08_nsc_bin,
		NSMB_ARC_FID_mg_entry_d_2d_mgvs_bg_layer08_nsc_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_mg_entry,
		"m0A",
		"mg_entry.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_mg_flower_d_2d_mg_bg_flower_down_ncg_bin,
		NSMB_ARC_FID_mg_flower_d_2d_mg_bg_flower_down_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_mg_flower,
		"m0B",
		"mg_flower.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_mg_luigi_d_2d_mg_bg_luigi1_ncg_bin,
		NSMB_ARC_FID_mg_luigi_d_2d_mg_bg_luigi1_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_mg_luigi,
		"m0C",
		"mg_luigi.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_mg_menu_common_d_2d_mg_bg_mgicons_variety_ncl_bin,
		NSMB_ARC_FID_mg_menu_common_d_2d_mg_bg_mgicons_variety_ncl_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_mg_menu_common,
		"m0D",
		"mg_menu_common.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_mg_teresa_d_2d_mg_bg_teresa1_ncg_bin,
		NSMB_ARC_FID_mg_teresa_d_2d_mg_bg_teresa1_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_mg_teresa,
		"m0E",
		"mg_teresa.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_mg_trampoline_d_2d_mg_bg_trampoline_nsc_bin,
		NSMB_ARC_FID_mg_trampoline_d_2d_mg_bg_trampoline_nsc_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_mg_trampoline,
		"m0F",
		"mg_trampoline.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_mgvs_common_d_2d_mgvs_common_ncl_bin,
		NSMB_ARC_FID_mgvs_common_d_2d_mgvs_common_ncl_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_mgvs_common,
		"m10",
		"mgvs_common.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_p_heyho_p_heyho_mini_nsbmd,
		NSMB_ARC_FID_p_heyho_p_heyho_mini_nsbmd
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_p_heyho,
		"m11",
		"p_heyho.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_pachinko_d_2d_mgvs_pachinko_ncg_bin,
		NSMB_ARC_FID_pachinko_d_2d_mgvs_pachinko_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_pachinko,
		"m12",
		"pachinko.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_pazzle_panel_d_2d_mg_bg_pazzle_panel_down_nsc_bin,
		NSMB_ARC_FID_pazzle_panel_d_2d_mg_bg_pazzle_panel_down_nsc_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_pazzle_panel,
		"m13",
		"pazzle_panel.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_snowball_d_2d_mg_bg_yuka_nsc_bin,
		NSMB_ARC_FID_snowball_d_2d_mg_bg_yuka_nsc_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_snowball,
		"m14",
		"snowball.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_snowwar_Y_head_eat_nsbca,
		NSMB_ARC_FID_snowwar_Y_head_eat_nsbca
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_snowwar,
		"m15",
		"snowwar.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_tranpu_d_2d_mgvs_toranpu_ncl_bin,
		NSMB_ARC_FID_tranpu_d_2d_mgvs_toranpu_ncl_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_tranpu,
		"m16",
		"tranpu.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_vs_amida_d_2d_mgvs_amida_ncg_bin,
		NSMB_ARC_FID_vs_amida_d_2d_mgvs_amida_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_vs_amida,
		"m17",
		"vs_amida.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_vs_balloon_fight_d_2d_mgvs_balloon_fight_ncg_bin,
		NSMB_ARC_FID_vs_balloon_fight_d_2d_mgvs_balloon_fight_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_vs_balloon_fight,
		"m18",
		"vs_balloon_fight.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_vs_escape_d_2d_mgvs_bg_escape_down_ncg_bin,
		NSMB_ARC_FID_vs_escape_d_2d_mgvs_bg_escape_down_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_vs_escape,
		"m19",
		"vs_escape.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_vs_flower_d_2d_mgvs_flower_ncl_bin,
		NSMB_ARC_FID_vs_flower_d_2d_mgvs_flower_ncl_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_vs_flower,
		"m1A",
		"vs_flower.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_vs_mogura_d_2d_mgvs_bg_mogura_down01_nsc_bin,
		NSMB_ARC_FID_vs_mogura_d_2d_mgvs_bg_mogura_down01_nsc_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_vs_mogura,
		"m1B",
		"vs_mogura.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_vs_pachinko_d_2d_mgvs_bg_jugempachinko_down_ncg_bin,
		NSMB_ARC_FID_vs_pachinko_d_2d_mgvs_bg_jugempachinko_down_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_vs_pachinko,
		"m1C",
		"vs_pachinko.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_vs_riversi_d_2d_mgvs_bg_riversi_2p_board_nsc_bin,
		NSMB_ARC_FID_vs_riversi_d_2d_mgvs_bg_riversi_2p_board_nsc_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_vs_riversi,
		"m1D",
		"vs_riversi.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_vs_snowball_d_2d_mgvs_bg_yukidama_ncg_bin,
		NSMB_ARC_FID_vs_snowball_d_2d_mgvs_bg_yukidama_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_vs_snowball,
		"m1E",
		"vs_snowball.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_vs_step_on_d_2d_mgvs_bg_step_on_ncg_bin,
		NSMB_ARC_FID_vs_step_on_d_2d_mgvs_bg_step_on_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_vs_step_on,
		"m1F",
		"vs_step_on.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_vs_tamaire_d_2d_hei_top_down_nsc_bin,
		NSMB_ARC_FID_vs_tamaire_d_2d_hei_top_down_nsc_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_vs_tamaire,
		"m20",
		"vs_tamaire.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_vs_teresa_d_2d_mgvs_teresa_ncg_bin,
		NSMB_ARC_FID_vs_teresa_d_2d_mgvs_teresa_ncg_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_vs_teresa,
		"m21",
		"vs_teresa.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_vs_wrecking_crew_d_2d_mgvs_bg_wrecking_crew_down_nsc_bin,
		NSMB_ARC_FID_vs_wrecking_crew_d_2d_mgvs_bg_wrecking_crew_down_nsc_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_vs_wrecking_crew,
		"m22",
		"vs_wrecking_crew.narc",
		NULL
	},
	{
		NULL,
		NULL,
		NSMB_ARC_FID_wrecking_crew_d_2d_mg_bg_wrecking_crew_down_nsc_bin,
		NSMB_ARC_FID_wrecking_crew_d_2d_mg_bg_wrecking_crew_down_nsc_bin
			+ NSMB_ARC_FILE_COUNT_ARCHIVE_wrecking_crew,
		"m23",
		"wrecking_crew.narc",
		NULL
	},
	{
		NULL,
		NULL,
		FILE_CPP_ARCHIVE_TERMINATOR_ID,
		FILE_CPP_ARCHIVE_TERMINATOR_ID,
		"mff",
		"archive_end",
		NULL
	}
};

#undef FILE_CPP_ARCHIVE_TERMINATOR_ID
#undef FILE_CPP_ARCHIVE_MESSAGE_COMMON_FILE_COUNT
#undef FILE_CPP_ARCHIVE_MESSAGE_COMMON_FIRST
#undef FILE_CPP_ARCHIVE_MENU_COMMON_FILE_COUNT
#undef FILE_CPP_ARCHIVE_MENU_COMMON_FIRST
#undef FILE_CPP_ARCHIVE_SLOT_BASE
#undef FILE_CPP_ARCHIVE_SLOT_SHIFT

namespace Cache {

CacheEntry::CacheEntry()
{
	references = 0;
	fileID = 0xffff;
	compressed = false;
	heap = NULL;
	data = NULL;
}

CacheEntry::~CacheEntry()
{
	fileID = 0xffff;
	references = 0;

	if (data != NULL) {
		unload();
		heap = NULL;
		data = NULL;
		size = 0;
	}
}

void *CacheEntry::loadFile(u32 extendedFileID, bool isCompressed)
{
	if (isCompressed == true)
		data = FS::loadFileLZ77(extendedFileID);
	else
		data = FS::loadExtFile(extendedFileID);

	if (data != NULL) {
		fileID = extendedFileID;
		compressed = isCompressed;
		heap = Memory::currentHeapPtr;
		size = Memory::currentHeapPtr->sizeOf(data);
		NDS::Memory::flushDataCache(data, size);
	}

	return data;
}

void *CacheEntry::loadFileToOverlay(u32 extendedFileID, bool isCompressed)
{
	data = overlayFileDestination;

	if (isCompressed == true)
		size = FS::loadFileLZ77(extendedFileID, data);
	else
		size = FS::loadExtFile(extendedFileID, data);

	u32 alignedSize = (size + 0xf) & ~0xf;
	overlayFileDestination = static_cast<u8 *>(data) + alignedSize;
	overlayFileRemaining -= alignedSize;
	fileID = extendedFileID;
	compressed = isCompressed;
	heap = NULL;
	NDS::Memory::flushDataCache(data, size);
	return data;
}

void *CacheEntry::loadData(u32 requestedSize)
{
	data = Memory::allocate(requestedSize);
	if (data != NULL) {
		fileID = 0x7a5;
		compressed = false;
		heap = Memory::currentHeapPtr;
		size = Memory::currentHeapPtr->sizeOf(data);
	}

	return data;
}

void CacheEntry::unload()
{
	if (heap != NULL)
		Memory::deallocate(static_cast<Heap *>(heap), data);
}

void setupCacheEntries()
{
	s16 i;
	for (i = 0; i < 128; ++i)
		fileCache0[i].entryID = i;

	for (i = 0; i < 128; ++i)
		fileCache1[i].entryID = i + 128;
}

namespace Internal {

CacheEntry *getFile(
	u32 extendedFileID, CacheEntry *entries, u32 count, bool allowUnused, bool compressed)
{
	CacheEntry *unused = NULL;

	for (s32 i = 0; i < (s32)count; ++i) {
		if (entries->references != 0) {
			if ((u16)extendedFileID == entries->fileID)
				return entries;
		} else if (allowUnused) {
			unused = entries;
		}
		++entries;
	}

	if (unused != NULL && unused->loadFile(extendedFileID, compressed) == NULL)
		return NULL;

	return unused;
}

CacheEntry *getFileInOverlay(
	u32 extendedFileID, CacheEntry *entries, u32 count, bool allowUnused, bool compressed)
{
	CacheEntry *unused = NULL;

	for (s32 i = 0; i < (s32)count; ++i) {
		if (entries->references != 0) {
			if ((u16)extendedFileID == entries->fileID)
				return entries;
		} else if (allowUnused) {
			unused = entries;
		}
		++entries;
	}

	if (unused != NULL
		&& unused->loadFileToOverlay(extendedFileID, compressed) == NULL)
		return NULL;

	return unused;
}

CacheEntry *getData(u32 size, CacheEntry *entries, u32 count)
{
	CacheEntry *unused = NULL;

	for (s32 i = 0; i < (s32)count; ++i) {
		if (entries->references == 0) {
			unused = entries;
			break;
		}
		++entries;
	}

	if (unused != NULL && unused->loadData(size) == NULL)
		return NULL;

	return unused;
}

void *loadFile(u32 extendedFileID, CacheEntry *entries, u32 count, bool compressed)
{
	CacheEntry *entry = getFile(extendedFileID, entries, count, true, compressed);
	if (entry == NULL)
		return NULL;

	void *file = entry->data;
	if (entry->references == 0)
		setup3DFile(file, true);

	++entry->references;
	return file;
}

void *loadFileToOverlay(
	u32 extendedFileID, CacheEntry *entries, u32 count, bool compressed)
{
	CacheEntry *entry =
		getFileInOverlay(extendedFileID, entries, count, true, compressed);
	if (entry == NULL)
		return NULL;

	void *file = entry->data;
	if (entry->references == 0)
		setup3DFile(file, false);

	++entry->references;
	return file;
}

bool setup3DFile(void *file, bool unloadTextures)
{
	struct TextureResource {
		u8 reserved_00_13[0x14];
		u32 dataOffset;
	};

	u32 signature = *static_cast<u32 *>(file);
	if (signature == 0x30444d42 || signature == 0x30585442) {
		if (!NDS::Graphics3D::setupResource(file))
			return false;

		void *texture = NDS::Graphics3D::getTexture(file);
		if (texture != NULL) {
			TextureResource *resource = static_cast<TextureResource *>(texture);
			u32 size = static_cast<u8 *>(texture) + resource->dataOffset
				- static_cast<u8 *>(file);
			if (unloadTextures)
				Memory::reallocate(Memory::currentHeapPtr, file, size);
		}
	}

	return true;
}

void *loadData(u32 size, CacheEntry *entries, u32 count)
{
	CacheEntry *entry = getData(size, entries, count);
	if (entry == NULL)
		return NULL;

	++entry->references;
	return entry->data;
}

bool unloadFile(u32 extendedFileID, CacheEntry *entries, u32 count)
{
	CacheEntry *entry = getFile(extendedFileID, entries, count, false, false);
	if (entry == NULL)
		return false;

	--entry->references;
	if (entry->references == 0)
		entry->~CacheEntry();

	return true;
}

void clear(CacheEntry *entries, u32 count)
{
	for (s32 i = 0; i < (s32)count; ++i)
		entries[i].~CacheEntry();
}

CacheEntry *findFile(u32 extendedFileID)
{
	CacheEntry *entry = getFile(extendedFileID, fileCache0, 128, false, false);
	if (entry != NULL)
		return entry;

	entry = getFile(extendedFileID, fileCache1, 128, false, false);
	return entry == NULL ? NULL : entry;
}

}

void *getFile(u32 extendedFileID)
{
	CacheEntry *entry = Internal::findFile(extendedFileID);
	if (entry != NULL)
		return entry->data;
	return NULL;
}

void *loadFile(u32 extendedFileID, bool compressed)
{
	if (activeFileCache == 0)
		return Internal::loadFile(extendedFileID, fileCache0, 128, compressed);
	return Internal::loadFile(extendedFileID, fileCache1, 128, compressed);
}

void *loadFileToOverlay(u32 extendedFileID, bool compressed)
{
	if (activeFileCache == 0)
		return Internal::loadFileToOverlay(extendedFileID, fileCache0, 128, compressed);
	return Internal::loadFileToOverlay(extendedFileID, fileCache1, 128, compressed);
}

void *loadData(u32 size)
{
	if (activeFileCache == 0)
		return Internal::loadData(size, fileCache0, 128);
	return Internal::loadData(size, fileCache1, 128);
}

bool unloadFile(u32 extendedFileID)
{
	Internal::unloadFile(extendedFileID, fileCache1, 128);
	Internal::unloadFile(extendedFileID, fileCache0, 128);
	return true;
}

void clear()
{
	Internal::clear(fileCache1, 128);
	Internal::clear(fileCache0, 128);
}

}

u32 getFileSize(u32 extendedFileID)
{
	NDS::Filesystem::File file;
	u32 size = 0;
	NDS::Filesystem::initializeFile(&file);

	NDS::Filesystem::FileId fileID = getFileID(toFileID(extendedFileID));

	if (Internal::openFile(&file, fileID)) {
		size = file.end - file.start;
		NDS::Filesystem::closeFile(&file);
	}

	return size;
}

u32 getDecompressedFileSize(u32 extendedFileID)
{
	u32 header;
	loadExtFile(extendedFileID, &header, sizeof(header));
	return header >> 8;
}

void loadFileToOBJVram(u32 extendedFileID, u32 offset)
{
	void *file = Cache::getFile(extendedFileID);
	if (file == NULL)
		return;

	Cache::CacheEntry *entry = Cache::Internal::findFile(extendedFileID);
	NDS::Memory::copy8(
		file, reinterpret_cast<void *>(0x06400000 + offset), entry->size);
}

void loadOBJPalette(u32 extendedFileID, u32 offset, bool compressed)
{
	void *file;

	if (compressed)
		file = loadFileLZ77(extendedFileID);
	else
		file = loadExtFile(extendedFileID);

	if (file == NULL)
		return;

	u32 size = Memory::currentHeapPtr->sizeOf(file);
	NDS::Graphics::uploadMainObjectPalette(file, offset, size);
	unloadFile(file);
}

void loadOBJExtPalette(u32 extendedFileID, u32 offset, bool compressed)
{
	void *file;

	if (compressed)
		file = loadFileLZ77(extendedFileID);
	else
		file = loadExtFile(extendedFileID);

	if (file == NULL)
		return;

	u32 size = Memory::currentHeapPtr->sizeOf(file);
	NDS::Graphics::beginMainObjectExtendedPaletteUpload();
	NDS::Graphics::uploadMainObjectExtendedPalette(file, offset, size);
	NDS::Graphics::endMainObjectExtendedPaletteUpload();
	unloadFile(file);
}

void loadOBJExtPaletteCached(u32 extendedFileID, u32 offset)
{
	void *file = Cache::getFile(extendedFileID);
	if (file == NULL)
		return;

	u32 size = Memory::currentHeapPtr->sizeOf(file);
	NDS::Graphics::beginMainObjectExtendedPaletteUpload();
	NDS::Graphics::uploadMainObjectExtendedPalette(file, offset, size);
	NDS::Graphics::endMainObjectExtendedPaletteUpload();
}

void loadBGPalette(u32 extendedFileID, u32 offset, bool compressed)
{
	void *file;

	if (compressed)
		file = loadFileLZ77(extendedFileID);
	else
		file = loadExtFile(extendedFileID);

	if (file == NULL)
		return;

	u32 size = Memory::currentHeapPtr->sizeOf(file);
	NDS::Graphics::uploadMainBackgroundPalette(
		static_cast<u16 *>(file), offset, size);
	unloadFile(file);
}

void loadBGExtPaletteCached(u32 extendedFileID, u32 offset)
{
	void *file = Cache::getFile(extendedFileID);
	u32 size = Memory::currentHeapPtr->sizeOf(file);
	if (file == NULL)
		return;

	NDS::Graphics::beginMainBackgroundExtendedPaletteUpload();
	NDS::Graphics::uploadMainBackgroundExtendedPalette(file, offset, size);
	NDS::Graphics::endMainBackgroundExtendedPaletteUpload();
}

void loadBGSubPalette(u32 extendedFileID, u32 offset)
{
	void *file = loadExtFile(extendedFileID);
	u32 size = Memory::currentHeapPtr->sizeOf(file);

	if (file != NULL) {
		NDS::Graphics::uploadSubBackgroundPalette(
			reinterpret_cast<u32>(file), offset, size);
		unloadFile(file);
	}
}

extern "C" void *func_02009864(void *object, u32 extendedFileID)
{
	func_02009828(object, extendedFileID);
	return object;
}

extern "C" void func_0200984c()
{
	data_0208b690 = func_0200981c;
}

extern "C" void func_02009828(void *object, u32 extendedFileID)
{
	u32 fileID = toFileID(extendedFileID);
	func_02044418(object, static_cast<u16>(fileID));
}

extern "C" void *func_0200981c(u16 fileID)
{
	return loadFile(fileID);
}

namespace Archive {

bool loadMinigameArchives()
{
	return mountList(minigameArchives, false, NULL);
}

void unloadMinigameArchives()
{
	unmountList(minigameArchives);
}

bool loadMainGameArchives()
{
	return mountList(mainGameArchives, false, NULL);
}

}

namespace Overlay {

void flush(const NDS::Filesystem::OverlayInfo *info)
{
	u32 fileSize = info->fileSize;
	u32 zeroFillSize = info->zeroFillSize;
	void *address = info->address;
	u32 size = fileSize + zeroFillSize;
	NDS::Memory::invalidateInstructionCache(address, size);
	NDS::Memory::invalidateDataCache(address, size);
}

bool trackAndLoad(u32 overlayID)
{
	Entry *empty = NULL;

	for (u32 i = 0; i < 16; ++i) {
		Entry *entry = &loadedOverlays[i];

		if (entry->id == overlayID) {
			++entry->references;
			return true;
		}

		if (entry->id == -1 && empty == NULL)
			empty = entry;
	}

	NDS::Filesystem::OverlayInfo info;
	Internal::loadOverlayInfo(&info, 0, overlayID);

	BOOL error =
		(data_020887f8 != 0 && func_02046bb4() != 0)
		|| (Net::errorState & 0x2000) != 0;
	if (error)
		return false;

	NDS::Filesystem::FileId fileID;
	NDS::Filesystem::getOverlayFileId(&fileID, &info);

	u32 address = reinterpret_cast<u32>(info.address);
	u32 size = info.fileSize + info.zeroFillSize;

	for (u32 i = 0; i < 16; ++i) {
		Entry *entry = &loadedOverlays[i];

		if (entry->id != overlayID && entry->id != -1
			&& entry->address + entry->size > address
			&& address + size > entry->address) {
			if (entry->references == 0) {
				Internal::unloadOverlay(0, entry->id);
				Internal::loadOverlayInfo(&info, 0, entry->id);

				error =
					(data_020887f8 != 0 && func_02046bb4() != 0)
					|| (Net::errorState & 0x2000) != 0;
				if (error)
					return false;

				flush(&info);
				entry->id = -1;
				entry->address = 0;
				entry->size = 0;

				if (empty == NULL)
					empty = entry;
			} else {
				NDS::System::halt();
			}
		}
	}

	if (empty != NULL) {
		empty->id = overlayID;
		empty->address = address;
		empty->size = size;
		++empty->references;
	}

	u32 loaded = Internal::loadOverlay(0, overlayID);
	if (data_020887f8 != 0)
		func_02046bb4();
	return loaded != 0;
}

void load(u32 overlayID)
{
	if (trackAndLoad(overlayID))
		return;

	if (NDS::System::isBootStatus2())
		NDS::Threads::exitCurrent();
	else
		NDS::System::halt();
}

void untrack(u32 overlayID)
{
	Entry *found = NULL;
	u32 i = 0;
	Entry *entry = loadedOverlays;

	for (; i < 16; ++i) {
		if (entry->id == overlayID) {
			--entry->references;
			found = entry;
		}
		++entry;
	}

	if (found != NULL)
		return;
	NDS::System::halt();
}

void initLoadedOverlayTable()
{
	u32 i = 0;
	Entry *entry = loadedOverlays;
	for (; i < 16; ++i) {
		entry->id = -1;
		entry->address = 0;
		entry->size = 0;
		++entry;
	}
}

}

u32 getLZ77DecompressedSize(void *header)
{
	return *static_cast<u32 *>(header) >> 8;
}

void init()
{
	if (Wifi::isMultiBootChild())
		NDS::Filesystem::initialize(-1);
	else
		NDS::Filesystem::initialize(2);
	romArchive = NDS::Filesystem::findArchive("rom", 3);
	Overlay::initLoadedOverlayTable();
	func_0200984c();
}

bool setFileCount(u16 count)
{
	fileCount = count;
	return true;
}

void setFileIDOffset(u32 mode, u16 offset)
{
	if (mode == 1)
		fileIDOffset = offset - 1;
}

u16 toFileID(u32 extendedFileID)
{
	if ((extendedFileID & 0xffff0000) != 0) {
		BOOL useUpperHalf = data_02085a84 != 0;
		if (useUpperHalf != FALSE)
			extendedFileID >>= 16;
		else
			extendedFileID &= 0xffff;
	}

	u16 fileID;
	if (extendedFileID >= 0x8000)
		fileID = extendedFileID;
	else
		fileID = fileIDOffset + extendedFileID;
	return fileID;
}

u16 getFileID(const char *path)
{
	NDS::Filesystem::FileId fileId;
	Internal::pathToFileID(&fileId, path);
	return fileId.index;
}

namespace Archive {

void *mount(
	const char *name,
	const char *path,
	Heap *heap,
	s32 alignment)
{
	void *result = NULL;
	NDS::Filesystem::File file;
	NDS::Filesystem::initializeFile(&file);
	Internal::openFile(&file, path);

	u32 alignedSize;
	void *archive;
	u32 size = file.end - file.start;
	alignedSize = (size + 15) & ~15;
	archive = Memory::allocate(
		heap, alignedSize + 0x70, alignment);
	void *image = static_cast<u8 *>(archive) + 0x70;
	Game::flushDataCache(image, alignedSize);

	if (Internal::readFile(&file, image, size) == size
		&& NDS::Filesystem::mountMemoryArchive(
			archive, name, image)) {
		result = archive;
	} else {
		Memory::deallocate(heap, archive);
	}

	NDS::Filesystem::closeFile(&file);
	return result;
}

void unmount(void *archive, Heap *heap)
{
	NDS::Filesystem::unmountArchive(archive);
	Memory::deallocate(heap, archive);
}

bool mount(u32 archiveID, s32 allocateFromFront, Heap *heap)
{
	Entry *entry = &archives[archiveID];
	if (heap == NULL)
		heap = Memory::rootHeapPtr;

	if (entry->image != NULL) {
		entry->heap = heap;
		void *archive =
			Memory::allocate(entry->heap, 0x70, 16);
		if (NDS::Filesystem::mountMemoryArchive(
				archive, entry->name, entry->image)) {
			entry->archive = archive;
		} else {
			Memory::deallocate(entry->heap, archive);
			entry->heap = NULL;
			return false;
		}

		return true;
	}

	if (entry->archive == NULL) {
		s32 alignment;
		if (allocateFromFront <= 0)
			alignment = -16;
		else
			alignment = 16;
		entry->heap = heap;
		NDS::Filesystem::changeDirectory("/ARCHIVE");
		entry->archive = mount(
			entry->name, entry->path, entry->heap, alignment);
	}

	return entry->archive != NULL;
}

bool mountBack(u32 archiveID, Heap *heap)
{
	return mount(archiveID, false, heap);
}

bool mountFront(u32 archiveID, Heap *heap)
{
	return mount(archiveID, true, heap);
}

bool mountList(
	const u32 *archiveIDs,
	bool allocateFromFront,
	Heap *heap)
{
	while (*archiveIDs != 47) {
		if (!mount(*archiveIDs, allocateFromFront, heap))
			return false;
		++archiveIDs;
	}

	return true;
}

void unmount(u32 archiveID)
{
	Entry *entry = &archives[archiveID];
	if (entry->archive == NULL)
		return;

	unmount(entry->archive, entry->heap);
	entry->archive = NULL;
	entry->heap = NULL;
}

void unmountList(const u32 *archiveIDs)
{
	while (*archiveIDs != 47) {
		unmount(*archiveIDs);
		++archiveIDs;
	}
}

void unmountAll()
{
	for (u32 i = 0; i < 48; ++i) {
		Entry *entry = &archives[i];
		if (entry->image == NULL && entry->archive != NULL) {
			unmount(entry->archive, entry->heap);
			entry->archive = NULL;
		}
	}
}

bool unmountAndMountLists(
	const u32 *wanted,
	const u32 *current,
	bool allocateFromFront,
	Heap *heap)
{
	while (*wanted != 47
		&& *current != 47
		&& *wanted == *current) {
		++wanted;
		++current;
	}

	unmountList(current);
	return mountList(wanted, allocateFromFront, heap);
}

void unmountCurrent()
{
	if (currentArchiveID < 0)
		return;

	unmount(currentArchiveID);
	currentArchiveID = -1;
}

void *getFile(u16 fileID)
{
	if (fileID < 0x8000)
		return NULL;

	for (u32 i = 0; i < 48; ++i) {
		Entry *entry = &archives[i];
		if (entry->firstFileID <= fileID
			&& fileID < entry->endFileID) {
			if (entry->archive == NULL) {
				if (mountBack(i, NULL))
					currentArchiveID = i;
				if (entry->archive == NULL) {
					NDS::System::halt();
					return NULL;
				}
			}

			return NDS::Filesystem::getArchiveFile(
				entry->archive,
				fileID - entry->firstFileID);
		}
	}

	NDS::System::halt();
	return NULL;
}

}

bool openFile(
	NDS::Filesystem::File *file, u16 fileID)
{
	bool result = false;
	NDS::Filesystem::initializeFile(file);

	if (fileID < 0x8000) {
		NDS::Filesystem::FileId id = getFileID(fileID);
		result = Internal::openFile(file, id);
	} else {
		for (u32 i = 0; i < 48; ++i) {
			Archive::Entry *entry = &Archive::archives[i];
			if (entry->firstFileID <= fileID
				&& fileID < entry->endFileID) {
				if (entry->archive == NULL) {
					if (Archive::mountBack(i, NULL))
						Archive::currentArchiveID = i;
					if (entry->archive == NULL) {
						NDS::System::halt();
						return false;
					}
				}

				result = NDS::Filesystem::openArchiveFile(
					file,
					entry->archive,
					fileID - entry->firstFileID);
				break;
			}
		}
	}

	if (!result)
		NDS::System::halt();
	return result;
}

NDS::Filesystem::FileId getFileID(u32 fileID)
{
	NDS::Filesystem::FileId id = {
		reinterpret_cast<u32>(romArchive),
		fileID
	};
	return id;
}

bool hasLZ77Header(const void *data)
{
	return strncmp(
		static_cast<const char *>(data), "LZ77", 4) == 0;
}

u32 readFile(
	NDS::Filesystem::File *file,
	void *destination,
	s32 maximumSize)
{
	u32 size = file->end - file->start;
	if (size > static_cast<u32>(maximumSize))
		size = maximumSize;

	Game::flushDataCache(destination, size);
	s32 result = Internal::readFile(file, destination, size);
	NDS::Filesystem::closeFile(file);
	Archive::unmountCurrent();
	if (size != result)
		return 0;

	hasLZ77Header(destination);
	Game::storeDataCache(destination, size);
	return size;
}

u32 loadFile(
	NDS::Filesystem::FileId fileId,
	void *destination,
	s32 maximumSize)
{
	NDS::Filesystem::File file;
	NDS::Filesystem::initializeFile(&file);
	if (!Internal::openFile(&file, fileId)) {
		NDS::System::halt();
		return 0;
	}

	return FS::readFile(&file, destination, maximumSize);
}

u32 loadFile(
	const char *path, void *destination, s32 maximumSize)
{
	NDS::Filesystem::FileId fileId;
	Internal::pathToFileID(&fileId, path);
	return loadFile(fileId, destination, maximumSize);
}

void *readFileMode0(
	NDS::Filesystem::File *file, bool storeCache)
{
	enum {
		Lz77Magic = 0x37375a4c,
		Lz77MagicReversed = 0x4c5a3737,
		RootHeapAllocationFlag = 0x4000
	};

	void *destination = NULL;
	Heap *destinationHeap;
	void *temporary;
	Heap *temporaryHeap = Memory::rootHeapPtr;
	destinationHeap = static_cast<Heap *>(destination);
	if (destinationHeap == NULL)
		destinationHeap = Memory::currentHeapPtr;
	u32 size = file->end - file->start;

	if (size < 8) {
		destination =
			Memory::allocate(destinationHeap, size, 4);
		if (destination != NULL)
			Internal::readFile(file, destination, size);
	} else {
		u32 header[2];
		if (Internal::readFile(file, header, sizeof(header)) != -1) {
			if (header[0] == Lz77Magic
				|| header[0] == Lz77MagicReversed) {
				u32 oldFlags;
				u32 decompressedSize = header[1] >> 8;
				destination = Memory::allocate(
					destinationHeap, decompressedSize, 4);

				if (destination != NULL) {
					oldFlags = temporaryHeap->setFlags(0);
					temporaryHeap->setFlags(
						oldFlags & ~RootHeapAllocationFlag);

					temporary = Memory::allocate(
						temporaryHeap, size - 4, -4);
					if (temporary != NULL) {
						NDS::Memory::copy8(
							&header[1], temporary, sizeof(u32));
						NDS::Memory::storeEntireDataCache();
						NDS::Memory::flushEntireDataCache();

						s32 result = Internal::readFile(
							file,
							static_cast<u8 *>(temporary) + 4,
							size - 8);
						if (result != -1)
							NDS::Memory::decompressLz8(
								temporary, destination);
					} else {
						u32 temporarySize =
							temporaryHeap->maxAllocatableSize(-4);
						temporary = Memory::allocate(
							temporaryHeap,
							temporarySize,
							-4);

						if (temporary != NULL) {
							NDS::Memory::LzStreamContext context;
							NDS::Memory::initializeLzStream(
								&context,
								destination,
								&header[1]);

							s32 remaining;
							do {
								s32 readSize =
									Internal::readFile(
										file,
										temporary,
										temporarySize);
								if (readSize == -1)
									break;
								remaining =
									NDS::Memory::consumeLzStream(
										&context,
										temporary,
										readSize);
							} while (remaining != 0);
						}
					}

					if (temporary != NULL)
						Memory::deallocate(
							temporaryHeap, temporary);
					temporaryHeap->setFlags(oldFlags);
					size = decompressedSize;
				}
			} else {
				destination = Memory::allocate(
					destinationHeap, size, 4);
				if (destination != NULL) {
					NDS::Memory::copy8(
						header, destination, sizeof(header));
					Internal::readFile(
						file,
						static_cast<u8 *>(destination) + 8,
						size - 8);
				}
			}
		}
	}

	if (file->status != 0 && destination != NULL) {
		Memory::deallocate(destinationHeap, destination);
		destination = NULL;
	}

	NDS::Filesystem::closeFile(file);
	Archive::unmountCurrent();
	if (storeCache)
		Game::storeDataCache(destination, size);
	return destination;
}

void *readFileMode1(
	NDS::Filesystem::File *file, bool storeCache)
{
	void *destination;
	u32 size = file->end - file->start;
	void *source = Memory::allocate(size, -4);
	Game::flushDataCache(source, size);

	s32 result = Internal::readFile(file, source, size);
	if (result != size)
		return NULL;

	if (hasLZ77Header(source)) {
		size = getLZ77DecompressedSize(
			static_cast<u8 *>(source) + 4);
		destination = Memory::allocate(size);
		NDS::Memory::decompressLz16(
			reinterpret_cast<u32>(
				static_cast<u8 *>(source) + 4),
			reinterpret_cast<u32>(destination));
	} else {
		destination = Memory::allocate(size);
		NDS::Memory::copy8(source, destination, size);
	}

	Memory::deallocate(source);
	NDS::Filesystem::closeFile(file);
	Archive::unmountCurrent();
	if (storeCache)
		Game::storeDataCache(destination, size);
	return destination;
}

void setReadMode(ReadMode mode)
{
	readMode = mode;
}

void setReadModeSafe()
{
	setReadMode(ReadMode1);
}

void setReadModeFast()
{
	setReadMode(ReadMode0);
}

void *readFile(
	NDS::Filesystem::File *file, bool storeCache)
{
	return readFunctionTable[readMode](file, storeCache);
}

u32 loadExtFile(u32 extendedFileID, void *destination)
{
	return loadExtFile(extendedFileID, destination, -1);
}

u32 loadExtFile(
	u32 extendedFileID, void *destination, s32 maximumSize)
{
	NDS::Filesystem::File file;
	openFile(&file, toFileID(extendedFileID));
	return FS::readFile(&file, destination, maximumSize);
}

void *loadFile(u16 fileID, bool storeCache)
{
	u32 size;
	void *destination;
	void *source = Archive::getFile(fileID);

	if (source != NULL) {
		if (hasLZ77Header(source)) {
			source = static_cast<u8 *>(source) + 4;
			size = getLZ77DecompressedSize(source);
			destination = Memory::allocate(size);
			NDS::Memory::decompressLz16(
				reinterpret_cast<u32>(source),
				reinterpret_cast<u32>(destination));
		} else {
			NDS::Filesystem::File file;
			openFile(&file, fileID);
			size = file.end - file.start;
			NDS::Filesystem::closeFile(&file);

			destination = Memory::allocate(size, 32);
			NDS::Memory::copy8(source, destination, size);
		}

		Archive::unmountCurrent();
		if (storeCache)
			Game::storeDataCache(destination, size);
		return destination;
	}

	NDS::Filesystem::File file;
	openFile(&file, fileID);
	return readFile(&file, storeCache);
}

void *loadExtFile(u32 extendedFileID, bool storeCache)
{
	return loadFile(toFileID(extendedFileID), storeCache);
}

void *loadExtFileUnflushed(u32 extendedFileID)
{
	return loadExtFile(extendedFileID, false);
}

void *loadExtFile(u32 extendedFileID)
{
	return loadExtFile(extendedFileID, true);
}

void *loadFile(u16 fileID)
{
	return loadFile(fileID, true);
}

void unloadFile(void *file)
{
	if (file != NULL)
		Memory::deallocate(file);
}

u32 loadFileLZ77(u32 extendedFileID, void *destination)
{
	void *source = loadExtFileUnflushed(extendedFileID);
	if (source == NULL)
		return 0;

	u32 size = getLZ77DecompressedSize(source);
	NDS::Memory::decompressLz16((u32)source, (u32)destination);
	unloadFile(source);
	return size;
}

void *loadFileLZ77(u32 extendedFileID)
{
	u16 fileID = toFileID(extendedFileID);
	void *source = Archive::getFile(fileID);
	void *destination;
	u32 decompressedSize;

	if (source != NULL) {
		decompressedSize = getLZ77DecompressedSize(source);
		destination = Memory::allocate(decompressedSize);
		NDS::Memory::decompressLz16(
			reinterpret_cast<u32>(source),
			reinterpret_cast<u32>(destination));
		Archive::unmountCurrent();
		Game::storeDataCache(destination, decompressedSize);
	} else {
		NDS::Filesystem::File file;
		openFile(&file, fileID);

		u32 compressedSize = file.end - file.start;
		source = Memory::allocate(compressedSize, -4);
		Game::flushDataCache(source, compressedSize);
		s32 readSize =
			Internal::readFile(&file, source, compressedSize);
		if (readSize != compressedSize)
			return NULL;

		decompressedSize = getLZ77DecompressedSize(source);
		destination = Memory::allocate(decompressedSize);
		NDS::Memory::decompressLz16(
			reinterpret_cast<u32>(source),
			reinterpret_cast<u32>(destination));
		Memory::deallocate(source);
		NDS::Filesystem::closeFile(&file);
		Archive::unmountCurrent();
		Game::storeDataCache(destination, decompressedSize);
	}

	return destination;
}

namespace Internal {

void setAssertion(const char *source)
{
	if (!Net::assert(false))
		return;

	assertSource = source;
	NDS::Threads::exitCurrent();
}

bool pathToFileID(
	NDS::Filesystem::FileId *fileId, const char *path)
{
	bool result = NDS::Filesystem::pathToFileId(fileId, path);
	if (!result) {
		setAssertion(convertPathToFileIDCrash);
		NDS::System::halt();
	}
	return result;
}

bool openFile(
	NDS::Filesystem::File *file, NDS::Filesystem::FileId fileId)
{
	bool result = NDS::Filesystem::openFile(file, fileId);
	if (!result) {
		setAssertion(readFileFastCrash);
		NDS::System::halt();
	}
	return result;
}

bool openFile(NDS::Filesystem::File *file, const char *path)
{
	bool result = NDS::Filesystem::openFile(file, path);
	if (!result) {
		setAssertion(openFileCrash);
		NDS::System::halt();
	}
	return result;
}

s32 readFile(
	NDS::Filesystem::File *file, void *destination, s32 length)
{
	s32 result = NDS::Filesystem::readFile(file, destination, length);
	if (result != length) {
		setAssertion(readFileCrash);
		NDS::System::halt();
	}
	return result;
}

bool loadOverlayInfo(
	NDS::Filesystem::OverlayInfo *info, u32 processor, u32 overlayID)
{
	return NDS::Filesystem::loadOverlayInfo(info, processor, overlayID);
}

bool loadOverlay(u32 processor, u32 overlayID)
{
	return NDS::Filesystem::loadOverlay(processor, overlayID);
}

bool unloadOverlay(u32 processor, u32 overlayID)
{
	return NDS::Filesystem::unloadOverlay(processor, overlayID);
}

}

}
