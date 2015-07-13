#include "SDL.hpp"

template <> luaL_Reg lux_Union<SDL_Keysym>::index[] =
{
	lux_index(SDL_Keysym, scancode),
	lux_index(SDL_Keysym, sym),
	lux_index(SDL_Keysym, mod)
};

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

extern "C" int luaopen_SDL_keys(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 int value;
	}
	args [] =
	{
	 {"KMOD_NONE", KMOD_NONE},
	 {"KMOD_LSHIFT", KMOD_LSHIFT},
	 {"KMOD_RSHIFT", KMOD_RSHIFT},
	 {"KMOD_LCTRL", KMOD_LCTRL},
	 {"KMOD_RCTRL", KMOD_RCTRL},
	 {"KMOD_LALT", KMOD_LALT},
	 {"KMOD_RALT", KMOD_RALT},
	 {"KMOD_LGUI", KMOD_LGUI},
	 {"KMOD_RGUI", KMOD_RGUI},
	 {"KMOD_NUM", KMOD_NUM},
	 {"KMOD_CAPS", KMOD_CAPS},
	 {"KMOD_MODE", KMOD_MODE},
	 {"KMOD_CTRL", KMOD_CTRL},
	 {"KMOD_SHIFT", KMOD_SHIFT},
	 {"KMOD_ALT", KMOD_ALT},
	 {"KMOD_GUI", KMOD_GUI},
	 {nullptr, 0}
	};
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs [] =
	{
	 {"GetKeyFromName", lux_cast(SDL_GetKeyFromName)},
	 {"GetKeyFromScancode", lux_cast(SDL_GetKeyFromScancode)},
	 {"GetKeyName", lux_cast(SDL_GetKeyName)},
	 {"GetKeyboardFocus", lux_cast(SDL_GetKeyboardFocus)},
	 {"GetKeyboardState", lux_cast(SDL_GetKeyboardState)},
	 {"GetModState", lux_cast(SDL_GetModState)},
	 {"GetScancodeFromKey", lux_cast(SDL_GetScancodeFromKey)},
	 {"GetScancodeFromName", lux_cast(SDL_GetScancodeFromName)},
	 {"GetScancodeName", lux_cast(SDL_GetScancodeName)},
	 {"HasScreenKeyboardSupport", lux_cast(SDL_HasScreenKeyboardSupport)},
	 {"IsScreenKeyboardShown", lux_cast(SDL_IsScreenKeyboardShown)},
	 {"IsTextInputActive", lux_cast(SDL_IsTextInputActive)},
	 {"SetModState", lux_cast(SDL_SetModState)},
	 {"SetTextInputRect", lux_cast(SDL_SetTextInputRect)},
	 {"StartTextInput", lux_cast(SDL_StartTextInput)},
	 {"StopTextInput", lux_cast(SDL_StopTextInput)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

