#include "SDL.hpp"

extern "C" int luaopen_SDL_hints(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 lua_Integer value;
	}
	args [] =
	{
	// SDL_HintPriority
	ARG(HINT_DEFAULT)
	ARG(HINT_NORMAL)
	ARG(HINT_OVERRIDE)
	END
	};
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs [] =
	{
//	REG(AddHintCallback)
	REG(ClearHints)
//	REG(DelHintCallback)
	REG(GetHint)
	REG(SetHint)
	REG(SetHintWithPriority)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

