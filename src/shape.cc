#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_shape.h>
#include "Common.h"

extern "C" int luaopen_SDL_shape(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}
	lux_Reg<lua_Integer> args[] =
	{
	ARG(NONSHAPEABLE_WINDOW)
	ARG(INVALID_SHAPE_ARGUMENT)
	ARG(WINDOW_LACKS_SHAPE)
	// WindowShapeMode
	{"ShapeModeDefault", ShapeModeDefault},
	{"ShapeModeBinarizeAlpha", ShapeModeBinarizeAlpha},
	{"ShapeModeReverseBinarizeAlpha", ShapeModeReverseBinarizeAlpha},
	{"ShapeModeColorKey", ShapeModeColorKey},
	END
	};
	lux_settable(state, args);
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

