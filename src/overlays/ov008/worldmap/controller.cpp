#include "../../../worldmap/controller.hpp"
#include "../../../worldmap/camera.hpp"
#include "../../../worldmap/character.hpp"
#include <nsmb/arm9/symbols.hpp>
#include <nds/text.hpp>
#include <nsmb/core/filesystem.hpp>
#include <nsmb/file_ids.hpp>
#include <nsmb/game/particle.hpp>
#include <nsmb/game/player.hpp>
#include <nsmb/overlays/ov000/symbols.hpp>
#include <nsmb/overlays/ov008/symbols.hpp>
#include <nsmb/overlays/ov011/symbols.hpp>
#include <nsmb/overlays/ov053/symbols.hpp>

using namespace WM;

struct __Work {
	NodeLink* link;
	u32 world;
	u32 n;
	u32 a;
};

struct WmModelCallbackContextPrefix {
	u32 unknown0;
	Ns3dDrawable* drawable;
	u32 commandFlags;
	u8 reserved0C_AC[0xA0];
	u8 nodeID;
	u8 materialID;
};
NTR_SIZE_GUARD(WmModelCallbackContextPrefix, 0xB0);
NTR_OFFSET_GUARD(WmModelCallbackContextPrefix, drawable, 0x4);
NTR_OFFSET_GUARD(WmModelCallbackContextPrefix, commandFlags, 0x8);
NTR_OFFSET_GUARD(WmModelCallbackContextPrefix, nodeID, 0xAC);
NTR_OFFSET_GUARD(WmModelCallbackContextPrefix, materialID, 0xAD);

enum {
	Data02085acc_Bit4 = 1 << 4,
	Data02085acc_Bit5 = 1 << 5,
	ToadHouseState_Bit0 = 1 << 0,
	ToadHouseState_Bit1 = 1 << 1,
	ToadHouseState_Bit2 = 1 << 2,
	ToadHouseState_Bit3 = 1 << 3,
	ToadHouseState_Bit4 = 1 << 4,
	ToadHouseState_Bit5 = 1 << 5,
	BridgeFlag_Bit0 = 1 << 0,
	BridgeFlag_Bit1 = 1 << 1,
	BridgeFlag_Bit2 = 1 << 2,
	BridgeFlag_Bit3 = 1 << 3,
	TowerCastleModelFlag_Bit0 = 1 << 0,
	TowerCastleModelFlag_Bit1 = 1 << 1,
	TowerCastleModelFlag_Bit2 = 1 << 2,
	TowerCastleModelFlag_Bit3 = 1 << 3,
	TowerCastleModelFlag_Bit4 = 1 << 4,
	TowerCastleModelFlag_Bit5 = 1 << 5,
	TowerCastleModelFlag_Bit6 = 1 << 6,
};

static inline PlayerModel* getPlayerModel(WmPlayerModel* playerModel) {
	return &playerModel->model;
}

extern "C" void func_ov008_020d24b0(void* callbackContext) {
	WmModelCallbackContextPrefix* context =
		scast<WmModelCallbackContextPrefix*>(callbackContext);
	func_ov008_020d23b4(scast<WmController*>(context->drawable->userData), callbackContext);
}

extern "C" void func_ov008_020d23b4(
	WmController* controller, void* callbackContext) {
	WmModelCallbackContextPrefix* context =
		scast<WmModelCallbackContextPrefix*>(callbackContext);
	u32 nodeID = (context->commandFlags & 4) != 0
		? context->nodeID
		: u32(-1);
	u32 materialID = (context->commandFlags & 8) != 0
		? context->materialID
		: u32(-1);
	for (int path = 0; path < WM::wxPathCount; path++) {
		if (nodeID == controller->pathMdlNodes[path]) {
			NDS::Graphics3D::setModelAlpha(
				controller->sourceModel->model,
				materialID,
				controller->pathMdlAlpha[path]);
			u32 alpha = controller->pathMdlAlpha[path];
			if (alpha == 30) {
				Ns_3dModelSetAllPolygonID(
					controller->sourceModel->model,
					controller->pathPolyID1);
				return;
			}
			if (alpha == 8) {
				Ns_3dModelSetAllPolygonID(
					controller->sourceModel->model,
					controller->pathPolyID2);
				return;
			}
			Ns_3dModelSetAllPolygonID(
				controller->sourceModel->model,
				controller->pathPolyID3);
			return;
		}
	}
	Ns_3dModelSetAllPolygonID(
		controller->sourceModel->model, controller->otherPolyID);
}

extern "C" void func_ov008_020d2024(
	WmController* controller, u32 index) {
	Vec3_32 position = controller->unk1EE4[index];
	if (index == 3) {
		position.z -= 0x2D000;
		s32 radius = 0x2F000;
		func_02022a50(
			data_ov008_020e952c[index], &position, &radius);
	} else {
		func_02022b64(data_ov008_020e952c[index], &position);
	}
}

extern "C" u32 func_ov008_020d20ac() {
	u32 world = save.game.currentWorld;
	for (int index = 0; index < 16; index++) {
		if (func_ov008_020ce214(world, index) != 0) {
			FS::Cache::loadFile(
				func_ov008_020ce214(world, index), false);
		}
	}
	FS::Cache::loadFile(NSMB_FID_map_player_cursor_nsbmd, false);
	FS::Cache::loadFile(NSMB_FID_map_map_point_nsbmd, false);
	FS::Cache::loadFile(NSMB_FID_map_map_point_nsbtp, false);
	FS::Cache::loadFile(NSMB_FID_map_map_dragon_nsbmd, false);
	FS::Cache::loadFile(NSMB_FID_map_map_dragon_nsbca, false);
	FS::Cache::loadFile(NSMB_FID_map_map_dragon_nsbtp, false);
	FS::Cache::loadFile(NSMB_FID_map_window_nsbmd, false);
	if (world == 0) {
		FS::Cache::loadFile(NSMB_FID_map_w1_kinoko_a_nsbmd, false);
	} else if (world == 7) {
		FS::Cache::loadFile(NSMB_FID_map_w8_bridge_nsbmd, false);
		FS::Cache::loadFile(NSMB_FID_map_w8_bridge_nsbca, false);
		FS::Cache::loadFile(NSMB_FID_map_w8_koppaC_nsbmd, false);
		FS::Cache::loadFile(NSMB_FID_map_w8_koppaC_nsbca, false);
	}
	return true;
}

extern "C" void func_ov008_020d21d0(
	WmController*, u32 node) {
	u32 nodeType = WM::wxNodes[node].type;
	u32 world = save.game.currentWorld;
	if (node == 0
		&& u16(save.game.worldStates[world] & WM::WS_ArrowToadHouse) != 0) {
		nodeType = WM::NT_ToadHouseRed;
		u8 toadHouseType = save.game.nodeStates[world][0];
		if (toadHouseType != 0) {
			switch (toadHouseType) {
			case 1:
				nodeType = WM::NT_ToadHouseGreen;
				break;
			case 2:
				nodeType = WM::NT_ToadHouseYellow;
				break;
			}
		}
	}
	data_02085a9c = nodeType;
}

extern "C" void func_ov008_020d2264(
	WmController* controller, fx32 scaleFactor) {
	WorldCameraTransformState* camera = data_ov000_020caa38;
	Vec3_32 offset(0, 0, -0x10000);
	Vec3_32 scale;
	scale.x =
		((i64)controller->unk2050.x * scaleFactor + 0x800) >> 12;
	scale.y =
		((i64)controller->unk2050.y * scaleFactor + 0x800) >> 12;
	scale.z = 0x1000;
	Game_modelMatrix = data_ov000_020caa54;
	NDS::Math::transformVector43(
		&offset, &Game_modelMatrix, &offset);
	Vec3_32::add4(offset, &camera->position, offset);
	MTX::setTranslation(
		Game_modelMatrix, offset.x, offset.y, offset.z);
	Vec3_16& rotation = camera->rotation;
	MTX::rotate(
		Game_modelMatrix,
		rotation.x,
		rotation.y,
		rotation.z);
	NDS::Graphics3D::setModelAlphaAll(
		controller->windowModel.model,
		controller->unk2050.z >> 4);
	controller->windowModel.render(Game_modelMatrix, &scale);
}

extern "C" u32 func_ov008_020d29a0(WmController* controller) {
	u32 console = Input::localConsoleID;
	if ((Input::consoleKeys[console][0] & NDS::Input::ButtonA) == 0) {
		return false;
	}

	u32 nodeType = WM::wxNodes[controller->currentNode].type;
	if (nodeType == WM::NT_Arrow) {
		if ((controller->toadHouseStates[controller->unk22F1]
			& ToadHouseState_Bit4) == 0) {
			return false;
		}
	} else {
		if (WM::wxNodes[save.game.currentWorldNode].areaID == 0xB9) {
			return false;
		}
		if (u8(save.game.nodeStates[save.game.currentWorld]
				[controller->currentNode] & WM::NS_Completed) != 0
			&& (save.game.completion & WM_SAVE_COMPLETION_BIT_0) == 0
			&& nodeType >= WM::NT_ToadHouseRed
			&& nodeType <= WM::NT_ToadHouseYellow) {
			return false;
		}
	}

	if ((nodeType >= WM::NT_ToadHouseRed
			&& nodeType <= WM::NT_ToadHouseYellow)
		|| nodeType == WM::NT_Arrow
		|| nodeType == WM::NT_ToadHousePurple) {
		data_02085acc.flags |= Data02085acc_Bit5;
	}

	controller->playerDirection = 2;
	func_ov008_020d32c4(controller, 5);

	if (nodeType == WM::NT_Tower) {
		controller->exitInteractionType = 1;
	} else if (nodeType == WM::NT_Castle) {
		controller->exitInteractionType = 2;
	} else if (nodeType == WM::NT_Tower2) {
		controller->exitInteractionType = 3;
	} else if (nodeType == WM::NT_FinalCastle) {
		controller->exitInteractionType = 4;
	} else {
		controller->playerDirection = 0;
		data_ov008_020ee3d0 = 0;
		func_ov008_020d32c4(controller, 6);
	}

	func_02012398(0x2C, 0);
	return true;
}

extern "C" u32 func_ov008_020d2e00(WmController* controller) {
	u32 world = save.game.currentWorld;
	u16 worldState = save.game.worldStates[world];
	bool startInteraction = false;

	if (u16(worldState & WM::WS_Bit1) == 0) {
		save.game.worldStates[world] |= WM::WS_Bit1;
		controller->exitInteractionType = 0;
		startInteraction = true;
	} else if ((WM::state & WM::ST_Bit8) != 0
		&& data_02085ac8 == 0) {
		u16 nodeFlags =
			WM::wxNodes[save.game.currentWorldNode].flag;
		if (u16(nodeFlags & WM::NF_Tower) != 0
			&& u16(worldState & WM::WS_Bit2) == 0) {
			save.game.worldStates[world] |=
				WM::WS_Bit2 | WM::WS_Bit8;
			controller->exitInteractionType = 1;
			startInteraction = true;
		} else if (u16(nodeFlags & WM::NF_Castle) != 0
			&& u16(worldState & WM::WS_Bit3) == 0) {
			save.game.worldStates[world] |=
				WM::WS_Bit3 | WM::WS_Bit9;
			controller->exitInteractionType = 2;
			startInteraction = true;
		} else if (u16(nodeFlags & WM::NF_Tower2) != 0
			&& u16(worldState & WM::WS_Bit4) == 0) {
			save.game.worldStates[world] |=
				WM::WS_Bit4 | WM::WS_Bit10;
			controller->exitInteractionType = 3;
			startInteraction = true;
		} else if (u16(nodeFlags & WM::NF_FinalCastle) != 0
			&& u16(worldState & WM::WS_Bit5) == 0) {
			save.game.worldStates[world] |=
				WM::WS_Bit5 | WM::WS_Bit11;
			controller->exitInteractionType = 4;
			startInteraction = true;
		}
	}

	if (startInteraction) {
		Actor* actor = Actor::spawnActor(
			0x140,
			controller->exitInteractionType,
			0,
			0,
			0,
			0);
		if (actor != 0) {
			if (controller->unk22EB == 0) {
				WM::state |= WM::ST_Bit0;
			}
			controller->unk22EB = 0;
			Actor::spawnActor(
				0x140,
				controller->exitInteractionType | 0x10000000,
				0,
				0,
				0,
				0);
			func_ov008_020d32c4(controller, 14);
			return true;
		}
	} else {
		if ((WM::state & WM::ST_Bit8) != 0
			&& data_02085ac8 == 0) {
			u16 nodeFlags =
				WM::wxNodes[save.game.currentWorldNode].flag;
			if (u16(nodeFlags & WM::NF_Tower) != 0
				&& u16(save.game.worldStates[world]
					& WM::WS_Bit8) == 0) {
				save.game.worldStates[world] |= WM::WS_Bit8;
				controller->unk22E3 = 2;
			} else if (u16(nodeFlags & WM::NF_Castle) != 0
				&& u16(save.game.worldStates[world]
					& WM::WS_Bit9) == 0) {
				save.game.worldStates[world] |= WM::WS_Bit9;
				controller->unk22E3 = 2;
			} else if (u16(nodeFlags & WM::NF_Tower2) != 0
				&& u16(save.game.worldStates[world]
					& WM::WS_Bit10) == 0) {
				save.game.worldStates[world] |= WM::WS_Bit10;
				controller->unk22E3 = 2;
			} else if (u16(nodeFlags & WM::NF_FinalCastle) != 0
				&& u16(save.game.worldStates[world]
					& WM::WS_Bit11) == 0) {
				save.game.worldStates[world] |= WM::WS_Bit11;
				controller->unk22E3 = 2;
			}
		}

		u16 nodeFlags =
			WM::wxNodes[save.game.currentWorldNode].flag;
		if (u16(nodeFlags & WM::NF_Final) != 0
			&& (WM::state & WM::ST_Bit8) != 0) {
			u32 value = func_ov008_020ce298(world);
			if ((WM::state & WM::ST_Bit9) != 0
				|| u16(save.game.worldStates[value]
					& WM::WS_Visited) == 0) {
				data_02085ac4 = value | 0x3000;
				WM::state |= WM::ST_Bit10;
				func_ov008_020d32c4(controller, 15);
				return true;
			}
		}
	}
	return false;
}

extern "C" void func_ov008_020d24c8(WmController* controller) {
	int emitter = 0;
	u32 world = save.game.currentWorld;
	for (int node = 0; node < WM::wxNodeCount; node++) {
		u8 nodeID = node;
		u32 nodeType = WM::wxNodes[node].type;
		if (nodeType == WM::NT_ToadHousePurple
			|| nodeType == WM::NT_Arrow
			|| u8(save.game.nodeStates[world][nodeID]
				& WM::NS_Completed) != 0) {
			continue;
		}

		u32 pathStatus = 1;
		WM::NodeLink* link = WM::wxNodes[node].links;
		for (;;) {
			if (link->node == u8(-1)) {
				break;
			}
			if (u8(save.game.pathStates[world][link->path]
				& WM::PS_Unlocked) != 0) {
				pathStatus = 3;
				break;
			}
			link++;
		}

		if (controller->nodeStates[node] == 3
			|| pathStatus != 3
			|| u16(WM::wxNodes[node].flag & WM::NF_Course) == 0) {
			continue;
		}

		Vec3_32 position;
		position.x = WM::wxPoints[node].x << 12;
		position.y = WM::wxPoints[node].y << 12;
		position.z = WM::wxPoints[node].z << 12;
		controller->envParticles[emitter].emitterID = func_02022890(
			controller->envParticles[emitter].emitterID,
			0x1A,
			&position,
			0,
			0,
			0,
			0);
		emitter++;
		if (emitter >= 2) {
			return;
		}
	}
}

extern "C" void func_ov008_020d2694(
	WmController* controller, u32 emitUnlockEffect) {
	Vec3_32 position;
	u32 world = save.game.currentWorld;
	u8 pathStatus;
	for (register int node = 0; node < WM::wxNodeCount; node++) {
		u8 nodeID = node;
		u16 nodeType = WM::wxNodes[node].type;
		if (nodeType == WM::NT_ToadHousePurple) {
			if (u8(save.game.nodeStates[world][nodeID]
				& WM::NS_Completed) != 0) {
				controller->nodeStates[node] = 0;
			} else {
				controller->nodeStates[node] = 4;
			}
		} else if (nodeType == WM::NT_Arrow) {
			if ((controller->toadHouseStates[controller->unk22F1]
				& ToadHouseState_Bit4) != 0) {
				controller->nodeStates[node] = 3;
				if (controller->unk22F0 != 0) {
					controller->unk22F0 = 0;
					position.x = WM::wxPoints[node].x << 12;
					position.y = WM::wxPoints[node].y << 12;
					position.z = WM::wxPoints[node].z << 12;
					func_02022b64(0x19, &position);
					func_02012398(0x32, 0);
				}
			} else {
				controller->nodeStates[node] = 2;
			}
		} else if (u8(save.game.nodeStates[world][nodeID]
			& WM::NS_Completed) != 0) {
			if ((save.game.completion
					& WM_SAVE_COMPLETION_BIT_0) == 0
				&& u8(nodeType + 0xEF) <= 2) {
				controller->nodeStates[node] = 1;
			} else {
				controller->nodeStates[node] = 0;
			}
		} else {
			pathStatus = 1;
			WM::NodeLink* link = WM::wxNodes[node].links;
			for (;;) {
				if (link->node == u8(-1)) {
					break;
				}
				if (u8(save.game.pathStates[world][link->path]
					& WM::PS_Unlocked) != 0) {
					pathStatus = 3;
					if ((save.game.completion
						& WM_SAVE_COMPLETION_BIT_0) != 0
						&& u8(nodeType + 0xEF) <= 2) {
						pathStatus = 0;
					}
					break;
				}
				link++;
			}
			if (emitUnlockEffect
				&& controller->nodeStates[node] != 3
				&& pathStatus == 3
				&& u16(WM::wxNodes[node].flag
					& WM::NF_Course) != 0) {
				position.x = WM::wxPoints[node].x << 12;
				position.y = WM::wxPoints[node].y << 12;
				position.z = WM::wxPoints[node].z << 12;
				func_02022b64(0x19, &position);
				func_02012398(0x32, 0);
			}
			controller->nodeStates[node] = pathStatus;
		}
	}
}

