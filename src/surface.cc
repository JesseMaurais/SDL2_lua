#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

template <> luaL_Reg lux_Class<SDL_Surface>::index[] =
	{
	{"format", lux_member(SDL_Surface, format)},
	{"w", lux_member(SDL_Surface, w)},
	{"h", lux_member(SDL_Surface, h)},
	{"pitch", lux_member(SDL_Surface, pitch)},
	{"pixels", lux_member(SDL_Surface, pixels)},
	{nullptr}
	};

static SDL_Surface *LoadBMP(const char *path)
{
	return SDL_LoadBMP(path);
}

static int SaveBMP(SDL_Surface *surface, const char *path)
{
	return SDL_SaveBMP(surface, path);
}

extern "C" int luaopen_SDL_surface(lua_State *state)
{
	/* Initialize */

	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Functions */

	luaL_Reg regs [] =
	{
	REG(BlitScaled)
	REG(BlitSurface)
//	REG(ConvertPixels)
	REG(ConvertSurface)
	REG(ConvertSurfaceFormat)
	REG(CreateRGBSurface)
//	REG(CreateRGBSurfaceFrom)
	REG(FillRect)
	REG(FillRects)
	REG(FreeSurface)
	REG(GetClipRect)
//	REG(GetColorKey)
//	REG(GetSurfaceAlphaMod)
//	REG(GetSurfaceBlendMode)
//	REG(GetSurfaceColorMod)
	{"LoadBMP", lux_cast(LoadBMP)},
	REG(LoadBMP_RW)
	REG(LockSurface)
	REG(LowerBlit)
	REG(LowerBlitScaled)
	{"SaveBMP", lux_cast(SaveBMP)},
	REG(SaveBMP_RW)
	REG(SetClipRect)
	REG(SetColorKey)
	REG(SetSurfaceAlphaMod)
//	REG(SetSurfaceBlendMode)
	REG(SetSurfaceColorMod)
	REG(SetSurfacePalette)
	REG(SetSurfaceRLE)
	REG(UnlockSurface)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Classes */

	lux_Class<SDL_Surface>::require(state);
	lua_pop(state, 1);

	/* Done */

	return 1;
}

