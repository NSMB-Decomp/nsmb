#include "StageEntity.hpp"
#include <nsmb/arm9/symbols.hpp>
#include <nsmb/overlays/ov000/symbols.hpp>
#include <nsmb/overlays/ov010/symbols.hpp>
#include <nsmb/overlays/ov054/symbols.hpp>
#include "Player/PlayerActor.hpp"









































i16 data_ov000_020c1f44[2];
bool StageEntity::updateCarried() {




  if (linked_player == (-1))
  {
    return true;
  }
PlayerBase *player =
		static_cast<PlayerBase *>(Game::getPlayer(linked_player));



  tryAttachToPlayerHands(0x4000, -0x2000, 0);
  if (carriedAction & 1)
  {
    _16();
    Vec3_32 *playerVelocity = &player->velocity;
    if (carriedAction & 2)
    {

      u8 playerVelocityDirection;
      fx32 throwX;
      direction = playerDirection;
      rotation.y = directionalRotationY[direction];
      fx32 halfPlayerVelocity = playerVelocity->x >> 1;
      if ((object_id == 0x23) || (object_id == 0xed))
      {
        throwX = data_ov000_020c1f44[direction];
      }
      else
      {
        throwX = data_ov000_020c1f40[direction];
      }
      playerVelocityDirection = (((u32) player->velocity.x) & 0x80000000) >> 31;
      if (direction == playerVelocityDirection)
      {
        throwX += halfPlayerVelocity;
      }
      if (throwX < minVelocity.x)
      {
throwX =
					Math::min(throwX, minVelocity.x);



      }
      else
        if (throwX > minVelocity.x)
      {
throwX =
					Math::max(throwX, minVelocity.x);



      }

      velocity.set(throwX, releaseForceY, 0);
      if (updateCarriedCollision())
      {
        activeCollider.unlink();
        func_02012398(0x70, &position);
        getScorePointsRegular(1, 0, 0x18000, player->linked_player);
        defeat(0, 0x3000, -0x300, 0);
        _11();
        return true;
      }
      if ((collisionMgr.flags & (0x15 << direction)) == 0)
      {
        position.x += unitDirection[direction] * 0x6000;
      }
      accelV = -0x300;
      thrownFlag = 1;
    }
    else
    {
      direction = playerDirection;
      rotation.y = directionalRotationY[direction];
      fx32 releaseVelocity;
      if (object_id == 0x23)
      {
        releaseVelocity = unitDirection[direction] * 0x600;
      }
      else
      {
        releaseVelocity = unitDirection[direction] * data_ov000_020c1f9c[releaseMode];
      }
      velocity.x = releaseVelocity;
      velocity.y = 0;
      velocity.z = 0;
      if (updateCarriedCollision())
      {
        activeCollider.unlink();
        func_02012398(0x70, &position);
        getScorePointsRegular(1, 0, 0x18000, player->linked_player);
        defeat(0, 0x3000, -0x300, 0);
        _11();
        return true;
      }
      if ((collisionMgr.flags & (0x15 << direction)) == 0)
      {
        position.x += unitDirection[direction] * 0x6000;
      }
      position.y += 0x2000;
      accelV = -0x300;
      thrownFlag = 0;
    }
    if (checkSquished())
    {
      getScorePointsRegular(1, 0, 0x18000, player->linked_player);
      _35();
      return true;
    }
    minVelocity.x = unitDirection[direction] * 0x6000;
    minVelocity.y = -0x4000;
    minVelocity.z = 0;
    carriedAction &= ~2;
    carriedAction &= ~1;
    if (releaseMode == 0)
    {
      updateStateID = 6;
    }
    else
      if (releaseMode == 1)
    {
      updateStateID = 7;
    }
    else
    {
      updateStateID = 8;
    }
    linked_player = player->linked_player;
    _12();
  }
  updateLiquids(-0x300);
  _11();
  return true;
}
