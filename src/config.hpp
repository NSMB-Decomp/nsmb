#pragma once

// TODO: Korea and China
#if defined(VER_A2DE)   // US
	#define CONFIG_REGION_CODE			'U'
	#define CONFIG_FILE_COUNT			1957
#elif defined(VER_A2DJ) // Japan
	#define CONFIG_REGION_CODE			'J'
	#define CONFIG_FILE_COUNT			???
#elif defined(VER_A2DP) // Europe
	#define CONFIG_REGION_CODE			'E'
	#define CONFIG_FILE_COUNT			???
#endif

#define CONFIG_BACKUP_TYPE				0xD01 // EEPROM 64kb
#define CONFIG_BACKUP_SLOT_SIZE			0x80
#define CONFIG_BACKUP_SIGNATURE			"Mario2d"

#define CONFIG_BUILDTIME_PATH			"/BUILDTIME"

#define CONFIG_DMA_FS					3

#define CONFIG_HEAP_SIZE_GAME			0x38000
#define CONFIG_HEAP_SIZE_SOUND			0xC0000
#define CONFIG_HEAP_SIZE_SOUND_BOSS		121000

#define CONFIG_PLAYER_MAX				2
#define CONFIG_CHARA_MAX				2
#define CONFIG_CONSOLE_MAX				4
