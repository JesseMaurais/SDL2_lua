#include <lux/lux.hpp>
#include <SDL2/SDL.h>

#define SDL_METATABLE "SDL"
#define GLC_METATABLE "GL"
#define STD_METATABLE "std"
#define TTF_METATABLE "TTF"
#define IMG_METATABLE "IMG"
#define MIX_METATABLE "Mix"
#define NET_METATABLE "NET"
#define GFX_METATABLE "GFX"

template <> void lux_push<SDL_bool>(lua_State *state, SDL_bool value)
{
	lua_pushboolean(state, value);
}

template <> SDL_bool lux_to<SDL_bool>(lua_State *state, int stack)
{
	(SDL_bool) lua_toboolean(state, stack);
}

