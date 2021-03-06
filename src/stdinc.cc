#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

extern "C" int luaopen_SDL2_stdinc(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Functions */

	luaL_Reg regs [] =
	{
	REG(malloc)
	REG(calloc)
	REG(realloc)
	REG(free)
	REG(getenv)
	REG(setenv)
	REG(qsort)
	REG(abs)
	REG(isdigit)
	REG(isspace)
	REG(toupper)
	REG(tolower)
	REG(memset)
	REG(memset4)
	REG(memcpy)
	REG(memmove)
	REG(memcmp)
	REG(wcslen)
	REG(wcslcpy)
	REG(wcslcat)
	REG(strlen)
	REG(strlcpy)
	REG(utf8strlcpy)
	REG(strlcat)
	REG(strdup)
	REG(strrev)
	REG(strupr)
	REG(strlwr)
	REG(strchr)
	REG(strrchr)
	REG(strstr)
	REG(itoa)
	REG(uitoa)
	REG(ltoa)
	REG(ultoa)
	REG(lltoa)
	REG(ulltoa)
	REG(atoi)
	REG(atof)
//	REG(strtol)
//	REG(strtoul)
//	REG(strtoull)
//	REG(strtod)
	REG(strcmp)
	REG(strncmp)
	REG(strcasecmp)
	REG(strncasecmp)
//	REG(sscanf)
//	REG(vsscanf)
//	REG(snprintf)
//	REG(vsnprintf)
	REG(acos)
	REG(asin)
	REG(atan)
	REG(atan2)
	REG(ceil)
	REG(copysign)
	REG(cos)
	REG(cosf)
//	REG(fabs)
	REG(floor)
	REG(log)
	REG(pow)
	REG(scalbn)
	REG(sin)
//	REG(sinf)
	REG(sqrt)
//	REG(sqrtf)
//	REG(tan)
//	REG(tanf)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Done */

	return 0;
}

