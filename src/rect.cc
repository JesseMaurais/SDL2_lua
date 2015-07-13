#include "SDL.hpp"

extern "C" int luaopen_SDL_rect(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	luaL_Reg regs [] =
	{
	REG(EnclosePoints)
	REG(HasIntersection)
	REG(IntersectRect)
//	REG(IntersectRectAndLine)
//	REG(PointInRect)
	REG(RectEmpty)
	REG(RectEquals)
	REG(UnionRect)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

