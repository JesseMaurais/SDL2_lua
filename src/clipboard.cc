#include "SDL.hpp"

extern "C" int luaopen_SDL_clipboard(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	luaL_Reg regs [] =
	{
	 {"GetClipboardText", lux_cast(SDL_GetClipboardText)},
	 {"HasClipboardText", lux_cast(SDL_HasClipboardText)},
	 {"SetClipboardText", lux_cast(SDL_SetClipboardText)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

