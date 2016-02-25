#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

extern "C" int luaopen_SDL_array(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	// Common numeric functions

	luaL_Reg regs[] =
	{
	{"Uint8", lux_Array<Uint8>::open},
	{"Uint16", lux_Array<Uint16>::open},
	{"Uint32", lux_Array<Uint32>::open},
	{"Uint64", lux_Array<Uint64>::open},
	{"Sint8", lux_Array<Sint8>::open},
	{"Sint16", lux_Array<Sint16>::open},
	{"Sint32", lux_Array<Sint32>::open},
	{"Sint64", lux_Array<Sint64>::open},
	{nullptr}
	};

	for (auto reg=regs; reg->name; ++reg)
	{
		luaL_requiref(state, reg->name, reg->func, true);
		lua_pop(state, 1);
	}

	// Character coding

	luaL_Reg codes[] =
	{
	{"Uint8", lux_Coder<Uint8>::open},
	{"Uint16", lux_Coder<Uint16>::open},
	{"Uint32", lux_Coder<Uint32>::open},
	{"Uint64", lux_Coder<Uint64>::open},
	{"Sint8", lux_Coder<Sint8>::open},
	{"Sint16", lux_Coder<Sint16>::open},
	{"Sint32", lux_Coder<Sint32>::open},
	{"Sint64", lux_Coder<Sint64>::open},
	{nullptr}
	};

	for (auto code=codes; code->name; ++code)
	{
		lua_pushstring(state, code->name);
		code->func(state);
		lua_pop(state, 1);
	}

	// Done

	return 0;
}

