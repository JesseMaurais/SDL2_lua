#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

extern "C" int luaopen_SDL_messagebox(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}
	lux_Reg<lua_Integer> args[] =
	{
	// SDL_MessageBoxFlags
	ARG(MESSAGEBOX_ERROR)
	ARG(MESSAGEBOX_WARNING)
	ARG(MESSAGEBOX_INFORMATION)
	// SDL_MessageBoxButtonData
	ARG(MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT)
	ARG(MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT)
	// SDL_MessageBoxColorType
	ARG(MESSAGEBOX_COLOR_BACKGROUND)
	ARG(MESSAGEBOX_COLOR_TEXT)
	ARG(MESSAGEBOX_COLOR_BUTTON_BORDER)
	ARG(MESSAGEBOX_COLOR_BUTTON_BACKGROUND)
//	ARG(MESSGAEBOX_COLOR_BUTTON_SELECTED)
	END
	};
	lux_settable(state, args);
	luaL_Reg regs [] =
	{
	REG(ShowMessageBox)
	REG(ShowSimpleMessageBox)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

