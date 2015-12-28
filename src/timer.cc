#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

extern "C" int luaopen_SDL_timer(lua_State *state)
{
	// Get the module's metatable
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}
	// Timer subsystem initialization
	if (SDL_InitSubSystem(SDL_INIT_TIMER) < 0)
	{
		auto error = SDL_GetError();
		return luaL_error(state, "SDL_InitSubSystem: %s", error);
	}
	// Register functions for timer
	luaL_Reg regs [] =
	{
	//REG(AddTimer)
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
