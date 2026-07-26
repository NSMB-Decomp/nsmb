#pragma once
#include "../Bases/Actor.hpp"
#include "../Vec.hpp"

class StageActor;
class ActiveCollider;

typedef void(*AcCallback)(ActiveCollider&, ActiveCollider&);

enum AcGroup {
	AC_GRP_Player,			// Player.
	AC_GRP_PlayerSpecial,	// Player sliding, slamming a fence, mega mushroom.
	AC_GRP_Group2,			// These two were probably planned for separated Player 2 groups.
	AC_GRP_Group3,			// ^^^
	AC_GRP_Entity,			// Koopa, Goomba, Trampoline, Thwomp, Bumper, etc...
	AC_GRP_Chasing,			// Lakitu, (Fire) Piranha Plant, Spike Bass, Flame Chomp, Fire Snake, Big Cheep Cheep, Cheep Cheep, Blooper, Chain Chomp, Cheep Skipper.
	AC_GRP_Item,			// Items, Star Coin, Boss Key, VS Battle Star, 'Lakithunder Effects'??
	AC_GRP_Fireball,		// Fireball
	AC_GRP_Bullet,			// Bullet Bill/Banzai Bill
	AC_GRP_Debris,			// Volcano Debris
	AC_GRP_MAX
};

/*
	Notes about AcGroup 5 ('Chasing', previously 'Hostile')

 	Used by spawnable enemies (coincidence?) OR enemies that spawn something (targeted projectiles).
	They do have something in common though, they all try to attack the player:
	- Some follow the player (blooper, flame chomp, cheep cheep variations, fire snake)
	- Some attack him directly (lakitu, chain chomp, piranha plants, boss bass, cheep skipper)

*/

enum AcAttack {
	AC_ATK_None,
	AC_ATK_Fireball,		// fireball
	AC_ATK_Flag2,			// checked by castle enemies (Thwomp, Dry Bones, FireBar, Podoboo), Boo, fish enemies and possibly other stuff
	AC_ATK_Flag3,
	AC_ATK_Flag4,
	AC_ATK_Sliding,			// player sliding
	AC_ATK_Flag6,
	AC_ATK_Flag7,
	AC_ATK_Flag8,
	AC_ATK_SlamFence,		// player slamming a fence
	AC_ATK_EntityAsWeapon,	// EAW: snowball, spiked ball, held/thrown entities, exploding bob-omb, etc
	AC_ATK_Flag11,
	AC_ATK_Flag12,
	AC_ATK_Flag13,
	AC_ATK_Flag14,
	AC_ATK_Flag15,
	AC_ATK_MAX
};

struct AcConfig {

	enum Option {
		FastIntersection = 0x0001,		// Skips intersection distance/point calculations (Rect only).
		Unknown2 = 0x0002,
		BypassDamage = 0x8000			// Entity As Weapons (EAW, such as entities held, shells thrown or Bob-Ombs exploding) will not deal damage on the entity that has this option set.
	};


	FxRect rect;
	u8 group;							// Group that the ActiveCollider will resemble.
	u8 attack;							// Attack that the ActiveCollider will perform.
	u16 detectGroups;					// Groups that the ActiveCollider will react to.
	u16 detectAttacks;					// Attacks that the ActiveCollider will respond to.
	u16 options;						// Various options for intersection and response configuration.
	AcCallback callback;

};
NTR_SIZE_GUARD(AcConfig, 0x1C);

class ActiveCollider {
public:

	enum Shape {
		S_Rectangle,
		S_Round,
		S_TrapezoidH,
		S_TrapezoidV,
		S_MAX
	};

	enum Layer {
		L_Ignored = 0xFF,
		L_Front = 0,
		L_Back
	};

	enum CollisionFlags {
		CF_Active = 0x01,
		CF_Passive = 0x02
	};

	enum CollisionState {
		CS_IgnoreCollision = 0x01,
		CS_Collided = 0x02
	};


	Actor* owner;
	u16 _8;
	u16	_a;
	ActiveCollider * prev;
	ActiveCollider * next;
	FxRect rect;
	u8 group;
	u8 attack;
	u16 detectGroups;
	u16 detectAttacks;
	u16 options;
	void *callback;
	Vec2_32 position;
	fx32 intersectionDistX[AC_GRP_MAX];
	fx32 intersectionDistY[AC_GRP_MAX];
	u8 _pad_8c[0x10];
	u32 collisionData;
	u16 collidedGroups;
	u16 flags;
	u8 _a4;
	u8 _a5;
	u8 collisionState;
	s8 collidedPlayerID;
	u8 _pad_a8[8];

	ActiveCollider();
	virtual ~ActiveCollider();

	void init(StageActor* owner, const AcConfig& config, u8 layerID = L_Front);

	bool resetCollisionState();
	void link();
	void unlink();
};
NTR_SIZE_GUARD(ActiveCollider, 0xb0);
NTR_OFFSET_GUARD(ActiveCollider, group, 0x24);
NTR_OFFSET_GUARD(ActiveCollider, detectAttacks, 0x28);
NTR_OFFSET_GUARD(ActiveCollider, callback, 0x2c);
NTR_OFFSET_GUARD(ActiveCollider, position, 0x30);
NTR_OFFSET_GUARD(ActiveCollider, intersectionDistX, 0x3c);
NTR_OFFSET_GUARD(ActiveCollider, intersectionDistY, 0x64);
NTR_OFFSET_GUARD(ActiveCollider, collisionData, 0x9c);
NTR_OFFSET_GUARD(ActiveCollider, collidedGroups, 0xa0);
NTR_OFFSET_GUARD(ActiveCollider, flags, 0xa2);
NTR_OFFSET_GUARD(ActiveCollider, collisionState, 0xa6);
NTR_OFFSET_GUARD(ActiveCollider, collidedPlayerID, 0xa7);
