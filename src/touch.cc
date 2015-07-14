#include "SDL.hpp"

extern "C" int luaopen_SDL_touch(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	luaL_Reg regs [] =
	{
	REG(GetNumTouchDevices)
	REG(GetTouchDevice)
	REG(GetNumTouchFingers)
	REG(GetTouchFinger)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

