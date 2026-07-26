#include "../../../worldmap/scene.hpp"
#include "../../../worldmap/camera.hpp"
#include "../../../worldmap/character.hpp"
#include "../../../worldmap/controller.hpp"
#include "../../../worldmap/entitymodel.hpp"
#include "../../../worldmap/minimap.hpp"
#include "../../../worldmap/playermodel.hpp"
#include "../../../menu/OptionsMenu.hpp"
#include "../../../Bases/Object.hpp"
#include "../../../objectid.hpp"
#include "../../../system/app.hpp"
#include "../../../system/vblank.hpp"
#include "../../../TextBox.hpp"
#include <nds/graphics.hpp>
#include <nds/graphics_controls.hpp>
#include <nds/input_buttons.hpp>
#include <nds/memory.hpp>
#include <nds/sound.hpp>
#include <nds/system.hpp>
#include <nsmb/arm9/functions.hpp>
#include <nsmb/arm9/symbols.hpp>
#include <nsmb/core/filesystem.hpp>
#include <nsmb/file_ids.hpp>
#include <nsmb/game/game.hpp>
#include <nsmb/game/player.hpp>
#include <nsmb/overlays/ov000/symbols.hpp>
#include <nsmb/overlays/ov008/symbols.hpp>
#include <nsmb/overlays/ov053/symbols.hpp>

WorldmapScene::~WorldmapScene() {}

extern "C" void func_ov008_020cdccc(u32 lastWorld)
{
	u32 world = 0;
	do {
		save.game.worldStates[world] |= WM::WS_Bits1Through5;
		world++;
	} while (world <= lastWorld);
}

extern "C" void func_ov008_020cdb70(int mode, int arrowValue)
{
	switch (mode) {
	case 1:
	case 2:
		data_ov008_020ee58c.renderArrows(arrowValue, 0, 0);
		break;
	case 3:
		TextBox::renderAButton(0, 0);
		break;
	}
	data_ov008_020ee58c.renderText(0, 0);
}

extern "C" void func_ov008_020cdbd0()
{
	u8 dialogBox = data_ov008_020ee374;
	int boxID =
		data_ov008_020e64ec[dialogBox][data_ov008_020ee380];
	int dialogFlag = 0;
	if (dialogBox != 0) {
		dialogFlag = 1;
	}
	TextBoxMessagePrefix* message = func_ov008_020cdc30(
		boxID, dialogFlag, data_ov008_020ee3f4);
	if (message != 0) {
		message->unk14E = 0xb;
	}
}

extern "C" TextBoxMessagePrefix* func_ov008_020cdc30(
	int boxID, int dialogBox, int textID)
{
	int activeBoxID = WM::dialogMsgID;
	data_ov008_020ee3a4 = true;
	if (activeBoxID == boxID) {
		return 0;
	}

	WM::dialogMsgID = boxID;
	if (dialogBox != 0) {
		data_ov008_020ee58c.setDialogBox();
	} else {
		data_ov008_020ee58c.setStandardBox();
	}

	int arguments = boxID;
	return data_ov008_020ee58c.loadText_2(textID, &arguments);
}

extern "C" u8 func_ov008_020cda24(u32 world, u32 path, u8 mask)
{
	return mask & WM::worlds[world].paths[path].flag;
}

extern "C" u16 func_ov008_020cda4c(u32 world, u32 node, u16 mask)
{
	return mask & WM::worlds[world].nodes[node].flag;
}

extern "C" u16 func_ov008_020cda7c(u32 world)
{
	return WM::worlds[world].nodeCount;
}

extern "C" WM::NodeLink* func_ov008_020cda94(u32 world, u32 node)
{
	return WM::worlds[world].nodes[node].links;
}

extern "C" bool func_ov008_020cdab8(u32 world)
{
	WM::Node* node = WM::worlds[world].nodes;
	u8 nodeCount = WM::worlds[world].nodeCount;
	u8 nodeID = 0;

	if (nodeCount != 0) {
		do {
			if ((node->flag & WM::NF_Final) != 0) {
				u8 nodeState =
					save.game.nodeStates[world][nodeID] &
					WM::NS_Completed;
				if (nodeState != 0) {
					return true;
				}
			}
			nodeID++;
			node++;
		} while (nodeID < nodeCount);
	}

	return false;
}

extern "C" void func_ov008_020cdb44(u32 sceneID, u32 settings)
{
	func_02011e3c(0x1e);
	func_020131fc(sceneID, settings);
}

extern "C" u8 func_ov008_020cdcac(u32 index)
{
	u8* values = &data_ov008_020e5cc8[index * 2];
	return values[data_ov008_020ee380];
}

extern "C" u32 func_ov008_020cdcf8()
{
	u32 completed = 0;
	u8 pathState;
	WM::Path* path;
	u32 total = 0;
	u32 signCompleted = 0;
	u32 signTotal = 0;
	u8 pathCount;
	u8 world = 0;
	u8 pathID;

	do {
		pathID = 0;
		pathCount = WM::worlds[world].pathCount;
		path = WM::worlds[world].paths;

		if (pathCount != 0) {
			do {
				u8 pathFlags = path->flag;
				if ((pathFlags & (WM::PF_Bit6 | WM::PF_Bit7)) ==
					0) {
					pathState =
						save.game.pathStates[world][pathID] &
						WM::PS_Unlocked;
					total++;
					if (pathState != 0) {
						completed++;
					}
					if ((pathFlags & WM::PF_Sign) != 0) {
						if (pathState != 0) {
							signCompleted++;
						}
						signTotal++;
					}
				}

				pathID++;
				path++;
			} while (pathID < pathCount);
		}
		world++;
	} while (world < 8);

	if (completed == total) {
		save.game.completion |= WM_SAVE_COMPLETION_BIT_1;
	}
	if (signCompleted == signTotal) {
		save.game.completion |= WM_SAVE_COMPLETION_BIT_2;
	}
	return completed;
}

extern "C" u32 func_ov008_020cddd8()
{
	u32 completed = 0;
	WM::Node* node;
	u32 total = 0;
	u32 cannonCompleted = 0;
	u32 cannonTotal = 0;
	u8 nodeCount;
	u8 world = 0;

	do {
		nodeCount = WM::worlds[world].nodeCount;
		u8 nodeID = 0;
		node = WM::worlds[world].nodes;

		if (nodeCount != 0) {
			do {
				if ((node->flag & WM::NF_StarCoins) != 0) {
					u8 nodeState =
						save.game.nodeStates[world][nodeID] &
						WM::NS_Completed;
					total++;
					if (nodeState != 0) {
						completed++;
					}
				}

				if (node->type == WM::NT_Cannon) {
					u8 nodeState =
						save.game.nodeStates[world][nodeID] &
						WM::NS_Completed;
					cannonTotal++;
					if (nodeState != 0) {
						cannonCompleted++;
					}
				}

				nodeID++;
				node++;
			} while (nodeID < nodeCount);
		}
		world++;
	} while (world < 8);

	if (completed != total) {
		return completed;
	}

	u32 completion =
		save.game.completion | WM_SAVE_COMPLETION_BIT_0;
	save.game.completion = completion;
	if (cannonCompleted == cannonTotal) {
		completion |= WM_SAVE_COMPLETION_BIT_8;
		save.game.completion = completion;
	}
	return completed;
}

extern "C" u32 func_ov008_020cdec0()
{
	u32 spent = 0;
	WM::Path* path;
	u32 total = 0;
	u8 pathCount;
	u8 world = 0;

	do {
		pathCount = WM::worlds[world].pathCount;
		u8 pathID = 0;
		path = WM::worlds[world].paths;

		if (pathCount != 0) {
			do {
				if ((path->flag & WM::PF_Sign) != 0) {
					u8 pathState =
						save.game.pathStates[world][pathID] &
						WM::PS_Unlocked;
					if (pathState != 0) {
						spent += path->price;
					}
					total += path->price;
				}
				pathID++;
				path++;
			} while (pathID < pathCount);
		}

		world++;
	} while (world < 8);

	u32 completion = save.game.completion;
	if ((completion & WM_SAVE_COMPLETION_BIT_19) != 0) {
		spent += 20;
	}
	if ((completion & WM_SAVE_COMPLETION_BIT_20) != 0) {
		spent += 20;
	}
	if ((completion & WM_SAVE_COMPLETION_BIT_21) != 0) {
		spent += 20;
	}
	if ((completion & WM_SAVE_COMPLETION_BIT_22) != 0) {
		spent += 20;
	}

	if (spent == total + 80) {
		save.game.completion |= WM_SAVE_COMPLETION_BIT_4;
	}
	return spent;
}

