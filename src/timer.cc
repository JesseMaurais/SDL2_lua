#include "SDL.hpp"

extern "C" int luaopen_SDL_timer(lua_State *state)
{
	luaL_getmetatable(state, SDL_METATABLE);
	luaL_Reg regs [] =
	{
//	 {"AddTimer", lux_cast(SDL_AddTimer)},
	 {"Delay", lux_cast(SDL_Delay)},
//	 {"GetPerformanceCounter", lux_cast(SDL_GetPerformanceCounter)},
//	 {"GetPerformanceFrequency", lux_cast(SDL_GetPerformanceFrequency)},
	 {"GetTicks", lux_cast(SDL_GetTicks)},
	 {"RemoveTimer", lux_cast(SDL_RemoveTimer)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

