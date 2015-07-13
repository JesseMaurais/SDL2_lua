#include "SDL.hpp"

template <> luaL_Reg lux_Union<SDL_Color>::index[] =
{
	lux_index(SDL_Color, r),
	lux_index(SDL_Color, g),
	lux_index(SDL_Color, b),
	lux_index(SDL_Color, a)
};
template <> luaL_Reg lux_Union<SDL_Color>::newindex[] =
{
	lux_newindex(SDL_Color, r),
	lux_newindex(SDL_Color, g),
	lux_newindex(SDL_Color, b),
	lux_newindex(SDL_Color, a)
};

template <> luaL_Reg lux_Union<SDL_Palette>::index[] =
{
	lux_index(SDL_Palette, ncolors),
	lux_index(SDL_Palette, colors)
};
template <> luaL_Reg lux_Union<SDL_Palette>::newindex[] =
{
	lux_newindex(SDL_Palette, ncolors),
	lux_newindex(SDL_Palette, colors)
};

template <> luaL_Reg lux_Union<SDL_PixelFormat>::index[] =
{
	lux_index(SDL_PixelFormat, format),
	lux_index(SDL_PixelFormat, palette),
	lux_index(SDL_PixelFormat, BitsPerPixel),
	lux_index(SDL_PixelFormat, BytesPerPixel),
	lux_index(SDL_PixelFormat, Rmask),
	lux_index(SDL_PixelFormat, Gmask),
	lux_index(SDL_PixelFormat, Bmask),
	lux_index(SDL_PixelFormat, Amask)
};
template <> luaL_Reg lux_Union<SDL_PixelFormat>::newindex[] =
{
	lux_newindex(SDL_PixelFormat, format),
	lux_newindex(SDL_PixelFormat, palette),
	lux_newindex(SDL_PixelFormat, BitsPerPixel),
	lux_newindex(SDL_PixelFormat, BytesPerPixel),
	lux_newindex(SDL_PixelFormat, Rmask),
	lux_newindex(SDL_PixelFormat, Gmask),
	lux_newindex(SDL_PixelFormat, Bmask),
	lux_newindex(SDL_PixelFormat, Amask)
};

static int GetRGB(lua_State *state)
{
	SDL_Color color;
	auto pixel = lux_to<Uint32>(state, 1);
	auto format = lux_to<SDL_PixelFormat*>(state, 2);
	SDL_GetRGB(pixel, format, &color.r, &color.g, &color.b);
	lux_push(state, color.r);
	lux_push(state, color.g);
	lux_push(state, color.b);
	return 3;
}

static int GetRGBA(lua_State *state)
{
	SDL_Color color;
	auto pixel = lux_to<Uint32>(state, 1);
	auto format = lux_to<SDL_PixelFormat*>(state, 2);
	SDL_GetRGBA(pixel, format, &color.r, &color.g, &color.b, &color.a);
	lux_push(state, color.r);
	lux_push(state, color.g);
	lux_push(state, color.b);
	lux_push(state, color.a);
	return 4;
}

static int PixelFormatEnumToMasks(lua_State *state)
{
	int bpp;
	Uint32 R, G, B, A;
	auto format = lux_to<Uint32>(state, 1);
	if (SDL_PixelFormatEnumToMasks(format, &bpp, &R, &G, &B, &A))
	{
	 lux_push(state, bpp);
	 lux_push(state, R);
	 lux_push(state, G);
	 lux_push(state, B);
	 lux_push(state, A);
	 return 5;
	}
	return 0;
}

