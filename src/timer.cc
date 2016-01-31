#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

extern "C" int luaopen_SDL_timer(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Initialize */

	if (SDL_InitSubSystem(SDL_INIT_TIMER) < 0)
	{
		auto error = SDL_GetError();
		return luaL_error(state, "SDL_InitSubSystem: %s", error);
	}

	/* Functions */

	luaL_Reg regs [] =
	{
//	REG(AddTimer)
	REG(Delay)
	REG(GetPerformanceCounter)
	REG(GetPerformanceFrequency)
	REG(GetTicks)
	REG(RemoveTimer)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Done */

	return 0;
}