extern "C" void func_ov008_020d2b68(WmController*) {
	u8 entityType = WM::ET_Invalid;
	for (int entity = 0; entity < 2; entity++) {
		if (u8(save.game.currentWorldNode) ==
			save.game.mapEntities[save.game.currentWorld][entity].node) {
			entityType = WM::wxEntities[entity].type;
		}
	}
	data_ov008_020ee3a8 = entityType;
	data_ov008_020ee3d0 = 1;
}

extern "C" u32 func_ov008_020d2be4(WmController* controller) {
	u32 completion = save.game.completion;
	if ((completion & WM_SAVE_COMPLETION_BIT_4) != 0
		&& (completion & 0x80) == 0) {
		data_ov008_020ee3e8 =
			WM::wxPoints[save.game.currentWorldNode].x << 12;
		func_ov008_020d32c4(controller, 19);
		return true;
	}
	return false;
}

extern "C" u32 func_ov008_020d2c54(WmController* controller) {
	if (controller->levelExit == 0) {
		return false;
	}
	controller->levelExit = 0;
	func_ov008_020d32c4(controller, 4);
	return true;
}

extern "C" u32 func_ov008_020d2c90(WmController* controller) {
	if ((WM::wxFlags & 0x80000000) == 0) {
		return false;
	}
	func_ov008_020d32c4(controller, 7);
	return true;
}

extern "C" u32 func_ov008_020d2cc8(WmController* controller) {
	if (controller->unk22E3 != 0) {
		controller->unk22E3 = 0;
		func_ov008_020ce5ec();
	}
	return 0;
}

extern "C" u32 func_ov008_020d2cf8(WmController* controller) {
	if (controller->unk22F0 == 0) {
		return false;
	}
	data_ov008_020ee3e8 = controller->cursorPosition.x;
	func_ov008_020d32c4(controller, 11);
	return true;
}

extern "C" u32 func_ov008_020d2d40(WmController* controller) {
	if (controller->unk22E1 == 0) {
		return false;
	}
	controller->unk22E1 = 0;
	func_ov008_020d32c4(controller, 10);
	return true;
}

extern "C" u32 func_ov008_020d2d7c(
	WmController* controller, u32 value) {
	if (controller->unk22E0 != 0) {
		controller->unk22E0 = 0;
		if (value != 0) {
			data_ov008_020ee3e8 = value;
		} else {
			data_ov008_020ee3e8 =
				WM::wxPoints[save.game.currentWorldNode].x << 12;
		}
		func_ov008_020d32c4(controller, 9);
		return true;
	}
	return false;
}

extern "C" void func_ov008_020d3304(WmController* controller) {
	if (data_ov008_020ee3d0 == 0) {
		return;
	}

	Vec3_32 source;
	Vec3_32 target;
	switch (controller->unk221C) {
	case 0:
	case 3: {
		controller->unk2220--;
		s32 value = s32(controller->unk2220) % 18;
		if (value < 9) {
			data_ov008_020ee3a0 = 1;
		} else {
			data_ov008_020ee3a0 = 0;
		}
		if (controller->unk2220 == 0) {
			data_ov008_020ee3a0 = 0;
			controller->unk221C = 1;
		}
		break;
	}
	case 1: {
		source.x = data_ov008_020ee3e8;
		source.y = data_ov008_020ee3dc;
		source.z = controller->unk20E4;
		target.x = controller->unk20E8;
		target.y = controller->unk20F0;
		target.z = controller->unk20EC;
		s32 result = func_02044120(
			&source,
			&target,
			controller->unk1ED4.x,
			controller->unk1ED4.y,
			controller->unk1ED4.z);
		data_ov008_020ee3e8 = source.x;
		data_ov008_020ee3dc = source.y;
		controller->unk20E4 = source.z;
		if (result == 0) {
			controller->unk2220 = 1;
			controller->unk221C = 2;
		}
		break;
	}
	case 2:
		controller->unk2220--;
		if (controller->unk2220 == 0) {
			save.game.completion |= WM_SAVE_COMPLETION_BIT_7;
			data_ov008_020ee3a0 = 2;
			data_ov008_020ee410 = 0;
			controller->playerModels[controller->luigiMode].init(
				WmPlayerModel::A_CoinComp, false);
			func_02011e7c(0x1D, 0);
			controller->unk221C = 4;
		}
		break;
	case 4:
		data_ov008_020ee410 = _FixedMul(
			_FixedSin(controller->unk2220), 0x14C0);
		controller->unk2220 += 0x19A;
		if (s32(controller->unk2220) >= 0x4000) {
			controller->unk221C = 5;
		}
		break;
	case 5: {
		fx32 value = _FixedMul(
			_FixedSin(controller->unk2220), 0x14C0);
		data_ov008_020ee410 = value;
		controller->unk2220 += 0x19A;
		if (value <= 0x1000) {
			data_ov008_020ee410 = 0x1000;
			controller->unk2220 = 60;
			controller->unk221C = 6;
		}
		break;
	}
	case 6:
		controller->unk2220--;
		if (controller->unk2220 == 0) {
			controller->unk221C = 7;
		}
		break;
	case 7: {
		source.x = data_ov008_020ee3e8;
		source.y = data_ov008_020ee3dc;
		source.z = controller->unk20E4;
		target.x = controller->cursorPosition.x;
		target.y = 0x1000;
		target.z = 0;
		s32 result = func_02044120(
			&source,
			&target,
			controller->unk1ED4.x,
			controller->unk1ED4.y,
			controller->unk1ED4.z);
		data_ov008_020ee3e8 = source.x;
		data_ov008_020ee3dc = source.y;
		controller->unk20E4 = source.z;
		if (result == 0) {
			controller->playerModels[controller->luigiMode].init(
				WmPlayerModel::A_Wait, false);
			if (func_ov008_020d2c90(controller) != 0) {
				break;
			}
			if (func_ov008_020d2cc8(controller) == 0) {
				controller->treeMusicSyncStart = 1;
			}
			func_ov008_020d32c4(controller, 0);
		}
		break;
	}
	}
}

extern "C" void func_ov008_020d32c4(
	WmController* controller, u32 taskID) {
	controller->taskID = taskID;
	controller->taskFunc = data_ov008_020ee6fc[taskID];
	controller->startTask = true;
	data_ov008_020ee414 = 0;
}

extern "C" void func_ov008_020d3240(WmController* controller) {
	if (controller->startTask != 0) {
		(controller->*data_ov008_020ee65c[controller->taskID])();
		controller->startTask = 0;
	}
	(controller->*controller->taskFunc)();
}

extern "C" void func_ov008_020d3b1c(WmController* controller) {
	controller->unk221C = 0;
	controller->unk2220 = 60;
	controller->unk20F4 = 0;
	controller->unk22F7 = 1;
	controller->unk22EF = 0;
}

extern "C" void func_ov008_020d3b44(WmController* controller) {
	switch (controller->unk221C) {
	case 0: {
		controller->unk2208--;
		if (controller->unk2208 != 0) {
			return;
		}
		u32 value = controller->unk2268;
		u8* memory = static_cast<u8*>(func_02014a9c());
		func_02016268(memory + 0x1628, value);
		if (controller->unk22EE != 0) {
			data_ov008_020ee398 = 2;
			WM::dialogMsgID = -1;
			func_ov008_020cdc30(
				6, 1, data_ov008_020ee3f4);
			data_ov008_020ee39c = 1;
		} else {
			data_ov008_020ee398 = 4;
			func_ov008_020cdc30(
				10, 0, data_ov008_020ee3f4);
		}
		func_02012398(0xE6, 0);
		controller->unk221C = 1;
		return;
	}
	case 1:
		data_ov008_020ee3e0 += 0x200;
		if (s32(data_ov008_020ee3e0) >= 0x1000) {
			data_ov008_020ee3e0 = 0x1000;
			controller->unk221C = 2;
		}
		return;
	case 2:
		if (controller->unk22EE != 0) {
			u8 selection = data_ov008_020ee3a4;
			u16 repeated = Input::consoleKeysRepeated[0];
			u32 action = 0;
			if ((repeated & NDS::Input::ButtonRight) != 0
				&& selection == 0) {
				goto toggleSelection;
			}
			if ((repeated & NDS::Input::ButtonLeft) != 0
				&& selection == 1) {
toggleSelection:
				func_02012398(0xE5, 0);
				selection ^= 1;
				data_ov008_020ee3a4 = selection;
			}
			u16 keys =
				Input::consoleKeys[Input::localConsoleID][0];
			if ((keys & NDS::Input::ButtonA) != 0) {
				func_02012398(0xE9, 0);
				action = selection != 0 ? 2 : 1;
			} else if ((keys & NDS::Input::ButtonB) != 0) {
				func_02012398(0xE9, 0);
				action = 2;
			}
			if (action == 1) {
				func_02012398(0xE7, 0);
				controller->unk221C = 3;
				controller->unk220C = 1;
				return;
			}
			if (action == 2) {
				func_02012398(0xE7, 0);
				controller->unk221C = 3;
				controller->unk220C = 0;
			}
			return;
		} else {
			u16 keys =
				Input::consoleKeys[Input::localConsoleID][0];
			if ((keys & NDS::Input::ButtonA) == 0
				&& (keys & NDS::Input::ButtonB) == 0) {
				return;
			}
			func_02012398(0xE9, 0);
			controller->unk221C = 3;
			controller->unk220C = 0;
			return;
		}
	case 3:
		data_ov008_020ee3e0 -= 0x200;
		if (s32(data_ov008_020ee3e0) > 0) {
			return;
		}
		data_ov008_020ee3e0 = 0;
		data_ov008_020ee398 = 0;
		data_ov008_020ee39c = 0;
		if (controller->unk220C != 0) {
			data_ov008_020ee3e8 =
				WM::wxPoints[save.game.currentWorldNode].x << 12;
			func_ov008_020d32c4(controller, 16);
			return;
		}
		data_ov008_020ee3d0 = 1;
		func_ov008_020d32c4(controller, 0);
		return;
	}
}

extern "C" void func_ov008_020d3774(WmController* controller) {
	switch (controller->unk221C) {
	case 0:
		if (controller->unk2220 != 0) {
			controller->unk2220--;
			if (controller->unk2220 == 0) {
				controller->unk2220 = 180;
				controller->unk221C = 1;
			}
		}
		break;
	case 1:
		controller->unk20F4 += 0x80;
		if (s32(controller->unk20F4) > 0x3000) {
			controller->unk20F4 = 0x3000;
		}
		if (controller->unk2220 != 0) {
			controller->unk2220--;
			if (controller->unk2220 == 0) {
				controller->bridgeFlags |=
					BridgeFlag_Bit1 | BridgeFlag_Bit2;
				controller->unk221C = 2;
				for (int i = 0; i < 8; i++) {
					func_02022b64(
						data_ov008_020e95a8[i],
						&controller->unk2040);
				}
			}
		}
		break;
	case 2:
		controller->unk20F4 -= 0x80;
		if (s32(controller->unk20F4) < 0x2000) {
			controller->unk20F4 = 0x2000;
		}
		data_ov008_020ee3e8 += 0x1000;
		if (data_ov008_020ee3e8 >= 0x190000) {
			data_ov008_020ee3e8 = 0x190000;
			controller->unk2220 = 60;
			controller->unk221C = 3;
		}
		break;
	case 3:
		if ((controller->bridgeFlags & BridgeFlag_Bit3) != 0) {
			controller->unk221C = 4;
			controller->unk2220 = 60;
		}
		break;
	case 4:
		controller->unk20F4 -= 0x200;
		if (s32(controller->unk20F4) < 0) {
			controller->unk20F4 = 0;
		}
		if (controller->unk2220 != 0) {
			controller->unk2220--;
			if (controller->unk2220 == 0) {
				controller->unk20F4 = 0;
				controller->unk221C = 5;
			}
		}
		break;
	case 5:
		data_ov008_020ee3e8 -= 0x2000;
		if (data_ov008_020ee3e8 <= controller->cursorPosition.x) {
			data_ov008_020ee3e8 = controller->cursorPosition.x;
			controller->unk2220 = 10;
			controller->unk221C = 6;
		}
		break;
	case 6:
		if (controller->unk2220 != 0) {
			controller->unk2220--;
			if (controller->unk2220 == 0) {
				WM::state |= WM::ST_Bit0;
				func_ov008_020d32c4(controller, 14);
			}
		}
		break;
	}

	if ((controller->bridgeFlags & BridgeFlag_Bit2) != 0) {
		controller->bridgeModel.frameController.update();
		if (controller->bridgeModel.frameController.finished()) {
			controller->bridgeFlags |= BridgeFlag_Bit3;
		}
		u16 frame = controller->bridgeModel.getFrame();
		switch (frame) {
		case 2:
		case 18:
		case 34:
		case 50:
			func_02012398(0x24, 0);
			break;
		case 183:
		case 199:
		case 215:
		case 231:
			func_02012398(0x22, 0);
			break;
		}
	}

	data_ov008_020ee3ec = controller->unk20F4;
	if (s32(controller->unk221C) < 4) {
		if (controller->unk22EF < 0x7F) {
			controller->unk22EF += 2;
			if (controller->unk22EF > 0x7F) {
				controller->unk22EF = 0x7F;
			}
		}
	} else if (controller->unk20F4 == 0
		&& controller->unk22EF != 0) {
		controller->unk22EF -= 2;
		if (s8(controller->unk22EF) < 0) {
			controller->unk22EF = 0;
		}
	}
	if (controller->unk22EF != 0) {
		func_020122d0(0x28, 0, controller->unk22EF);
	}
}

extern "C" void func_ov008_020d36fc(WmController* controller) {
	controller->unk20E8 =
		WM::wxPoints[save.game.currentWorldNode].x << 12;
	controller->unk20E4 = 0;
	controller->unk20F0 = 0x800;
	controller->unk20EC =
		WM::wxPoints[save.game.currentWorldNode].z << 12;
	controller->playerDirection = 0;
	controller->unk2220 = 90;
	controller->unk221C = 0;
}

extern "C" void func_ov008_020d3e58(WmController* controller) {
	controller->unk2208 = 0x1e;
	data_ov008_020ee3e0 = 0;
	controller->unk221C = 0;
}

extern "C" void func_ov008_020d3e7c(WmController* controller) {
	Vec3_32 source;
	Vec3_32 target;
	switch (controller->unk221C) {
	case 0: {
		controller->unk2208--;
		if (controller->unk2208 != 0) {
			break;
		}
		controller->unk2208 = 40;
		u32 world = save.game.currentWorld;
		u8 path = controller->unk2218;
		save.game.pathStates[world][path] |=
			WM::PS_Bit20 | WM::PS_Unlocked;
		save.game.starCoinsSpent = func_ov008_020cdec0();
		func_ov008_020cdcf8();
		controller->unk221C = 1;
		break;
	}
	case 1:
		controller->unk2208--;
		if (controller->unk2208 == 0) {
			controller->unk221C = 2;
		}
		break;
	case 2: {
		source.x = data_ov008_020ee3e8;
		source.y = data_ov008_020ee3dc;
		source.z = controller->unk20E4;
		target.x = controller->unk20E8;
		target.y = controller->unk20F0;
		target.z = controller->unk20EC;
		s32 result = func_02044120(
			&source,
			&target,
			controller->unk1ED4.x,
			controller->unk1ED4.y,
			controller->unk1ED4.z);
		data_ov008_020ee3e8 = source.x;
		data_ov008_020ee3dc = source.y;
		controller->unk20E4 = source.z;
		if (result == 0) {
			func_02012398(0x25, 0);
			controller->unk221C = 3;
		}
		break;
	}
	case 3:
		controller->signBoneAnims[controller->unk2214].update();
		if (controller->signBoneAnims[controller->unk2214]
				.frameController.finished()) {
			func_02022b64(
				0, &controller->signPos[controller->unk2214]);
			func_02022b64(
				1, &controller->signPos[controller->unk2214]);
			func_ov008_020cdcf8();
			controller->signStates[controller->unk2214] = 0;
			for (int i = 0; i < 2; i++) {
				controller->envParticles[i].emitterID = 0;
				controller->envParticles[i].unknown = 0;
			}
			controller->unk2220 = 60;
			controller->unk221C = 4;
			func_02012398(0x26, 0);
			func_02012398(0x31, 0);
		}
		break;
	case 4:
		func_ov008_020d24c8(controller);
		controller->unk2220--;
		if (controller->unk2220 == 0) {
			func_ov008_020d2694(controller, 1);
			controller->unk2220 = 20;
			controller->unk221C = 5;
		}
		break;
	case 5:
		controller->unk2220--;
		if (controller->unk2220 == 0) {
			func_02012398(0x21, 0);
			controller->unk22E7 = 0;
			controller->unk2208 = 1;
			controller->unk221C = 6;
		}
		break;
	case 6:
		if (func_ov008_020d4d00(controller) != 0) {
			controller->unk2220 = 30;
			controller->unk221C = 7;
		}
		break;
	case 7:
		controller->unk2220--;
		if (controller->unk2220 == 0) {
			controller->unk221C = 8;
		}
		break;
	case 8: {
		source.x = data_ov008_020ee3e8;
		source.y = data_ov008_020ee3dc;
		source.z = controller->unk20E4;
		target.x = controller->cursorPosition.x;
		target.y = 0x1000;
		target.z = 0;
		s32 result = func_02044120(
			&source,
			&target,
			controller->unk1ED4.x,
			controller->unk1ED4.y,
			controller->unk1ED4.z);
		data_ov008_020ee3e8 = source.x;
		data_ov008_020ee3dc = source.y;
		controller->unk20E4 = source.z;
		if (result == 0) {
			data_ov008_020ee3d0 = 1;
			func_ov008_020d2cc8(controller);
			func_ov008_020d32c4(controller, 0);
		}
		break;
	}
	}
}

