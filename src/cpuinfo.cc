#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

extern "C" int luaopen_SDL_cpuinfo(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}
	luaL_Reg regs [] =
	{
	REG(GetCPUCacheLineSize)
	REG(GetCPUCount)
	REG(GetSystemRAM)
	REG(Has3DNow)
	REG(HasAVX)
//	REG(HasAVX2)
	REG(HasAltiVec)
	REG(HasMMX)
	REG(HasRDTSC)
	REG(HasSSE)
	REG(HasSSE2)
	REG(HasSSE3)
	REG(HasSSE41)
	REG(HasSSE42)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

