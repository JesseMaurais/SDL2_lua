#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"
 
static int GetRevision(lua_State *state)
{
	const char *string = SDL_GetRevision();
	lua_pushstring(state, string);
	return 1;
}

static int GetVersion(lua_State *state)
{
	SDL_version lib;
	SDL_GetVersion(&lib);
	return lux_push(state, lib.major, lib.minor, lib.patch);
}

extern "C" int luaopen_SDL_version(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}
	luaL_Reg regs [] =
	{
	{"GetRevision", GetRevision},
	{"GetRevisionNumber", lux_cast(SDL_GetRevisionNumber)},
	{"GetVersion", GetVersion},
	{nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

