#include "Scene.hpp"
#include <nsmb/core/net/packet.hpp>
#include <nsmb/game/connect/status_display.hpp>

class ConnectScene : public Scene
{
      public:
	ConnectionStatusDisplay connectionStatus;
	Net::PacketBuffer packetBuffer;
	s32 connectionSubstate;
	s32 connectionTimer;
	u8 syncedAidMask;
	u8 reserved_105_107[3];

	inline ConnectScene();
	~ConnectScene();
	static void *create();

	static ObjectProfile profile;

	virtual s32 onCreate();
	virtual s32 onDestroy();
	virtual s32 onUpdate();
	virtual s32 onRender();
	static void func_020037e4(u32);
	static void func_020037b4();
	static void func_0200379c(u32, u32);
	void func_02003250(u32, u32);
	void func_02003580();
};
NITRO_SIZE_ASSERT(ConnectScene, 0x108);
NTR_OFFSET_GUARD(ConnectScene, connectionStatus, 0x64);
NTR_OFFSET_GUARD(ConnectScene, packetBuffer, 0xe4);
NTR_OFFSET_GUARD(ConnectScene, connectionSubstate, 0xfc);
NTR_OFFSET_GUARD(ConnectScene, connectionTimer, 0x100);
NTR_OFFSET_GUARD(ConnectScene, syncedAidMask, 0x104);
