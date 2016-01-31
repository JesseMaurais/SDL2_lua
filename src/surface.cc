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

static int GetColorKey(lua_State *state)
{
	Uint32 key;
	auto surface = lux_to<SDL_Surface*>(state, 1);
	if (!SDL_GetColorKey(surface, &key))
	{
	 lua_pushinteger(state, key);
	 return 1;
	}
	return 0;
}

static int GetSurfaceAlphaMod(lua_State *state)
{
	Uint8 alpha;
	auto surface = lux_to<SDL_Surface*>(state, 1);
	if (!SDL_GetSurfaceAlphaMod(surface, &alpha))
	{
	 lua_pushinteger(state, alpha);
	 return 1;
	}
	return 0;
}

static int GetSurfaceBlendMode(lua_State *state)
{
	SDL_BlendMode mode;
	auto surface = lux_to<SDL_Surface*>(state, 1);
	if (!SDL_GetSurfaceBlendMode(surface, &mode))
	{
	 lux_push(state, mode);
	 return 1;
	}
	return 0;
}

static int GetSurfaceColorMod(lua_State *state)
{
	Uint8 r, g, b;
	auto surface = lux_to<SDL_Surface*>(state, 1);
	if (!SDL_GetSurfaceColorMod(surface, &r, &g, &b))
	{
	 return lux_push(state, r, g, b);
	}
	return 0;
}

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
	{"GetColorKey", GetColorKey},
	{"GetSurfaceAlphaMod", GetSurfaceAlphaMod},
	{"GetSurfaceBlendMode", GetSurfaceBlendMode},
	{"GetSurfaceColorMod", GetSurfaceColorMod},
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
	REG(SetSurfaceBlendMode)
	REG(SetSurfaceColorMod)
	REG(SetSurfacePalette)
	REG(SetSurfaceRLE)
	REG(UnlockSurface)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Structures */

	lux_Class<SDL_Surface>::require(state);

	/* Done */

	return 0;
}