extern "C" void func_ov008_020d4278(WmController* controller) {
	controller->unk20F4 = controller->signPos[controller->unk2214].y;
	controller->velocity.y = 0x2000;
	controller->minVelocity.y = -0x4000;
	controller->accelV = -0x100;
	func_02022b64(2, &controller->signPos[controller->unk2214]);
	func_02022b64(3, &controller->signPos[controller->unk2214]);
	func_02012398(0x1e, 0);
	controller->unk2208 = 20;
	controller->unk22EF = 3;
	func_ov008_020d5140(controller, controller->unk22F2);
	controller->unk221C = 0;
	controller->unk22E3 = 8;
}

extern "C" void func_ov008_020d4330(WmController* controller) {
	controller->unk2208--;
	if (controller->unk2208 != 0) {
		return;
	}
	func_ov008_020d32c4(controller, 4);
}

extern "C" void func_ov008_020d4368(WmController* controller) {
	controller->unk2208 = 0x40;
}

extern "C" void func_ov008_020d4378(WmController* controller) {
	if ((WM::state & WM::ST_Unk10) != 0) {
		u32 model = data_ov008_020ee3b0;
		WM::state &= ~WM::ST_Unk10;
		controller->towerCastleModels[model].init(
			2, FrameCtrl::Standard, 0x1000, 0);
		controller->towerCastleModelFlags[model] |= 0x10;
		func_ov008_020d2024(controller, model);
		func_02012398(0x1D, 0);
	}
	if ((WM::state & WM::ST_Bit2) == 0) {
		return;
	}
	if (controller->exitInteractionType == 0) {
		if (save.game.currentWorld != 0) {
			controller->unk22E3 = 1;
		}
	} else {
		controller->unk22E3 = 1;
	}
	u32 value = data_ov008_020ee3e8;
	data_ov008_020ee3ac = 0;
	if (func_ov008_020d2d7c(controller, value) != 0) {
		return;
	}
	if (u16(WM::wxNodes[save.game.currentWorldNode].flag
		& WM::NF_Final) != 0) {
		func_ov008_020d32c4(controller, 4);
		return;
	}
	if (func_ov008_020d2c90(controller) != 0) {
		return;
	}
	if (func_ov008_020d2cf8(controller) != 0) {
		return;
	}
	func_ov008_020d2cc8(controller);
	if (func_ov008_020d2c54(controller) != 0) {
		return;
	}
	func_ov008_020d32c4(controller, 0);
}

extern "C" void func_ov008_020d4514(WmController* controller) {
	data_ov008_020ee388 = 0;
	if (controller->unk22E0 != 0) {
		WM::state |= WM::ST_Bit3;
	}
}

extern "C" void func_ov008_020d4548(WmController* controller) {
	data_ov008_020ee414 = 1;
	if (Math::expLerp(
			&data_ov008_020ee3e8,
			controller->cursorPosition.x,
			controller->unk1EC4.y,
			controller->unk1EC4.z,
			controller->unk1EC4.x) == 0) {
		controller->unk2204 = 0;
		data_ov008_020ee3d0 = 1;
		func_ov008_020d32c4(controller, 0);
	}
}

extern "C" void func_ov008_020d45c0(WmController*) {}

extern "C" void func_ov008_020d45c4(WmController* controller) {
	data_ov008_020ee414 = 1;
	data_ov008_020ee394 = 0;
	controller->manualCameraState = 3;
	u32 console = Input::localConsoleID;
	u32 cancelMask =
		NDS::Input::ButtonA
		| NDS::Input::ButtonB
		| NDS::Input::ButtonStart
		| NDS::Input::ButtonRight
		| NDS::Input::ButtonLeft
		| NDS::Input::ButtonUp
		| NDS::Input::ButtonDown
		| NDS::Input::ButtonX
		| NDS::Input::ButtonY;
	u32 cancelKeys = Input::consoleKeys[console][0] & cancelMask;
	u32 world = save.game.currentWorld;
	bool cancel = false;
	if (cancelKeys != 0) {
		cancel = true;
		goto inputDone;
	}
	u16 repeatedKeys = data_02087650[console][0];
	if ((repeatedKeys & NDS::Input::ButtonL) != 0) {
		controller->manualCameraState = 1;
		fx32 position =
			data_ov008_020ee3e8 - controller->unk1EC4.x;
		data_ov008_020ee3e8 = position;
		if (position < func_ov008_020ce1b4(world)) {
			data_ov008_020ee3e8 =
				func_ov008_020ce1b4(world);
		}
		data_ov008_020ee394 = 1;
	} else if ((repeatedKeys & NDS::Input::ButtonR) != 0) {
		controller->manualCameraState = 2;
		fx32 position =
			data_ov008_020ee3e8 + controller->unk1EC4.x;
		data_ov008_020ee3e8 = position;
		if (position > func_ov008_020ce184(world)) {
			data_ov008_020ee3e8 =
				func_ov008_020ce184(world);
		}
		data_ov008_020ee394 = 1;
	}
inputDone:
	if (cancel) {
		func_02012398(0xEA, 0);
		controller->manualCameraState = 0;
		func_ov008_020d32c4(controller, 13);
	}
	controller->cameraScaleAngle += 0xCCC;
	fx32 cameraScale =
		_FixedMul(_FixedSin(controller->cameraScaleAngle), 4);
	controller->unk2060.x = cameraScale;
	controller->unk2060.y = cameraScale;
}

extern "C" void func_ov008_020d4784(WmController*) {}

extern "C" void func_ov008_020d4788(WmController* controller) {
	Vec3_32 position;
	if (data_ov008_020ee3d0 != 0) {
		switch (controller->unk221C) {
		case 0:
			controller->unk2208--;
			if (controller->unk2208 == 0) {
				controller->unk221C = 1;
			}
			break;
		case 1:
			if (Math::expLerp(
				&data_ov008_020ee3e8,
				controller->unk1FB0[controller->unk22F1].x,
				controller->unk1ED4.x,
				controller->unk1ED4.y,
				controller->unk1ED4.z) == 0) {
				controller->unk2208 = 30;
				controller->unk221C = 2;
			}
			break;
		case 2:
			controller->unk2208--;
			if (controller->unk2208 == 0) {
				position = controller->unk1FB0[controller->unk22F1];
				u32 particleSet =
					data_02088c4c[save.game.currentWorld][0] & 3;
				for (int particle = 0; particle < 3; particle++) {
					func_02022b64(
						data_ov008_020e95e8[particleSet][particle],
						&position);
				}
				controller->unk220C = 0;
				controller->unk221C = 3;
				func_02012398(0x1F, 0);
			}
			break;
		case 3: {
			s32 value = data_ov008_020e9760[controller->unk220C];
			if (value != -1) {
				controller->unk2030.x = value;
				controller->unk2030.y =
					data_ov008_020e97f0[controller->unk220C];
				controller->unk2030.z =
					data_ov008_020e9760[controller->unk220C];
				controller->unk220C++;
			} else {
				controller->unk2030.x = 0x1000;
				controller->unk2030.y = 0x1000;
				controller->unk2030.z = 0x1000;
				controller->toadHouseStates[controller->unk22F1] |=
					ToadHouseState_Bit4;
				controller->unk2208 = 30;
				controller->unk221C = 4;
			}
			break;
		}
		case 4:
			controller->unk2208--;
			if (controller->unk2208 == 20) {
				func_ov008_020d2694(controller, 1);
			}
			if (controller->unk2208 == 0) {
				controller->unk221C = 5;
			}
			break;
		case 5:
			if (Math::expLerp(
				&data_ov008_020ee3e8,
				controller->cursorPosition.x,
				controller->unk1ED4.x,
				controller->unk1ED4.y,
				controller->unk1ED4.z) == 0) {
				controller->unk2208 = 1;
				controller->unk221C = 6;
			}
			break;
		case 6:
			controller->unk2208--;
			if (controller->unk2208 == 0) {
				func_ov008_020d2cc8(controller);
				if (func_ov008_020d2c54(controller) == 0) {
					func_ov008_020d32c4(controller, 0);
				}
			}
			break;
		}
	}
}

extern "C" void func_ov008_020d4a5c(WmController* controller) {
	controller->unk2208 = 10;
	controller->unk221C = 0;
}

extern "C" void func_ov008_020d4a74(WmController* controller) {
	if (data_ov008_020ee3d0 == 0) {
		return;
	}
	switch (controller->unk221C) {
	case 0:
		controller->unk2208--;
		if (controller->unk2208 != 0) {
			return;
		}
		for (int house = 0; house < 8; house++) {
			if ((controller->toadHouseStates[house]
				& ToadHouseState_Bit2) != 0) {
				u32 nodeType =
					WM::wxNodes[WM::wxToadHouses[house].node].type;
				s32 particleSet = -1;
				if (nodeType == WM::NT_Arrow) {
					particleSet =
						save.game.nodeStates[save.game.currentWorld][0] & 3;
				} else if (nodeType >= WM::NT_ToadHouseRed
					&& nodeType <= WM::NT_ToadHouseYellow) {
					particleSet = nodeType - WM::NT_ToadHouseRed;
				}
				if (particleSet >= 0) {
					for (int particle = 0; particle < 3; particle++) {
						func_02022b64(
							data_ov008_020e95e8[particleSet][particle],
							&controller->unk1FB0[house]);
					}
				}
			}
		}
		controller->unk220C = 0;
		controller->unk221C = 1;
		func_02012398(0x20, 0);
		return;
	case 1: {
		s32 value = data_ov008_020e960c[controller->unk220C];
		if (value != -1) {
			controller->unk2030.x = value;
			controller->unk2030.y = value;
			controller->unk2030.z = value;
			controller->unk220C++;
			return;
		}
		controller->unk2030.x = 0;
		controller->unk2030.y = 0;
		controller->unk2030.z = 0;
		for (int house = 0; house < 8; house++) {
			u8 state = controller->toadHouseStates[house];
			if ((state & ToadHouseState_Bit2) != 0) {
				if ((state & ToadHouseState_Bit3) != 0) {
					controller->toadHouseStates[house] = 0;
				} else {
					controller->toadHouseStates[house] =
						state & ~ToadHouseState_Bit0;
				}
			}
		}
		controller->unk221C = 2;
		controller->unk2208 = 30;
		return;
	}
	case 2:
		controller->unk2208--;
		if (controller->unk2208 != 0) {
			return;
		}
		func_ov008_020d2694(controller, 1);
		if (func_ov008_020d2c90(controller) != 0) {
			return;
		}
		if (func_ov008_020d2c54(controller) != 0) {
			return;
		}
		func_ov008_020d32c4(controller, 0);
		return;
	}
}

extern "C" void func_ov008_020d4cdc(WmController* controller) {
	controller->unk22EF = 1;
	controller->unk2208 = 10;
	controller->unk220C = 0;
	controller->unk221C = 0;
}

extern "C" u32 func_ov008_020d4d00(WmController* controller) {
	if (controller->unk2208 != 0) {
		controller->unk2208--;
		if (controller->unk2208 == 0) {
			controller->unk2208 = 2;
			controller->unk22E7++;
			u32 world = save.game.currentWorld;
			u8 alpha = data_ov008_020e2e44[controller->unk22E7];
			if (alpha != 0) {
				for (int path = 0; path < WM::wxPathCount; path++) {
					if (u8(save.game.pathStates[world][u8(path)]
						& WM::PS_Bit20) != 0) {
						controller->pathMdlAlpha[path] =
							data_ov008_020e2e44[controller->unk22E7];
					}
				}
			} else {
				for (int path = 0; path < WM::wxPathCount; path++) {
					if (u8(save.game.pathStates[world][u8(path)]
						& WM::PS_Bit20) != 0) {
						save.game.pathStates[world][u8(path)] &=
							~WM::PS_Bit20;
						save.game.pathStates[world][u8(path)] |=
							WM::PS_Unk40;
					}
				}
				controller->unk2208 = 0;
				return true;
			}
		}
	}
	return false;
}

extern "C" void func_ov008_020d4e34(WmController* controller) {
	if (data_ov008_020ee3d0 == 0) {
		return;
	}
	if (controller->unk22FA == 0) {
		return;
	}
	Vec3_32 source;
	Vec3_32 target;
	switch (controller->unk221C) {
	case 0: {
		source.x = data_ov008_020ee3e8;
		source.y = data_ov008_020ee3dc;
		source.z = controller->unk20E4;
		target.x = controller->unk20E8;
		target.y = controller->unk20F0;
		target.z = controller->unk20EC;
		s32 result = func_02044120(
			&source,
			&target,
			controller->unk1ED4.x,
			controller->unk1ED4.y,
			controller->unk1ED4.z);
		data_ov008_020ee3e8 = source.x;
		data_ov008_020ee3dc = source.y;
		controller->unk20E4 = source.z;
		if (result == 0) {
			for (int particle = 0; particle < 2; particle++) {
				controller->envParticles[particle].emitterID = 0;
				controller->envParticles[particle].unknown = 0;
			}
			controller->unk2220 = 60;
			controller->unk221C = 1;
			func_02012398(0x31, 0);
		}
		break;
	}
	case 1:
		func_ov008_020d24c8(controller);
		controller->unk2220--;
		if (controller->unk2220 == 0) {
			func_ov008_020d2694(controller, 1);
			controller->unk2220 = 20;
			controller->unk221C = 2;
		}
		break;
	case 2:
		controller->unk2220--;
		if (controller->unk2220 == 0) {
			func_02012398(0x21, 0);
			controller->unk22E7 = 0;
			controller->unk2208 = 1;
			controller->unk221C = 3;
		}
		break;
	case 3:
		if (func_ov008_020d4d00(controller) != 0) {
			controller->unk2220 = 30;
			controller->unk221C = 4;
		}
		break;
	case 4:
		controller->unk2220--;
		if (controller->unk2220 == 0) {
			controller->unk221C = 5;
		}
		break;
	case 5: {
		source.x = data_ov008_020ee3e8;
		source.y = data_ov008_020ee3dc;
		source.z = controller->unk20E4;
		target.x = controller->cursorPosition.x;
		target.y = 0x1000;
		target.z = 0;
		s32 result = func_02044120(
			&source,
			&target,
			controller->unk1ED4.x,
			controller->unk1ED4.y,
			controller->unk1ED4.z);
		data_ov008_020ee3e8 = source.x;
		data_ov008_020ee3dc = source.y;
		controller->unk20E4 = source.z;
		if (result == 0) {
			if (func_ov008_020d2c90(controller) != 0) {
				break;
			}
			if (func_ov008_020d2cf8(controller) != 0) {
				break;
			}
			func_ov008_020d2cc8(controller);
			if (func_ov008_020d2c54(controller) != 0) {
				break;
			}
			func_ov008_020d32c4(controller, 0);
		}
		break;
	}
	}
}

extern "C" void func_ov008_020d5140(WmController* controller, u8 pointIndex) {
	u32 world = save.game.currentWorldNode;
	WM::Node* nodes = WM::wxNodes;
	WM::Point* points = WM::wxPoints;
	s32 pointX = points[pointIndex].x << 12;
	u8 worldPoint = nodes[world].unk6;
	if (worldPoint != 0) {
		world = worldPoint;
	}

	s32 worldX = points[world].x << 12;
	s32 deltaX = pointX - worldX;
	s32 halfDistance;
	if (deltaX > 0) {
		halfDistance = deltaX / 2;
		controller->unk20E8 = worldX + halfDistance;
	} else {
		halfDistance = -deltaX / 2;
		controller->unk20E8 = worldX - halfDistance;
	}

	controller->unk20E4 = 0;
	s32 pointZ = WM::wxPoints[pointIndex].z << 12;
	s32 worldZ = WM::wxPoints[world].z << 12;
	controller->unk20EC = worldZ + (pointZ - worldZ) / 2;

	if (halfDistance <= 0x28000) {
		controller->unk20F0 = 0xA00;
		return;
	}
	if (halfDistance <= 0x48000) {
		controller->unk20F0 = 0xC00;
		return;
	}
	if (halfDistance <= 0x68000) {
		controller->unk20F0 = 0xE00;
		return;
	}
	if (halfDistance <= 0x88000) {
		controller->unk20F0 = 0x1100;
		return;
	}
	if (halfDistance <= 0xA8000) {
		controller->unk20F0 = 0x1400;
		return;
	}
	if (halfDistance <= 0xC8000) {
		controller->unk20F0 = 0x1800;
	} else {
		controller->unk20F0 = 0x1C00;
	}
}