extern "C" u32 func_ov008_020cdf9c()
{
	u32 collected = 0;
	WM::Node* node;
	u32 total = 0;
	u8 world = 0;

	do {
		u32 worldCollected;
		u32 worldTotal;
		u8 nodeCount;
		u8 nodeID;
		node = WM::worlds[world].nodes;
		worldTotal = 0;
		nodeCount = WM::worlds[world].nodeCount;
		worldCollected = worldTotal;
		nodeID = worldTotal;

		if (nodeCount != 0) {
			do {
				if ((node->flag & WM::NF_StarCoins) != 0) {
					s32 starCoin = 0;
					do {
						u8 starCoinMask = 1 << starCoin;
						u8 nodeState =
							starCoinMask &
							save.game.nodeStates[world][nodeID];
						if (nodeState != 0) {
							worldCollected++;
							collected++;
						}
						worldTotal++;
						total++;
						starCoin++;
					} while (starCoin < 3);
				}

				node++;
				nodeID++;
			} while (nodeID < nodeCount);
		}

		if (worldCollected == worldTotal) {
			data_ov008_020ee390 |= 1 << world;
		}
		world++;
	} while (world < 8);

	if (collected == total) {
		save.game.completion |= WM_SAVE_COMPLETION_BIT_3;
	}
	return collected;
}

extern "C" void func_ov008_020ce0a0()
{
	save.game.starCoinsCollected = func_ov008_020cdf9c();
	save.game.starCoinsSpent = func_ov008_020cdec0();
	func_ov008_020cddd8();
	func_ov008_020cdcf8();
}

extern "C" u32 func_ov008_020ce0d4(u32 index)
{
	return data_ov008_020e2d3c[index];
}

extern "C" Vec3_32 func_ov008_020ce0e4(u32 index)
{
	Vec3_32 result;
	result.x = data_ov008_020e2d58[index][0];
	result.y = data_ov008_020e2d5c[index][0];
	result.z = data_ov008_020e2d60[index][0];
	return result;
}

extern "C" u32 func_ov008_020ce12c(u32 index)
{
	return data_ov008_020e650c[index];
}

extern "C" u32 func_ov008_020ce13c(u32 index)
{
	return data_ov008_020e6bf8[index][0];
}

extern "C" u32 func_ov008_020ce154(u32 index)
{
	return data_ov008_020e6bf4[index][0];
}

extern "C" u32 func_ov008_020ce16c(u32 index)
{
	return data_ov008_020e6bf0[index][0];
}

extern "C" fx32 func_ov008_020ce184(u32 index)
{
	u32 result = data_ov008_020e6718[index][0];
	if (index != 7) {
		return result;
	}

	u8 nodeState = save.game.nodeStates[7][6] & WM::NS_Completed;
	if (nodeState != 0) {
		result = 0x420000;
	}
	return result;
}

extern "C" fx32 func_ov008_020ce1b4(u32 index)
{
	return data_ov008_020e6714[index][0];
}

extern "C" u32 func_ov008_020ce1c4(u32 row, u32 column)
{
	return data_ov008_020e77b0[row][column][0];
}

extern "C" u32 func_ov008_020ce1d8(u32 row, u32 column)
{
	return data_ov008_020e77ac[row][column][0];
}

extern "C" u32 func_ov008_020ce1ec(u32 row, u32 column)
{
	return data_ov008_020e77a8[row][column][0];
}

extern "C" u32 func_ov008_020ce200(u32 row, u32 column)
{
	return data_ov008_020e77a4[row][column][0];
}

extern "C" u32 func_ov008_020ce214(u32 row, u32 column)
{
	return data_ov008_020e8794[row][column];
}

extern "C" void func_ov008_020ce228() {}

extern "C" void func_ov008_020ce22c()
{
	u32 world = save.game.currentWorld;
	data_ov008_020ee3f0 = 4;
	data_ov008_020ee3d0 = 0;
	data_02088c3c[world] |= WM::WS_Completed;

	if (world != 7) {
		world = func_ov008_020ce298(world);
	}
	func_ov008_020cdb44(9, world | 0x3000);
}

extern "C" u32 func_ov008_020ce298(u32 nodeType)
{
	u8 powerup = Game::getPlayerPowerup(0);
	u32 result;

	switch (nodeType) {
	case 0:
		result = 1;
		break;
	case 1:
		if (powerup != WmPlayerModel::P_Shell) {
			result = 2;
		} else {
			result = 3;
		}
		break;
	case 2:
		result = 4;
		break;
	case 3:
		result = 4;
		break;
	case 4:
		if (powerup != WmPlayerModel::P_Shell) {
			result = 5;
		} else {
			result = 6;
		}
		break;
	case 5:
		result = 7;
		break;
	case 6:
		result = 7;
		break;
	case 7:
		result = 7;
		break;
	}

	return result;
}

extern "C" void func_ov008_020ce330(WorldmapScene* scene)
{
	if (data_ov008_020ee37c != 0) {
		data_ov008_020ee37c = 0;
		data_ov008_020ee3a4 = 0;
		scene->dialogState = 0;
		scene->dialogInitFlag = 1;
	}

	switch (scene->dialogState) {
	case 0:
		data_ov008_020ee3e0 += 0x200;
		if (data_ov008_020ee3e0 >= 0x1000) {
			data_ov008_020ee3e0 = 0x1000;
			scene->dialogState = 1;
		}
		return;

	case 1: {
		u16 repeated = Input::consoleKeysRepeated[0];
		if (((repeated & NDS_PAD_BUTTON_RIGHT) != 0
				&& data_ov008_020ee3a4 == 0)
			|| ((repeated & NDS_PAD_BUTTON_LEFT) != 0
				&& data_ov008_020ee3a4 == 1)) {
			func_02012398(0xE5, 0);
			data_ov008_020ee3a4 ^= 1;
		}

		u8 console = Input::localConsoleID;
		if ((Input::consoleKeys[console][0] & NDS_PAD_BUTTON_A) != 0) {
			func_02012398(0xE9, 0);
			if (data_ov008_020ee3a4 == 0) {
				data_ov008_020ee398 = 3;
				func_ov008_020cdc30(
					0xB, 0, data_ov008_020ee3f4);
				data_02088f30 = 0;
				scene->dialogState = 2;
				scene->dialogActionTimer = 0x78;
				App::startWritingSave();
			} else {
				func_02012398(0xE7, 0);
				scene->dialogState = 4;
			}
		}
	}

	case 2:
		scene->dialogActionTimer--;
		if (scene->dialogActionTimer != 0) {
			return;
		}

		if (func_02012d98(save.options.currentSlot, &save) != 0) {
			data_ov008_020ee398 = 4;
			func_ov008_020cdc30(
				0xC, 0, data_ov008_020ee3f4);
			data_02088f30 = 1;
			scene->dialogState = 3;
		} else {
			Scene::switchToCorruptedSave(0xF);
		}
		App::finishWritingSave();
		return;

	case 3: {
		u8 console = Input::localConsoleID;
		if ((Input::consoleKeys[console][0] & NDS_PAD_BUTTON_A) == 0) {
			return;
		}
		func_02012398(0xE9, 0);
		scene->dialogState = 4;
		return;
	}

	case 4:
		if ((data_ov008_020ee3e0 -= 0x200) > 0) {
			return;
		}
		data_ov008_020ee3e0 = 0;
		data_ov008_020ee3f0 = 1;
		data_ov008_020ee398 = 0;
		data_ov008_020ee3d0 = 1;
		WM::dialogMsgID = -1;
		scene->unk87C = 0;
		data_ov008_020ee374 = 0;
		func_ov008_020cdbd0();
		return;

	default:
		return;
	}
}