extern "C" int luaopen_SDL_pixels(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 int value;
	}
	args [] =
	{
	 // SDL_PixelFormatEnum
	 {"PIXELFORMAT_UNKNOWN", SDL_PIXELFORMAT_UNKNOWN},
	 {"PIXELFORMAT_INDEX1LSB", SDL_PIXELFORMAT_INDEX1LSB},
	 {"PIXELFORMAT_INDEX1MSB", SDL_PIXELFORMAT_INDEX1MSB},
	 {"PIXELFORMAT_INDEX4LSB", SDL_PIXELFORMAT_INDEX4LSB},
	 {"PIXELFORMAT_INDEX4MSB", SDL_PIXELFORMAT_INDEX4MSB},
	 {"PIXELFORMAT_INDEX8", SDL_PIXELFORMAT_INDEX8},
	 {"PIXELFORMAT_RGB332", SDL_PIXELFORMAT_RGB332},
	 {"PIXELFORMAT_RGB444", SDL_PIXELFORMAT_RGB444},
	 {"PIXELFORMAT_RGB555", SDL_PIXELFORMAT_RGB555},
	 {"PIXELFORMAT_BGR555", SDL_PIXELFORMAT_BGR555},
	 {"PIXELFORMAT_ARGB4444", SDL_PIXELFORMAT_ARGB4444},
	 {"PIXELFORMAT_RGBA4444", SDL_PIXELFORMAT_RGBA4444},
	 {"PIXELFORMAT_ABGR4444", SDL_PIXELFORMAT_ABGR4444},
	 {"PIXELFORMAT_BGRA4444", SDL_PIXELFORMAT_BGRA4444},
	 {"PIXELFORMAT_ARGB1555", SDL_PIXELFORMAT_ARGB1555},
	 {"PIXELFORMAT_RGBA5551", SDL_PIXELFORMAT_RGBA5551},
	 {"PIXELFORMAT_ABGR1555", SDL_PIXELFORMAT_ABGR1555},
	 {"PIXELFORMAT_BGRA5551", SDL_PIXELFORMAT_BGRA5551},
	 {"PIXELFORMAT_RGB565", SDL_PIXELFORMAT_RGB565},
	 {"PIXELFORMAT_BGR565", SDL_PIXELFORMAT_BGR565},
	 {"PIXELFORMAT_RGB24", SDL_PIXELFORMAT_RGB24},
	 {"PIXELFORMAT_BGR24", SDL_PIXELFORMAT_BGR24},
	 {"PIXELFORMAT_RGB888", SDL_PIXELFORMAT_RGB888},
	 {"PIXELFORMAT_RGBX8888", SDL_PIXELFORMAT_RGBX8888},
	 {"PIXELFORMAT_BGR888", SDL_PIXELFORMAT_BGR888},
	 {"PIXELFORMAT_BGRX8888", SDL_PIXELFORMAT_BGRX8888},
	 {"PIXELFORMAT_ARGB8888", SDL_PIXELFORMAT_ARGB8888},
	 {"PIXELFORMAT_RGBA8888", SDL_PIXELFORMAT_RGBA8888},
	 {"PIXELFORMAT_ABGR8888", SDL_PIXELFORMAT_ABGR8888},
	 {"PIXELFORMAT_BGRA8888", SDL_PIXELFORMAT_BGRA8888},
	 {"PIXELFORMAT_ARGB2101010", SDL_PIXELFORMAT_ARGB2101010},
	 {"PIXELFORMAT_YV12", SDL_PIXELFORMAT_YV12},
	 {"PIXELFORMAT_IYUV", SDL_PIXELFORMAT_IYUV},
	 {"PIXELFORMAT_YUY2", SDL_PIXELFORMAT_YUY2},
	 {"PIXELFORMAT_UYVY", SDL_PIXELFORMAT_UYVY},
	 {"PIXELFORMAT_YVYU", SDL_PIXELFORMAT_YVYU},
	 // SDL_PIXELTYPE
	 {"PIXELTYPE_UNKNOWN", SDL_PIXELTYPE_UNKNOWN},
	 {"PIXELTYPE_INDEX1", SDL_PIXELTYPE_INDEX1},
	 {"PIXELTYPE_INDEX4", SDL_PIXELTYPE_INDEX4},
	 {"PIXELTYPE_INDEX8", SDL_PIXELTYPE_INDEX8},
	 {"PIXELTYPE_PACKED8", SDL_PIXELTYPE_PACKED8},
	 {"PIXELTYPE_PACKED16", SDL_PIXELTYPE_PACKED16},
	 {"PIXELTYPE_PACKED32", SDL_PIXELTYPE_PACKED32},
	 {"PIXELTYPE_ARRAYU8", SDL_PIXELTYPE_ARRAYU8},
	 {"PIXELTYPE_ARRAYU16", SDL_PIXELTYPE_ARRAYU16},
	 {"PIXELTYPE_ARRAYU32", SDL_PIXELTYPE_ARRAYU32},
	 {"PIXELTYPE_ARRAYF16", SDL_PIXELTYPE_ARRAYF16},
	 {"PIXELTYPE_ARRAYF32", SDL_PIXELTYPE_ARRAYF32},
	 // SDL_PIXELORDER
	 {"BITMAPORDER_NONE", SDL_BITMAPORDER_NONE},
	 {"BITMAPORDER_4321", SDL_BITMAPORDER_4321},
	 {"BITMAPORDER_1234", SDL_BITMAPORDER_1234},
	 {"PACKEDORDER_NONE", SDL_PACKEDORDER_NONE},
	 {"PACKEDORDER_XRGB", SDL_PACKEDORDER_XRGB},
	 {"PACKEDORDER_RGBX", SDL_PACKEDORDER_RGBX},
	 {"PACKEDORDER_ARGB", SDL_PACKEDORDER_ARGB},
	 {"PACKEDORDER_RGBA", SDL_PACKEDORDER_RGBA},
	 {"PACKEDORDER_XBGR", SDL_PACKEDORDER_XBGR},
	 {"PACKEDORDER_BGRX", SDL_PACKEDORDER_BGRX},
	 {"PACKEDORDER_ABGR", SDL_PACKEDORDER_ABGR},
	 {"PACKEDORDER_BGRA", SDL_PACKEDORDER_BGRA},
	 {"ARRAYORDER_NONE", SDL_ARRAYORDER_NONE},
	 {"ARRAYORDER_RGB", SDL_ARRAYORDER_RGB},
	 {"ARRAYORDER_RGBA", SDL_ARRAYORDER_RGBA},
	 {"ARRAYORDER_ARGB", SDL_ARRAYORDER_ARGB},
	 {"ARRAYORDER_BGR", SDL_ARRAYORDER_BGR},
	 {"ARRAYORDER_BGRA", SDL_ARRAYORDER_BGRA},
	 {"ARRAYORDER_ABGR", SDL_ARRAYORDER_ABGR},
	 // SDL_PIXELLAYOUT
	 {"PACKEDLAYOUT_NONE", SDL_PACKEDLAYOUT_NONE},
	 {"PACKEDLAYOUT_332", SDL_PACKEDLAYOUT_332},
	 {"PACKEDLAYOUT_4444", SDL_PACKEDLAYOUT_4444},
	 {"PACKEDLAYOUT_1555", SDL_PACKEDLAYOUT_1555},
	 {"PACKEDLAYOUT_5551", SDL_PACKEDLAYOUT_5551},
	 {"PACKEDLAYOUT_565", SDL_PACKEDLAYOUT_565},
	 {"PACKEDLAYOUT_8888", SDL_PACKEDLAYOUT_8888},
	 {"PACKEDLAYOUT_2101010", SDL_PACKEDLAYOUT_2101010},
	 {"PACKEDLAYOUT_1010102", SDL_PACKEDLAYOUT_1010102},
	 // end
	 {nullptr, 0}
	};
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs [] = 
	{
	 {"AllocFormat", lux_cast(SDL_AllocFormat)},
	 {"AllocPalette", lux_cast(SDL_AllocPalette)},
	 {"CalculateGammaRamp", lux_cast(SDL_CalculateGammaRamp)},
	 {"FreeFormat", lux_cast(SDL_FreeFormat)},
	 {"FreePalette", lux_cast(SDL_FreePalette)},
	 {"GetPixelFormatName", lux_cast(SDL_GetPixelFormatName)},
	 {"GetRGB", GetRGB},
	 {"GetRGBA", GetRGBA},
	 {"MapRGB", lux_cast(SDL_MapRGB)},
	 {"MapRGBA", lux_cast(SDL_MapRGBA)},
	 {"MasksToPixelFormatEnum", lux_cast(SDL_MasksToPixelFormatEnum)},
	 {"PixelFormatEnumToMasks", PixelFormatEnumToMasks},
	 {"SetPaletteColors", lux_cast(SDL_SetPaletteColors)},
	 {"SetPixelFormatPalette", lux_cast(SDL_SetPixelFormatPalette)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

