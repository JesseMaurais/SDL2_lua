#include "SDL.hpp"
#include <SDL2/SDL_shape.h>

extern "C" int luaopen_SDL_shape(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 lua_Integer value;
	}
	args [] =
	{
	ARG(NONSHAPEABLE_WINDOW)
	ARG(INVALID_SHAPE_ARGUMENT)
	ARG(WINDOW_LACKS_SHAPE)
	// WindowShaopeMode
	{"ShapeModeDefault", ShapeModeDefault},
	{"ShapeModeBinarizeAlpha", ShapeModeBinarizeAlpha},
	{"ShapeModeReverseBinarizeAlpha", ShapeModeReverseBinarizeAlpha},
	{"ShapeModeColorKey", ShapeModeColorKey},
	END
	};
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs []
	{
	REG(CreateShapedWindow)
	REG(IsShapedWindow)
	REG(SetWindowShape)
	REG(GetShapedWindowMode)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