extern "C" void func_ov008_020ce5ec()
{
	u32 value = data_ov008_020ee3f4;
	data_ov008_020ee3f0 = 3;
	data_ov008_020ee398 = 2;
	data_ov008_020ee3e0 = 0;
	data_ov008_020ee378 = 1;
	data_ov008_020ee37c = 1;
	data_ov008_020ee3d0 = 0;
	func_ov008_020cdc30(7, 1, value);
	func_02012398(0xe6, 0);
}

extern "C" void func_ov008_020ce674(WorldmapScene* scene)
{
	if (data_ov008_020ee37c != 0) {
		data_ov008_020ee37c = 0;
		scene->unk87C = 0;
		data_ov008_020ee374 = 0;
		scene->dialogState = 0;
		scene->menuState = 0;
		func_ov008_020d0534();
	}

	switch (scene->menuState) {
	case 0:
		data_ov008_020ee3e0 += 0x200;
		if (data_ov008_020ee3e0 >= 0x1000) {
			data_ov008_020ee3e0 = 0x1000;
			scene->menuState = 1;
		}
		break;

	case 1:
		if (data_ov008_020ee374 == 0
			&& func_ov008_020d04fc(scene) != 0
			&& func_0201ec88(
				WM::wxNodes[save.game.currentWorldNode].areaID) != 0
			&& data_02085a10 != 0) {
			data_ov008_020ee398 = 4;
			func_ov008_020cdc30(
				0xF, 0, data_ov008_020ee3f4);
			data_ov008_020ee374 = 4;
		}
		break;

	case 2:
		func_02012398(0xEB, 0);
		scene->menuState = 3;

	case 3:
		if ((data_ov008_020ee3e0 -= 0x200) <= 0) {
			data_ov008_020ee3e0 = 0;
			data_ov008_020ee384 = 0;
			data_ov008_020ee3f0 = 1;
			data_ov008_020ee398 = 0;
			scene->unk87C = 0;
			data_ov008_020ee374 = 0;
			data_ov008_020ee3d0 = 1;
			NDS::Sound::pauseSequence();
		}
		break;
	}

	if (data_ov008_020ee3e0 != 0x1000) {
		return;
	}

	u8 previousMode = data_ov008_020ee374;
	switch (previousMode) {
	case 0: {
		u16 repeated = Input::consoleKeysRepeated[0];
		if ((repeated & NDS_PAD_BUTTON_DOWN) != 0
			&& scene->unk87C < scene->menuLastSelection) {
			func_02012398(0xE5, 0);
			scene->unk87C++;
		} else if ((repeated & NDS_PAD_BUTTON_UP) != 0
			&& scene->unk87C != 0) {
			func_02012398(0xE5, 0);
			scene->unk87C--;
		}

		u16 keys =
			Input::consoleKeys[Input::localConsoleID][0];
		if ((keys & NDS_PAD_BUTTON_START) != 0) {
			scene->menuExitRequested = 1;
			break;
		}

		if ((keys & NDS_PAD_BUTTON_A) != 0) {
			if (scene->unk87C == func_ov008_020cdcac(0)) {
				scene->menuExitRequested = 1;
				break;
			}

			func_02012398(0xE9, 0);
			if (scene->unk87C == func_ov008_020cdcac(1)) {
				data_ov008_020ee374 = 1;
				data_ov008_020ee384 = 1;
				scene->dialogState = 0;
				scene->dialogInitFlag = 1;
			} else if (
				scene->unk87C == func_ov008_020cdcac(2)) {
				data_ov008_020ee374 = 2;
				data_ov008_020ee384 = 1;
				OptionsMenu::menuOpen();
			} else if (
				scene->unk87C == func_ov008_020cdcac(3)) {
				data_ov008_020ee374 = 3;
				data_ov008_020ee384 = 1;
			}
		} else if ((keys & NDS_PAD_BUTTON_B) != 0) {
			scene->menuExitRequested = 1;
		}
		break;
	}

	case 1:
		switch (scene->dialogState) {
		case 0: {
			u16 repeated = Input::consoleKeysRepeated[0];
			if (((repeated & NDS_PAD_BUTTON_RIGHT) != 0
					&& data_ov008_020ee3a4 == 0)
				|| ((repeated & NDS_PAD_BUTTON_LEFT) != 0
					&& data_ov008_020ee3a4 == 1)) {
				func_02012398(0xE5, 0);
				data_ov008_020ee3a4 ^= 1;
			}

			u16 keys =
				Input::consoleKeys[Input::localConsoleID][0];
			if ((keys & NDS_PAD_BUTTON_A) != 0) {
				func_02012398(0xE9, 0);
				if (data_ov008_020ee3a4 != 0) {
					data_ov008_020ee374 = 0;
					break;
				}

				data_ov008_020ee398 = 3;
				func_ov008_020cdc30(
					0xB, 0, data_ov008_020ee3f4);
				data_02088f30 = 0;
				scene->dialogState = 1;
				scene->dialogActionTimer = 0x78;
				App::startWritingSave();
			} else if ((keys & NDS_PAD_BUTTON_B) != 0) {
				func_02012398(0xEA, 0);
				data_ov008_020ee374 = 0;
			}
			break;
		}

		case 1:
			scene->dialogActionTimer--;
			if (scene->dialogActionTimer != 0) {
				break;
			}

			if (func_02012d98(
					save.options.currentSlot, &save) != 0) {
				data_ov008_020ee398 = 4;
				func_ov008_020cdc30(
					0xC, 0, data_ov008_020ee3f4);
				data_02088f30 = 1;
				scene->dialogState = 2;
			} else {
				Scene::switchToCorruptedSave(0xF);
			}
			App::finishWritingSave();
			break;

		case 2: {
			u16 keys =
				Input::consoleKeys[Input::localConsoleID][0];
			if ((keys & NDS_PAD_BUTTON_A) != 0) {
				func_02012398(0xE9, 0);
				scene->menuState = 3;
			}
			break;
		}
		}
		break;

	case 3: {
		u16 repeated = Input::consoleKeysRepeated[0];
		if (((repeated & NDS_PAD_BUTTON_RIGHT) != 0
				&& data_ov008_020ee3a4 == 0)
			|| ((repeated & NDS_PAD_BUTTON_LEFT) != 0
				&& data_ov008_020ee3a4 == 1)) {
			func_02012398(0xE5, 0);
			data_ov008_020ee3a4 ^= 1;
		}

		u16 keys =
			Input::consoleKeys[Input::localConsoleID][0];
		if ((keys & NDS_PAD_BUTTON_A) != 0) {
			func_02012398(0xE9, 0);
			if (data_ov008_020ee3a4 == 0) {
				func_ov008_020cdb44(4, 0);
				return;
			}
			data_ov008_020ee374 = 0;
		} else if ((keys & NDS_PAD_BUTTON_B) != 0) {
			func_02012398(0xEA, 0);
			data_ov008_020ee374 = 0;
		}
		break;
	}

	case 2:
		scene->func_ov008_020d08dc();
		if (OptionsMenu::taskID == OptionsMenu::T_Closed) {
			data_ov008_020ee374 = 0;
		}
		break;

	case 4: {
		u16 keys =
			Input::consoleKeys[Input::localConsoleID][0];
		if ((keys & NDS_PAD_BUTTON_A) != 0) {
			func_02012398(0xE9, 0);
			data_ov008_020ee374 = 0;
			data_ov008_020ee398 = 1;
		}
		break;
	}
	}

	if (previousMode != data_ov008_020ee374) {
		func_ov008_020cdbd0();
	}
	if (scene->menuExitRequested != 0) {
		scene->menuExitRequested = 0;
		scene->menuState = 2;
	}
}

