#include "SDL.hpp"

template <> SDL_HintPriority lux_to<SDL_HintPriority>(lua_State *state, int in)
{
	return (SDL_HintPriority) luaL_checkinteger(state, in);
}

extern "C" int luaopen_SDL_hints(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 int value;
	}
	args [] =
	{
	 // SDL_HintPriority
	 {"HINT_DEFAULT", SDL_HINT_DEFAULT},
	 {"HINT_NORMAL", SDL_HINT_NORMAL},
	 {"HINT_OVERRIDE", SDL_HINT_OVERRIDE},
	 {nullptr, 0}
	};
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs [] =
	{
//	 {"AddHintCallback", lux_cast(SDL_AddHintCallback)},
	 {"ClearHints", lux_cast(SDL_ClearHints)},
//	 {"DelHintCallback", lux_cast(SDL_DelHintCallback)},
	 {"GetHint", lux_cast(SDL_GetHint)},
	 {"SetHint", lux_cast(SDL_SetHint)},
	 {"SetHintWithPriority", lux_cast(SDL_SetHintWithPriority)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

