#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

template <> const char *Type<SDL_mutex>::name = "Mutex";
template <> const char *Type<SDL_cond>::name = "Condition";
template <> const char *Type<SDL_sem>::name = "Semaphore";

extern "C" int luaopen_SDL_mutex(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}
	luaL_newmetatable(state, Type<SDL_mutex>::name);
	luaL_newmetatable(state, Type<SDL_cond>::name);
	luaL_newmetatable(state, Type<SDL_sem>::name);
	lua_pop(state, 3);
	luaL_Reg regs[] =
	{
	{"CondBroadcast", lux_cast(SDL_CondBroadcast)},
	{"CondSignal", lux_cast(SDL_CondSignal)},
	{"CondWait", lux_cast(SDL_CondWait)},
	{"CondWaitTimeout", lux_cast(SDL_CondWaitTimeout)},
	{"CreateCond", lux_cast(SDL_CreateCond)},
	{"CreateMutex", lux_cast(SDL_CreateMutex)},
	{"CreateSemaphore", lux_cast(SDL_CreateSemaphore)},
	{"DestroyCond", lux_cast(SDL_DestroyCond)},
	{"DestroyMutex", lux_cast(SDL_DestroyMutex)},
	{"DestroySemaphore", lux_cast(SDL_DestroySemaphore)},
	{"LockMutex", lux_cast(SDL_LockMutex)},
	{"SemPost", lux_cast(SDL_SemPost)},
	{"SemTryWait", lux_cast(SDL_SemTryWait)},
	{"SemValue", lux_cast(SDL_SemValue)},
	{"SemWait", lux_cast(SDL_SemWait)},
	{"SemWaitTimeout", lux_cast(SDL_SemWaitTimeout)},
	{"TryLockMutex", lux_cast(SDL_TryLockMutex)},
	{"UnlockMutex", lux_cast(SDL_UnlockMutex)},
	{nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

