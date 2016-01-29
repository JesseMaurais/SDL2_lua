#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

static SDL_assert_state AssertHandler(const SDL_assert_data *data, void *user)
{
	auto state = reinterpret_cast<lua_State*>(user);
	lua_call(state, lua_gettop(state) - 1, LUA_MULTRET);
	auto action = lux_to<SDL_assert_state>(state, 2);
	lua_pop(state, 1);
	if (!lua_isfunction(state, 1))
	{
		auto handler = SDL_GetDefaultAssertionHandler();
		SDL_SetAssertionHandler(handler, nullptr);
	}
	return action;
}

static int SetAssertionHandler(lua_State *state)
{
	auto stack = lua_newthread(state);
	lua_xmove(state, stack, lua_gettop(state));
	SDL_SetAssertionHandler(AssertHandler, stack);
	return 0;
}

static int Assert(lua_State *state)
{
	SDL_assert(false and not true);
	return 0;
}

static int AssertParanoid(lua_State *state)
{

}

static int AssertRelease(lua_State *state)
{

}

extern "C" int luaopen_SDL_assert(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}
	lux_Reg<lua_Integer> args [] =
	{
	// SDL_AssertState
	{"ASSERTION_RETRY", SDL_ASSERTION_RETRY},
	{"ASSERTION_BREAK", SDL_ASSERTION_BREAK},
	{"ASSERTION_ABORT", SDL_ASSERTION_ABORT},
	{"ASSERTION_IGNORE", SDL_ASSERTION_IGNORE},
	{"ASSERTION_ALWAYS_IGNORE", SDL_ASSERTION_ALWAYS_IGNORE},
	{nullptr}
	};
	lux_settable(state, args);
	luaL_Reg regs [] =
	{
	{"ResetAssertionReport", lux_cast(SDL_ResetAssertionReport)},
	{"SetAssertionHandler", SetAssertionHandler},
	{"assert", Assert},
	{"assert_paranoid", AssertParanoid},
	{"assert_release", AssertRelease},
	{nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

