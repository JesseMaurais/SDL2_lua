#include <SDL2/SDL_ttf.h>
#include "SDL.hpp"

static int GlyphMetrics(lua_State *state)
{
	auto font = lux_to<TTF_Font*>(state, 1);
	auto ch = lux_to<Uint16>(state, 2);
	int minx, maxx, miny, maxy, advance;
	if (TTF_GlyphMetrics(font, ch, &minx, &maxx, &miny, &maxy, &advance))
	{
	 lux_push(state, minx, maxx, miny, maxy, advance);
	 return 5;
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


extern "C" int luaopen_TTF(lua_State *state)
{
	if (TTF_Init())
	{
		const char *error = TTF_GetError();
		return luaL_error(state, "TTF_Init: %s", error);
	}
	else atexit(TTF_Quit);

	luaL_newmetatable(state, TTF_METATABLE);
	lux_newtype<TTF_Font*>(state, "Font");
	struct {
	 const char *name;
	 int value;
	}
	args [] =
	{
	{"STYLE_NORMAL", TTF_STYLE_NORMAL},
	{"STYLE_BOLD", TTF_STYLE_BOLD},
	{"STYLE_ITALIC", TTF_STYLE_ITALIC},
	{"STYLE_UNDERLINE", TTF_STYLE_UNDERLINE},
	{"STRIKETHROUGH", TTF_STYLE_STRIKETHROUGH},
	{"HINTING_NORMAL", TTF_HINTING_NORMAL},
	{"HINTINT_LIGHT", TTF_HINTING_LIGHT},
	{"HINTING_MONO", TTF_HINTING_MONO},
	{"HINTING_NONE", TTF_HINTING_NONE},
	{nullptr, 0}
	};
	luaL_Reg regs [] = 
	{
	{"OpenFont", lux_cast(TTF_OpenFont)},
	{"OpenFontIndex", lux_cast(TTF_OpenFontIndex)},
	{"OpenFontRW", lux_cast(TTF_OpenFontRW)},
	{"OpenFontIndexRW", lux_cast(TTF_OpenFontIndexRW)},
	{"GetFontStyle", lux_cast(TTF_GetFontStyle)},
	{"SetFontStyle", lux_cast(TTF_SetFontStyle)},
	{"GetFontOutline", lux_cast(TTF_GetFontOutline)},
	{"SetFontOutline", lux_cast(TTF_SetFontOutline)},
	{"GetFontHinting", lux_cast(TTF_GetFontHinting)},
	{"SetFontHinting", lux_cast(TTF_SetFontHinting)},
	{"FontHeight", lux_cast(TTF_FontHeight)},
	{"FontAscent", lux_cast(TTF_FontAscent)},
	{"FontDescent", lux_cast(TTF_FontDescent)},
	{"FontLineSkip", lux_cast(TTF_FontLineSkip)},
	{"GetFontKerning", lux_cast(TTF_GetFontKerning)},
	{"SetFontKerning", lux_cast(TTF_SetFontKerning)},
	{"FontFaces", lux_cast(TTF_FontFaces)},
	{"FontFaceIsFixedWidth", lux_cast(TTF_FontFaceIsFixedWidth)},
	{"FontFaceFamilyName", lux_cast(TTF_FontFaceFamilyName)},
	{"FontFaceStyleName", lux_cast(TTF_FontFaceStyleName)},
	{"GlyphIsProvided", lux_cast(TTF_GlyphIsProvided)},
	{"GlyphMetrics", GlyphMetrics},
	{"SizeText", SizeText},
	{"SizeUTF8", SizeUTF8},
	{"RenderText", RenderText},
	{"RenderUTF8", RenderUTF8},
	{"RenderGlyph", RenderGlyph},
	{"CloseFont", lux_cast(TTF_CloseFont)},
	{"GetFontKerningSize", lux_cast(TTF_GetFontKerningSize)},
	{nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