extern "C" void func_ov008_020ced20()
{
	data_ov008_020ee3f0 = 2;
	data_ov008_020ee398 = 1;
	data_ov008_020ee3e0 = 0;
	data_ov008_020ee384 = 1;
	data_ov008_020ee37c = 1;
	data_ov008_020ee3d0 = 0;
	NDS::Sound::pauseSequence();
	func_02012398(0xeb, 0);
	func_ov008_020cdbd0();
}

extern "C" void func_ov008_020ced90(WorldmapScene* scene)
{
	func_02021808();
	u32 currentWorld = save.game.currentWorld;
	if (data_ov008_020ee414 != 0 && WM::currentWorld != currentWorld) {
		func_ov008_020cdb44(9, WM::currentWorld | 0x800);
		data_ov008_020ee3d0 = 0;
	} else if (data_ov008_020ee38c != 0) {
		u32 currentNode = save.game.currentWorldNode;
		save.game.savedWorld = currentWorld;
		save.game.savedWorldNode = currentNode;
		data_ov008_020ee3d0 = 0;

		if (Game::getStageCheckpoint()) {
			data_02085a2c = data_02085a34;
		} else {
			data_02085a2c = 0;
			if ((data_02085acc.flags & (1 << 5)) == 0) {
				data_02085a34 = 0;
			}
		}

		data_02085a38 = 0;
		u32 group = 0;
		u32 stage = 0;
		u32 act = 0;
		if (currentNode != 0) {
			func_0201f468(
				WM::wxNodes[currentNode].areaID,
				&group,
				&stage,
				&act);
		} else {
			u8 nodeType = data_02088c4c[currentWorld][0];
			func_0201f468(
				data_ov008_020e61ac[nodeType],
				&group,
				&stage,
				&act);
		}

		if (Game::getStageCheckpoint()) {
			data_02085a1c = 1;
		} else if ((data_02085acc.flags & (1 << 5)) == 0) {
			Game::resetStageCheckpoint();
		}
		Game::saveBackupParams();

		data_02085a6c =
			WM::wxNodes[save.game.currentWorldNode].flag;
		u8 character = Game::character;
		u32 powerup = Game::getPlayerPowerup(0);
		Game::loadLevel(
			0xD,
			0,
			group,
			stage,
			act,
			0,
			1,
			character,
			1,
			powerup,
			0xFF,
			1,
			1,
			0xFF,
			1,
			0,
			~0);
	}

	scene->func_ov008_020d08dc();
}

extern "C" void func_ov008_020cefd4(WorldmapScene* scene)
{
	if (!GlobalFader.fadedIn()) {
		return;
	}

	if (data_ov008_020ee378 != 0) {
		data_ov008_020ee3f0 = 3;
	} else {
		data_ov008_020ee3f0 = 1;
		data_ov008_020ee3d0 = 1;
	}
	scene->unk87E = 1;
}

extern "C" u32 func_ov008_020cf034(WorldmapScene* scene)
{
	Input::updatePlayerInput();
	scene->particleHandler.updateParticles();
	(scene->*data_ov008_020ee4b4[data_ov008_020ee3f0])();

	if ((save.game.completion & WM_SAVE_COMPLETION_BIT_7) == 0) {
		s32 actualStarCoins = Save::getStarCoinAmount();
		if (scene->displayedStarCoins > actualStarCoins) {
			if (scene->starCoinTickTimer == 0) {
				scene->displayedStarCoins--;
				scene->starCoinTickTimer = 4;
			} else {
				scene->starCoinTickTimer--;
				func_02012398(0xED, 0);
			}
		}

		if (scene->displayedStarCoins < 100) {
			func_0200b580(
				data_ov053_0216e994,
				data_ov053_0216ea74,
				scene->displayedStarCoins,
				2,
				3);
		} else {
			func_0200b580(
				data_ov053_0216ea34,
				data_ov053_0216ea74,
				scene->displayedStarCoins,
				3,
				3);
		}
	}

	return 1;
}

extern "C" void func_ov008_020cf12c(WorldmapScene* scene, u32 state)
{
	func_ov008_020d12ac(&data_ov008_020ee49c);
	scene->Scene::postUpdate(state);
}

