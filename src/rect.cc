#include "SDL.hpp"

template <> luaL_Reg lux_Union<SDL_Point>::index[] =
{
	lux_index(SDL_Point, x),
	lux_index(SDL_Point, y)
};
template <> luaL_Reg lux_Union<SDL_Point>::newindex[] =
{
	lux_newindex(SDL_Point, x),
	lux_newindex(SDL_Point, y)
};
template <> luaL_Reg lux_Union<SDL_Rect>::index[] =
{
	lux_index(SDL_Rect, x),
	lux_index(SDL_Rect, y),
	lux_index(SDL_Rect, w),
	lux_index(SDL_Rect, h)
};
template <> luaL_Reg lux_Union<SDL_Rect>::newindex[] =
{
	lux_newindex(SDL_Rect, x),
	lux_newindex(SDL_Rect, y),
	lux_newindex(SDL_Rect, w),
	lux_newindex(SDL_Rect, h)
};

extern "C" int luaopen_SDL_rect(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	luaL_Reg regs [] =
	{
	 {"EnclosePoints", lux_cast(SDL_EnclosePoints)},
	 {"HasIntersection", lux_cast(SDL_HasIntersection)},
	 {"IntersectRect", lux_cast(SDL_IntersectRect)},
//	 {"IntersectRectAndLine", lux_cast(SDL_IntersectRectAndLine)},
//	 {"PointInRect", lux_cast(SDL_PointInRect)},
	 {"RectEmpty", lux_cast(SDL_RectEmpty)},
	 {"RectEquals", lux_cast(SDL_RectEquals)},
	 {"UnionRect", lux_cast(SDL_UnionRect)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

