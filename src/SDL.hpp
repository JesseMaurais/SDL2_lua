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

#define REG(name) {#name, lux_cast(SDL_##name)},
#define ARG(name) {#name, SDL_##name},
#define END {nullptr}


template <> void lux_push<SDL_bool>(lua_State *state, SDL_bool value)
{
	lua_pushboolean(state, value);
}
template <> SDL_bool lux_to<SDL_bool>(lua_State *state, int stack)
{
	(SDL_bool) lua_toboolean(state, stack);
}


template <> void lux_push<SDL_AudioStatus>(lua_State *state, SDL_AudioStatus value)
{
	lua_pushinteger(state, value);
}
template <> SDL_AudioStatus lux_to<SDL_AudioStatus>(lua_State *state, int stack)
{
	return (SDL_AudioStatus) luaL_checkinteger(state, stack);
}


template <> void lux_push<SDL_eventaction>(lua_State *state, SDL_eventaction value)
{
	lua_pushinteger(state, value);
}
template <> SDL_eventaction lux_to<SDL_eventaction>(lua_State *state, int index)
{
	return (SDL_eventaction) luaL_checkinteger(state, index);
}


template <> void lux_push<SDL_HintPriority>(lua_State *state, SDL_HintPriority value)
{
	lua_pushinteger(state, value);
}
template <> SDL_HintPriority lux_to<SDL_HintPriority>(lua_State *state, int in)
{
	return (SDL_HintPriority) luaL_checkinteger(state, in);
}



template <> void lux_push<SDL_Keymod>(lua_State *state, SDL_Keymod value)
{
	lua_pushinteger(state, value);
}
template <> SDL_Keymod lux_to<SDL_Keymod>(lua_State *state, int arg)
{
	return (SDL_Keymod) luaL_checkinteger(state, arg);
}


template <> void lux_push<SDL_Keycode>(lua_State *state, SDL_Keycode value)
{
	lua_pushinteger(state, value);
}
template <> SDL_Keycode lux_to<SDL_Keycode>(lua_State *state, int arg)
{
	return (SDL_Keycode) luaL_checkinteger(state, arg);
}


template <> void lux_push<SDL_Scancode>(lua_State *state, SDL_Scancode value)
{
	lua_pushinteger(state, value);
}
template <> SDL_Scancode lux_to<SDL_Scancode>(lua_State *state, int arg)
{
	return (SDL_Scancode) luaL_checkinteger(state, arg);
}


template <> void lux_push<SDL_JoystickGUID>(lua_State *state, SDL_JoystickGUID guid)
{
	SDL_memcpy(new (state) SDL_JoystickGUID, guid.data, sizeof(guid));
}
template <> SDL_JoystickGUID lux_to<SDL_JoystickGUID>(lua_State *state, int arg)
{
	SDL_JoystickGUID guid;
	auto data = lua_touserdata(state, arg);
	luaL_argcheck(state, data, arg, "GUID expected");
	SDL_memcpy(guid.data, data, sizeof(guid));
	return guid;
}


template <> void lux_push<SDL_RendererFlip>(lua_State *state, SDL_RendererFlip value)
{
	lua_pushinteger(state, value);
}
template <> SDL_RendererFlip lux_to<SDL_RendererFlip>(lua_State *state, int arg)
{
	return (SDL_RendererFlip) luaL_checkinteger(state, arg);
}


template <> void lux_push<SDL_BlendMode>(lua_State *state, SDL_BlendMode value)
{
	lua_pushinteger(state, value);
}
template <> SDL_BlendMode lux_to<SDL_BlendMode>(lua_State *state, int arg)
{
	return (SDL_BlendMode) luaL_checkinteger(state, arg);
}


template <> void lux_push<SDL_TextureAccess>(lua_State *state, SDL_TextureAccess value)
{
	lua_pushinteger(state, value);
}
template <> SDL_TextureAccess lux_to<SDL_TextureAccess>(lua_State *state, int arg)
{
	return (SDL_TextureAccess) luaL_checkinteger(state, arg);
}
