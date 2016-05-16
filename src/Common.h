#ifndef SDL2_lua
#define SDL2_lua

// We always include these

#include <lux/lux.hpp>
#include <SDL2/SDL.h>

// Entire API is put into this metatable

#define SDL_METATABLE "SDL2_lua"
#define SDL_REQUIRED "You must require'SDL2'"

// Use the same type-to-metatable mappings across modules

template <class T> using Type = lux_Type<T*>;

template <> const char *Type<SDL_RendererInfo>::name = "RendererInfo";
template <> const char *Type<SDL_DisplayMode>::name = "DisplayMode";
template <> const char *Type<SDL_Renderer>::name = "Renderer";
template <> const char *Type<SDL_Texture>::name = "Texture";
template <> const char *Type<SDL_Window>::name = "Window";
template <> const char *Type<SDL_Event>::name = "Event";

template <> const char *Type<SDL_Color>::name = "Color";
template <> const char *Type<SDL_Palette>::name = "Palette";
template <> const char *Type<SDL_PixelFormat>::name = "PixelFormat";
template <> const char *Type<SDL_Surface>::name = "Surface";

template <> const char *Type<SDL_GameController>::name = "GameController";
template <> const char *Type<SDL_Joystick>::name = "Joystick";
template <> const char *Type<SDL_Finger>::name = "Finger";

template <> const char *Type<SDL_Thread>::name = "Thread";
template <> const char *Type<SDL_mutex>::name = "Mutex";
template <> const char *Type<SDL_cond>::name = "Cond";
template <> const char *Type<SDL_sem>::name = "Sem";

template <> const char *Type<SDL_RWops>::name = "RWops";

// Some shorthand for binding functions and paramters

#define REG(name) {#name, lux_cast(SDL_##name)},
#define ARG(name) {#name, SDL_##name},
#define MEM(rec, mem) {#mem, lux_member(rec, mem)},
#define END {nullptr}

// Custom push/to stack operations for SDL types

// SDL_bool

template <> inline
int lux_push<SDL_bool>(lua_State *state, SDL_bool value)
{
	lua_pushboolean(state, value); return 1;
}
template <> inline
SDL_bool lux_to<SDL_bool>(lua_State *state, int stack)
{
	return (SDL_bool) lua_toboolean(state, stack);
}

// SDL_AudioStatus

template <> inline
int lux_push<SDL_AudioStatus>(lua_State *state, SDL_AudioStatus value)
{
	lua_pushinteger(state, value); return 1;
}
template <> inline
SDL_AudioStatus lux_to<SDL_AudioStatus>(lua_State *state, int stack)
{
	return (SDL_AudioStatus) luaL_checkinteger(state, stack);
}

// SDL_eventaction

template <> inline
int lux_push<SDL_eventaction>(lua_State *state, SDL_eventaction value)
{
	lua_pushinteger(state, value); return 1;
}
template <> inline
SDL_eventaction lux_to<SDL_eventaction>(lua_State *state, int index)
{
	return (SDL_eventaction) luaL_checkinteger(state, index);
}

// SDL_HintPriority

template <> inline
int lux_push<SDL_HintPriority>(lua_State *state, SDL_HintPriority value)
{
	lua_pushinteger(state, value); return 1;
}
template <> inline
SDL_HintPriority lux_to<SDL_HintPriority>(lua_State *state, int in)
{
	return (SDL_HintPriority) luaL_checkinteger(state, in);
}

// SDL_Keymod

template <> inline
int lux_push<SDL_Keymod>(lua_State *state, SDL_Keymod value)
{
	lua_pushinteger(state, value); return 1;
}
template <> inline
SDL_Keymod lux_to<SDL_Keymod>(lua_State *state, int arg)
{
	return (SDL_Keymod) luaL_checkinteger(state, arg);
}

// SDL_Scancode

template <> inline
int lux_push<SDL_Scancode>(lua_State *state, SDL_Scancode value)
{
	lua_pushinteger(state, value); return 1;
}
template <> inline
SDL_Scancode lux_to<SDL_Scancode>(lua_State *state, int arg)
{
	return (SDL_Scancode) luaL_checkinteger(state, arg);
}

// SDL_RendererFlip

template <> inline
int lux_push<SDL_RendererFlip>(lua_State *state, SDL_RendererFlip value)
{
	lua_pushinteger(state, value); return 1;
}
template <> inline
SDL_RendererFlip lux_to<SDL_RendererFlip>(lua_State *state, int arg)
{
	return (SDL_RendererFlip) luaL_checkinteger(state, arg);
}

// SDL_BlendMode

template <> inline
int lux_push<SDL_BlendMode>(lua_State *state, SDL_BlendMode value)
{
	lua_pushinteger(state, value); return 1;
}
template <> inline
SDL_BlendMode lux_to<SDL_BlendMode>(lua_State *state, int arg)
{
	return (SDL_BlendMode) luaL_checkinteger(state, arg);
}

// SDL_TextureAccess

template <> inline
int lux_push<SDL_TextureAccess>(lua_State *state, SDL_TextureAccess value)
{
	lua_pushinteger(state, value); return 1;
}
template <> inline
SDL_TextureAccess lux_to<SDL_TextureAccess>(lua_State *state, int arg)
{
	return (SDL_TextureAccess) luaL_checkinteger(state, arg);
}

// SDL_MessageBoxFlags

template <> inline
int lux_push<SDL_MessageBoxFlags>(lua_State *state, SDL_MessageBoxFlags value)
{
	lua_pushinteger(state, value); return 1;
}
template <> inline
SDL_MessageBoxFlags lux_to<SDL_MessageBoxFlags>(lua_State *state, int arg)
{
	return (SDL_MessageBoxFlags) luaL_checkinteger(state, arg);
}

// SDL_MessageBoxButtonFlags

template <> inline
int lux_push<SDL_MessageBoxButtonFlags>(lua_State *state, SDL_MessageBoxButtonFlags value)
{
	lua_pushinteger(state, value); return 1;
}
template <> inline
SDL_MessageBoxButtonFlags lux_to<SDL_MessageBoxButtonFlags>(lua_State *state, int arg)
{
	return (SDL_MessageBoxButtonFlags) luaL_checkinteger(state, arg);
}

// SDL_MessageBoxColorType

template <> inline
int lux_push<SDL_MessageBoxColorType>(lua_State *state, SDL_MessageBoxColorType value)
{
	lua_pushinteger(state, value); return 1;
}
template <> inline
SDL_MessageBoxColorType lux_to<SDL_MessageBoxColorType>(lua_State *state, int arg)
{
	return (SDL_MessageBoxColorType) luaL_checkinteger(state, arg);
}

// SDL_JoystickGUID

template <> inline
int lux_push<SDL_JoystickGUID>(lua_State *state, SDL_JoystickGUID guid)
{
	SDL_memcpy(new (state) SDL_JoystickGUID, guid.data, sizeof(guid));
	return 1;
}
template <> inline
 SDL_JoystickGUID lux_to<SDL_JoystickGUID>(lua_State *state, int arg)
{
	SDL_JoystickGUID guid;
	auto data = lua_touserdata(state, arg);
	luaL_argcheck(state, data, arg, "GUID expected");
	SDL_memcpy(guid.data, data, sizeof(guid));
	return guid;
}

#endif // file