extern "C" void func_ov008_020d511c(WmController* controller) {
	func_ov008_020d5140(controller, controller->unk22F2);
	controller->unk221C = 0;
}

extern "C" void func_ov008_020d5284(WmController* controller) {
	func_ov008_020d32c4(controller, 0);
}

extern "C" void func_ov008_020d5294(WmController* controller) {
	for (int entity = 0; entity < 2; entity++) {
		if (u8(save.game.currentWorldNode) ==
			save.game.mapEntities[save.game.currentWorld][entity].node) {
			save.game.mapEntities[save.game.currentWorld][entity].node =
				0xFF;
			controller->entityDirs[entity] = -1;
		}
	}
}

extern "C" void func_ov008_020d52f0(WmController* controller) {
	if (data_ov008_020ee3d0 == 0) {
		return;
	}

	bool allFinished = true;
	bool playMoveSound = false;
	bool playSpecialMoveSound = false;

	int entity = 0;
	Vec3_32* entityPosition = controller->entityRenderPos;
	for (; entity < 2; entityPosition++, entity++) {
		if (controller->entityDirs[entity] < 0) {
			continue;
		}

		if (controller->entityUnk2090[entity]
			== controller->entityUnk20A0[entity]) {
			continue;
		}

		controller->entityNoRotY[entity] = 1;
		bool reachedTarget = false;

		if (controller->entityTypes[entity] == 0) {
			s32 currentY = controller->entityRenderPos[entity].y;
			s32 deltaY = currentY - controller->entityUnk20F8[entity];
			controller->entityUnk20F8[entity] = currentY;

			if (controller->unk22D6[entity] != 0) {
				if (deltaY < 0) {
					deltaY = -deltaY;
				}
				if (deltaY < 0x10) {
					func_02022b64(
						data_ov008_020e943c[0],
						entityPosition);
					controller->unk22D6[entity] = 0;
				}
			} else {
				if (deltaY > 0x10) {
					func_02022b64(
						data_ov008_020e943c[0],
						entityPosition);
					controller->unk22D6[entity] = 1;
				} else {
					controller->entityUnk2250[entity] = func_02022890(
						controller->entityUnk2250[entity],
						data_ov008_020e93ec[0],
						entityPosition,
						0,
						0,
						0,
						0);
				}
				s32 frame = controller->entityModels[entity]
					.model.frameController.currentFrame;
				if (frame == 0x1000 || frame == 0xE000) {
					playMoveSound = true;
				}
			}
		} else {
			s32 frame = controller->entityModels[entity]
				.model.frameController.currentFrame;
			if (frame == 0x1000 || frame == 0xF000) {
				playSpecialMoveSound = true;
			}
		}

		u32 world = save.game.currentWorld;
		s32 cameraX = data_ov008_020ee48c.x;
		u8 node = save.game.mapEntities[world][entity].node;
		s32 distance = cameraX - controller->entityRenderPos[entity].x;
		if (distance < 0) {
			distance = -distance;
		}

		if ((distance >> 12) < 0xC0) {
			controller->entityUnk2098[entity] = 0xC00;
		} else {
			distance = data_ov008_020ee48c.x
				- (WM::wxPoints[node].x << 12);
			if (distance < 0) {
				distance = -distance;
			}
			distance = (distance >> 12) - 0xC0;
			if (distance < 0) {
				distance = 0;
			}
			controller->entityUnk2098[entity] =
				((distance / 0x40) + 1) * 0xC00;
		}

		if (controller->entityDirs[entity] != 0) {
			controller->entityUnk2090[entity] -=
				controller->entityUnk2098[entity];
			if (controller->entityUnk2090[entity]
				> controller->entityUnk20A0[entity]) {
				allFinished = false;
			} else {
				controller->entityUnk2090[entity] =
					controller->entityUnk20A0[entity];
				reachedTarget = true;
			}
		} else {
			controller->entityUnk2090[entity] +=
				controller->entityUnk2098[entity];
			if (controller->entityUnk2090[entity]
				< controller->entityUnk20A0[entity]) {
				allFinished = false;
			} else {
				controller->entityUnk2090[entity] =
					controller->entityUnk20A0[entity];
				reachedTarget = true;
			}
		}

		if (!reachedTarget) {
			continue;
		}

		int moveStep = controller->unk22DC[entity];
		if (moveStep < 2
			&& controller->entityStates[entity][moveStep] != 0xFF) {
			controller->unk22DC[entity] = moveStep + 1;
			u8 link = controller->entityStates[entity][moveStep];
			func_ov008_020d59a8(
				controller,
				entity,
				&WM::wxNodes[node].links[link]);
			allFinished = false;
			continue;
		}

		if (controller->entityTypes[entity] == 0) {
			controller->entityModels[entity].init(1);
			if (controller->entityUnk20A8[entity] < 0) {
				controller->entityRotY[entity] = s16(0xC000);
			} else {
				controller->entityRotY[entity] = s16(0x4000);
			}
			controller->entityUnk2298[entity] = 0;
		}
		controller->entityNoRotY[entity] = 0;
	}

	if (playMoveSound) {
		func_02012398(0x19, 0);
	}
	if (playSpecialMoveSound) {
		func_02012398(0x1C, 0);
	}
	if (!allFinished) {
		return;
	}

	func_ov008_020d2b68(controller);
	if (func_ov008_020d2cf8(controller) == 0) {
		func_ov008_020d2cc8(controller);
		if (func_ov008_020d2c54(controller) == 0) {
			func_ov008_020d32c4(controller, 0);
		}
	}
	WM::state &= ~WM::ST_EntityMove;
}

extern "C" void func_ov008_020d582c(WmController* controller) {
	controller->moveEntities();
	for (int entity = 0; entity < 2; entity++) {
		if (controller->entityDirs[entity] >= 0) {
			controller->entityUnk2250[entity] = 0;
			controller->entityUnk20F8[entity] =
				controller->entityRenderPos[entity].y;
			controller->unk22D6[entity] = 0;
			controller->unk22DC[entity] = 1;
			u32 link = controller->entityStates[entity][0];
			if (link != 0xFF) {
				u32 node =
					save.game.mapEntities[
						save.game.currentWorld][entity].node;
				WM::Node* volatile& nodes = WM::wxNodes;
				WM::NodeLink* nodeLink = &nodes[node].links[link];
				func_ov008_020d59a8(
					controller, entity, nodeLink);
			} else {
				func_ov008_020d58f4(controller, entity);
			}
		}
	}
}

extern "C" void func_ov008_020d58f4(
	WmController* controller, u32 entity) {
	controller->entityModels[entity].init(1);
	if ((WM::wxNodes[
			save.game.mapEntities[save.game.currentWorld][entity].node]
			.links->flag & WM::LF_Reverse) == 0) {
		controller->entityUnk2090[entity] = 0;
	} else {
		controller->entityUnk2090[entity] =
			controller->entityCursor[entity].frameController.getFrameCount()
			<< 12;
	}
	controller->entityUnk20A0[entity] =
		controller->entityUnk2090[entity];
}

extern "C" void func_ov008_020d59a8(
	WmController* controller, u32 entity, WM::NodeLink* link) {
	controller->entityModels[entity].init(0);
	controller->entityCursor[entity].init(
		WM::wxPaths[link->path].animID,
		FrameCtrl::Standard,
		0xC00,
		0);
	save.game.mapEntities[save.game.currentWorld][entity].node =
		link->node;
	if ((link->flag & WM::LF_Reverse) != 0) {
		controller->entityUnk2090[entity] =
			controller->entityCursor[entity]
				.frameController.getFrameCount() << 12;
		controller->entityUnk20A0[entity] = 0;
		controller->entityDirs[entity] = 1;
	} else {
		controller->entityUnk2090[entity] = 0;
		controller->entityUnk20A0[entity] =
			controller->entityCursor[entity]
				.frameController.getFrameCount() << 12;
		controller->entityDirs[entity] = 0;
	}
}

extern "C" void func_ov008_020d5ab8(WmController* controller) {
	controller->unk2208--;
	if (controller->unk2208 != 0) {
		return;
	}
	func_ov008_020d32c4(controller, 1);
}

extern "C" void func_ov008_020d5af0(WmController* controller) {
	controller->playerModels[controller->luigiMode].init(4, false);
	controller->unk2208 = 20;
}

extern "C" void func_ov008_020d5b28(WmController* controller) {
	switch (controller->unk221C) {
	case 0:
		controller->unk2208--;
		if (controller->unk2208 != 0) {
			return;
		}
		func_02012398(0x17, 0);
		func_02022b64(
			data_ov008_020e943c[controller->playerPowerupMini],
			&controller->cursorPosition);
		controller->playerModels[controller->luigiMode].init(1, false);
		controller->unk221C = 1;
		return;

	case 1: {
		u8 animFlags = controller->unk1E18->flag;
		if ((animFlags & WM::AF_PeachSfxJump) != 0) {
			if (controller->unk20CC != 0) {
				controller->unk20CC -= 0x40;
			}
		} else if ((animFlags & WM::AF_ScaleUp) != 0) {
			if (controller->unk20CC < 0x1000) {
				controller->unk20CC += 0x40;
			}
		}

		fx32 scale = _FixedMul(
			data_ov008_020e956c[Game::getPlayerPowerup(0)],
			controller->unk20CC);
		controller->playerPowerupScale.x = scale;
		controller->playerPowerupScale.y = scale;
		controller->playerPowerupScale.z = scale;

		if (!func_ov008_020d63e4(controller, 0)) {
			return;
		}

		u8 model = controller->unk1E18->flag & WM::AF_ModelType;
		u32 anim = 2;
		if ((controller->towerCastleModelFlags[model] & 0x40)
			!= 0) {
			anim = 3;
		}
		controller->towerCastleModels[model].init(
			anim, FrameCtrl::Standard, 0x1000, 0);
		controller->towerCastleModelFlags[model] |= 8;
		func_ov008_020d2024(controller, model);
		func_02012398(0x1D, 0);
		controller->unk2208 = 20;
		data_ov008_020ee388 = 0;
		controller->unk221C = 2;
		return;
	}

	case 2:
		controller->unk2208--;
		if (controller->unk2208 == 0) {
			data_ov008_020ee38c = 1;
		}
		return;
	}
}

extern "C" void func_ov008_020d5d4c(WmController* controller) {
	controller->unk20B0 = 0;
	controller->unk1E18 = WM::wxAnims[controller->exitInteractionType];
	controller->playerCursor.init(
		WM::wxPaths[controller->unk1E18->path].animID,
		FrameCtrl::Standard,
		0x1000,
		0);
	controller->playerCursorFrame = 0;
	controller->unk20BC =
		controller->playerCursor.frameController.getFrameCount() << 12;
	controller->unk20CC = 0x1000;
	controller->playerModels[controller->luigiMode].init(0, false);
	WmPlayerModel* playerModel =
		&controller->playerModels[controller->luigiMode];
	func_ov011_0212cca4(&playerModel->model, controller->unk20C0);
	controller->entityUnk2250[0] = 0;
	controller->entityUnk20F8[0] = controller->cursorPosition.y + 0x20;
	controller->unk22EA = 1;
	controller->playerDirection = 0xFF;
	controller->unk2208 = 30;
	controller->unk22EF = 0;
	controller->unk221C = 0;
}

extern "C" void func_ov008_020d5e64(WmController* controller) {
	switch (controller->unk221C) {
	case 0:
		if (data_ov008_020ee3d0 == 0) {
			return;
		}

		bool animateModel = false;
		if ((WM::state & WM::ST_Bit9) == 0) {
			animateModel = true;
		}
		if (u16(WM::wxNodes[save.game.currentWorldNode].flag
				& WM::NF_Final) != 0) {
			if ((WM::state & WM::ST_Bit10) == 0) {
				animateModel = true;
			}
		} else {
			animateModel = true;
		}
		if (animateModel) {
			u8 model =
				controller->unk1E18->flag & WM::AF_ModelType;
			u32 anim = 2;
			if ((controller->towerCastleModelFlags[model] & 0x40)
				!= 0) {
				anim = 3;
			}
			controller->towerCastleModels[model].init(
				anim, FrameCtrl::Standard, 0x1000, 0);
			controller->towerCastleModelFlags[model] |= 8;
		}
		data_ov008_020ee388 = 1;
		controller->unk221C = 1;
		return;

	case 1: {
		u8 animFlags = controller->unk1E18->flag;
		if ((animFlags & WM::AF_PeachSfxJump) != 0) {
			if (controller->unk20CC != 0) {
				controller->unk20CC -= 0x40;
			}
		} else if ((animFlags & WM::AF_ScaleUp) != 0) {
			if (controller->unk20CC < 0x1000) {
				controller->unk20CC += 0x40;
			}
		}

		fx32 scale = _FixedMul(
			data_ov008_020e956c[Game::getPlayerPowerup(0)],
			controller->unk20CC);
		controller->playerPowerupScale.x = scale;
		controller->playerPowerupScale.y = scale;
		controller->playerPowerupScale.z = scale;

		if (!func_ov008_020d63e4(controller, 0)) {
			return;
		}

		u32 nextWorld =
			func_ov008_020ce298(save.game.currentWorld);
		controller->unk1E18++;

		if (u16(WM::wxNodes[save.game.currentWorldNode].flag
				& WM::NF_Final) != 0
			&& (WM::state & WM::ST_Bit8) != 0
			&& ((WM::state & WM::ST_Bit9) != 0
				|| u16(data_02088c3c[nextWorld]
					& WM::WS_Visited) == 0)
			&& controller->unk1E18->path != u8(-1)) {
			func_ov008_020d6284(controller);
			controller->unk221C = 1;
			func_02022b64(
				data_ov008_020e943c[
					controller->playerPowerupMini],
				&controller->cursorPosition);
			return;
		}

		if (controller->unk1E18->path != u8(-1)) {
			func_02012398(0x16, 0);
			func_02022b64(
				data_ov008_020e943c[
					controller->playerPowerupMini],
				&controller->cursorPosition);
		}
		func_ov008_020d6384(controller);

		if (u16(WM::wxNodes[save.game.currentWorldNode].flag
				& WM::NF_Final) != 0
			&& (WM::state & WM::ST_Bit8) != 0
			&& ((WM::state & WM::ST_Bit9) != 0
				|| u16(data_02088c3c[nextWorld]
					& WM::WS_Visited) == 0)) {
			func_ov008_020ce22c();
		} else {
			func_ov008_020d2cc8(controller);
			func_ov008_020d32c4(controller, 0);
		}
		controller->unk221C = 2;
		return;
	}

	case 2:
		return;
	}
}

extern "C" void func_ov008_020d61d8(WmController* controller) {
	controller->unk1E18 = WM::wxAnims[controller->exitInteractionType];
	func_ov008_020d6284(controller);
	controller->unk20CC =
		0x1000 - controller->playerCursor.frameController.getFrameCount() * 0x40;
	if (controller->unk20CC < 0) {
		controller->unk20CC = 0;
	}
	controller->playerModels[controller->luigiMode].init(1, false);
	WmPlayerModel* playerModel =
		&controller->playerModels[controller->luigiMode];
	func_ov011_0212cca4(
		&playerModel->model,
		controller->unk20C0);
	controller->unk221C = 0;
}

extern "C" void func_ov008_020d6284(WmController* controller) {
	if ((controller->unk1E18->flag & WM::AF_Reverse) != 0) {
		controller->unk20B0 = 1;
	} else {
		controller->unk20B0 = 0;
	}
	controller->playerCursor.init(
		WM::wxPaths[controller->unk1E18->path].animID,
		FrameCtrl::Standard,
		0x1000,
		0);
	if (controller->unk20B0 != 0) {
		controller->playerCursorFrame =
			controller->playerCursor.frameController.getFrameCount() << 12;
		controller->unk20BC = 0;
	} else {
		controller->playerCursorFrame = 0;
		controller->unk20BC =
			controller->playerCursor.frameController.getFrameCount() << 12;
	}
	controller->entityUnk2250[0] = 0;
	controller->entityUnk20F8[0] = controller->cursorPosition.y + 0x20;
	controller->unk22EA = 1;
	controller->playerDirection = 0xFF;
	controller->unk22EF = 0;
}

extern "C" void func_ov008_020d6384(WmController* controller) {
	controller->playerCursorFrame = controller->unk20BC;
	controller->playerModels[controller->luigiMode].init(0, false);
	controller->unk20C8 = 0;
	fx32 scale = data_ov008_020e956c[Game::getPlayerPowerup(0)];
	controller->playerPowerupScale.x = scale;
	controller->playerPowerupScale.y = scale;
	controller->playerPowerupScale.z = scale;
}

