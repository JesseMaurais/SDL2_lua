#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

#if SDL_VERSION_ATLEAST(2, 0, 4)
static int GetGlobalMouseState(lua_State *state)
{
	int x, y, buttons = SDL_GetGlobalMouseState(&x, &y);
	return lux_push(state, x, y, buttons);
}
#endif

static int GetMouseState(lua_State *state)
{
	int x, y, buttons = SDL_GetMouseState(&x, &y);
	return lux_push(state, x, y, buttons);
}

static int GetRelativeMouseState(lua_State *state)
{
	int x, y, buttons = SDL_GetRelativeMouseState(&x, &y);
	return lux_push(state, x, y, buttons);
}

extern "C" int luaopen_SDL2_mouse(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Parameters */

	lux_Reg<lua_Integer> args[] =
	{
	// SDL_SystemCursor
	ARG(SYSTEM_CURSOR_ARROW)
	ARG(SYSTEM_CURSOR_IBEAM)
	ARG(SYSTEM_CURSOR_WAIT)
	ARG(SYSTEM_CURSOR_CROSSHAIR)
	ARG(SYSTEM_CURSOR_WAITARROW)
	ARG(SYSTEM_CURSOR_SIZENWSE)
	ARG(SYSTEM_CURSOR_SIZEWE)
	ARG(SYSTEM_CURSOR_SIZENS)
	ARG(SYSTEM_CURSOR_SIZEALL)
	ARG(SYSTEM_CURSOR_NO)
	ARG(SYSTEM_CURSOR_HAND)
	END
	};
	lux_settable(state, args);

	/* Functions */

	luaL_Reg regs [] =
	{
	#if SDL_VERSION_ATLEAST(2, 0, 4)
	REG(CaptureMouse)
	#endif 
	REG(CreateColorCursor)
	REG(CreateCursor)
	REG(CreateSystemCursor)
	REG(FreeCursor)
	REG(GetCursor)
	REG(GetDefaultCursor)
	#if SDL_VERSION_ATLEAST(2, 0, 4)
	{"GetGlobalMouseState", GetGlobalMouseState},
	#endif
	REG(GetMouseFocus)
	{"GetMouseState", GetMouseState},
	REG(GetRelativeMouseMode)
	{"GetRelativeMouseState", GetRelativeMouseState},
	REG(SetCursor)
	REG(SetRelativeMouseMode)
	REG(ShowCursor)
	#if SDL_VERSION_ATLEAST(2, 0, 4)
	REG(WarpMouseGlobal)
	#endif
	REG(WarpMouseInWindow)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Done */

	return 0;
}

