#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

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

extern "C" int luaopen_SDL_render(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}
	// Register types for render
	luaL_newmetatable(state, Type<SDL_Renderer>::name);
	luaL_newmetatable(state, Type<SDL_Texture>::name);
	lua_pop(state, 2);
	// Register functions for render
	lux_Reg<lua_Integer> args[] =
	{
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
//	REG(GetRenderDrawBlendMode)
	REG(GetRenderDrawColor)
	REG(GetRenderDriverInfo)
	REG(GetRenderTarget)
	REG(GetRenderer)
	REG(GetRendererInfo)
//	REG(GetRendererOutputSize)
//	REG(GetTextureAlphaMod)
//	REG(GetTextureBlendMode)
//	REG(GetTextureColorMod)
//	REG(LockTexture)
//	REG(QueryTexture)
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
//	REG(RenderGetLogicalSize)
//	REG(RenderGetScale)
	REG(RenderGetViewport)
//	REG(RenderIsClipEnabled)
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
//	REG(UnlockTexture)
//	REG(UpdateTexture)
//	REG(UpdateUYVTexture)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}


