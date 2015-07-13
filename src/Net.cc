#include "SDL.hpp"
#include <SDL2/SDL_net.h>

template <> luaL_Reg lux_Union<IPaddress>::index[] =
{
	lux_index(IPaddress, host),
	lux_index(IPaddress, port)
};

template <> luaL_Reg lux_Union<UDPpacket>::index[] =
{
	lux_index(UDPpacket, channel),
	lux_index(UDPpacket, data),
	lux_index(UDPpacket, len),
	lux_index(UDPpacket, maxlen),
	lux_index(UDPpacket, status),
	lux_subindex(UDPpacket, address)
};

#define REG(name) {#name, lux_cast(SDLNet_##name)},
#define END {nullptr, nullptr}

extern "C" int luaopen_Net(lua_State *state)
{
	if (SDLNet_Init())
	{
		const char *error = SDLNet_GetError();
		return luaL_error(state, "SDLNet_Init: %s", error);
	}
	else atexit(SDLNet_Quit);

	luaL_newmetatable(state, NET_METATABLE);
	lux_newtype<IPaddress*>(state, "IPaddress");
	lux_newtype<TCPsocket>(state, "TCPsocket");
	lux_newtype<UDPsocket>(state, "UDPsocket");
	lux_newtype<UDPpacket*>(state, "UDPpacket");
	lux_newtype<UDPpacket**>(state, "UDPpacketV");
	lux_newtype<SDLNet_SocketSet>(state, "SocketSet");
	lux_newtype<SDLNet_GenericSocket>(state, "GenericSocket");
	struct {
	 const char *name;
	 lua_Integer value;
	}
	args [] =
	{
	{"INADDR_ANY", INADDR_ANY},
	{"INADDR_NONE", INADDR_NONE},
	{"INADDR_LOOPBACK", INADDR_LOOPBACK},
	{"INADDR_BROADCAST", INADDR_BROADCAST},
	{nullptr, 0}
	};
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
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

