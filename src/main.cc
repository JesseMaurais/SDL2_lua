//#define SDL_MAIN_HANDLED
#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

extern "C" int luaopen_SDL_main(lua_State *state)
{
	// Is this necessary if main is in the interpreter?
	// SDL_SetMainReady();
	// Default initialization
	if (SDL_Init(0) < 0)
	{
		// Failure: report error
		auto error = SDL_GetError();
		return luaL_error(state, "SDL_Init: %s", error);
	}
	else // Success: set quit
	if (atexit(SDL_Quit) < 0)
	{
		// Failed to set the cleanup function call at program exit
		return luaL_error(state, "Cannot make exit (atexit < 0)");
	}
	// Create/obtain the SDL2 metatable
	luaL_newmetatable(state, SDL_METATABLE);
	return 1;
}
