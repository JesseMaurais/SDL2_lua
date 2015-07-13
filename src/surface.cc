#include "SDL.hpp"

template <> luaL_Reg lux_Union<SDL_Surface>::index[] =
{
	lux_index(SDL_Surface, format),
	lux_index(SDL_Surface, w),
	lux_index(SDL_Surface, h),
	lux_index(SDL_Surface, pitch),
	lux_index(SDL_Surface, pixels)
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
	luaL_newmetatable(state, SDL_METATABLE);
	lux_Union<SDL_Surface>::open(state);
	luaL_Reg regs [] =
	{
	 {"BlitScaled", lux_cast(SDL_BlitScaled)},
	 {"BlitSurface", lux_cast(SDL_BlitSurface)},
//	 {"ConvertPixels", lux_cast(SDL_ConvertPixels)},
	 {"ConvertSurface", lux_cast(SDL_ConvertSurface)},
	 {"ConvertSurfaceFormat", lux_cast(SDL_ConvertSurfaceFormat)},
	 {"CreateRGBSurface", lux_cast(SDL_CreateRGBSurface)},
//	 {"CreateRGBSurfaceFrom", lux_cast(SDL_CreateRGBSurfaceFrom)},
	 {"FillRect", lux_cast(SDL_FillRect)},
	 {"FillRects", lux_cast(SDL_FillRects)},
	 {"FreeSurface", lux_cast(SDL_FreeSurface)},
	 {"GetClipRect", lux_cast(SDL_GetClipRect)},
//	 {"GetColorKey", lux_cast(SDL_GetColorKey)},
//	 {"GetSurfaceAlphaMod", lux_cast(SDL_GetSurfaceAlphaMod)},
//	 {"GetSurfaceBlendMode", lux_cast(SDL_GetSurfaceBlendMode)},
//	 {"GetSurfaceColorMod", lux_cast(SDL_GetSurfaceColorMod)},
	 {"LoadBMP", lux_cast(LoadBMP)},
	 {"LoadBMP_RW", lux_cast(SDL_LoadBMP_RW)},
	 {"LockSurface", lux_cast(SDL_LockSurface)},
	 {"LowerBlit", lux_cast(SDL_LowerBlit)},
	 {"LowerBlitScaled", lux_cast(SDL_LowerBlitScaled)},
	 {"SaveBMP", lux_cast(SaveBMP)},
	 {"SaveBMP_RW", lux_cast(SDL_SaveBMP_RW)},
	 {"SetClipRect", lux_cast(SDL_SetClipRect)},
	 {"SetColorKey", lux_cast(SDL_SetColorKey)},
	 {"SetSurfaceAlphaMod", lux_cast(SDL_SetSurfaceAlphaMod)},
//	 {"SetSurfaceBlendMode", lux_cast(SDL_SetSurfaceBlendMode)},
	 {"SetSurfaceColorMod", lux_cast(SDL_SetSurfaceColorMod)},
	 {"SetSurfacePalette", lux_cast(SDL_SetSurfacePalette)},
	 {"SetSurfaceRLE", lux_cast(SDL_SetSurfaceRLE)},
	 {"UnlockSurface", lux_cast(SDL_UnlockSurface)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