extern "C" u32 func_ov008_020cf15c(WorldmapScene* scene)
{
	u8 currentNode = save.game.currentWorldNode;
	u32 currentWorld = save.game.currentWorld;
	u32 playerID = data_02085a7c;

	Particle::Handler::renderParticles();

	u32 renderValue = 0;
	if (scene->unk87E != 0) {
		switch (data_ov008_020ee398) {
		case 1:
			if (data_ov008_020ee374 != 2) {
				u32 mode = 1;
				renderValue = scene->unk87C;
				if (data_ov008_020ee374 != 0) {
					mode = 2;
					renderValue = data_ov008_020ee3a4;
				}
				if (data_ov008_020ee3e0 == 0x1000) {
					func_ov008_020cdb70(mode, renderValue);
				}
				renderValue = 1;
			}
			break;

		case 2:
			if (data_ov008_020ee3e0 == 0x1000) {
				func_ov008_020cdb70(
					2, data_ov008_020ee3a4);
			}
			renderValue = 1;
			break;

		case 3:
			if (data_ov008_020ee3e0 == 0x1000) {
				func_ov008_020cdb70(
					renderValue, renderValue);
			}
			renderValue = 1;
			break;

		case 4:
			if (data_ov008_020ee3e0 == 0x1000) {
				func_ov008_020cdb70(3, renderValue);
			}
			renderValue = 1;
			break;
		}
	}

	if (renderValue != 0) {
		func_ov008_020d2264(
			WM::instance, data_ov008_020ee3e0);
	}

	Layout::drawCellMain(
		1, data_ov008_020e6d74[save.game.currentWorld],
		0, 0, 0, 0, 0, 0, 0, 0, 0);
	Layout::drawCellMain(
		2, data_ov008_020e6d70[data_02085a9c],
		0, 0, 0, 0, 0, 0, 0, 0, 0);
	Layout::drawCellMain(
		0, data_ov053_0216e9c4,
		0, 0, 0, 0, 0, 0, 0, 0, 0);

	u16 nodeFlag =
		WM::wxNodes[save.game.currentWorldNode].flag
		& WM::NF_StarCoins;
	if (nodeFlag != 0) {
		u8 coinMask = 1;
		u8 starCoins =
			Save::getLevelStarCoins(currentWorld, currentNode);
		u8 checkpointCoins = 0;
		if (Game::getStageCheckpoint()) {
			checkpointCoins =
				data_02085a34 & ~starCoins;
			starCoins |= checkpointCoins;
		}

		for (s32 coin = 0; coin < 3; coin++) {
			if ((starCoins & coinMask) != 0) {
				bool visible = true;
				if ((checkpointCoins & coinMask) != 0
					&& (FrameCounter & 8) != 0) {
					visible = false;
				}
				if (visible) {
					Layout::drawCellMain(
						data_ov008_020e5ec0[coin],
						data_ov053_0216e734,
						0, 0, 0, 0, 0, 0, 0, 0, 0);
				}
			} else {
				Layout::drawCellMain(
					data_ov008_020e5ec0[coin],
					data_ov053_0216e74c,
					0, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			coinMask <<= 1;
		}
	}

	if (data_ov008_020ee3a0 != 0) {
		u32 cell;
		const void* attrs;
		if ((save.game.completion
				& WM_SAVE_COMPLETION_BIT_7) != 0) {
			cell = 12;
			attrs = data_ov053_0216e9fc;
		} else if (scene->displayedStarCoins < 100) {
			cell = 6;
			attrs = data_ov053_0216e994;
		} else {
			cell = 6;
			attrs = data_ov053_0216ea34;
		}

		if (data_ov008_020ee3a0 == 2) {
			fx32 scale = data_ov008_020ee410;
			scene->unknown858.x = scale;
			scene->unknown858.y = scale;
		} else {
			scene->unknown858.x = 0x1000;
			scene->unknown858.y = 0x1000;
		}

		if (scene->unknown858.x != 0) {
			Layout::drawCellMain(
				cell, attrs,
				0, 0, 0, &scene->unknown858,
				0, 0, 0, 0, 0);
		}

		if (cell == 6) {
			s16 phaseDistance = static_cast<s16>(
				scene->starCoinIconPhase - 0xE434);
			if (phaseDistance < 0) {
				phaseDistance = -phaseDistance;
			}
			if (phaseDistance > 0xCCC
				|| data_ov008_020ee39c != 0) {
				scene->starCoinIconPhase += 0xCCC;
			} else {
				scene->starCoinIconPhase = 0xE434;
			}

			fx32 scale =
				_FixedMul(
					_FixedSin(scene->starCoinIconPhase),
					0x260)
				+ 0x1180;
			scene->unknown858.x = scale;
			scene->unknown858.y = scale;
			Layout::drawCellMain(
				10, data_ov053_0216e744,
				0, 0, 0, &scene->unknown858,
				0, 0, 0, 0, 0);
		}
	}

	const void* itemAttrs =
		data_ov008_020e64d4[
			Game::getPlayerInventoryPowerup(playerID)];
	if (itemAttrs != 0) {
		Layout::drawCellMain(
			7, itemAttrs,
			0, 0, 0, 0, 0, 0, 0, 0, 0);
	}
	Layout::drawCellMain(
		7, data_ov053_0216e974,
		0, 0, 0, 0, 0, 0, 0, 0, 0);

	if (data_02085a10 != 0) {
		u8 palette;
		if (func_0201ed0c(
				WM::wxNodes[
					save.game.currentWorldNode].areaID) != 0
			&& u8(data_02088c4c[currentWorld][currentNode]
				& WM::NS_Completed) != 0) {
			palette = 0;
		} else {
			palette = 8;
		}

		Layout::drawCellMain(
			11, data_ov053_0216e754,
			0, palette, 0, 0, 0, 0, 0, 0, 0);
	}

	scene->func_ov008_020d113c();
	return 1;
}

extern "C" void func_ov008_020cf790() {}

extern "C" bool func_ov008_020cf794()
{
	FS::Cache::clear();
	if (data_0203bd30 != SC_Worldmap) {
		func_02011d40();
	}
	System::resetSubBGVBlank();
	return true;
}

extern "C" u32 func_ov008_020cf7c8(WorldmapScene* scene)
{
	enum SceneSetting {
		SS_ClearSpecialNodeStates = 1 << 9,
		SS_ReturningToMap = 1 << 11,
		SS_RequestTransition = 1 << 12,
		SS_NewGame = 1 << 13,
		SS_KeepWorldFlag = 1 << 14,
	};

	u32 settings = scene->settings;
	u32 worldID = settings & 0xf;
	u32 unlockedFlags = 0;
	data_02085ac4 = worldID | 0x4000;
	save.game.currentWorld = worldID;
	data_02088c3c[worldID] |= WM::WS_Visited;
	WM::currentWorld = worldID;

	for (s32 index = 0; index < 9; index++) {
		const WmWorldUnlockRule& rule =
			data_ov008_020e6e38[index];
		u16 firstWorldState =
			save.game.worldStates[rule.firstWorld]
			& WM::WS_Visited;
		if (firstWorldState != 0) {
			u16 secondWorldState =
				save.game.worldStates[rule.secondWorld]
				& WM::WS_Visited;
			if (secondWorldState != 0
				&& func_ov008_020cdab8(
					rule.firstWorld)) {
				unlockedFlags |= rule.completionFlag;
			}
		}
	}
	save.game.completion |= unlockedFlags;

	Net::stopConnection();

	u16 worldFlags = WM::worlds[worldID].flag;
	u16 nodeCount = WM::worlds[worldID].nodeCount;
	u16 pathCount = WM::worlds[worldID].pathCount;
	data_02085a7c = 0;
	data_02085abc &= 0x7fffffff;
	WM::wxPaths = WM::worlds[worldID].paths;
	WM::wxNodes = WM::worlds[worldID].nodes;
	WM::wxPoints = WM::worlds[worldID].points;
	WM::wxSigns = WM::worlds[worldID].signs;
	WM::wxEntities = WM::worlds[worldID].entities;
	WM::wxToadHouses = WM::worlds[worldID].toadHouses;
	WM::wxAnims = WM::worlds[worldID].anims;
	WM::wxNodeCount = nodeCount;
	WM::wxPathCount = pathCount;
	WM::wxForts = WM::worlds[worldID].forts;
	WM::state = 0;
	data_ov008_020ee3d0 = 0;
	data_ov008_020ee414 = 0;
	data_ov008_020ee3ec = 0;
	data_ov008_020ee38c = 0;
	data_ov008_020ee37c = 0;
	WM::wxFlags = worldFlags;
	data_ov008_020ee3a8 = 0xff;
	data_ov008_020ee378 = 0;
	data_ov008_020ee3dc = 0x1000;
	data_ov008_020ee388 = 1;
	data_ov008_020ee3ac = 0;
	data_ov008_020ee390 = 0;
	scene->unk87E = 0;
	data_ov008_020ee39c = 0;
	data_ov008_020ee394 = 0;
	data_ov008_020ee3a0 = 1;
	scene->unknown858.x = 0x1000;
	scene->unknown858.y = 0x1000;
	scene->starCoinIconPhase = 0xe434;
	data_ov008_020e5a2c = -1;
	data_ov008_020ee3c4 =
		WM::wxPoints[save.game.currentWorldNode].x << 12;
	if (data_ov008_020ee3c4 < func_ov008_020ce1b4(worldID)) {
		data_ov008_020ee3c4 = func_ov008_020ce1b4(worldID);
	} else if (data_ov008_020ee3c4
		> func_ov008_020ce184(worldID)) {
		data_ov008_020ee3c4 = func_ov008_020ce184(worldID);
	}
	data_ov008_020ee48c.x = data_ov008_020ee3c4;
	data_ov008_020ee48c.y = 0;
	data_ov008_020ee48c.z = 0;

	u16 worldInitialized =
		save.game.worldStates[worldID] & WM::WS_Initialized;
	if (worldInitialized == 0) {
		save.game.worldStates[worldID] |= WM::WS_Initialized;
		u8 saveWorldID = worldID;
		for (s32 entity = 0; entity < 2; entity++) {
			save.game.mapEntities[saveWorldID][entity].node =
				WM::wxEntities[entity].node;
			save.game.mapEntities[saveWorldID][entity].type =
				WM::wxEntities[entity].type;
		}
	}

	if ((settings & SS_ReturningToMap) != 0) {
		if (WM::currentWorld == save.game.savedWorld) {
			save.game.currentWorldNode =
				save.game.savedWorldNode;
		} else {
			save.game.currentWorldNode = 0;
		}
	}
	if ((settings & SS_RequestTransition) != 0) {
		data_02085acc.flags |= 1 << 4;
	}
	if ((settings & SS_KeepWorldFlag) != 0
		&& (data_02085acc.flags & 1) == 0) {
		WM::wxFlags |= 0x80000000;
	}
	if ((settings & SS_NewGame) != 0) {
		save.game.currentWorldNode = 0;
		save.game.savedWorld = worldID;
		save.game.savedWorldNode = 0;
		switch (worldID) {
		case 1:
			func_ov008_020cdccc(0);
			break;
		case 2:
		case 3:
			func_ov008_020cdccc(1);
			break;
		case 4:
			func_ov008_020cdccc(3);
			break;
		case 5:
		case 6:
			func_ov008_020cdccc(4);
			break;
		case 7:
			func_ov008_020cdccc(6);
			break;
		}
	}

	if ((settings & SS_ClearSpecialNodeStates) != 0) {
		for (u32 mapWorld = 0; mapWorld < 8; mapWorld++) {
			for (u8 node = 0;
				node < static_cast<u8>(
					WM::worlds[mapWorld].nodeCount & 0xff);
				node++) {
				u8 nodeType =
					WM::worlds[mapWorld].nodes[node].type;
				if (nodeType >= WM::NT_ToadHouseRed
					&& nodeType <= WM::NT_ToadHouseYellow) {
					save.game.nodeStates[mapWorld][node] &=
						~0xc0;
				}
			}
		}
	}
	if ((settings & (1 << 8)) != 0) {
		WM::state |= WM::ST_CourseLeft;
	}

	u32 transitionFlags = data_02085acc.flags;
	if ((transitionFlags & (1 << 2)) != 0) {
		WM::state |= WM::ST_Bit8;
	}
	if ((transitionFlags & (1 << 3)) != 0) {
		Game::loadBackupParams();
		Save::loadPlayerData();
	}

	func_ov008_020ce0a0();
	scene->displayedStarCoins = Save::getStarCoinAmount();
	scene->starCoinTickTimer = 0;

	u32 displayPowerMask = 0xfffffdf1;
	REG_POWER_CNT =
		(REG_POWER_CNT & displayPowerMask) |
		static_cast<u16>(0x20e);
	NDS::Graphics::resetMainBackgroundBank();
	NDS::Graphics::resetMainObjectBank();
	NDS::Graphics::resetMainBackgroundPaletteBank();
	NDS::Graphics::resetMainObjectPaletteBank();
	NDS::Graphics::resetTextureBank();
	NDS::Graphics::resetTexturePaletteBank();
	NDS::Graphics::resetClearImageBank();
	NDS::Graphics::resetSubBackgroundBank();
	NDS::Graphics::resetSubObjectBank();
	NDS::Graphics::resetSubBackgroundPaletteBank();
	NDS::Graphics::resetSubObjectPaletteBank();
	NDS::Graphics::assignTextureBank(6);
	NDS::Graphics::assignMainBackgroundBank(8);
	NDS::Graphics::assignTexturePaletteBank(0x10);
	NDS::Graphics::assignMainObjectBank(1);
	NDS::Graphics::assignMainBackgroundPaletteBank(0x40);
	NDS::Graphics::assignMainObjectPaletteBank(0x20);
	NDS::Graphics::assignSubBackgroundBank(0x80);
	NDS::Graphics::assignSubObjectBank(0x100);
	data_02085b18 = 0;
	NDS::Graphics::setMainDisplayMode(1, 5, 1);
	REG_POWER_CNT |= 0x8000;
	REG_DISPCNT = (REG_DISPCNT & 0xffcfffef) | 0x200010;
	NDS::Graphics3D::initializeTextureArena(2, 1);
	NDS::Graphics3D::initializePaletteArena(0x10000, 1);
	REG_DISPCNT = (REG_DISPCNT & 0xffbfff9f) | 0x20;
	data_02085a88 = 0x11;

	NDS::Graphics::setMainBackgroundPriority(0, 1);
	NDS::Graphics::setMainBackgroundPriority(1, 2);
	NDS::Graphics::setMainBackgroundPriority(2, 3);
	NDS::Graphics::setMainBackgroundPriority(3, 0);
	NDS::Graphics::setMainObjectScreenBase(1);
	NDS::Graphics::setMainObjectCharacterBase(0);
	NDS::Graphics::configureMainTextBackground(1, 3, 1, 0x30, 0, 0);
	NDS::Graphics::configureMainTextBackground(2, 2, 0, 0x2c, 0, 0);
	NDS::Graphics::configureMainTextBackground(3, 2, 0, 0x34, 0, 0);
	NDS::Graphics::setMainBackgroundMosaicEnabled(0, false);
	NDS::Graphics::setMainBackgroundMosaicEnabled(1, false);
	NDS::Graphics::setMainBackgroundMosaicEnabled(2, false);
	NDS::Graphics::setMainBackgroundMosaicEnabled(3, false);
	NDS::Graphics::setMainBackgroundHorizontalOffset(1, 0);
	NDS::Graphics::setMainBackgroundHorizontalOffset(2, 0);
	NDS::Graphics::setMainBackgroundHorizontalOffset(3, 0);
	NDS::Memory::clearFast(
		0, NDS::Graphics::mainBackground1Map(), 0x800);

	NDS::Graphics::setSubDisplayMode(0);
	NDS::Graphics::configureSubTextBackground(0, 1, 0, 0xe, 4, 0);
	NDS::Graphics::configureSubTextBackground(1, 1, 0, 0xc, 4, 0);
	NDS::Graphics::configureSubTextBackground(2, 1, 0, 0xa, 4, 0);
	NDS::Graphics::configureSubTextBackground(3, 0, 0, 9, 4, 0);

	FS::loadFileLZ77(
		NSMB_FID_uiStudio_d_2d_UI_O_1P_course_select_b_d_ncg_bin,
		NDS::Graphics::subBackground0Tiles());
	u32 currentWorld = save.game.currentWorld;
	FS::loadFileLZ77(
		WmPathMap::getMaskNscFile(currentWorld),
		NDS::Graphics::subBackground0Map());
	FS::loadFileLZ77(
		WmPathMap::getNscFile(currentWorld),
		reinterpret_cast<void *>(
			NDS::Graphics::subBackground1Map()));
	FS::loadFileLZ77(
		reinterpret_cast<u32>(data_ov008_020e2d44),
		reinterpret_cast<void *>(
			NDS::Graphics::subBackground2Map()));
	u32 bottomScreenTheme = save.game.bottomScreenTheme;
	FS::loadFileLZ77(
		data_ov008_020e2d8c[bottomScreenTheme],
		reinterpret_cast<void *>(
			NDS::Graphics::subBackground3Map()));
	NDS::Memory::fill8(
		static_cast<u8 *>(NDS::Graphics::subBackground0Map()) + 0x800,
		0, 0x800);
	NDS::Memory::fill8(
		reinterpret_cast<void *>(
			NDS::Graphics::subBackground1Map() + 0x800),
		0, 0x800);
	NDS::Memory::fill8(
		reinterpret_cast<void *>(
			NDS::Graphics::subBackground2Map() + 0x800),
		0, 0x800);
	FS::loadFileLZ77(
		NSMB_FID_uiStudio_d_2d_UI_O_1P_course_select_b_d_ncl_bin,
		reinterpret_cast<void *>(0x05000400));

	NDS::Graphics::setSubVisiblePlanes(
		NDS_VISIBLE_PLANE_BACKGROUND0 |
		NDS_VISIBLE_PLANE_BACKGROUND1 |
		NDS_VISIBLE_PLANE_BACKGROUND2 |
		NDS_VISIBLE_PLANE_BACKGROUND3 |
		NDS_VISIBLE_PLANE_OBJECTS);
	NDS::Graphics::setSubBackgroundPriority(0, 0);
	NDS::Graphics::setSubBackgroundPriority(1, 1);
	NDS::Graphics::setSubBackgroundPriority(2, 2);
	NDS::Graphics::setSubBackgroundPriority(3, 3);
	NDS::Graphics::setSubBackgroundHorizontalOffset(0, 0x40000);
	NDS::Graphics::setSubBackgroundHorizontalOffset(1, 0x40000);
	NDS::Graphics::setSubBackgroundHorizontalOffset(2, 0x40000);
	NDS::Graphics::setSubBackgroundHorizontalOffset(3, 0);
	System::setupSubBGVBlank();
	NDS::Graphics::setSubBackgroundMosaicEnabled(0, false);
	NDS::Graphics::setSubBackgroundMosaicEnabled(1, false);
	NDS::Graphics::setSubBackgroundMosaicEnabled(2, false);
	NDS::Graphics::setSubBackgroundMosaicEnabled(3, false);
	func_ov000_020bd594();
	func_ov000_020bd240();

	OptionsMenu::taskID = 0;
	OptionsMenu::restOffset = 0;
	u32 displayFlags =
		const_cast<BNCD *>(Layout::bncd[1])->getDisplayFlags();
	REG_DISPCNT_SUB =
		(REG_DISPCNT_SUB & 0xffcfffef) | displayFlags;
	scene->uiCells = Layout::bncl[1]->cells;

	if ((WM::wxFlags & 2) != 0) {
		NDS::Graphics::setClearImageOffset(0x1f7fff);
		NDS::Graphics::setFogTable(data_ov008_020e2d8c);
		NDS::Graphics::configureFog(true, 0, 3, 0x1800);
	}

	FS::Cache::activeFileCache = 0;
	WmPlayerModel::loadResources();
	WmEntityModel::loadResources();
	func_ov008_020d20ac();
	func_ov008_020db28c();
	Layout::bncl[0] = static_cast<const BNCL *>(
		FS::Cache::loadFile(
			NSMB_FID_uiStudio_UI_O_1P_course_select_u_bncl,
			false));
	func_0200b87c();
	data_02087700 = 0x80;
	func_0200b83c(0);
	func_0200b83c(1);
	FS::loadOBJPalette(
		NSMB_FID_uiStudio_UI_O_1P_course_select_o_ud_ncl_bin,
		0, false);

	u8 paletteBytes[8];
	paletteBytes[0] = 0xff;
	u8* paletteDestination =
		reinterpret_cast<u8 *>(0x06400000);
	for (s32 index = 0; index < 0x80; index++) {
		NDS::Memory::copy8(
			paletteBytes, paletteDestination, 1);
		paletteDestination++;
	}

	u32 scriptFile = Font::getScriptFileID(0);
	data_ov008_020ee3f4 =
		reinterpret_cast<u32>(
			FS::Cache::loadFile(scriptFile, false));
	data_ov008_020ee380 = 0;
	if ((save.game.completion & WM_SAVE_COMPLETION_BIT_5) != 0) {
		data_ov008_020ee380 = 1;
	}
	scene->menuLastSelection =
		data_ov008_020e5a30[data_ov008_020ee380];
	WM::dialogMsgID = -1;
	data_ov008_020ee58c.setDefaultBox();
	data_ov008_020ee58c.loadSingleplayerDialogOptions();
	data_ov008_020ee58c.setStandardBox();
	data_02085c24 = 1;
	data_02085c34 = 0x3e;
	data_02085c30 = 0x10;
	data_02085c2c = 0x10;
	func_ov000_020a3b24(0);
	scene->particleHandler.init(1);

	data_ov000_020caa38 =
		reinterpret_cast<WorldCameraTransformState *>(
			Object::spawnObject(WM_Camera, scene, 0, 0));
	WM::instance =
		static_cast<WmController *>(
			Actor::spawnActor(
				WM_Controller, worldID, 0, 0, 0, 0));
	Object::spawnObject(WM_Minimap, scene, 0, 0);

	if ((settings & SS_ReturningToMap) == 0) {
		NDS::Sound::setLuigiSounds(Game::character);
		NDS::Sound::loadMenuSoundList(data_ov008_020e650c);
	} else {
		func_ov008_020d1478(&data_ov008_020ee49c, 2);
	}

	if (WM::wxNodes != 0) {
		func_0201ec88(
			WM::wxNodes[save.game.currentWorldNode].areaID);
	}
	data_ov008_020ee3f0 = 0;
	func_ov008_020ce0a0();
	return 1;
}

extern "C" u32 func_ov008_020d04fc(WorldmapScene*)
{
	if (!(save.game.completion & WM_SAVE_COMPLETION_BIT_5)) {
		return 0;
	}

	return func_ov008_020d0548(&data_ov008_020ee3d4);
}

extern "C" void func_ov008_020d0614(u32* value)
{
	*value = 0;
}

extern "C" u32 func_ov008_020d0548(u32* value)
{
	if (*value < 8) {
		u32 result = data_ov008_020e2dfc[*value].check();
		if (result != 0) {
			(*value)++;
		} else if (Input::consoleKeys[Input::localConsoleID][0] != 0) {
			func_ov008_020d0614(value);
			return 0;
		}
	}

	if (*value >= 8) {
		if (data_02085a10 == 0) {
			data_02085a10 = 1;
			func_02012398(0x33, 0);
		} else {
			data_02085a10 = 0;
			func_02012398(0xee, 0);
		}

		func_ov008_020d0614(value);
		return 1;
	}

	return 0;
}

extern "C" void func_ov008_020d0534()
{
	func_ov008_020d0614(&data_ov008_020ee3d4);
}

extern "C" u32 func_ov008_020d0620()
{
	return Input::consoleKeys[Input::localConsoleID][0] & NDS_PAD_BUTTON_L;
}

extern "C" u32 func_ov008_020d0644()
{
	return Input::consoleKeys[Input::localConsoleID][0] & NDS_PAD_BUTTON_R;
}

extern "C" u32 func_ov008_020d0668()
{
	return Input::consoleKeys[Input::localConsoleID][0] & NDS_PAD_BUTTON_X;
}

extern "C" u32 func_ov008_020d068c()
{
	return Input::consoleKeys[Input::localConsoleID][0] & NDS_PAD_BUTTON_Y;
}

void WorldmapScene::func_ov008_020d06b0()
{
	OptionsMenu::menuUnloadWorldmap();
}

void WorldmapScene::func_ov008_020d06bc()
{
	OptionsMenu::menuMain();
}

void WorldmapScene::func_ov008_020d06c8()
{
	if (OptionsMenu::taskID == OptionsMenu::T_SlideIn) {
		OptionsMenu::menuSlideIn();
		return;
	}

	OptionsMenu::menuClose();
}

void WorldmapScene::func_ov008_020d06fc()
{
	OptionsMenu::menuLoad();
}

void WorldmapScene::func_ov008_020d0708()
{
	switch (OptionsMenu::taskID) {
	case OptionsMenu::T_Open:
		OptionsMenu::menuInit();
		return;
	case OptionsMenu::T_ClosePress:
		OptionsMenu::menuClosePress();
		return;
	case OptionsMenu::T_CloseRelease:
		OptionsMenu::menuCloseRelease();
		return;
	case OptionsMenu::T_CloseWait:
		OptionsMenu::menuCloseWait();
		return;
	case OptionsMenu::T_SlideOut:
		OptionsMenu::menuSlideOut();
	}
}

void WorldmapScene::func_ov008_020d0788()
{
	if (data_ov008_020e5a2c != -1) {
		return;
	}
	if (data_ov008_020ee414 == 0) {
		return;
	}

	BOOL connected =
		data_0208b4f0 != 0 && data_0208b4ec != 0;
	if (!connected) {
		return;
	}

	s32 selection =
		Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
	switch (selection) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		u16 worldState =
			data_02088c3c[selection] & WM::WS_Visited;
		if (worldState == 0) {
			return;
		}

		u32 currentWorld = save.game.currentWorld;
		data_ov008_020e5a2c = selection & 7;
		if (selection != currentWorld) {
			func_ov008_020d1478(&data_ov008_020ee49c, 0);
			func_02012398(0xe9, 0);
			return;
		}

		func_ov008_020d1478(&data_ov008_020ee49c, 1);
		func_02012398(0xe9, 0);
	}
}

void WorldmapScene::func_ov008_020d08dc()
{
	typedef void (WorldmapScene::*Task)();
	static Task tasks[] = {
		&WorldmapScene::func_ov008_020d0788,
		&WorldmapScene::func_ov008_020d0708,
		&WorldmapScene::func_ov008_020d06fc,
		&WorldmapScene::func_ov008_020d06c8,
		&WorldmapScene::func_ov008_020d06bc,
		&WorldmapScene::func_ov008_020d0708,
		&WorldmapScene::func_ov008_020d0708,
		&WorldmapScene::func_ov008_020d0708,
		&WorldmapScene::func_ov008_020d0708,
		&WorldmapScene::func_ov008_020d06b0,
		&WorldmapScene::func_ov008_020d06c8,
	};

	(this->*tasks[OptionsMenu::taskID])();
}

void WorldmapScene::func_ov008_020d0a4c()
{
	OptionsMenu::menuDraw();
}

void WorldmapScene::func_ov008_020d0a58()
{
	u8 worldFlag = data_ov008_020ee390
		& (1 << save.game.currentWorld);
	if (worldFlag != 0) {
		Layout::drawCellSubEx(
			&uiCells[24], &uiCells[24], true, 0,
			0, -OptionsMenu::restOffset, 0, 0, 0x10);
	}

	Layout::drawCellSubEx(
		uiCells + 19,
		uiCells + 10 + save.game.currentWorld, true, 0,
		0, -OptionsMenu::restOffset, 0, 0, 0x10);
	Layout::drawCellSubEx(
		&uiCells[18], 0, true, 0,
		0, -OptionsMenu::restOffset, 0, 0, 0x10);

	for (s32 digit = 0; digit < 2; digit++) {
		s32 lives = Game::getPlayerLives(0);
		if (digit != 0) {
			lives /= 10;
		} else {
			lives %= 10;
		}

		if (digit == 0 || lives != 0) {
			Layout::drawCellSubEx(
				&uiCells[data_ov008_020e2d34[digit]],
				&uiCells[lives], true, 0,
				0, -OptionsMenu::restOffset, 0, 0, 0x10);
		}
	}

	Layout::drawCellSubEx(
		uiCells + 20 + Game::character, 0, true, 0,
		0, -OptionsMenu::restOffset, 0, 0, 0x10);

	for (s32 index = 0, cellOffset = 0;
		index < 8;
		index++, cellOffset += sizeof(BNCL_Cell)) {
		Layout::drawCellSubEx(
			reinterpret_cast<const BNCL_Cell*>(
				reinterpret_cast<const u8*>(uiCells + 45)
				+ cellOffset),
			0, true, 0,
			0, -OptionsMenu::restOffset, 0, 0, 0x10);
	}

	u32 worldMarkerFrame =
		static_cast<s32>(uiCellFrame++) / 3;
	s32 worldMarkerY =
		data_ov008_020e2d70[worldMarkerFrame % 7];
	Layout::drawCellSubEx(
		uiCells + 56 + save.game.currentWorld, 0, true, 0,
		0, -OptionsMenu::restOffset, worldMarkerY, 0, 0x10);

	for (s32 world = 0, cellOffset = 0;
		world < 8;
		world++, cellOffset += sizeof(BNCL_Cell)) {
		Vec2_32* scale;
		if (world != data_ov008_020e5a2c) {
			static Vec2_32 normalScale(0x1000);
			scale = &normalScale;
		} else {
			static Vec2_32 selectedScale;
			selectedScale.x = data_ov008_020ee49c.value00;
			selectedScale.y = data_ov008_020ee49c.value00;
			scale = &selectedScale;
		}
		Vec2_32 drawScale(*scale);

		s32 worldX = 0;
		if (world == data_ov008_020e5a2c) {
			worldX =
				(0x1000 - data_ov008_020ee49c.value00)
				<< 4;
			worldX >>= 12;
		}

		u8 palette = 0;
		u16 worldState =
			save.game.worldStates[world] & WM::WS_Visited;
		if (worldState != 0) {
			switch (world) {
			case 0:
			case 7:
				palette = 0xfd;
				break;
			case 1:
			case 5:
				palette = 0xfc;
				break;
			case 2:
			case 3:
				palette = 0xfe;
				break;
			case 4:
			case 6:
				palette = 0xff;
				break;
			}
		}

		Layout::drawCellSubEx(
			reinterpret_cast<const BNCL_Cell*>(
				reinterpret_cast<const u8*>(uiCells + 37)
				+ cellOffset),
			0, true, &drawScale,
			0, worldX - OptionsMenu::restOffset,
			0, palette, 0x10);
	}

	for (s32 marker = 0, cellOffset = 0;
		marker < 9;
		marker++, cellOffset += sizeof(BNCL_Cell)) {
		u8 palette = 0;
		if ((save.game.completion
			& data_ov008_020e2dac[marker]) != 0) {
			palette = 0xff;
			}
			Layout::drawCellSubEx(
				reinterpret_cast<const BNCL_Cell*>(
					reinterpret_cast<const u8*>(uiCells + 28)
					+ cellOffset),
			0, true, 0,
			0, -OptionsMenu::restOffset, 0, palette, 0x10);
	}

	bool hasOtherWorld = false;
	for (s32 world = 1; world <= 7; world++) {
		u16 worldState =
			save.game.worldStates[world] & WM::WS_Visited;
		if (worldState != 0) {
			hasOtherWorld = true;
			break;
		}
	}
	if (!hasOtherWorld) {
		return;
	}

	Layout::drawCellSubEx(
		&uiCells[53], 0, true, 0,
		0, -OptionsMenu::restOffset, 0, 0, 0x10);

	u32 animationFrame =
		static_cast<u32>(uiCellFrame) % 126;
	s32 animationY = 0;
	if (animationFrame < 66) {
		animationY =
			data_ov008_020e2dd0[animationFrame % 22];
	}
	Layout::drawCellSubEx(
		&uiCells[54], 0, true, 0,
		0, -OptionsMenu::restOffset, animationY, 0, 0x10);
	Layout::drawCellSubEx(
		&uiCells[55], 0, true, 0,
		0, -OptionsMenu::restOffset, animationY, 0, 0x10);
}

void WorldmapScene::func_ov008_020d113c()
{
	typedef void (WorldmapScene::*Task)();
	static Task tasks[] = {
		&WorldmapScene::func_ov008_020d0a58,
		&WorldmapScene::func_ov008_020d0a58,
		&WorldmapScene::func_ov008_020d0a4c,
		&WorldmapScene::func_ov008_020d0a4c,
		&WorldmapScene::func_ov008_020d0a4c,
		&WorldmapScene::func_ov008_020d0a4c,
		&WorldmapScene::func_ov008_020d0a4c,
		&WorldmapScene::func_ov008_020d0a4c,
		&WorldmapScene::func_ov008_020d0a4c,
		&WorldmapScene::func_ov008_020d0a58,
		&WorldmapScene::func_ov008_020d0a58,
	};

	(this->*tasks[OptionsMenu::taskID])();
}

extern "C" void func_ov008_020d12ac(Unk020d1478Config* config)
{
	s8 selection = data_ov008_020e5a2c;
	if (selection == -1) {
		return;
	}

	u16 angle = static_cast<s16>(config->value08);
	config->value00 =
		(_FixedMul(config->value04, _FixedSin(angle)) & ~0xff)
		+ 0x1000;
	config->value08 += 0x1000;

	switch (config->mode) {
	case 2:
		if (config->value0C > 0) {
			config->value0C--;
			config->padding10 = 0;
		}
		if (config->value0C == 0) {
			config->value04 =
				_FixedMul(config->value04, 0xf5c);
			config->padding10++;
		}

		if (data_ov008_020ee414 != 0
			&& config->padding10 > 0x14
			&& config->value0C == 0
			&& ((0x1000 - config->value00) << 4) == 0) {
			config->value00 = 0x1000;
			config->value08 = 0;
			data_ov008_020e5a2c = -1;
		}
		return;
	case 0:
		if (config->value0C >= 0) {
			config->value0C--;
		}
		if (config->value0C == 0) {
			WM::currentWorld = selection;
			func_02012398(0x30, 0);
			data_ov008_020ee414 = 0;
		}
		return;
	default:
		if (static_cast<u32>(config->value08) >= 0x10000) {
			data_ov008_020e5a2c = -1;
		}
	}
}

extern "C" void func_ov008_020d1478(Unk020d1478Config* config, u32 mode)
{
	config->value04 = 0x333;
	config->value00 = 0x1000;
	config->value08 = 0;
	config->value0C = 0x1e;
	config->mode = mode;

	switch (config->mode) {
	case 2:
		config->value0C = 0x32;
		data_ov008_020e5a2c = save.game.currentWorld;
		return;
	case 0:
		data_ov008_020ee414 = 0;
		return;
	default:
		config->value04 = 0x333;
		config->value08 = 0x8000;
		return;
	}
}

WorldmapScene* WorldmapScene::create()
{
	return new WorldmapScene();
}

extern "C" void func_ov008_020d153c() {}

extern "C" void func_ov008_020d1540() {}