extern "C" bool func_ov008_020d63e4(
	WmController* controller, u32 flags) {
	s32 currentY = controller->cursorPosition.y;
	s32 previousY = controller->entityUnk20F8[0];
	controller->entityUnk20F8[0] = currentY;
	s32 deltaY = currentY - previousY;

	if (controller->unk22EF == 0) {
		controller->unk20C8 &= ~2;
		u32* movementFlags = &controller->unk20C8;
		if (controller->unk22EA == 1) {
			if (controller->luigiMode == 0) {
				*movementFlags |= 2;
			}
			if (deltaY < 0) {
				deltaY = -deltaY;
			}
			if (deltaY < 0x10) {
				if ((flags & 2) != 0) {
					func_02022b64(
						data_ov008_020e943c[
							controller->playerPowerupMini],
						&controller->cursorPosition);
				}
				controller->unk22EA = 0;
			}
		} else {
			if (deltaY > 0x10) {
				if ((flags & 1) != 0) {
					func_02022b64(
						data_ov008_020e943c[
							controller->playerPowerupMini],
						&controller->cursorPosition);
				}
				controller->unk22EA = 1;
				func_02012398(0x17, 0);
			} else {
				controller->entityUnk2250[0] = func_02022890(
					controller->entityUnk2250[0],
					data_ov008_020e93ec[
						controller->playerPowerupMini],
					&controller->cursorPosition,
					0,
					0,
					0,
					0);
			}

			if (func_ov011_0212cc8c(
					getPlayerModel(
						&controller->playerModels[
							controller->luigiMode]),
					7)
				|| func_ov011_0212cc8c(
					getPlayerModel(
						&controller->playerModels[
							controller->luigiMode]),
					0x26)) {
				func_02012398(
					data_ov008_020e95c8[save.game.currentWorld],
					0);
			}
		}
	}

	bool reachedTarget = false;
	if (controller->playerCursorFrame > controller->unk20BC) {
		controller->playerCursorFrame -= 0x1000;
		if (controller->playerCursorFrame <= controller->unk20BC) {
			reachedTarget = true;
		}
		return reachedTarget;
	}
	controller->playerCursorFrame += 0x1000;
	if (controller->playerCursorFrame >= controller->unk20BC) {
		reachedTarget = true;
	}
	return reachedTarget;
}

extern "C" void func_ov008_020d65dc(WmController* controller) {
	if (controller->unk22EF != 0) {
		if (controller->playerCursorFrame > 30 * 0x1000
			&& controller->playerCursorFrame
				< (controller->playerCursor.frameController
						.getFrameCount() - 30)
					* 0x1000) {
			func_02012314(0x13, 0);
		}

		if (controller->playerCursorFrame > controller->unk20BC) {
			if (controller->playerCursorFrame == 30 * 0x1000) {
				func_02012398(0x18, 0);
			}
		} else if (controller->playerCursorFrame
			== (controller->playerCursor.frameController
					.getFrameCount() - 30)
				* 0x1000) {
			func_02012398(0x18, 0);
		}
	}

	if (!func_ov008_020d63e4(controller, 3)) {
		return;
	}

	u32 linkCount;
	WM::NodeLink* link;
	u32 node;
	WM::Node* nodes;

	linkCount = 0;
	if (controller->taskID == WmController::Walk) {
		node = controller->currentNode;
		nodes = WM::wxNodes;
		if (u16(nodes[node].flag & WM::NF_Fork) != 0) {
			link = nodes[node].links;
			for (;;) {
				if (link->node == u8(-1)) {
					break;
				}
				if (link->node
						!= u8(save.game.currentWorldNode)
					&& (u8(save.game.pathStates[
							save.game.currentWorld][link->path]
							& WM::PS_Unlocked) != 0
						|| (WM::wxPaths[link->path].flag
							& WM::PF_Sign) != 0)) {
					controller->selectedLink = link;
					linkCount++;
				}
				link++;
			}
		}
	}

	if (linkCount == 1) {
		func_ov008_020d67f8(controller);
		return;
	}

	func_02012398(0x16, 0);
	func_ov008_020d6384(controller);
	func_ov008_020d32c4(controller, 0);
	save.game.currentWorldNode = controller->currentNode;
	func_ov008_020d21d0(controller, controller->currentNode);
	func_ov008_020d2b68(controller);
	WM::state &= ~WM::ST_PlayerMove;
	func_0201ec88(
		WM::wxNodes[save.game.currentWorldNode].areaID);
}

extern "C" void func_ov008_020d67f8(WmController* controller) {
	WM::state |= WM::ST_PlayerMove;

	u8 path;
	if (controller->taskID == WmController::Walk) {
		WM::NodeLink* link = controller->selectedLink;
		controller->currentNode = link->node;
		path = link->path;
		if ((link->flag & WM::LF_Reverse) != 0) {
			controller->unk20B0 = 1;
		} else {
			controller->unk20B0 = 0;
		}
	} else {
		controller->currentNode =
			data_02085acc.returnNode;
		controller->unk20B0 = data_02085acc.reverse;
		path = data_02085acc.path;
	}

	controller->playerCursor.init(
		WM::wxPaths[path].animID,
		FrameCtrl::Standard,
		0x1000,
		0);
	if (controller->unk20B0 != 0) {
		controller->playerCursorFrame =
			controller->playerCursor.frameController
				.getFrameCount() << 12;
		controller->unk20BC = 0;
	} else {
		controller->playerCursorFrame = 0;
		controller->unk20BC =
			controller->playerCursor.frameController
				.getFrameCount() << 12;
	}

	data_02085acc.returnNode = save.game.currentWorldNode;
	data_02085acc.reverse = controller->unk20B0 ^ 1;
	data_02085acc.path = path;
	controller->unk22EF = 0;

	u32 playerState = controller->unk20C0;
	if (u8(WM::wxPaths[path].flag & WM::PF_Pipe) != 0) {
		controller->playerModels[
			controller->luigiMode].init(3, false);
		controller->unk20C8 = 1;
		controller->playerCursor.frameController.currentFrame = 0;
		controller->playerPowerupScale.x = controller->unk20C4;
		controller->playerPowerupScale.z = controller->unk20C4;
		controller->unk20B0 = 0;
		func_02012398(0x18, 0);
		controller->unk22EF = 1;
	} else {
		controller->playerModels[
			controller->luigiMode].init(1, false);
		controller->unk20C8 = 0;
	}

	WmPlayerModel* playerModel =
		&controller->playerModels[controller->luigiMode];
	func_ov011_0212cca4(
		getPlayerModel(playerModel), playerState);
	controller->entityUnk2250[0] = 0;
	controller->entityUnk20F8[0] = controller->cursorPosition.y;
	controller->unk22EA = 0;
	controller->playerDirection = 0xFF;
}

extern "C" void func_ov008_020d6a14(WmController* controller) {
	controller->unk2208--;
	if (controller->unk2208 == 0) {
		data_ov008_020ee38c = 1;
	}
}

extern "C" void func_ov008_020d6a40(WmController* controller) {
	controller->unk2208 = 0x14;
}

extern "C" void func_ov008_020d6a50(WmController* controller) {
	u32 world = save.game.currentWorld;
	if (data_ov008_020ee3d0 == 0) {
		return;
	}
	data_ov008_020ee414 = 1;

	if (controller->musicPlayReq != 0) {
		controller->musicPlayReq = 0;
		controller->unk22F6 = 0;
		func_02011e7c(func_ov008_020ce12c(world), 0);
	}

	if (data_ov008_020e5a2c != -1) {
		return;
	}

	u32 console = Input::localConsoleID;
	u16 keys = Input::consoleKeys[console][0];
	if ((keys & NDS::Input::ButtonStart) != 0) {
		func_ov008_020ced20();
		return;
	}
	if (func_ov008_020d29a0(controller) != 0) {
		return;
	}

	console = Input::localConsoleID;
	keys = Input::consoleKeys[console][0];
	if ((keys & NDS::Input::ButtonL) != 0
		|| (keys & NDS::Input::ButtonR) != 0) {
		data_ov008_020ee3d0 = 0;
		func_ov008_020d32c4(
			controller, WmController::CameraMove);
		fx32 position = controller->cursorPosition.x;
		data_ov008_020ee3e8 = position;
		if (position < func_ov008_020ce1b4(world)) {
			data_ov008_020ee3e8 =
				func_ov008_020ce1b4(world);
			return;
		}
		position = data_ov008_020ee3e8;
		fx32 rightBound = func_ov008_020ce184(world);
		if (position <= rightBound) {
			return;
		}
		data_ov008_020ee3e8 =
			func_ov008_020ce184(world);
		return;
	}

	u16 repeatedKeys = data_02087650[console][0];
	u32 directionKeys = repeatedKeys
		& (NDS::Input::ButtonRight
			| NDS::Input::ButtonLeft
			| NDS::Input::ButtonUp
			| NDS::Input::ButtonDown);
	if (directionKeys == 0
		&& (keys & NDS::Input::ButtonA) == 0) {
		goto setInputDelay;
	}

	if (controller->unk2204 != 0) {
		controller->unk2204--;
		directionKeys =
			Input::consoleKeys[console][0]
			& (NDS::Input::ButtonRight
				| NDS::Input::ButtonLeft
				| NDS::Input::ButtonUp
				| NDS::Input::ButtonDown);
	}

	if ((directionKeys & NDS::Input::ButtonRight) != 0) {
		controller->playerDirection = 1;
	} else if ((directionKeys & NDS::Input::ButtonLeft) != 0) {
		controller->playerDirection = 3;
	} else if ((directionKeys & NDS::Input::ButtonUp) != 0) {
		controller->playerDirection = 2;
	} else if ((directionKeys & NDS::Input::ButtonDown) != 0) {
		controller->playerDirection = 0;
	}

	Save* saveData;
	WM::Node** nodeTable;
	WM::NodeLink* link;
	u32 pathWorld;
	saveData = &save;
	nodeTable = &WM::wxNodes;
	link = (*nodeTable)[
		saveData->game.currentWorldNode].links;
	pathWorld = saveData->game.currentWorld;
	for (;;) {
		if (link->node == u8(-1)) {
			return;
		}

		u16 linkFlags = link->flag;
		u8 linkDirection =
			u8(linkFlags & WM::LF_Direction);
		bool selected = false;
		u32 expectedKeys =
			data_ov008_020e955c[linkDirection];
		if ((linkFlags & WM::LF_Pipe) != 0) {
			if ((data_02087650[
					Input::localConsoleID][1]
					& NDS::Input::ButtonA) != 0) {
				selected = true;
			}
		} else if (directionKeys == expectedKeys) {
			selected = true;
		}

		if (selected) {
			u8 path = link->path;
			if (u8(save.game.pathStates[pathWorld][path]
					& WM::PS_Unlocked) != 0) {
				controller->selectedLink = link;
				controller->unk2204 = 0x10;
				data_ov008_020ee3d0 = 0;
				func_ov008_020d32c4(
					controller, WmController::Walk);
				return;
			}

			if (u8(WM::wxPaths[path].flag
					& WM::PF_Sign) != 0) {
				controller->unk2268 =
					WM::wxPaths[path].price;
				u32 starCoins = Save::getStarCoinAmount();
				if (controller->unk2268 > starCoins) {
					data_ov008_020ee3d0 = 0;
					controller->unk22EE = 0;
					controller->playerDirection =
						linkDirection;
					func_ov008_020d32c4(
						controller,
						WmController::SignPrompt);
				} else {
					for (int sign = 0; sign < 5; sign++) {
						if (WM::wxSigns[sign].path
							== path) {
							controller->unk2214 = sign;
							controller->unk2218 = path;
							data_ov008_020ee3d0 = 0;
							controller->unk22EE = 1;
							controller->unk22F2 =
								link->node;
							controller->playerDirection =
								linkDirection;
							func_ov008_020d32c4(
								controller,
								WmController::SignPrompt);
							break;
						}
					}
				}
			}
		}
		link++;
	}

setInputDelay:
	controller->unk2204 = 0x10;
}

extern "C" void func_ov008_020d6e1c() {
	data_ov008_020ee388 = 1;
}

extern "C" u32 func_ov008_020d6e30(WmController* controller) {
	u8 paused = data_ov008_020ee384;
	Vec3_32 particlePosition;
	data_ov008_020ee414 = 0;
	if (paused != 0) {
		return true;
	}

	func_ov008_020d3240(controller);
	controller->playerCursor.frameController.currentFrame =
		controller->playerCursorFrame;

	for (int emitter = 0; emitter < 2; emitter++) {
		if (controller->unk2228[emitter] != -1) {
			controller->envEmitterIDs[emitter] = func_02022890(
				controller->envEmitterIDs[emitter],
				controller->unk2228[emitter],
				&controller->position,
				0,
				0,
				0,
				0);
		}
	}
	for (int flame = 0; flame < 2; flame++) {
		for (int emitter = 0; emitter < 3; emitter++) {
			controller->flamesEmitterIDs[flame][emitter] =
				func_02022890(
					controller->flamesEmitterIDs[flame][emitter],
					data_ov008_020e9508[emitter],
					&data_ov008_020ee63c[flame],
					0,
					0,
					0,
					0);
		}
	}

	if (controller->worldMatAnimFileID != 0) {
		controller->worldMatAnim.update();
	}
	if (controller->worldTexSRTFileID != 0) {
		controller->worldTexSRT.update();
	}
	if (controller->worldTexAnimFileID != 0) {
		controller->worldTexAnim.update();
	}
	if (controller->treeModelFileID != 0) {
		if (controller->treeMusicSyncStart != 0) {
			if (data_02088b94[2] == 1) {
				if (controller->treeBoneAnimFileID != 0) {
					controller->treeBoneAnim.init(
						0, FrameCtrl::Standard, 0x1000, 0);
					controller->treeBoneAnim.setFrame(0);
				}
				if (controller->treeTexAnimFileID != 0) {
					controller->treeTexAnim.init(
						0, FrameCtrl::Standard, 0x1000, 0);
					controller->treeTexAnim.setFrame(0);
				}
			}
		} else if (data_02088b94[2] == 1) {
			controller->treeMusicSyncStart = 1;
		} else {
			if (controller->treeBoneAnimFileID != 0
				&& controller->treeBoneAnim.finished()) {
				controller->treeBoneAnim.init(
					0, FrameCtrl::Standard, 0x1000, 0);
				controller->treeBoneAnim.setFrame(0);
			}
			if (controller->treeTexAnimFileID != 0
				&& controller->treeTexAnim.finished()) {
				controller->treeTexAnim.init(
					0, FrameCtrl::Standard, 0x1000, 0);
				controller->treeTexAnim.setFrame(0);
			}
		}
		if (controller->unk22F6 == 0) {
			if (controller->treeBoneAnimFileID != 0) {
				controller->treeBoneAnim.update();
			}
			if (controller->treeTexAnimFileID != 0) {
				controller->treeTexAnim.update();
			}
		}
	}

	AnimationCtrl* nodeTexAnim = controller->nodeTexAnims;
	for (int nodeModel = 0; nodeModel < 4;
		nodeModel++, nodeTexAnim++) {
		nodeTexAnim->update();
	}

	for (int model = 0; model < 4; model++) {
		if ((controller->towerCastleModelFlags[model] & 0x1E) != 0) {
			if ((controller->towerCastleModelFlags[model]
					& TowerCastleModelFlag_Bit1) != 0) {
				if (GlobalFader.fadedIn()) {
					controller->towerCastleModels[model]
						.frameController.update();
					if ((controller->towerCastleModelFlags[model]
							& TowerCastleModelFlag_Bit5) != 0) {
						controller->towerCastleModelFlags[model] &=
							~TowerCastleModelFlag_Bit5;
						func_02012398(0x1D, 0);
					}
					u32 currentFrame =
						controller->towerCastleModels[model].getFrame();
					u32 effectFrame = 0x14;
					if (model >= 2) {
						effectFrame = 0x15;
					}
					if (effectFrame == currentFrame) {
						particlePosition = controller->unk1EE4[model];
						particlePosition.y += 0x3C000;
						func_02022b64(0x18, &particlePosition);
						func_02022b64(2, &particlePosition);
						func_02012398(0x23, 0);
					} else if (currentFrame == 0x23
						&& (save.game.currentWorld != 7
							|| save.game.currentWorldNode != 6)) {
						WM::state |= WM::ST_Bit0;
					}
					if (controller->towerCastleModels[model]
							.frameController.finished()) {
						controller->unk22FA = 1;
						controller->towerCastleModelFlags[model] &=
							~TowerCastleModelFlag_Bit1;
						controller->towerCastleModelFlags[model] |=
							TowerCastleModelFlag_Bit2;
						controller->towerCastleModels[model].init(
							1, FrameCtrl::Looping, 0x1000, 0);
						if (u16(WM::wxNodes[
								save.game.currentWorldNode].flag
								& WM::NF_W8Castle) != 0) {
							data_ov008_020ee3e8 =
								controller->cursorPosition.x;
							func_ov008_020d32c4(controller, 18);
						}
					}
				}
			} else {
				controller->towerCastleModels[model]
					.frameController.update();
				if ((controller->towerCastleModelFlags[model]
						& (TowerCastleModelFlag_Bit3
							| TowerCastleModelFlag_Bit4)) != 0
					&& controller->towerCastleModels[model]
						.frameController.finished()) {
					controller->towerCastleModelFlags[model] &= ~0x1E;
					if ((controller->towerCastleModelFlags[model]
							& TowerCastleModelFlag_Bit6) != 0) {
						controller->towerCastleModels[model].init(
							1, FrameCtrl::Looping, 0x1000, 0);
						controller->towerCastleModelFlags[model] |=
							TowerCastleModelFlag_Bit2;
					} else {
						controller->towerCastleModels[model].init(
							0, FrameCtrl::Standard, 0x1000, 0);
					}
				}
			}
		}
	}

	controller->playerModels[controller->luigiMode].update(
		controller->unk20C8);
	for (int entity = 0; entity < 2; entity++) {
		if (controller->entityDirs[entity] >= 0) {
			controller->entityCursor[entity]
				.frameController.currentFrame =
				controller->entityUnk2090[entity];
			controller->entityModels[entity].update();
			if (controller->entityNoRotY[entity] == 0) {
				if (WM::wxEntities[entity].type
					== WM::ET_FlyingBlock) {
					controller->entityUnk2298[entity] += 0x200;
					s32 angleIndex =
						(u16(controller->entityUnk2298[entity])
							>> 4) * 2;
					s32 radius = func_ov008_020ce0d4(1);
					controller->entityPosition[entity].x =
						_FixedMul(
							radius,
							_FixedCosTable(angleIndex));
					controller->entityPosition[entity].z =
						_FixedMul(
							radius / 2,
							_FixedSinTable(angleIndex));
				} else if (controller->entityUnk2298[entity] != 0) {
					if (controller->entityRotY[entity] == 0
						&& controller->unk2294[entity] != 0) {
						controller->unk2294[entity]--;
					} else {
						controller->entityRotY[entity] +=
							controller->entityUnk2298[entity];
					}
					if (controller->entityUnk2298[entity] < 0) {
						if (controller->entityRotY[entity]
							< -0x4000) {
							controller->entityRotY[entity] =
								s16(-0x4000);
							controller->entityUnk2298[entity] = 0;
						}
					} else if (controller->entityRotY[entity]
						> 0x4000) {
						controller->entityRotY[entity] = 0x4000;
						controller->entityUnk2298[entity] = 0;
					}
				} else {
					controller->entityPosition[entity].x +=
						controller->entityUnk20A8[entity];
					if (controller->entityUnk20A8[entity] < 0) {
						if (controller->entityPosition[entity].x
							< -0xF000) {
							controller->entityPosition[entity].x =
								-0xF000;
							controller->entityUnk20A8[entity] =
								0xC00;
							controller->entityUnk2298[entity] =
								0x400;
							controller->unk2294[entity] = 0;
						}
					} else if (controller->entityPosition[entity].x
						> 0xF000) {
						controller->entityPosition[entity].x =
							0xF000;
						controller->entityUnk20A8[entity] =
							-0xC00;
						controller->entityUnk2298[entity] =
							s16(-0x400);
						controller->unk2294[entity] = 0;
					}
				}
			}
		}
	}
	return true;
}

