#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

template <> luaL_Reg lux_Class<SDL_Color>::index[] =
	{
	{"r", lux_member(SDL_Color, r)},
	{"g", lux_member(SDL_Color, g)},
	{"b", lux_member(SDL_Color, b)},
	{"a", lux_member(SDL_Color, a)},
	{nullptr}
	};

template <> luaL_Reg lux_Class<SDL_Palette>::index[] =
	{
	{"ncolors", lux_member(SDL_Palette, ncolors)},
	{"colors", lux_member(SDL_Palette, colors)},
	{nullptr}
	};

template <> luaL_Reg lux_Class<SDL_PixelFormat>::index[] =
	{
	{"format", lux_member(SDL_PixelFormat, format)},
	{"palette", lux_member(SDL_PixelFormat, palette)},
	{"BitsPerPixel", lux_member(SDL_PixelFormat, BitsPerPixel)},
	{"BytesPerPixel", lux_member(SDL_PixelFormat, BytesPerPixel)},
	{"Rmask", lux_member(SDL_PixelFormat, Rmask)},
	{"Gmask", lux_member(SDL_PixelFormat, Gmask)},
	{"Bmask", lux_member(SDL_PixelFormat, Bmask)},
	{"Amask", lux_member(SDL_PixelFormat, Amask)},
	{nullptr}
	};

static int GetPixelFormatName(lua_State *state)
{
	lua_pushstring(state, SDL_GetPixelFormatName(lua_tointeger(state, 1)));
	return 1;
}

static int GetRGB(lua_State *state)
{
	SDL_Color color;
	auto pixel = lux_to<Uint32>(state, 1);
	auto format = lux_to<SDL_PixelFormat*>(state, 2);
	SDL_GetRGB(pixel, format, &color.r, &color.g, &color.b);
	return lux_push(state, color.r, color.g, color.b);
}

static int GetRGBA(lua_State *state)
{
	SDL_Color color;
	auto pixel = lux_to<Uint32>(state, 1);
	auto format = lux_to<SDL_PixelFormat*>(state, 2);
	SDL_GetRGBA(pixel, format, &color.r, &color.g, &color.b, &color.a);
	return lux_push(state, color.r, color.g, color.b, color.a);
}

static int PixelFormatEnumToMasks(lua_State *state)
{
	int bpp;
	Uint32 R, G, B, A;
	auto format = lux_to<Uint32>(state, 1);
	if (SDL_PixelFormatEnumToMasks(format, &bpp, &R, &G, &B, &A))
	{
	 return lux_push(state, bpp, R, G, B, A);
	}
	return 0;
}

