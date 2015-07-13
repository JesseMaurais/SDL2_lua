#include "SDL.hpp"

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
	luaL_newmetatable(state, SDL_METATABLE);
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
	return 1;
}

