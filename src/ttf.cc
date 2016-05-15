#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Common.h"

static int GlyphMetrics(lua_State *state)
{
	auto font = lux_to<TTF_Font*>(state, 1);
	auto code = lux_to<Uint16>(state, 2);
	int minx, maxx, miny, maxy, advance;
	if (TTF_GlyphMetrics(font, code, &minx, &maxx, &miny, &maxy, &advance))
	{
	 return lux_push(state, minx, maxx, miny, maxy, advance);
	}
	return 0;
}

static int SizeText(lua_State *state)
{
	auto font = lux_to<TTF_Font*>(state, 1);
	auto text = lua_tostring(state, 2);
	int width, height;
	if (!TTF_SizeText(font, text, &width, &height))
	{
	 return lux_push(state, width, height);
	}
	return 0;
}

static int SizeUTF8(lua_State *state)
{
	auto font = lux_to<TTF_Font*>(state, 1);
	auto text = lua_tostring(state, 2);
	int width, height;
	if (!TTF_SizeUTF8(font, text, &width, &height))
	{
	 return lux_push(state, width, height);
	}
	return 0;
}

static inline void optcolor(lua_State *state, int arg, SDL_Color &color)
{
	auto opt = luaL_optstring(state, arg, nullptr);
	if (opt)
	{
		int R = color.r;
		int G = color.g;
		int B = color.b;
		int A = color.a;
		sscanf(opt, "%d.%d.%d.%d", &R, &G, &B, &A);
		color.r = R;
		color.g = G;
		color.b = B;
		color.a = A;
	}
}

static int RenderText(lua_State *state)
{
	const char *opt[] = {"Solid", "Shaded", "Blended", "Wrapped", nullptr};
	SDL_Color fg = {0xFF, 0xFF, 0xFF, 0xFF};
	SDL_Color bg = {0x00, 0x00, 0x00, 0xFF};
	Uint32 length;

	auto font = lux_to<TTF_Font*>(state, 1);
	auto text = luaL_checkstring(state, 2);
	SDL_Surface *surface;
	switch (luaL_checkoption(state, 3, "Blended", opt))
	{
	case 0:
	optcolor(state, 4, fg);
	surface = TTF_RenderText_Solid(font, text, fg);
	break;
	case 1:
	optcolor(state, 4, fg);
	optcolor(state, 5, bg);
	surface = TTF_RenderText_Shaded(font, text, fg, bg);
	break;
	case 2:
	optcolor(state, 4, fg);
	surface = TTF_RenderText_Blended(font, text, fg);
	break;
	case 3:
	length = luaL_checkinteger(state, 4);
	optcolor(state, 5, fg);
	surface = TTF_RenderText_Blended_Wrapped(font, text, fg, length);
	break;
	};
	lux_push(state, surface);
	return 1;
}

static int RenderUTF8(lua_State *state)
{
	const char *opt[] = {"Solid", "Shaded", "Blended", "Wrapped", nullptr};
	SDL_Color fg = {0xFF, 0xFF, 0xFF, 0xFF};
	SDL_Color bg = {0x00, 0x00, 0x00, 0xFF};
	Uint32 length;

	auto font = lux_to<TTF_Font*>(state, 1);
	auto text = luaL_checkstring(state, 2);
	SDL_Surface *surface;
	switch (luaL_checkoption(state, 3, "Blended", opt))
	{
	case 0:
	optcolor(state, 4, fg);
	surface = TTF_RenderUTF8_Solid(font, text, fg);
	break;
	case 1:
	optcolor(state, 4, fg);
	optcolor(state, 5, bg);
	surface = TTF_RenderUTF8_Shaded(font, text, fg, bg);
	break;
	case 2:
	optcolor(state, 4, fg);
	surface = TTF_RenderUTF8_Blended(font, text, fg);
	break;
	case 3:
	length = luaL_checkinteger(state, 4);
	optcolor(state, 5, fg);
	surface = TTF_RenderUTF8_Blended_Wrapped(font, text, fg, length);
	break;
	};
	lux_push(state, surface);
	return 1;
}

static int RenderGlyph(lua_State *state)
{
	const char *opt[] = {"Solid", "Shaded", "Blended", nullptr};
	SDL_Color fg = {0xFF, 0xFF, 0xFF, 0xFF};
	SDL_Color bg = {0x00, 0x00, 0x00, 0xFF};
	Uint32 length;

	auto font = lux_to<TTF_Font*>(state, 1);
	auto text = lux_to<Uint16>(state, 2);
	SDL_Surface *surface;
	switch (luaL_checkoption(state, 3, "Blended", opt))
	{
	case 0:
	optcolor(state, 4, fg);
	surface = TTF_RenderGlyph_Solid(font, text, fg);
	break;
	case 1:
	optcolor(state, 4, fg);
	optcolor(state, 5, bg);
	surface = TTF_RenderGlyph_Shaded(font, text, fg, bg);
	break;
	case 2:
	optcolor(state, 4, fg);
	surface = TTF_RenderGlyph_Blended(font, text, fg);
	break;
	};
	lux_push(state, surface);
	return 1;
}

#undef REG
#define REG(name) {#name, lux_cast(TTF_##name)},
#undef ARG
#define ARG(name) {#name, TTF_##name},

template <> const char *Type<TTF_Font>::name = "Font";

extern "C" int luaopen_SDL2_ttf(lua_State *state)
{
	if (TTF_Init() < 0)
	{
		const char *error = TTF_GetError();
		return luaL_error(state, "TTF_Init: %s", error);
	}
	else
	if (atexit(TTF_Quit))
	{
		return luaL_error(state, "Cannot make exit (atexit < 0)");
	}

	luaL_newmetatable(state, "SDL2_ttf");
	luaL_newmetatable(state, Type<TTF_Font>::name);
	lua_pop(state, 1);
	lux_Reg<lua_Integer> args[] =
	{
	ARG(STYLE_NORMAL)
	ARG(STYLE_BOLD)
	ARG(STYLE_ITALIC)
	ARG(STYLE_UNDERLINE)
	ARG(STYLE_STRIKETHROUGH)
	ARG(HINTING_NORMAL)
	ARG(HINTING_LIGHT)
	ARG(HINTING_MONO)
	ARG(HINTING_NONE)
	END
	};
	lux_settable(state, args);
	luaL_Reg regs [] = 
	{
	REG(OpenFont)
	REG(OpenFontIndex)
	REG(OpenFontRW)
	REG(OpenFontIndexRW)
	REG(GetFontStyle)
	REG(SetFontStyle)
	REG(GetFontOutline)
	REG(SetFontOutline)
	REG(GetFontHinting)
	REG(SetFontHinting)
	REG(FontHeight)
	REG(FontAscent)
	REG(FontDescent)
	REG(FontLineSkip)
	REG(GetFontKerning)
	REG(SetFontKerning)
	REG(FontFaces)
	REG(FontFaceIsFixedWidth)
	REG(FontFaceFamilyName)
	REG(FontFaceStyleName)
	REG(GlyphIsProvided)
	{"GlyphMetrics", GlyphMetrics},
	{"SizeText", SizeText},
	{"SizeUTF8", SizeUTF8},
	{"RenderText", RenderText},
	{"RenderUTF8", RenderUTF8},
	{"RenderGlyph", RenderGlyph},
	REG(CloseFont)
	REG(GetFontKerningSize)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

