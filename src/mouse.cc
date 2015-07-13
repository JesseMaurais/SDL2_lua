#include "SDL.hpp"

extern "C" int luaopen_SDL_mouse(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 lua_Integer value;
	}
	args [] =
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
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs [] =
	{
//	REG(CaptureMouse)
	REG(CreateColorCursor)
	REG(CreateCursor)
	REG(CreateSystemCursor)
	REG(FreeCursor)
	REG(GetCursor)
	REG(GetDefaultCursor)
//	REG(GetGlobalMouseState)
	REG(GetMouseFocus)
//	REG(GetMouseState)
	REG(GetRelativeMouseMode)
//	REG(GetRelativeMouseState)
	REG(SetCursor)
	REG(SetRelativeMouseMode)
	REG(ShowCursor)
//	REG(WarpMouseGlobal)
	REG(WarpMouseInWindow)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

