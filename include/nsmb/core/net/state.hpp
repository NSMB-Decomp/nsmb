#pragma once

#include "../../../../src/base_types.hpp"

struct NicknameInfo;

namespace Net {

extern u8 connectionState;
extern u16 errorState;

BOOL assert(BOOL condition);

void acceptChildren();
u8 *getParentBssid(u32 aid);
NicknameInfo *getParentGameInfo(u32 aid);
void startMultiBootTransfer();

}
