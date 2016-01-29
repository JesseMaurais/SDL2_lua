#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

static void LogOutputFunction(void *user, int category, SDL_LogPriority priority, const char *message)
{
	auto state = reinterpret_cast<lua_State*>(user);
	lua_pushintegr(state, category)
	lux_push(state, priority);
	lua_pushstring(state, message);
	lua_call(state, 3, 1);
}

static int LogSetOutputFunction(lua_State *state)
{
	auto stack = lua_newthread(state);
	lua_pop(state, 1);
	lua_xmove(state, stack, 1);
	SDL_LogSetOutputFunction(LogOutputFunction, stack);
	return 1;
}

extern "C" int luaopen_SDL_log(lua_State *state)
{
	
}