extern "C" u32 func_ov008_020d7734(WmController* controller) {
	u32 world = save.game.currentWorld;
	Mat4x3 playerMatrix;
	Mat4x3 worldMatrix;
	Vec3_32 pointPosition;
	Vec3_32 modelScale(0x1000, 0x1000, 0x1000);
	Mat4x3 entityMatrix;
	Mat4x3 entityMatrixUnrotated;

	MTX::setTranslation(Game_modelMatrix, controller->position);
	controller->playerCursor.matrix = Game_modelMatrix;
	controller->playerCursor.render(&controller->scale);
	controller->playerCursor.getNodeMatrix(0, &Game_modelMatrix);
	playerMatrix = Game_modelMatrix;
	controller->cursorPosition.x = Game_modelMatrix.s.m30;
	controller->cursorPosition.y = Game_modelMatrix.s.m31;
	controller->cursorPosition.z = Game_modelMatrix.s.m32;

	if (data_ov008_020ee3ac != 0
		|| controller->taskID == WmController::CameraMove
		|| controller->taskID == WmController::CameraReturn
		|| controller->taskID == WmController::PathUnlock
		|| controller->taskID == WmController::SignRemove
		|| controller->taskID == WmController::Task18
		|| controller->taskID == WmController::Task19
		|| controller->taskID == WmController::Th2) {
		fx32 cameraX = data_ov008_020ee3e8;
		fx32 cameraZ = controller->unk20E4;
		data_ov008_020ee48c.x = cameraX;
		data_ov008_020ee48c.y = 0;
		data_ov008_020ee48c.z = cameraZ;
	} else {
		data_ov008_020ee48c.x = controller->cursorPosition.x;
		data_ov008_020ee48c.y = 0;
		data_ov008_020ee48c.z = 0;
	}

	if ((controller->manualCameraState & 1) != 0) {
		Layout::drawCellMain(
			8, data_ov053_0216e73c, 0, 0, 0, 0, 0, 0, 0,
			controller->unk2060.x, 0);
	}
	if ((controller->manualCameraState & 2) != 0) {
		Layout::drawCellMain(
			9, data_ov053_0216e75c, 0, 0, 0, 0, 0, 0, 0,
			-controller->unk2060.x, 0);
	}

	MTX::setTranslation(Game_modelMatrix, controller->position);
	controller->worldModel.matrix = Game_modelMatrix;
	controller->worldModel.render(&controller->scale);
	worldMatrix = Game_modelMatrix;

	if (data_ov008_020ee388 != 0) {
		MTX::multiply(playerMatrix, Game_modelMatrix, Game_modelMatrix);
		if ((controller->unk20C8 & 1) == 0
			&& controller->unk20B0 != 0) {
			MTX::rotateY(Game_modelMatrix, s16(-0x8000));
		}
		playerMatrix = Game_modelMatrix;
		if (controller->playerDirection != 0xFF) {
			for (int index = 0; index < 9; index++) {
				playerMatrix.a[index] =
					data_ov008_020e96d0[
						controller->playerDirection].a[index];
			}
		}
		controller->playerModels[controller->luigiMode].render(
			&playerMatrix, &controller->playerPowerupScale);
	}

	int entity = 0;
	ModelAnm* entityCursor = controller->entityCursor;
	fx32* entityRenderPosition = &controller->entityRenderPos[0].x;
	for (; entity < 2;
		entityCursor++, entityRenderPosition += 4,
		entity++) {
		if (controller->entityDirs[entity] >= 0) {
			MTX::setTranslation(Game_modelMatrix, controller->position);
			controller->entityCursor[entity].matrix = Game_modelMatrix;
			entityCursor->render(&controller->scale);
			entityCursor->getNodeMatrix(
				0, &Game_modelMatrix);
			pointPosition.setFromMat4x3(Game_modelMatrix);
			MTX::multiply(
				Game_modelMatrix, worldMatrix, Game_modelMatrix);
			if (controller->entityDirs[entity] != 0) {
				MTX::rotateY(Game_modelMatrix, s16(-0x8000));
			}
			entityMatrixUnrotated = Game_modelMatrix;
			MTX::setTranslation(
				Game_modelMatrix,
				pointPosition);
			MTX::translate(
				Game_modelMatrix,
				controller->entityOffset[entity]);
			MTX::translate(
				Game_modelMatrix,
				controller->entityPosition[entity]);
			if (controller->entityNoRotY[entity] == 0
				|| WM::wxEntities[entity].type
					== WM::ET_FlyingBlock) {
				MTX::rotateY(
					Game_modelMatrix,
					controller->entityRotY[entity]);
				entityMatrix = Game_modelMatrix;
			} else {
				entityMatrix = Game_modelMatrix;
				entityMatrix.s.m00 = entityMatrixUnrotated.s.m00;
				entityMatrix.s.m01 = entityMatrixUnrotated.s.m01;
				entityMatrix.s.m02 = entityMatrixUnrotated.s.m02;
				entityMatrix.s.m10 = entityMatrixUnrotated.s.m10;
				entityMatrix.s.m11 = entityMatrixUnrotated.s.m11;
				entityMatrix.s.m12 = entityMatrixUnrotated.s.m12;
				entityMatrix.s.m20 = entityMatrixUnrotated.s.m20;
				entityMatrix.s.m21 = entityMatrixUnrotated.s.m21;
				entityMatrix.s.m22 = entityMatrixUnrotated.s.m22;
			}
			entityRenderPosition[0] = entityMatrix.s.m30;
			entityRenderPosition[1] = entityMatrix.s.m31;
			entityRenderPosition[2] = entityMatrix.s.m32;
			controller->entityModels[entity].render(
				entityMatrix,
				modelScale,
				controller->entityOffset[entity]);
		}
	}

	if (controller->treeModelFileID != 0) {
		controller->treeModel.render(worldMatrix, &controller->scale);
	}

	for (int node = 0; node < WM::wxNodeCount; node++) {
		if (u16(WM::wxNodes[node].flag & WM::NF_Course) != 0
			&& controller->nodeStates[node] != 4) {
			pointPosition.x = WM::wxPoints[node].x << 12;
			pointPosition.y = WM::wxPoints[node].y << 12;
			pointPosition.z = WM::wxPoints[node].z << 12;
			MTX::setTranslation(Game_modelMatrix, pointPosition);
			controller->nodeModels[
				controller->nodeStates[node]].render(
					Game_modelMatrix, &controller->scale);
		}
	}

	for (int sign = 0; sign < 5; sign++) {
		if (controller->signStates[sign] != 0) {
			MTX::setTranslation(
				Game_modelMatrix, controller->signPos[sign]);
			MTX::rotate(
				Game_modelMatrix, controller->signRot[sign]);
			controller->signModels[sign].render(
				Game_modelMatrix, &controller->scale);
		}
	}

	for (int house = 0; house < 8; house++) {
		if (controller->toadHouseStates[house] != 0) {
			MTX::setTranslation(
				Game_modelMatrix, controller->unk1FB0[house]);
			u32 node = WM::wxToadHouses[house].node;
			if (node != 0) {
				if ((controller->toadHouseStates[house]
					& ToadHouseState_Bit1) != 0) {
					controller->toadHouseModels[3].render(
						Game_modelMatrix, &controller->scale);
				}
				if ((controller->toadHouseStates[house]
					& ToadHouseState_Bit0) != 0) {
					u32 nodeType = WM::wxNodes[node].type;
					if (nodeType >= WM::NT_ToadHouseRed
						&& nodeType <= WM::NT_ToadHouseYellow) {
						if ((controller->toadHouseStates[house]
							& ToadHouseState_Bit2) != 0) {
							modelScale = controller->unk2030;
						} else {
							modelScale = controller->scale;
						}
						controller->toadHouseModels[
							nodeType
								- WM::NT_ToadHouseRed].render(
									Game_modelMatrix,
									&modelScale);
					}
				}
				if ((controller->toadHouseStates[house]
					& ToadHouseState_Bit5) != 0) {
					controller->toadHouseModels[4].render(
						Game_modelMatrix, &modelScale);
				}
			} else {
				if ((controller->toadHouseStates[house]
					& ToadHouseState_Bit0) != 0) {
					if ((controller->toadHouseStates[house]
						& ToadHouseState_Bit2) != 0) {
						modelScale = controller->unk2030;
					} else {
						modelScale = controller->scale;
					}
					controller->toadHouseModels[3].render(
						Game_modelMatrix, &modelScale);
					controller->toadHouseModels[
						u8(save.game.nodeStates[world][0]
							& 3)].render(
							Game_modelMatrix, &modelScale);
				}
			}
		}
	}

	for (int model = 0; model < 4; model++) {
		if ((controller->towerCastleModelFlags[model] & 1) != 0) {
			MTX::setTranslation(
				Game_modelMatrix, controller->unk1EE4[model]);
			controller->towerCastleModels[model].render(
				Game_modelMatrix, &controller->scale);
		}
	}

	if ((controller->bridgeFlags & BridgeFlag_Bit1) != 0) {
		MTX::setTranslation(
			Game_modelMatrix, controller->unk2040);
		controller->bridgeModel.render(
			Game_modelMatrix, &controller->scale);
	}
	return true;
}

extern "C" void func_ov008_020d81cc(WmController*) {}

extern "C" bool func_ov008_020d81d0(WmController*) {
	return true;
}

extern "C" u32 func_ov008_020d81d8(WmController* controller) {
	u32 world = save.game.currentWorld;
	u32 worldModelFileID = func_ov008_020ce214(world, 0);
	u32 cursorAnimFileID = func_ov008_020ce214(world, 1);
	controller->worldMatAnimFileID =
		func_ov008_020ce214(world, 2);
	controller->worldTexSRTFileID =
		func_ov008_020ce214(world, 3);
	controller->worldTexAnimFileID =
		func_ov008_020ce214(world, 4);
	controller->treeModelFileID =
		func_ov008_020ce214(world, 5);
	controller->treeBoneAnimFileID =
		func_ov008_020ce214(world, 6);
	controller->treeTexAnimFileID =
		func_ov008_020ce214(world, 7);
	controller->towerModelFileID =
		func_ov008_020ce214(world, 8);
	u32 towerAnimFileID = func_ov008_020ce214(world, 9);
	controller->castleModelFileID =
		func_ov008_020ce214(world, 10);
	u32 castleAnimFileID = func_ov008_020ce214(world, 11);

	if (!controller->worldModel.create(
		FS::Cache::getFile(worldModelFileID), 0, 0)) {
		return false;
	}
	if (controller->worldMatAnimFileID != 0
		&& !controller->worldMatAnim.createCtrl(
			&controller->worldModel.drawable,
			FS::Cache::getFile(controller->worldMatAnimFileID),
			0, 0)) {
		return false;
	}
	if (controller->worldTexSRTFileID != 0
		&& !controller->worldTexSRT.createCtrl(
			&controller->worldModel.drawable,
			FS::Cache::getFile(controller->worldTexSRTFileID),
			0, 0)) {
		return false;
	}
	if (controller->worldTexAnimFileID != 0
		&& !controller->worldTexAnim.createCtrl(
			&controller->worldModel.drawable,
			FS::Cache::getFile(controller->worldTexAnimFileID),
			0, controller->worldModel.texture)) {
		return false;
	}

	for (int player = 0; player < 2; player++) {
		if (!controller->playerModels[player].create(
			player, Game::getPlayerPowerup(0), 1)) {
			return false;
		}
	}

	if (!controller->playerCursor.create(
		FS::Cache::getFile(NSMB_FID_map_player_cursor_nsbmd),
		FS::Cache::getFile(cursorAnimFileID), 0, 0, 0)) {
		return false;
	}
	WmEntityModel* entityModel = controller->entityModels;
	ModelAnm* entityCursor = controller->entityCursor;
	for (int entity = 0; entity < 2;
		entity++, entityModel++, entityCursor++) {
		u32 entityType = WM::wxEntities[entity].type;
		controller->entityTypes[entity] = entityType;
		if (!entityModel->create(
			entityType)) {
			return false;
		}
		if (!entityCursor->create(
			FS::Cache::getFile(NSMB_FID_map_player_cursor_nsbmd),
			FS::Cache::getFile(cursorAnimFileID), 0, 0, 0)) {
			return false;
		}
	}

	if (controller->treeModelFileID != 0) {
		if (!controller->treeModel.create(
			FS::Cache::getFile(controller->treeModelFileID),
			0, 0)) {
			return false;
		}
		if (controller->treeBoneAnimFileID != 0
			&& !controller->treeBoneAnim.createCtrl(
				&controller->treeModel.drawable,
				FS::Cache::getFile(
					controller->treeBoneAnimFileID),
				0, 0)) {
			return false;
		}
		if (controller->treeTexAnimFileID != 0
			&& !controller->treeTexAnim.createCtrl(
				&controller->treeModel.drawable,
				FS::Cache::getFile(
					controller->treeTexAnimFileID),
				0, controller->treeModel.texture)) {
			return false;
		}
	}

	if (controller->towerModelFileID != 0) {
		ModelAnm* towerModel = controller->towerCastleModels;
		for (int model = 0; model < 2;
			model++, towerModel++) {
			if (!towerModel->create(
				FS::Cache::getFile(
					controller->towerModelFileID),
				FS::Cache::getFile(towerAnimFileID),
				0, 0, 0)) {
				return false;
			}
		}
	}
	if (controller->castleModelFileID != 0) {
		ModelAnm* castleModel =
			controller->towerCastleModels;
		castleModel += 2;
		for (int model = 2; model < 4;
			model++, castleModel++) {
			if (model == 3 && world == 7) {
				if (!castleModel->create(
					FS::Cache::getFile(
						NSMB_FID_map_w8_koppaC_nsbmd),
					FS::Cache::getFile(
						NSMB_FID_map_w8_koppaC_nsbca),
					0, 0, 0)) {
					return false;
				}
			} else if (!castleModel->create(
				FS::Cache::getFile(
					controller->castleModelFileID),
				FS::Cache::getFile(castleAnimFileID),
				0, 0, 0)) {
				return false;
			}
		}
	}

	Model* nodeModel = controller->nodeModels;
	int node = 0;
	AnimationCtrl* nodeTexAnim = controller->nodeTexAnims;
	for (; node < 4;
		node++, nodeModel++, nodeTexAnim++) {
		if (!nodeModel->create(
			FS::Cache::getFile(NSMB_FID_map_map_point_nsbmd),
			0, 0)) {
			return false;
		}
		if (!nodeTexAnim->createCtrl(
			&nodeModel->drawable,
			FS::Cache::getFile(NSMB_FID_map_map_point_nsbtp),
			node, controller->nodeModels[node].texture)) {
			return false;
		}
	}

	Model* signModel = controller->signModels;
	AnimationCtrl* signBoneAnim = controller->signBoneAnims;
	AnimationCtrl* signTexAnim = controller->signTexAnims;
	for (int sign = 0; sign < 5;
		sign++, signModel++, signBoneAnim++, signTexAnim++) {
		if (!signModel->create(
			FS::Cache::getFile(NSMB_FID_map_map_dragon_nsbmd),
			0, 0)) {
			return false;
		}
		if (!signBoneAnim->createCtrl(
			&signModel->drawable,
			FS::Cache::getFile(NSMB_FID_map_map_dragon_nsbca),
			0, 0)) {
			return false;
		}
		if (!signTexAnim->createCtrl(
			&signModel->drawable,
			FS::Cache::getFile(NSMB_FID_map_map_dragon_nsbtp),
			0, controller->signModels[sign].texture)) {
			return false;
		}
	}

	Model* toadHouseModel = controller->toadHouseModels;
	for (int house = 0; house < 4;
		house++, toadHouseModel++) {
		u32 fileID = func_ov008_020ce214(
			world, data_ov008_020e954c[house]);
		if (!toadHouseModel->create(
			FS::Cache::getFile(fileID), 0, 0)) {
			return false;
		}
	}
	if (world == 0
		&& !controller->toadHouseModels[4].create(
			FS::Cache::getFile(NSMB_FID_map_w1_kinoko_a_nsbmd),
			0, 0)) {
		return false;
	}

	if (!controller->windowModel.create(
		FS::Cache::getFile(NSMB_FID_map_window_nsbmd), 0, 0)) {
		return false;
	}
	controller->bridgeFlags = 0;
	if (world == 7) {
		if (!controller->bridgeModel.create(
			FS::Cache::getFile(NSMB_FID_map_w8_bridge_nsbmd),
			FS::Cache::getFile(NSMB_FID_map_w8_bridge_nsbca),
			0, 0, 0)) {
			return false;
		}
		controller->bridgeFlags = BridgeFlag_Bit0;
	}
	return true;
}

