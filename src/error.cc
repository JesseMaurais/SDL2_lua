#include "SDL.hpp"

extern "C" int luaopen_SDL_error(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	luaL_Reg regs [] =
	{
	 {"ClearError", lux_cast(SDL_ClearError)},
	 {"GetError", lux_cast(SDL_GetError)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

