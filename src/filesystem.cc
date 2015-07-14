#include "SDL.hpp"

extern "C" int luaopen_SDL_filesystem(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	luaL_Reg regs [] =
	{
	REG(GetBasePath)
	REG(GetPrefPath)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

