#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

static int GetPowerInfo(lua_State *state)
{
	int seconds, percent, power = SDL_GetPowerInfo(&seconds, &percent);
	return lux_push(state, power, seconds, percent);
}

extern "C" int luaopen_SDL2_power(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Parameters */

	lux_Reg<lua_Integer> args[] =
	{
	// SDL_PowerState
	ARG(POWERSTATE_UNKNOWN)
	ARG(POWERSTATE_ON_BATTERY)
	ARG(POWERSTATE_NO_BATTERY)
	ARG(POWERSTATE_CHARGING)
	ARG(POWERSTATE_CHARGED)
	END
	};
	lux_settable(state, args);

	/* Functions */

	luaL_Reg regs[] =
	{
	{"GetPowerInfo", GetPowerInfo},
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Done */

	return 0;
}