extern "C" u32 func_ov008_020d8a0c(WmController* controller) {
    u32 world = save.game.currentWorld;
    Ns3dStringData resourceName;
	if (!controller->prepareResourcesSafe(0, Memory_gameHeap)) {
		return false;
	}

	u32 currentNode = u8(save.game.currentWorldNode);
	controller->currentNode = save.game.currentWorldNode;
	controller->position.set(0);
	controller->rotation.x = 0;
	controller->rotation.y = 0;
	controller->rotation.z = 0;
	controller->scale.set(0x1000);
	controller->unk20E0 = 1;
	controller->unk1EC4.set(0x4400, 0x200, 0x10000);
	controller->unk1ED4.set(0x200, 0x8000, 0x1000);
	controller->unk2050.set(400, 400, 0x120);
	controller->unk22E0 = 0;
	controller->unk22E1 = 0;
	controller->unk22F0 = 0;
	controller->unk22E3 = 0;
	data_ov008_020ee3e8 = 0;
	controller->unk20E4 = 0;

	for (int emitter = 0; emitter < 2; emitter++) {
		controller->envEmitterIDs[emitter] = 0;
		controller->unk2228[emitter] =
			data_ov008_020e9638[world][emitter];
	}
	for (int flame = 0; flame < 2; flame++) {
		for (int emitter = 0; emitter < 3; emitter++) {
			controller->flamesEmitterIDs[flame][emitter] = 0;
		}
	}

	controller->playerDirection = 0;
	controller->musicPlayReq = 1;
	controller->treeMusicSyncStart = 0;
	controller->unk22F6 = 0;
	controller->unk2224 = 0;
	controller->unk22F7 = 0;
	controller->manualCameraState = 0;
	controller->unk2060.set(0x1000);
	controller->cameraScaleAngle = 0;
	controller->levelExit = 0;

	if (u16(WM::wxNodes[save.game.currentWorldNode].flag
			& (WM::NF_Tower | WM::NF_Castle
				| WM::NF_Tower2 | WM::NF_FinalCastle)) != 0
		&& (WM::state & WM::ST_CourseLeft) != 0) {
		controller->levelExit = 1;
		data_ov008_020ee388 = 0;
		u16 currentNodeFlags = WM::wxNodes[save.game.currentWorldNode].flag;
		if (u16(currentNodeFlags & WM::NF_Tower) != 0) {
			controller->exitInteractionType = 1;
		} else if (u16(currentNodeFlags & WM::NF_Castle) != 0) {
			controller->exitInteractionType = 2;
		} else if (u16(currentNodeFlags & WM::NF_Tower2) != 0) {
			controller->exitInteractionType = 3;
		} else if (u16(currentNodeFlags & WM::NF_FinalCastle) != 0) {
			controller->exitInteractionType = 4;
		}
	}

	s32 environmentParticle = data_ov008_020e9588[world];
	if (environmentParticle != -1) {
		func_02022b64(environmentParticle, &controller->position);
	}
	if ((data_02085acc.flags & Data02085acc_Bit4) != 0) {
		controller->unk22E3 = 4;
	}

	Ns_3dModelSetAllPolygonID(controller->windowModel.model, 14);
	if (controller->worldTexAnimFileID != 0) {
		controller->worldTexAnim.init(
			0, FrameCtrl::Looping, 0x1000, 0);
	}
	controller->sourceModel = &controller->worldModel;
	Ns_3dModelSetAllPolygonID(controller->worldModel.model, 3);
	controller->towerCastleModelFlags[0] = 3;
	controller->towerCastleModelFlags[1] = 4;
	controller->towerCastleModelFlags[2] = 3;
	controller->towerCastleModelFlags[3] = 3;
	controller->worldModel.setOwner(controller);
	controller->worldModel.setCommandCallback(
		func_ov008_020d24b0, nullptr, 0, 1);

	controller->luigiMode = Game::character;
	controller->playerModels[controller->luigiMode].init(0, false);
	fx32 powerupScale =
		data_ov008_020e956c[Game::getPlayerPowerup(0)];
	controller->playerPowerupScale.set(powerupScale);
	controller->playerPowerupMini = 0;
	if (Game::getPlayerPowerup(0) == WmPlayerModel::P_Shell) {
		controller->playerPowerupMini = 1;
	}

	controller->playerCursor.init(
		WM::wxPaths[
			WM::wxNodes[currentNode].links[0].path].animID,
		FrameCtrl::Standard, 0x1000, 0);
	controller->playerCursor.drawable.flags |= 4;
	controller->unk20B0 = 0;
	controller->playerCursorFrame = 0;
	if ((WM::wxNodes[currentNode].links[0].flag
		& WM::LF_Reverse) != 0) {
		controller->playerCursorFrame =
			controller->playerCursor.frameController.getFrameCount()
			<< 12;
	}
	controller->unk20C0 = 0x2E20;
	controller->unk20C8 = 0;
	controller->unk2204 = 0x10;
	controller->unk20C4 = 0xB00;

	u32 entitySpawns = 0;
	u32 tempScore = save.game.tempScore;
	for (int scorePart = 0; scorePart < 2; scorePart++) {
		if (tempScore >= 50000) {
			tempScore -= 50000;
			entitySpawns++;
		}
	}
	save.game.tempScore = tempScore % 50000;
	for (int entity = 0; entity < 2; entity++) {
		if (save.game.mapEntities[world][entity].node == 0xFF
			&& entitySpawns != 0) {
			entitySpawns--;
			u32 node = func_ov008_020da724();
			if (node != 0xFF) {
				save.game.mapEntities[world][entity].node = node;
			}
		}
	}

	for (int entity = 0; entity < 2; entity++) {
		u32 node = save.game.mapEntities[world][entity].node;
		u32 entityType = WM::wxEntities[entity].type;
		if (node == 0xFF) {
			controller->entityDirs[entity] = -1;
			continue;
		}

		controller->entityModels[entity].init(1);
		controller->entityCursor[entity].init(
			WM::wxPaths[
				WM::wxNodes[node].links[0].path].animID,
			FrameCtrl::Standard, 0x1000, 0);
		controller->entityCursor[entity].drawable.flags |= 4;
		controller->entityDirs[entity] = 0;
		controller->entityUnk2090[entity] = 0;
		controller->entityUnk20A0[entity] = 0;
		if ((WM::wxNodes[node].links[0].flag
			& WM::LF_Reverse) != 0) {
			controller->entityUnk20A0[entity] =
				controller->entityCursor[entity]
					.frameController.getFrameCount() << 12;
		}
		controller->entityUnk2098[entity] =
			controller->entityUnk20A0[entity];
		controller->entityNoRotY[entity] = 0;
		Vec3_32 entityPosition = func_ov008_020ce0e4(entityType);
		controller->entityPosition[entity] = entityPosition;
		controller->entityOffset[entity].set(0);
		if (entityType == WM::ET_HammerBro) {
			controller->entityUnk20A8[entity] = 0xC00;
			controller->entityRotY[entity] = 0x4000;
			controller->entityUnk2298[entity] = 0;
		} else {
			controller->entityRotY[entity] = 0;
			controller->entityUnk2298[entity] = 0x2000;
		}
	}

	save.game.actorRespawnWorld = save.game.currentWorld;
	controller->unk1E9C.x = 0;
	controller->unk1E9C.y = 0;
	controller->unk1E9C.z = 0;
	for (int unlock = 0; unlock < 4; unlock++) {
		u8 path = WM::wxPoints[0].transitPath(0, unlock);
		if (path == 0) {
			break;
		}
		if ((save.game.pathStates[world][path]
			& WM::PS_Unlocked) == 0) {
			save.game.pathStates[world][path] |=
				WM::PS_Unk40 | WM::PS_Unlocked;
		}
	}

	for (int house = 0; house < 8; house++) {
		controller->toadHouseStates[house] = 0;
	}
	controller->unk2030.set(0x1000);
	for (int house = 0; house < 8; house++) {
		u32 node = WM::wxToadHouses[house].node;
		if (node == u32(-1)) {
			break;
		}

		if (node == 0) {
			controller->unk22F1 = 0;
			if ((save.game.worldStates[world]
				& WM::WS_ArrowToadHouse) == 0) {
				if ((WM::state & WM::ST_Bit8) != 0
					&& (WM::wxNodes[save.game.currentWorldNode].flag
						& WM::NF_StarCoins) != 0) {
					u32 randomValue = data_02085aa0 % 100;
					u32 threshold = 11;
					for (int selection = 1;
						selection < 10;
						selection++, threshold += 11) {
						if (threshold == randomValue) {
							u8 houseType;
							if (selection < 4) {
								houseType = 0;
							} else if (selection < 7) {
								houseType = 1;
							} else {
								houseType = 2;
							}
							save.game.worldStates[world] |=
								WM::WS_ArrowToadHouse;
							save.game.nodeStates[world][0] =
								houseType;
							controller->toadHouseStates[house] =
								ToadHouseState_Bit0
								| ToadHouseState_Bit1
								| ToadHouseState_Bit2;
							controller->unk2030.set(0);
							controller->unk22F0 = 1;
							break;
						}
					}
				}
			} else if ((WM::state & WM::ST_Bit8) == 0
				|| currentNode != 0) {
				controller->toadHouseStates[house] =
					ToadHouseState_Bit0
					| ToadHouseState_Bit1
					| ToadHouseState_Bit3
					| ToadHouseState_Bit4;
			} else {
				controller->toadHouseStates[house] =
					ToadHouseState_Bit0
					| ToadHouseState_Bit1
					| ToadHouseState_Bit2
					| ToadHouseState_Bit3;
				controller->unk22E1 = 1;
				save.game.worldStates[world] &=
					~WM::WS_ArrowToadHouse;
			}
		} else if (WM::wxNodes[node].type
			== WM::NT_ToadHousePurple) {
			if ((save.game.completion
				& WM_SAVE_COMPLETION_BIT_5) != 0) {
				controller->toadHouseStates[house] =
					ToadHouseState_Bit1
					| ToadHouseState_Bit5;
				save.game.nodeStates[0][17] |=
					WM::NS_LevelDone | WM::NS_Completed;
				save.game.pathStates[0][21] |=
					WM::PS_Unk40 | WM::PS_Unlocked;
			}
		} else if ((save.game.completion
			& WM_SAVE_COMPLETION_BIT_0) == 0) {
			u8& nodeState = save.game.nodeStates[world][u8(node)];
			if ((nodeState & WM::NS_Completed) != 0) {
				if ((nodeState & WM::NS_LevelDone) == 0) {
					nodeState |= WM::NS_ToadHouseDone;
					controller->toadHouseStates[house] =
						ToadHouseState_Bit0
						| ToadHouseState_Bit1
						| ToadHouseState_Bit2;
					controller->unk22E1 = 1;
				} else {
					controller->toadHouseStates[house] =
						ToadHouseState_Bit1;
				}
			} else {
				controller->toadHouseStates[house] =
					ToadHouseState_Bit0
					| ToadHouseState_Bit1;
			}
		} else {
			controller->toadHouseStates[house] =
				ToadHouseState_Bit0 | ToadHouseState_Bit1;
		}

		controller->unk1FB0[house].set(
			WM::wxToadHouses[house].x,
			WM::wxToadHouses[house].y,
			WM::wxToadHouses[house].z);
	}

	controller->unk22EB = 0;
	controller->unk22FA = 1;
	for (int model = 0; model < 4; model++) {
		controller->towerCastleModelFlags[model] = 0;
	}
	for (int fort = 0; fort < 4; fort++) {
		u32 node = WM::wxForts[fort].node;
		if (node == u32(-1)) {
			break;
		}

		s32 model = -1;
		u32 nodeType = WM::wxNodes[node].type;
		if (nodeType == WM::NT_Tower
			&& controller->towerModelFileID != 0) {
			model = 0;
		} else if (nodeType == WM::NT_Tower2
			&& controller->towerModelFileID != 0) {
			model = 1;
		} else if (nodeType == WM::NT_Castle
			&& controller->castleModelFileID != 0) {
			model = 2;
		} else if (nodeType == WM::NT_FinalCastle
			&& controller->castleModelFileID != 0) {
			model = 3;
		}
		if (model < 0) {
			continue;
		}

		controller->towerCastleModelFlags[model] =
			TowerCastleModelFlag_Bit0;
		controller->unk1EE4[model].set(
			WM::wxForts[fort].x,
			WM::wxForts[fort].y,
			WM::wxForts[fort].z);
		u8 nodeState = save.game.nodeStates[world][u8(node)];
		if ((nodeState & WM::NS_Completed) == 0) {
			continue;
		}
		if ((nodeState & WM::NS_StandardExit) != 0) {
			controller->towerCastleModels[model].init(
				1, FrameCtrl::Looping, 0x1000, 0);
			controller->towerCastleModelFlags[model] |=
				TowerCastleModelFlag_Bit2
				| TowerCastleModelFlag_Bit6;
		} else if (u16(WM::wxNodes[currentNode].flag
				& (WM::NF_Tower | WM::NF_Castle
					| WM::NF_Tower2
					| WM::NF_FinalCastle)) != 0
			&& (WM::state & WM::ST_Bit8) != 0
			&& data_02085ac8 == 0) {
			controller->towerCastleModels[model].init(
				0, FrameCtrl::Standard, 0x1000, 0);
			controller->towerCastleModelFlags[model] |=
				TowerCastleModelFlag_Bit1
				| TowerCastleModelFlag_Bit5
				| TowerCastleModelFlag_Bit6;
			controller->unk22EB = 1;
			controller->unk22FA = 0;
			WM::state |= WM::ST_Bit9;
			controller->unk22E3 |= 0x10;
		}
	}

	if ((WM::state & WM::ST_Bit8) != 0
		&& data_02085ac8 == 0) {
		data_02088c4c[world][currentNode] |=
			WM::NS_StandardExit;
	}

	if ((controller->bridgeFlags & BridgeFlag_Bit0) != 0) {
		controller->unk2040.set(0x13C000, 0, 0);
		controller->bridgeModel.init(
			0, FrameCtrl::Standard, 0x1000, 0);
		if ((save.game.nodeStates[7][6]
			& WM::NS_LevelDone) != 0) {
			controller->bridgeModel.frameController.currentFrame =
				controller->bridgeModel.frameController
					.getFrameCount() << 12;
		}
		bool bridgeComplete =
			(save.game.nodeStates[7][6]
				& WM::NS_Completed) != 0;
		if (bridgeComplete) {
			controller->bridgeFlags |= BridgeFlag_Bit1;
		}
		func_0204d98c(bridgeComplete);
	}

	func_ov008_020d2694(controller, false);
	controller->unk22E2 = 0;
	for (int node = 0; node < WM::wxNodeCount; node++) {
		u8& nodeState = save.game.nodeStates[world][node];
		if ((nodeState & WM::NS_Completed) != 0
			&& (nodeState & WM::NS_LevelDone) == 0) {
			nodeState |= WM::NS_LevelDone;
			controller->unk22E2 = 1;
		}
	}

	func_ov008_020d21d0(controller, currentNode);
	if ((WM::state & WM::ST_Bit8) != 0
		&& (save.game.nodeStates[world][currentNode]
			& WM::NS_Completed) != 0) {
		for (int unlock = 0; unlock < 4; unlock++) {
			u8 path = WM::wxPoints[currentNode].transitPath(
				data_02085ac8, unlock);
			if (path == 0) {
				break;
			}
			if ((WM::wxPaths[path].flag & WM::PF_Sign) == 0
				&& (save.game.pathStates[world][path]
					& WM::PS_Unlocked) == 0) {
				save.game.pathStates[world][path] |=
					WM::PS_Unlocked;
				controller->unk22E0 = 1;
			}
		}
		if (controller->unk22E0 != 0) {
			controller->unk22F2 =
				WM::wxPoints[currentNode]
					.transitValues[data_02085ac8];
		}
	}

	for (int path = 0; path < 30; path++) {
		controller->pathMdlNodes[path] = -1;
	}
	for (int path = 0; path < WM::wxPathCount; path++) {
		for (int character = 0; character < 16; character++) {
			resourceName.c[character] = 0;
		}
		NDS::Text::format(
			resourceName.c, data_ov008_020e9880, path);
		s32 nodeIndex =
			controller->sourceModel->getNodeIndex(&resourceName);
		controller->pathMdlNodes[path] = nodeIndex;
		if (nodeIndex < 0) {
			continue;
		}

		u8& pathState = save.game.pathStates[world][u8(path)];
		if ((pathState & WM::PS_Unk40) != 0) {
			controller->pathMdlAlpha[path] = 30;
		} else if ((WM::wxPaths[path].flag
			& WM::PF_Unk1) != 0) {
			controller->pathMdlAlpha[path] = 0;
		} else {
			controller->pathMdlAlpha[path] = 8;
		}
		if ((pathState & WM::PS_Unlocked) != 0) {
			pathState |= WM::PS_Bit20;
			controller->unk22E0 = 1;
		}
	}

	for (int material = 0; material < 2; material++) {
		controller->materials[material] = -1;
		for (int candidate = 0; candidate < 2; candidate++) {
			for (int character = 0;
				character < 16; character++) {
				resourceName.c[character] = 0;
			}
			NDS::Text::copyString(
				resourceName.c,
				data_ov008_020e953c[material][candidate]);
			s32 materialIndex =
				controller->sourceModel->getMaterialIndex(
					&resourceName);
			if (materialIndex >= 0) {
				controller->materials[material] =
					materialIndex;
				break;
			}
		}
	}

	for (int sign = 0; sign < 5; sign++) {
		controller->signStates[sign] = 0;
	}
	for (int sign = 0; sign < 5; sign++) {
		u32 path = WM::wxSigns[sign].path;
		if (path == 0) {
			break;
		}
		if ((save.game.pathStates[world][u8(path)]
			& WM::PS_Unlocked) != 0) {
			continue;
		}
		controller->signStates[sign] = 1;
		controller->signPos[sign].set(
			WM::wxSigns[sign].x,
			WM::wxSigns[sign].y,
			WM::wxSigns[sign].z);
		controller->signRot[sign].x = -0xE38;
		controller->signRot[sign].y = 0;
		controller->signRot[sign].z = 0;
		controller->signBoneAnims[sign].init(
			0, FrameCtrl::Standard, 0x1000, 0);
		controller->signTexAnims[sign].init(
			0, FrameCtrl::Standard, 0x1000, 0);
		controller->signTexAnims[sign].setFrame(0);
	}

	if (func_ov008_020d2be4(controller) == 0
		&& func_ov008_020d2e00(controller) == 0
		&& func_ov008_020d2d40(controller) == 0
		&& func_ov008_020d2d7c(controller, 0) == 0
		&& func_ov008_020d2c90(controller) == 0
		&& func_ov008_020d2cf8(controller) == 0) {
		if (func_ov008_020d2cc8(controller) == 0) {
			controller->musicPlayReq = 1;
		}
		if (func_ov008_020d2c54(controller) == 0) {
			func_ov008_020d32c4(controller, WmController::Idle);
		}
	}

	if (controller->musicPlayReq == 0) {
		controller->unk2210 = 0;
		if (controller->treeModelFileID != 0) {
			controller->treeBoneAnim.init(
				0, FrameCtrl::Standard, 0x1000, 0);
		}
		if (controller->treeTexAnimFileID != 0) {
			controller->treeTexAnim.init(
				0, FrameCtrl::Standard, 0x1000, 0);
		}
	} else {
		controller->treeMusicSyncStart = 1;
	}

	data_02085acc.flags = 0;
	data_02085ac8 = 0;
	return true;
}

