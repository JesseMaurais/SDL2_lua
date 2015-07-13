#include "SDL.hpp"

extern "C" int luaopen_SDL_cpuinfo(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	luaL_Reg regs [] =
	{
	{"GetCPUCacheLineSize", lux_cast(SDL_GetCPUCacheLineSize)},
	{"GetCPUCount", lux_cast(SDL_GetCPUCount)},
	{"GetSystemRAM", lux_cast(SDL_GetSystemRAM)},
	{"Has3DNow", lux_cast(SDL_Has3DNow)},
	{"HasAVX", lux_cast(SDL_HasAVX)},
//	{"HasAVX2", lux_cast(SDL_HasAVX2)},
	{"HasAltiVec", lux_cast(SDL_HasAltiVec)},
	{"HasMMX", lux_cast(SDL_HasMMX)},
	{"HasRDTSC", lux_cast(SDL_HasRDTSC)},
	{"HasSSE", lux_cast(SDL_HasSSE)},
	{"HasSSE2", lux_cast(SDL_HasSSE2)},
	{"HasSSE3", lux_cast(SDL_HasSSE3)},
	{"HasSSE41", lux_cast(SDL_HasSSE41)},
	{"HasSSE42", lux_cast(SDL_HasSSE42)},
	{nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}
