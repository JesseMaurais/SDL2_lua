#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

static Uint32 TimerCallback(Uint32 interval, void *data)
{
	auto state = reinterpret_cast<lua_State*>(data);
	lua_call(state, lua_gettop(state), 2);
	return lua_tointeger(state, 2);
}

static int AddTimer(lua_State *state)
{
	auto stack = lua_newthread(state);
	lua_xmove(state, stack, lua_gettop(state));
	Uint32 delay = lua_tointeger(state, 2);
	auto id = SDL_AddTimer(delay, TimerCallback, stack);
	lux_push(state, id);
	return 1;
}

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
//	{"AddTimer", AddTimer},
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
