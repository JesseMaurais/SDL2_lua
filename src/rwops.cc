#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

static int RWclose(SDL_RWops *ops)
{
	return SDL_RWclose(ops);
}

static size_t RWread(SDL_RWops *ops, void *ptr, size_t size, size_t items)
{
	return SDL_RWread(ops, ptr, size, items);
}

static Sint64 RWseek(SDL_RWops *ops, Sint64 offset, int whence)
{
	return SDL_RWseek(ops, offset, whence);
}

static Sint64 RWsize(SDL_RWops *ops)
{
	return SDL_RWsize(ops);
}

static Sint64 RWtell(SDL_RWops *ops)
{
	return SDL_RWtell(ops);
}

static size_t RWwrite(SDL_RWops *ops, void *ptr, size_t size, size_t items)
{
	return SDL_RWwrite(ops, ptr, size, items);
}

extern "C" int luaopen_SDL2_rwops(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Functions */

	luaL_Reg regs [] =
	{
	REG(AllocRW)
	REG(FreeRW)
	REG(RWFromConstMem)
	REG(RWFromFP)
	REG(RWFromFile)
	REG(RWFromMem)
	{"RWclose", lux_cast(RWclose)},
	{"RWread", lux_cast(RWread)},
	{"RWseek", lux_cast(RWseek)},
	{"RWsize", lux_cast(RWsize)},
	{"RWtell", lux_cast(RWtell)},
	{"RWwrite", lux_cast(RWwrite)},
	REG(ReadBE16)
	REG(ReadBE32)
	REG(ReadBE64)
	REG(ReadLE16)
	REG(ReadLE32)
	REG(ReadLE64)
	REG(WriteBE16)
	REG(WriteBE32)
	REG(WriteBE64)
	REG(WriteLE16)
	REG(WriteLE32)
	REG(WriteLE64)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Structures */

	luaL_newmetatable(state, Type<SDL_RWops>::name);

	/* Done */

	return 0;
}

