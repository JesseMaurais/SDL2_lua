#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

template <> luaL_Reg lux_Class<SDL_Finger>::index[] =
	{
	MEM(SDL_Finger, id)
	MEM(SDL_Finger, x)
	MEM(SDL_Finger, y)
	MEM(SDL_Finger, pressure)
	END
	};

extern "C" int luaopen_SDL_touch(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Functions */

	luaL_Reg regs [] =
	{
	REG(GetNumTouchDevices)
	REG(GetTouchDevice)
	REG(GetNumTouchFingers)
	REG(GetTouchFinger)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Structures */

	lux_Class<SDL_Finger>::require(state);

	/* Done */

	return 0;
}
