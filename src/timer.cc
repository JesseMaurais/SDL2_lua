#include "SDL.hpp"

extern "C" int luaopen_SDL_timer(lua_State *state)
{
	luaL_getmetatable(state, SDL_METATABLE);
	luaL_Reg regs [] =
	{
//	REG(AddTimer", lux_cast(SDL_AddTimer)},
	REG(Delay)
	REG(GetPerformanceCounter)
	REG(GetPerformanceFrequency)
	REG(GetTicks)
	REG(RemoveTimer)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

