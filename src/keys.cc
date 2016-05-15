#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

#undef ARG
#define ARG(name) {#name, name},

extern "C" int luaopen_SDL2_keys(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Parameters */

	lux_Reg<lua_Integer> args[] =
	{
	ARG(KMOD_NONE)
	ARG(KMOD_LSHIFT)
	ARG(KMOD_RSHIFT)
	ARG(KMOD_LCTRL)
	ARG(KMOD_RCTRL)
	ARG(KMOD_LALT)
	ARG(KMOD_RALT)
	ARG(KMOD_LGUI)
	ARG(KMOD_RGUI)
	ARG(KMOD_NUM)
	ARG(KMOD_CAPS)
	ARG(KMOD_MODE)
	ARG(KMOD_CTRL)
	ARG(KMOD_SHIFT)
	ARG(KMOD_ALT)
	ARG(KMOD_GUI)
	END
	};
	lux_settable(state, args);

	/* Functions */

	luaL_Reg regs [] =
	{
	REG(GetKeyFromName)
	REG(GetKeyFromScancode)
	REG(GetKeyName)
	REG(GetKeyboardFocus)
	REG(GetKeyboardState)
	REG(GetModState)
	REG(GetScancodeFromKey)
	REG(GetScancodeFromName)
	REG(GetScancodeName)
	REG(HasScreenKeyboardSupport)
	REG(IsScreenKeyboardShown)
	REG(IsTextInputActive)
	REG(SetModState)
	REG(SetTextInputRect)
	REG(StartTextInput)
	REG(StopTextInput)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Done */

	return 0;
}

