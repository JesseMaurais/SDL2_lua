#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

static int GetPlatform(lua_State *state)
{
	const char *string = SDL_GetPlatform();
	lua_pushstring(state, string);
	return 1;
}

extern "C" int luaopen_SDL2_platform(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Functions */

	luaL_Reg regs[] =
	{
	{"GetPlatform", GetPlatform},
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Done */

	return 0;
}

