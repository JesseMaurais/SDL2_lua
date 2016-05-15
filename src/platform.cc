#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

extern "C" int luaopen_SDL2_platform(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Functions */

	luaL_Reg regs[] =
	{
	REG(GetPlatform)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Done */

	return 0;
}