WmController::WmController() {}

WmController::~WmController() {}

s32 WmController::getEntityMoveIndex(u32 entityIdx, u32 moveIdx, u32 moveStep) {
	return (entityIdx * 12 + moveIdx) * 2 + moveStep;
}

void WmController::moveEntitiesOnce(u8* entityMoves, u32 entityIdx, u32 moveIdx, u8* moveTbl, u8* nodeTbl, u32* entityNodes, BOOL order) {

	u8 node = nodeTbl[moveIdx];
	if (node == 0xFF)
		return;

	if (order && isEntityAtNode(node, entityIdx, entityNodes))
		return;

	for (int s = 0; s < 2; s++) {
		entityMoves[s] = moveTbl[getEntityMoveIndex(entityIdx, moveIdx, s)];
	}

	entityNodes[entityIdx] = node;

}

void WmController::moveEntitiesLoop(u8* entityMoves, u32 entityIdx, u8* moveTbl, u8* nodeTbl, u32* entityNodes, BOOL order) {

	if (order) {

		for (int m = 0; m < 12; m++) {

			// Entity is already at this node, cancel this movement
			if (nodeTbl[m] != 0xFF && isEntityAtNode(nodeTbl[m], entityIdx, entityNodes))
				nodeTbl[m] = 0xFF;

		}

	}

	// Count number of moves
	int moveNum = 0;

	for (int m = 0; m < 12; m++) {

		if (nodeTbl[m] != 0xFF)
			moveNum++;

	}

	if (moveNum == 0)
		return;

	u32 random = Wifi::random();
	s32 randMove = (moveNum * (random & 0x7FFF)) >> 15;

	for (int m = 0; m < 12; m++) {

		if (nodeTbl[m] == 0xFF)
			continue;

		if (randMove > 0) {
			randMove--;
			continue;
		}

		moveEntitiesOnce(entityMoves, entityIdx, m, moveTbl, nodeTbl, entityNodes, false);
		return;

	}

}

void WmController::moveEntities() {

	// int linkA;
	// u32 uVar2;
	// //u8 *pNodeTbl;
	// //u32 entityNode;
	// int extraout_r1;
	// u8 *puVar3;
	// //u8 *pMoveTbl;
	// int i;
	// u32 moveCount;
	// u8(*pauVar4)[2];
	// int linkB;
	// NodeLink *nextLink;


	//__Work w;
	//NodeLink* w_link;
	//u32 w_world;
	//u32 w_a;
	//u32 w_n;
	u32 entityNodes[2];
	u32 buf4[2];
	u32 buf3[2];
	u8 moveTbl[2*12*2];
	u8 nodeTbl[2][12];
	//int g;

	NodeLink* nextLink; // 1
	int moveCount3 = 0;
	int mi2; // 2
	int mi; // 2
	//int moveCount; // # doesn't matter
	int e; // 3-4 (must be before 5)
	int g; // 5

	//s32* pb = buf3;

	NodeLink* w_link;
	u32 w_world = save.game.currentWorld;

	WM::state |= ST_EntityMove;

	u8* pm = moveTbl;
	u8* pn;

	for (pn = nodeTbl[0], e = 0; e < 2; pn += 12, e++) {

		for (moveCount3 = 0; moveCount3 < 12; moveCount3++) {

			for (int w = 0; w < 2; w++) {
				*pm = 0xff;
				pm++;
			}

			// int c = 0;
			// while (++c < 2) {
			// 	*pm = 0xff;
			// 	pm++;
			// };

			// for (u32 c = 0; c < 2;) {
			// 	c++;
			// 	*pm = 0xff;
			// 	pm++;
			// 	//moveTbl[(a*2*12) + (b*12) + c] = 0xff;
			// }

			//nodeTbl[e][f] = 0xff;
			pn[moveCount3] = 0xff;
			//p1 += 2;
			//nodeTbl[(a*12) + b] = 0xff;

		}

		for (moveCount3 = 0; moveCount3 < 2; moveCount3++) {
			entityStates[e][moveCount3] = 0xff;
		}

		buf3[e] = 0;
		//pn += 12;

	}

	//w_n = 1; // Does not need to exist!
	//pn = nodeTbl;
	//pm = moveTbl;

	for (pn = nodeTbl[0], e = 0; e < 2; pn += 12, e++) {
		/* u32 node = save.game.mapEntities[w_world][e].node;
		//entityNodes[e] = save.game.mapEntities[w_world][e].node;
		node = entityNodes[e] = node;
		//w_a = entityNodes[e];
		w_a = node;
		buf4[e] = node; */
		//w_a = buf4[e] = entityNodes[e] = save.game.mapEntities[w_world][e].node;
		u32 w_a = entityNodes[e] = save.game.mapEntities[w_world][e].node;
		buf4[e] = w_a;
		//w_a = tmp;
		//entityNodes[e] = w_a;
		//w_a = entityNodes[e];
		// u32 tmp = node;
		// w_a = entityNodes[e];
		/* entity exists (linked to a node) */

		if (w_a == 0xff) continue;

		moveCount3 = 0;
		w_link = WM::wxNodes[w_a].links;
		//int linkA = 0;
		/* iterate through all 4 possible links of the current node */
		for (int f = 0; f < 4; w_link++, f++) {
			if (w_link->node == 0xff)
				break;

			if (canEntityTransitLink(w_link) != 0) {
				/* entity cannot stop at this node, analyze next node's links */
				if (canEntityStopAtNode(w_link) != 0) {
					/* entity can stop at first node */
					moveTbl[getEntityMoveIndex(e, moveCount3, 0)] = f;
					pn[moveCount3] = w_link->node;
					moveCount3++;
				} else {

					nextLink = WM::wxNodes[w_link->node].links;
					for (mi = 0; mi < 4; nextLink++, mi++) {
						if (nextLink->node == 0xff)
							break;

						/* can transit link, can stop at node and target node isn't source node */
						if (canEntityTransitLink(nextLink) && canEntityStopAtNode(nextLink) && (nextLink->node != w_a)) {
							moveTbl[getEntityMoveIndex(e, moveCount3, 0)] = f;
							moveTbl[getEntityMoveIndex(e, moveCount3, 1)] = mi;
							pn[moveCount3] = nextLink->node;
							moveCount3++;
						}
					};
				}
			}
		}

		buf3[e] = moveCount3;
	}

	int q;

	if ((buf3[0] == 0) || (buf3[1] == 0)) {
		q = -1;
		for (e = 0; e < 2; e++) {
			if ((int)buf3[e] <= 0)
				continue;
			q = e;
			break;
		}
		if (q == -1) {
			return;
		}
		moveEntitiesLoop(entityStates[q], q, moveTbl, nodeTbl[q], buf4, 1);
		return;
	}

	if ((buf3[0] == 1) && (buf3[1] == 1)) {
		// linkA = 0;
		// //pMoveTbl = nodeTbl;
		// pauVar4 = this->entityStates;
		// do {
		// 	func_ov008_020db030(*pauVar4, linkA, 0, moveTbl, &moveTbl[linkA*12], buf4, (u32)(linkA != 0));
		// 	linkA += 1;
		// 	//pMoveTbl = pMoveTbl + 0xc;
		// 	pauVar4 = pauVar4 + 1;
		// } while (linkA < 2);
		//u8* pn = nodeTbl;
		//pm = entityStates[0];
		u8* pn = nodeTbl[0];
		for (e = 0; e < 2; e++) {
			moveEntitiesOnce(entityStates[e], e, 0, moveTbl, pn/* [e] */, buf4, (u32)(e != 0));
			//pm += 2;
			pn += 12;
		}
	} else {
		if ((buf3[0] == 1) || (buf3[1] == 1)) {
			q = -1;
			for (e = 0; e < 2; e++) {
				if (buf3[e] == 1) {
					q = e;
					break;
				}
			}
			moveEntitiesOnce(entityStates[q], q, 0, moveTbl, nodeTbl[q], buf4, 0);
			int r = q == 0 ? 1 : 0;
			moveEntitiesLoop(entityStates[r], r, moveTbl, nodeTbl[r], buf4, 1);
			return;
		}
		u8* pn = nodeTbl[0];
		for (e = 0; e < 2; e++) {
			moveEntitiesLoop(entityStates[e], e, moveTbl, pn/* [e] */, buf4, (u32)(e != 0));
			pn += 12;
		}
	}

}

extern "C" u32 func_ov008_020daa18(
	u32 world, WM::NodeLink* link) {
	if (func_ov008_020cda4c(
			world, link->node, WM::NF_Course) == 0) {
		return true;
	}
	if (func_ov008_020cda4c(
			world, link->node, WM::NF_StarCoins) == 0) {
		return false;
	}
	if (func_ov008_020cda4c(
			world, link->node, WM::NF_Castle) != 0
		|| func_ov008_020cda4c(
			world, link->node, WM::NF_FinalCastle) != 0) {
		return false;
	}
	return true;
}

extern "C" u32 func_ov008_020da9a4(
	u32 world, WM::NodeLink* link) {
	if ((link->flag & WM::LF_Pipe) != 0) {
		return false;
	}
	u8 pathState = save.game.pathStates[world][link->path];
	if (u8(pathState & WM::PS_Unk40) == 0
		&& func_ov008_020cda24(world, link->path, WM::PF_Unk1) != 0) {
		return false;
	}
	return func_ov008_020daa18(world, link);
}

extern "C" u32 func_ov008_020da7f4(
	u32 currentWorld, u32 destinationWorld, u32 node) {
	if (func_ov008_020cda4c(
			destinationWorld, node, WM::NF_StarCoins) == 0
		|| func_ov008_020cda4c(
			destinationWorld, node, WM::NF_Castle) != 0
		|| func_ov008_020cda4c(
			destinationWorld, node, WM::NF_FinalCastle) != 0) {
		return false;
	}
	if (destinationWorld == 7
		&& u8(save.game.nodeStates[destinationWorld][6]
			& WM::NS_Completed) == 0) {
		for (const u8* excludedNode = data_ov008_020e2e3c;
			excludedNode < data_ov008_020e2e41;
			excludedNode++) {
			if (*excludedNode == node) {
				return false;
			}
		}
	}
	bool occupied = false;
	int entity = 0;
	do {
		if (node ==
			save.game.mapEntities[destinationWorld][entity].node) {
			occupied = true;
			break;
		}
		entity++;
	} while (entity < 2);
	if (occupied) {
		return false;
	}
	if (currentWorld == destinationWorld) {
		s32 distance =
			(WM::wxPoints[node].x << 12) - data_ov008_020ee3c4;
		if (distance < 0) {
			distance = -distance;
		}
		if (distance < 0xC0000) {
			return false;
		}
	}
	WM::NodeLink* link =
		func_ov008_020cda94(destinationWorld, node);
	int validLinks = 0;
	for (u32 linkIndex = 0; linkIndex < 4; linkIndex++, link++) {
		if (link->node == 0xFF) {
			break;
		}
		if (func_ov008_020da9a4(destinationWorld, link) != 0) {
			validLinks++;
		}
	}
	if (validLinks == 0) {
		return false;
	}
	return true;
}

extern "C" u32 func_ov008_020da730() {
	u32 currentWorld = u8(save.game.currentWorld);
	u32 destinationWorld = u8(save.game.actorRespawnWorld);
	u32 validNodes;
	u32 validNodeCount;
	u32 nodeCount = func_ov008_020cda7c(destinationWorld);
	validNodes = 0;
	validNodeCount = 0;
	for (u32 node = 0; node < nodeCount; node++) {
		if (func_ov008_020da7f4(
				currentWorld, destinationWorld, node) != 0) {
			validNodes |= 1 << node;
			validNodeCount++;
		}
	}
	if (validNodeCount != 0) {
		u32 random = Wifi::random();
		u32 selectedNode =
			validNodeCount * (random & 0x7FFF) >> 15;
		u32 validNode = 0;
		for (u32 node = 0; node < nodeCount; node++) {
			if (((validNodes >> node) & 1) != 0) {
				if (selectedNode == validNode) {
					return u8(node);
				}
				validNode++;
			}
		}
	}
	return 0xFF;
}

extern "C" u32 func_ov008_020da724() {
	return func_ov008_020da730();
}

bool WmController::isEntityAtNode(u8 node, u32 entityIdx, u32* entityNodes) {

	for (int e = 0; e < 2; e++) {

		if (e == entityIdx)
			continue;

		if (entityNodes[e] == node)
			return true;

	}

	return false;

}

bool WmController::canEntityTransitLink(WM::NodeLink* link) {

	if (link->flag & LF_Pipe)
		return false;

	u8 ps = save.game.pathStates[save.game.currentWorld][link->path];
	if (u8(ps & PS_Unk40) == 0 && u8(wxPaths[link->path].flag & PF_Unk1))
		return false;

	return true;

}

bool WmController::canEntityStopAtNode(WM::NodeLink* link) {

	u16 flag = wxNodes[link->node].flag;

	if (u16(flag & NF_Course) == 0)
		return false;

	if (u16(flag & NF_StarCoins) == 0)
		return false;

	if (u16(flag & NF_Castle) || u16(flag & NF_FinalCastle))
		return false;

	return true;

}


void* WmController::create() {
	return new WmController();
}
