#include "SDL.hpp"

extern "C" int luaopen_SDL_cpuinfo(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
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
