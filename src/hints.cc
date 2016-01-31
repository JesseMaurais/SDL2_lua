#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

extern "C" int luaopen_SDL_hints(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Parameters */

	lux_Reg<lua_Integer> args[] =
	{
	// SDL_HintPriority
	ARG(HINT_DEFAULT)
	ARG(HINT_NORMAL)
	ARG(HINT_OVERRIDE)
	END
	};
	lux_settable(state, args);

	/* Functions */

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

	/* Done */

	return 0;
}