extern "C" int luaopen_SDL_pixels(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Parameters */

	lux_Reg<lua_Integer> args[] =
	{
	 // SDL_PixelFormatEnum
	ARG(PIXELFORMAT_UNKNOWN)
	ARG(PIXELFORMAT_INDEX1LSB)
	ARG(PIXELFORMAT_INDEX1MSB)
	ARG(PIXELFORMAT_INDEX4LSB)
	ARG(PIXELFORMAT_INDEX4MSB)
	ARG(PIXELFORMAT_INDEX8)
	ARG(PIXELFORMAT_RGB332)
	ARG(PIXELFORMAT_RGB444)
	ARG(PIXELFORMAT_RGB555)
	ARG(PIXELFORMAT_BGR555)
	ARG(PIXELFORMAT_ARGB4444)
	ARG(PIXELFORMAT_RGBA4444)
	ARG(PIXELFORMAT_ABGR4444)
	ARG(PIXELFORMAT_BGRA4444)
	ARG(PIXELFORMAT_ARGB1555)
	ARG(PIXELFORMAT_RGBA5551)
	ARG(PIXELFORMAT_ABGR1555)
	ARG(PIXELFORMAT_BGRA5551)
	ARG(PIXELFORMAT_RGB565)
	ARG(PIXELFORMAT_BGR565)
	ARG(PIXELFORMAT_RGB24)
	ARG(PIXELFORMAT_BGR24)
	ARG(PIXELFORMAT_RGB888)
	ARG(PIXELFORMAT_RGBX8888)
	ARG(PIXELFORMAT_BGR888)
	ARG(PIXELFORMAT_BGRX8888)
	ARG(PIXELFORMAT_ARGB8888)
	ARG(PIXELFORMAT_RGBA8888)
	ARG(PIXELFORMAT_ABGR8888)
	ARG(PIXELFORMAT_BGRA8888)
	ARG(PIXELFORMAT_ARGB2101010)
	ARG(PIXELFORMAT_YV12)
	ARG(PIXELFORMAT_IYUV)
	ARG(PIXELFORMAT_YUY2)
	ARG(PIXELFORMAT_UYVY)
	ARG(PIXELFORMAT_YVYU)
	 // SDL_PIXELTYPE
	ARG(PIXELTYPE_UNKNOWN)
	ARG(PIXELTYPE_INDEX1)
	ARG(PIXELTYPE_INDEX4)
	ARG(PIXELTYPE_INDEX8)
	ARG(PIXELTYPE_PACKED8)
	ARG(PIXELTYPE_PACKED16)
	ARG(PIXELTYPE_PACKED32)
	ARG(PIXELTYPE_ARRAYU8)
	ARG(PIXELTYPE_ARRAYU16)
	ARG(PIXELTYPE_ARRAYU32)
	ARG(PIXELTYPE_ARRAYF16)
	ARG(PIXELTYPE_ARRAYF32)
	 // SDL_PIXELORDER
	ARG(BITMAPORDER_NONE)
	ARG(BITMAPORDER_4321)
	ARG(BITMAPORDER_1234)
	ARG(PACKEDORDER_NONE)
	ARG(PACKEDORDER_XRGB)
	ARG(PACKEDORDER_RGBX)
	ARG(PACKEDORDER_ARGB)
	ARG(PACKEDORDER_RGBA)
	ARG(PACKEDORDER_XBGR)
	ARG(PACKEDORDER_BGRX)
	ARG(PACKEDORDER_ABGR)
	ARG(PACKEDORDER_BGRA)
	ARG(ARRAYORDER_NONE)
	ARG(ARRAYORDER_RGB)
	ARG(ARRAYORDER_RGBA)
	ARG(ARRAYORDER_ARGB)
	ARG(ARRAYORDER_BGR)
	ARG(ARRAYORDER_BGRA)
	ARG(ARRAYORDER_ABGR)
	 // SDL_PIXELLAYOUT
	ARG(PACKEDLAYOUT_NONE)
	ARG(PACKEDLAYOUT_332)
	ARG(PACKEDLAYOUT_4444)
	ARG(PACKEDLAYOUT_1555)
	ARG(PACKEDLAYOUT_5551)
	ARG(PACKEDLAYOUT_565)
	ARG(PACKEDLAYOUT_8888)
	ARG(PACKEDLAYOUT_2101010)
	ARG(PACKEDLAYOUT_1010102)
	END
	};
	lux_settable(state, args);

	/* Functions */

	luaL_Reg regs [] = 
	{
	REG(AllocFormat)
	REG(AllocPalette)
	REG(CalculateGammaRamp)
	REG(FreeFormat)
	REG(FreePalette)
	{"GetPixelFormatName", GetPixelFormatName},
	{"GetRGB", GetRGB},
	{"GetRGBA", GetRGBA},
	REG(MapRGB)
	REG(MapRGBA)
	REG(MasksToPixelFormatEnum)
	{"PixelFormatEnumToMasks", PixelFormatEnumToMasks},
	REG(SetPaletteColors)
	REG(SetPixelFormatPalette)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Structures */

	lux_Class<SDL_Color>::require(state);
	lux_Class<SDL_Palette>::require(state);
	lux_Class<SDL_PixelFormat>::require(state);

	/* Done */

	return 0;
}

