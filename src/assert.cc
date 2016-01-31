#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

typedef SDL_assert_state SDL_AssertState;
typedef SDL_assert_data SDL_AssertData;

static SDL_AssertState AssertionHandler(const SDL_AssertData *data, void *user)
{
	if (data->always_ignore) return SDL_ASSERTION_IGNORE;
	static char buffer[BUFSIZ];
	sprintf(buffer,
		"Condition (%s) failed in function %s at line %d in file %s",
		data->condition, data->function, data->linenum, data->filename);
	SDL_MessageBoxButtonData buttons[] =
	{
	{SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, SDL_ASSERTION_RETRY, "Retry"},
	{SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, SDL_ASSERTION_BREAK, "Break"},
	{0, SDL_ASSERTION_ABORT, "Abort"},
	{0, SDL_ASSERTION_IGNORE, "Ignore"},
	{0, SDL_ASSERTION_ALWAYS_IGNORE, "Always Ignore"}
	};
	SDL_MessageBoxData box;
	box.flags = SDL_MESSAGEBOX_ERROR;
	box.window = nullptr;
	box.title = "Assertion";
	box.message = buffer;
	box.numbuttons = SDL_arraysize(buttons);
	box.buttons = buttons;
	box.colorScheme = nullptr;
	int id = SDL_ASSERTION_ABORT;;
	if (SDL_ShowMessageBox(&box, &id))
	{
		auto error = SDL_GetError();
		SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "%s", error);
	}
	return (SDL_AssertState) id;
}

static int assert_test(lua_State *state)
{
	SDL_assert(false and not true);
	return 0;
}

extern "C" int luaopen_SDL_assert(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Initialize */

	SDL_SetAssertionHandler(AssertionHandler, state);

	/* Functions */

	luaL_Reg regs[] =
	{
	{"assert", assert_test},
	{nullptr}
	};
	luaL_setfuncs(state, regs, 0);

	/* Done */

	return 0;
}

