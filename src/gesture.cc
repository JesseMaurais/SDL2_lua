#include "SDL.hpp"

extern "C" int luaopen_SDL_gesture(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	luaL_Reg regs [] =
	{
	REG(RecordGesture)
	REG(SaveAllDollarTemplates)
	REG(SaveDollarTemplate)
	REG(LoadDollarTemplates)
	END
	};
	luaL_setfuncs(state, regs, 0);
}

