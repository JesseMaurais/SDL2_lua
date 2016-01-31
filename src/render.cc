#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

template <> luaL_Reg lux_Class<SDL_RendererInfo>::index[] =
	{
	MEM(SDL_RendererInfo, name)
	MEM(SDL_RendererInfo, flags)
	MEM(SDL_RendererInfo, num_texture_formats)
//	MEM(SDL_RendererInfo, texture_formats)
	MEM(SDL_RendererInfo, max_texture_width)
	MEM(SDL_RendererInfo, max_texture_height)
	END
	};

static int CreateWindowAndRenderer(lua_State *state)
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int w = lua_tointeger(state, 1);
	int h = lua_tointeger(state, 2);
	int f = lua_tointeger(state, 3);
	if (!SDL_CreateWindowAndRenderer(w, h, f, &window, &renderer))
	{
		return lux_push(state, window, renderer);
	}
	return 0;
}

static int GetRenderDrawBlendMode(lua_State *state)
{
	SDL_BlendMode mode;
	auto renderer = lux_to<SDL_Renderer*>(state, 1);
	if (!SDL_GetRenderDrawBlendMode(renderer, &mode))
	{
	 lua_pushinteger(state, mode);
	 return 1;
	}
	return 0;
}

static int GetRenderDrawColor(lua_State *state)
{
	Uint8 r, g, b, a;
	auto renderer = lux_to<SDL_Renderer*>(state, 1);
	if (!SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a))
	{
	 return lux_push(state, r, g, b, a);
	}
	return 0;
}

static int GetRendererOutputSize(lua_State *state)
{
	int w, h;
	auto renderer = lux_to<SDL_Renderer*>(state, 1);
	if (!SDL_GetRendererOutputSize(renderer, &w, &h))
	{
	 return lux_push(state, w, h);
	}
	return 0;
}

static int GetTextureAlphaMod(lua_State *state)
{
	Uint8 mod;
	auto texture = lux_to<SDL_Texture*>(state, 1);
	if (!SDL_GetTextureAlphaMod(texture, &mod))
	{
	 lua_pushinteger(state, mod);
	 return 1;
	}
	return 0;
}

static int GetTextureBlendMode(lua_State *state)
{
	SDL_BlendMode mode;
	auto texture = lux_to<SDL_Texture*>(state, 1);
	if (!SDL_GetTextureBlendMode(texture, &mode))
	{
	 lua_pushinteger(state, mode);
	 return 1;
	}
	return 0;
}

static int GetTextureColorMod(lua_State *state)
{
	Uint8 r, g, b;
	auto texture = lux_to<SDL_Texture*>(state, 1);
	if (!SDL_GetTextureColorMod(texture, &r, &g, &b))
	{
	 return lux_push(state, r, g, b);
	}
	return 1;
}

static int QueryTexture(lua_State *state)
{
	Uint32 format;
	int access, w, h;
	auto texture = lux_to<SDL_Texture*>(state, 1);
	if (!SDL_QueryTexture(texture, &format, &access, &w, &h))
	{
	 return lux_push(state, format, access, w, h);
	}
	return 0;
}

static int RenderGetLogicalSize(lua_State *state)
{
	int w, h;
	auto renderer = lux_to<SDL_Renderer*>(state, 1);
	SDL_RenderGetLogicalSize(renderer, &w, &h);
	return lux_push(state, w, h);
}

static int RenderGetScale(lua_State *state)
{
	float scaleX, scaleY;
	auto renderer = lux_to<SDL_Renderer*>(state, 1);
	SDL_RenderGetScale(renderer, &scaleX, &scaleY);
	return lux_push(state, scaleX, scaleY);
}

extern "C" int luaopen_SDL_render(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Parameters */

	lux_Reg<lua_Integer> args[] =
	{
	// SDL_BlendMode
	ARG(BLENDMODE_NONE)
	ARG(BLENDMODE_BLEND)
	ARG(BLENDMODE_ADD)
	ARG(BLENDMODE_MOD)
	// SDL_RendererFlags
	ARG(RENDERER_SOFTWARE)
	ARG(RENDERER_ACCELERATED)
	ARG(RENDERER_PRESENTVSYNC)
	ARG(RENDERER_TARGETTEXTURE)
	// SDL_RendererFlip
	ARG(FLIP_NONE)
	ARG(FLIP_HORIZONTAL)
	ARG(FLIP_VERTICAL)
	// SDL_TextureAccess
	ARG(TEXTUREACCESS_STATIC)
	ARG(TEXTUREACCESS_STREAMING)
	ARG(TEXTUREACCESS_TARGET)
	// SDL_TextureModulate
	ARG(TEXTUREMODULATE_NONE)
	ARG(TEXTUREMODULATE_COLOR)
	ARG(TEXTUREMODULATE_ALPHA)
	END
	};
	lux_settable(state, args);

	/* Functions */

	luaL_Reg regs [] =
	{
	REG(CreateRenderer)
	REG(CreateSoftwareRenderer)
	REG(CreateTexture)
	REG(CreateTextureFromSurface)
	{"CreateWindowAndRenderer", CreateWindowAndRenderer},
	REG(DestroyRenderer)
	REG(DestroyTexture)
	REG(GetNumRenderDrivers)
	{"GetRenderDrawBlendMode", GetRenderDrawBlendMode},
	{"GetRenderDrawColor", GetRenderDrawColor},
	REG(GetRenderDriverInfo)
	REG(GetRenderTarget)
	REG(GetRenderer)
	REG(GetRendererInfo)
	{"GetRendererOutputSize", GetRendererOutputSize},
	{"GetTextureAlphaMod", GetTextureAlphaMod},
	{"GetTextureBlendMode", GetTextureBlendMode},
	{"GetTextureColorMod", GetTextureColorMod},
//	REG(LockTexture)
	{"QueryTexture", QueryTexture},
	REG(RenderClear)
	REG(RenderCopy)
	REG(RenderCopyEx)
	REG(RenderDrawLine)
	REG(RenderDrawLines)
	REG(RenderDrawPoint)
	REG(RenderDrawPoints)
	REG(RenderDrawRect)
	REG(RenderDrawRects)
	REG(RenderFillRect)
	REG(RenderFillRects)
	REG(RenderGetClipRect)
	{"RenderGetLogicalSize", RenderGetLogicalSize},
	{"RenderGetScale", RenderGetScale},
	REG(RenderGetViewport)
	#if SDL_VERSION_ATLEAST(2, 0, 4)
	REG(RenderIsClipEnabled)
	#endif
	REG(RenderPresent)
//	REG(RenderReadPixels)
	REG(RenderSetClipRect)
	REG(RenderSetLogicalSize)
	REG(RenderSetScale)
	REG(RenderSetViewport)
	REG(RenderTargetSupported)
	REG(SetRenderDrawBlendMode)
	REG(SetRenderDrawColor)
	REG(SetRenderTarget)
	REG(SetTextureAlphaMod)
	REG(SetTextureBlendMode)
	REG(SetTextureColorMod)
	REG(UnlockTexture)
//	REG(UpdateTexture)
	#if SDL_VERSION_ATLEAST(2, 0, 1)
	REG(UpdateYUVTexture)
	#endif
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Structures */

	luaL_newmetatable(state, Type<SDL_Renderer>::name);
	luaL_newmetatable(state, Type<SDL_Texture>::name);
	
	/* Done */

	return 0;
}


