//#define SDL_MAIN_HANDLED
#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

extern "C" int luaopen_SDL_main(lua_State *state)
{
	// Is this necessary if main is in the interpreter?
//	SDL_SetMainReady();

	/* Initialize */

	if (SDL_Init(0) < 0)
	{
		// Failure: report error
		auto error = SDL_GetError();
		return luaL_error(state, "SDL_Init: %s", error);
	}
	else
	if (atexit(SDL_Quit) < 0)
	{
		// Failed to set the cleanup function call at program exit
		return luaL_error(state, "Cannot make exit (atexit < 0)");
	}

	/* Module Metatable */

	luaL_newmetatable(state, SDL_METATABLE);

	/* Done */

	return 1;
}
