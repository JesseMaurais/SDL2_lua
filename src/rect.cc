#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

template <> luaL_Reg lux_Class<SDL_Point>::index[] =
	{
	MEM(SDL_Point, x)
	MEM(SDL_Point, y)
	END
	};

template <> luaL_Reg lux_Class<SDL_Rect>::index[] =
	{
	MEM(SDL_Rect, x)
	MEM(SDL_Rect, y)
	MEM(SDL_Rect, w)
	MEM(SDL_Rect, h)
	END
	};

static int IntersectRectAndLine(lua_State *state)
{
	auto rect = lux_to<SDL_Rect*>(state, 1);
	int x1 = lua_tointeger(state, 2);
	int y1 = lua_tointeger(state, 3);
	int x2 = lua_tointeger(state, 4);
	int y2 = lua_tointeger(state, 5);
	auto result = SDL_IntersectRectAndLine(rect, &x1, &y1, &x2, &y2);
	return lux_push(state, result, x1, y1, x2, y2);
}

extern "C" int luaopen_SDL2_rect(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Functions */

	luaL_Reg regs [] =
	{
	REG(EnclosePoints)
	REG(HasIntersection)
	REG(IntersectRect)
	{"IntersectRectAndLine", IntersectRectAndLine},
	#if SDL_VERSION_ATLEAST(2, 0, 4)
	REG(PointInRect)
	#endif
	REG(RectEmpty)
	REG(RectEquals)
	REG(UnionRect)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Structures */

	lux_Class<SDL_Point>::require(state);
	lux_Class<SDL_Rect>::require(state);

	/* Done */

	return 0;
}

