#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"


static int ShowMessageBox(lua_State *state)
{
	SDL_MessageBoxData data;
	// flags
	lua_getfield(state, 1, "flags");
	data.flags = luaL_optinteger(state, -1, SDL_MESSAGEBOX_INFORMATION);
	// window
	lua_getfield(state, 1, "window");
	data.window = lux_opt<SDL_Window*>(state, -1, nullptr);
	// title
	lua_getfield(state, 1, "title");
	data.title = luaL_optstring(state, -1, nullptr);
	// message
	lua_getfield(state, 1, "message");
	data.message = luaL_checkstring(state, -1);
	// buttons
	lua_getfield(state, 1, "buttons");
	int table = lua_gettop(state);
	data.numbuttons = luaL_len(state, table);;
	SDL_MessageBoxButtonData buttons[data.numbuttons];
	data.buttons = buttons;
	lua_pushnil(state);
	for (int n = 0; lua_next(state, table); ++n)
	{
		buttons[n].flags = 0;
		buttons[n].buttonid = lua_tointeger(state, -2);
		buttons[n].text = lua_tostring(state, -1);
		lua_pop(state, 1);
	}
	// default colors
	data.colorScheme = nullptr;
	// user input
	int id;
	if (!SDL_ShowMessageBox(&data, &id))
	{
		lua_pushinteger(state, id);
		return 1;
	}
	return 0;
}

extern "C" int luaopen_SDL_messagebox(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Parameters */

	lux_Reg<lua_Integer> args[] =
	{
	// SDL_MessageBoxFlags
	ARG(MESSAGEBOX_ERROR)
	ARG(MESSAGEBOX_WARNING)
	ARG(MESSAGEBOX_INFORMATION)
	// SDL_MessageBoxButtonData
	ARG(MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT)
	ARG(MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT)
	// SDL_MessageBoxColorType
	ARG(MESSAGEBOX_COLOR_BACKGROUND)
	ARG(MESSAGEBOX_COLOR_TEXT)
	ARG(MESSAGEBOX_COLOR_BUTTON_BORDER)
	ARG(MESSAGEBOX_COLOR_BUTTON_BACKGROUND)
	ARG(MESSAGEBOX_COLOR_BUTTON_SELECTED)
//	ARG(MESSAGEBOX_COLOR_BUTTON_MAX)
	END
	};
	lux_settable(state, args);

	/* Functions */

	luaL_Reg regs [] =
	{
	{"ShowMessageBox", ShowMessageBox},
	REG(ShowSimpleMessageBox)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Done */

	return 0;
}

