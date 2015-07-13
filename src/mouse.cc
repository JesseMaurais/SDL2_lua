#include "SDL.hpp"

extern "C" int luaopen_SDL_mouse(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	  const char *name;
	  int value;
	}
	args [] =
	{
	 // SDL_SystemCursor
	 {"SYSTEM_CURSOR_ARROW", SDL_SYSTEM_CURSOR_ARROW},
	 {"SYSTEM_CURSOR_IBEAM", SDL_SYSTEM_CURSOR_IBEAM},
	 {"SYSTEM_CURSOR_WAIT", SDL_SYSTEM_CURSOR_WAIT},
	 {"SYSTEM_CURSOR_CROSSHAIR", SDL_SYSTEM_CURSOR_CROSSHAIR},
	 {"SYSTEM_CURSOR_WAITARROW", SDL_SYSTEM_CURSOR_WAITARROW},
	 {"SYSTEM_CURSOR_SIZENWSE", SDL_SYSTEM_CURSOR_SIZENWSE},
	 {"SYSTEM_CURSOR_SIZEWE", SDL_SYSTEM_CURSOR_SIZEWE},
	 {"SYSTEM_CURSOR_SIZENS", SDL_SYSTEM_CURSOR_SIZENS},
	 {"SYSTEM_CURSOR_SIZEALL", SDL_SYSTEM_CURSOR_SIZEALL},
	 {"SYSTEM_CURSOR_NO", SDL_SYSTEM_CURSOR_NO},
	 {"SYSTEM_CURSOR_HAND", SDL_SYSTEM_CURSOR_HAND},
	 // end
	 {nullptr, 0}
	};
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs [] =
	{
//	 {"CaptureMouse", lux_cast(SDL_CaptureMouse)},
	 {"CreateColorCursor", lux_cast(SDL_CreateColorCursor)},
	 {"CreateCursor", lux_cast(SDL_CreateCursor)},
	 {"CreateSystemCursor", lux_cast(SDL_CreateSystemCursor)},
	 {"FreeCursor", lux_cast(SDL_FreeCursor)},
	 {"GetCursor", lux_cast(SDL_GetCursor)},
	 {"GetDefaultCursor", lux_cast(SDL_GetDefaultCursor)},
//	 {"GetGlobalMouseState", lux_cast(SDL_GetGlobalMouseState)},
	 {"GetMouseFocus", lux_cast(SDL_GetMouseFocus)},
//	 {"GetMouseState", lux_cast(SDL_GetMouseState)},
	 {"GetRelativeMouseMode", lux_cast(SDL_GetRelativeMouseMode)},
//	 {"GetRelativeMouseState", lux_cast(SDL_GetRelativeMouseState)},
	 {"SetCursor", lux_cast(SDL_SetCursor)},
	 {"SetRelativeMouseMode", lux_cast(SDL_SetRelativeMouseMode)},
	 {"ShowCursor", lux_cast(SDL_ShowCursor)},
//	 {"WarpMouseGlobal", lux_cast(SDL_WarpMouseGlobal)},
	 {"WarpMouseInWindow", lux_cast(SDL_WarpMouseInWindow)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

