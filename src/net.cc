#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>
#include "Common.h"

#undef REG
#define REG(name) {#name, lux_cast(SDLNet_##name)},

extern "C" int luaopen_SDL_net(lua_State *state)
{
	if (SDLNet_Init() < 0)
	{
		const char *error = SDLNet_GetError();
		return luaL_error(state, "SDLNet_Init: %s", error);
	}
	else
	if (atexit(SDLNet_Quit))
	{
		return luaL_error(state, "Cannot make exit (atexit < 0)");
	}
	luaL_newmetatable(state, "SDL2_net");
	lux_Reg<lua_Integer> args[] =
	{
	{"INADDR_ANY", INADDR_ANY},
	{"INADDR_NONE", INADDR_NONE},
	{"INADDR_LOOPBACK", INADDR_LOOPBACK},
	{"INADDR_BROADCAST", INADDR_BROADCAST},
	{nullptr, 0}
	};
	lux_settable(state, args);
	luaL_Reg regs [] =
	{
	REG(ResolveHost)
	REG(ResolveIP)
	REG(GetLocalAddresses)
	REG(TCP_Open)
	REG(TCP_Accept)
	REG(TCP_GetPeerAddress)
	REG(TCP_Send)
	REG(TCP_Recv)
	REG(TCP_Close)
	REG(AllocPacket)
	REG(ResizePacket)
	REG(FreePacket)
	REG(AllocPacketV)
	REG(FreePacketV)
	REG(UDP_Open)
	REG(UDP_SetPacketLoss)
	REG(UDP_Bind)
	REG(UDP_Unbind)
	REG(UDP_GetPeerAddress)
	REG(UDP_SendV)
	REG(UDP_Send)
	REG(UDP_RecvV)
	REG(UDP_Recv)
	REG(UDP_Close)
	REG(AllocSocketSet)
	REG(AddSocket)
	REG(TCP_AddSocket)
	REG(UDP_AddSocket)
	REG(DelSocket)
	REG(TCP_DelSocket)
	REG(UDP_DelSocket)
	REG(CheckSockets)
	REG(FreeSocketSet)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

