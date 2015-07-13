#include "SDL.hpp"


template <> SDL_RendererFlip lux_to<SDL_RendererFlip>(lua_State *state, int arg)
{
	return (SDL_RendererFlip) luaL_checkinteger(state, arg);
}
template <> SDL_BlendMode lux_to<SDL_BlendMode>(lua_State *state, int arg)
{
	return (SDL_BlendMode) luaL_checkinteger(state, arg);
}
template <> SDL_TextureAccess lux_to<SDL_TextureAccess>(lua_State *state, int arg)
{
	return (SDL_TextureAccess) luaL_checkinteger(state, arg);
}

template <> luaL_Reg lux_Union<SDL_RendererInfo>::index[] =
{
	lux_index(SDL_RendererInfo, name),
	lux_index(SDL_RendererInfo, flags),
	lux_index(SDL_RendererInfo, num_texture_formats),
	lux_index(SDL_RendererInfo, texture_formats),
	lux_index(SDL_RendererInfo, max_texture_width),
	lux_index(SDL_RendererInfo, max_texture_height)
};

static int CreateWindowAndRenderer(lua_State *state)
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int w = lua_tointeger(state, 1);
	int h = lua_tointeger(state, 2);
	int f = lua_tointeger(state, 3);
	if (SDL_CreateWindowAndRenderer(w, h, f, &window, &renderer))
	{
	 return 0;
	}
	else
	{
	 lux_push(state, window);
	 lux_push(state, renderer);
	 return 2;
	}
}

extern "C" int luaopen_SDL_render(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 int value;
	}
	args [] =
	{
	 // SDL_RendererFlags
	 {"RENDERER_SOFTWARE", SDL_RENDERER_SOFTWARE},
	 {"RENDERER_ACCELERATED", SDL_RENDERER_ACCELERATED},
	 {"RENDERER_PRESENTVSYNC", SDL_RENDERER_PRESENTVSYNC},
	 {"RENDERER_TARGETTEXTURE", SDL_RENDERER_TARGETTEXTURE},
	 // SDL_RendererFlip
	 {"FLIP_NONE", SDL_FLIP_NONE},
	 {"FLIP_HORIZONTAL", SDL_FLIP_HORIZONTAL},
	 {"FLIP_VERTICAL", SDL_FLIP_VERTICAL},
	 // SDL_TextureAccess
	 {"TEXTUREACCESS_STATIC", SDL_TEXTUREACCESS_STATIC},
	 {"TEXTUREACCESS_STREAMING", SDL_TEXTUREACCESS_STREAMING},
	 {"TEXTUREACCESS_TARGET", SDL_TEXTUREACCESS_TARGET},
	 // SDL_TextureModulate
	 {"TEXTUREMODULATE_NONE", SDL_TEXTUREMODULATE_NONE},
	 {"TEXTUREMODULATE_COLOR", SDL_TEXTUREMODULATE_COLOR},
	 {"TEXTUREMODULATE_ALPHA", SDL_TEXTUREMODULATE_ALPHA},
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
	 {"CreateRenderer", lux_cast(SDL_CreateRenderer)},
	 {"CreateSoftwareRenderer", lux_cast(SDL_CreateSoftwareRenderer)},
	 {"CreateTexture", lux_cast(SDL_CreateTexture)},
	 {"CreateTextureFromSurface", lux_cast(SDL_CreateTextureFromSurface)},
	 {"CreateWindowAndRenderer", CreateWindowAndRenderer},
	 {"DestroyRenderer", lux_cast(SDL_DestroyRenderer)},
	 {"DestroyTexture", lux_cast(SDL_DestroyTexture)},
	 {"GetNumRenderDrivers", lux_cast(SDL_GetNumRenderDrivers)},
//	 {"GetRenderDrawBlendMode", lux_cast(SDL_GetRenderDrawBlendMode)},
	 {"GetRenderDrawColor", lux_cast(SDL_GetRenderDrawColor)},
	 {"GetRenderDriverInfo", lux_cast(SDL_GetRenderDriverInfo)},
	 {"GetRenderTarget", lux_cast(SDL_GetRenderTarget)},
	 {"GetRenderer", lux_cast(SDL_GetRenderer)},
	 {"GetRendererInfo", lux_cast(SDL_GetRendererInfo)},
//	 {"GetRendererOutputSize", lux_cast(SDL_GetRendererOutputSize)},
//	 {"GetTextureAlphaMod", lux_cast(SDL_GetTextureAlphaMod)},
//	 {"GetTextureBlendMode", lux_cast(SDL_GetTextureBlendMode)},
//	 {"GetTextureColorMod", lux_cast(SDL_GetTextureColorMod)},
//	 {"LockTexture", lux_cast(SDL_LockTexture)},
//	 {"QueryTexture", lux_cast(SDL_QueryTexture)},
	 {"RenderClear", lux_cast(SDL_RenderClear)},
	 {"RenderCopy", lux_cast(SDL_RenderCopy)},
	 {"RenderCopyEx", lux_cast(SDL_RenderCopyEx)},
	 {"RenderDrawLine", lux_cast(SDL_RenderDrawLine)},
	 {"RenderDrawLines", lux_cast(SDL_RenderDrawLines)},
	 {"RenderDrawPoint", lux_cast(SDL_RenderDrawPoint)},
	 {"RenderDrawPoints", lux_cast(SDL_RenderDrawPoints)},
	 {"RenderDrawRect", lux_cast(SDL_RenderDrawRects)},
	 {"RenderDrawRects", lux_cast(SDL_RenderDrawRects)},
	 {"RenderFillRect", lux_cast(SDL_RenderFillRect)},
	 {"RenderFillRects", lux_cast(SDL_RenderFillRects)},
	 {"RenderGetClipRect", lux_cast(SDL_RenderGetClipRect)},
//	 {"RenderGetLogicalSize", lux_cast(SDL_RenderGetLogicalSize)},
//	 {"RenderGetScale", lux_cast(SDL_RenderGetScale)},
	 {"RenderGetViewport", lux_cast(SDL_RenderGetViewport)},
//	 {"RenderIsClipEnabled", lux_cast(SDL_RenderIsClipEnabled)},
	 {"RenderPresent", lux_cast(SDL_RenderPresent)},
//	 {"RenderReadPixels", lux_cast(SDL_RenderReadPixels)},
	 {"RenderSetClipRect", lux_cast(SDL_RenderSetClipRect)},
	 {"RenderSetLogicalSize", lux_cast(SDL_RenderSetLogicalSize)},
	 {"RenderSetScale", lux_cast(SDL_RenderSetScale)},
	 {"RenderSetViewport", lux_cast(SDL_RenderSetViewport)},
	 {"RenderTargetSupported", lux_cast(SDL_RenderTargetSupported)},
	 {"SetRenderDrawBlendMode", lux_cast(SDL_SetRenderDrawBlendMode)},
	 {"SetRenderDrawColor", lux_cast(SDL_SetRenderDrawColor)},
	 {"SetRenderTarget", lux_cast(SDL_SetRenderTarget)},
	 {"SetTextureAlphaMod", lux_cast(SDL_SetTextureAlphaMod)},
	 {"SetTextureBlendMode", lux_cast(SDL_SetTextureBlendMode)},
	 {"SetTextureColorMod", lux_cast(SDL_SetTextureColorMod)},
//	 {"UnlockTexture", lux_cast(SDL_UnlockTexture)},
//	 {"UpdateTexture", lux_cast(SDL_UpdateTexture)},
//	 {"UpdateUYVTexture", lux_cast(SDL_UpdateYUVTexture)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}


