#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

extern "C" int luaopen_SDL2_cpuinfo(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Functions */

	luaL_Reg regs [] =
	{
	REG(GetCPUCacheLineSize)
	REG(GetCPUCount)
	#if SDL_VERSION_ATLEAST(2, 0, 1)
	REG(GetSystemRAM)
	#endif
	REG(Has3DNow)
	#if SDL_VERSION_ATLEAST(2, 0, 2)
	REG(HasAVX)
	#endif
	#if SDL_VERSION_ATLEAST(2, 0, 4)
	REG(HasAVX2)
	#endif
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

	/* Done */

	return 0;
}

