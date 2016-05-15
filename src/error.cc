#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

static int SetError(lua_State *state)
{
	const char *string = luaL_checkstring(state, 1);
	int result = SDL_SetError("%s", string);
	lua_pushinteger(state, result);
	return 1;
}

static int GetError(lua_State *state)
{
	const char *string = SDL_GetError();
	lua_pushstring(state, string);
	return 1;
}

extern "C" int luaopen_SDL2_error(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Functions */

	luaL_Reg regs [] =
	{
	{"SetError", SetError},
	REG(ClearError)
	{"GetError", GetError},
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Done */

	return 0;
}

