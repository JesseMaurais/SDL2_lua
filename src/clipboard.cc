#include "SDL.hpp"

extern "C" int luaopen_SDL_clipboard(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	luaL_Reg regs [] =
	{
	REG(GetClipboardText)
	REG(HasClipboardText)
	REG(SetClipboardText)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

