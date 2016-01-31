#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

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

	/* Done */

	return 0;
}
