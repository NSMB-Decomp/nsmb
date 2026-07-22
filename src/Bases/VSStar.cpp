#include "VSStar.hpp"
#include <nsmb/arm9/symbols.hpp>
#include <nsmb/overlays/ov010/symbols.hpp>
#include "Player/PlayerActor.hpp"

void *VsStar::create()
{
	return new VsStar();
}

bool VsStar::func_ov020_02132660(u32)
{
}

void VsStar::func_ov020_02132618()
{
}

//void VsStar::func_ov020_02132510()
//{
//}

void VsStar::damagePlayer(ActiveCollider *collider, PlayerBase *player)
{
	if ((collider->_8 + 0x4e4) == 0) {
		collider->_1c0 = 1;
		this->func_ov020_02132510(player, (void*)player->linked_player);
	}
}

void VsStar::_24()
{
}

void VsStar::_26()
{
	return VsStar::_24();
}

void VsStar::_27()
{
	return VsStar::_24();
}

void VsStar::_30()
{
	return VsStar::_24();
}

void VsStar::_25()
{
	return VsStar::_24();
}

void VsStar::_31()
{
	return VsStar::_24();
}

void VsStar::_21()
{
}

void VsStar::func_ov020_0213238c()
{
}

bool VsStar::func_ov020_021322a4()
{
}

void VsStar::func_ov020_021320dc(u32)
{
}

bool VsStar::func_ov020_0213203c()
{
}

bool VsStar::func_ov020_02131f7c()
{
}

bool VsStar::func_ov020_02131c54()
{
}

void VsStar::func_ov020_02131bbc()
{
	u8 direction;

	if (this->setting_1 != 0) {
		this->setting_1 -= 1;
		direction = this->direction ^ 1;
		if ((this->setting_1 & 1) == 0) {
			direction = this->direction;
		}
		PlayerActor *player = (PlayerActor*)Game::getPlayer(this->_4cc);
		Vec3_32* pos1 = &player->position;
		Vec3_32 position;
		position.x = pos1->x;
		position.y = pos1->y;
		position.z = pos1->z;
		Actor::spawnActor(0x22, direction << 0x1f | 3, &position, 0, 0, 0);
		return;
	}
	return;
}

s32 VsStar::onCreate()
{
	u32 settings = this->settings;
	this->setting_0 = READ_NIBBLE(settings, 0);
	this->setting_1 = READ_NIBBLE(settings, 1);
	return true;
}

bool VsStar::onUpdate_0()
{
}

s32 VsStar::onRender()
{
	if (data_02085a84 != 0) {
		if (this->_4e2 != 0) {
			return true;
		}
		u32 a = 0;
		if (this->_3ea != 0) {
			a = 0x20;
		}
		Vec2_32 scale;
		scale.x = this->scale.x;
		scale.y = this->scale.y;
		Vec3_32 position = this->position;
		Vec3_16 rotation = this->rotation;
		Actor::wrapPosition((u32)&position, (u32)&rotation, 1);
		drawSprite(DAT_02039200, position.x, position.y + 0x10000, a, 0, 3, &scale, (u32)&rotation, 0, 0);
	}
}

s32 VsStar::onDestroy()
{
	if (this->setting_0 == 1) {
		func_ov010_020f9d64(&this->field_0x47c);
	}
	return true;
}

VsStar::~VsStar()
{
}
