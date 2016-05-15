#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

extern "C" int luaopen_SDL2_mutex(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Functions */

	luaL_Reg regs[] =
	{
	REG(CondBroadcast)
	REG(CondSignal)
	REG(CondWait)
	REG(CondWaitTimeout)
	REG(CreateCond)
	REG(CreateMutex)
	REG(CreateSemaphore)
	REG(DestroyCond)
	REG(DestroyMutex)
	REG(DestroySemaphore)
	REG(LockMutex)
	REG(SemPost)
	REG(SemTryWait)
	REG(SemValue)
	REG(SemWait)
	REG(SemWaitTimeout)
	REG(TryLockMutex)
	REG(UnlockMutex)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Structures */

	luaL_newmetatable(state, Type<SDL_mutex>::name);
	luaL_newmetatable(state, Type<SDL_cond>::name);
	luaL_newmetatable(state, Type<SDL_sem>::name);

	/* Done */

	return 0;
}

