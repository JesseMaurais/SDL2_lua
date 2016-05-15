#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

#if SDL_VERSION_ATLEAST(2, 0, 2)
static int GameControllerAddMappingsFromFile(lua_State *state)
{
	auto path = lua_tostring(state, 1);
	auto ops = SDL_RWFromFile(path, "rb");
	auto gamecontroller = SDL_GameControllerAddMappingsFromRW(ops, true);
	lux_push(state, gamecontroller);
	return 1;
}
#endif

extern "C" int luaopen_SDL2_gamecontroller(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Initialize */

	if (SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) < 0)
	{
		auto error = SDL_GetError();
		return luaL_error(state, "SDL_InitSubSystem: %s", error);
	}

	/* Parameters */

	lux_Reg<lua_Integer> args [] =
	{
	// SDL_GameControllerAxis
	ARG(CONTROLLER_AXIS_INVALID)
	ARG(CONTROLLER_AXIS_LEFTX)
	ARG(CONTROLLER_AXIS_LEFTY)
	ARG(CONTROLLER_AXIS_RIGHTX)
	ARG(CONTROLLER_AXIS_RIGHTY)
	ARG(CONTROLLER_AXIS_TRIGGERLEFT)
	ARG(CONTROLLER_AXIS_TRIGGERRIGHT)
	ARG(CONTROLLER_AXIS_MAX)
	// SDL_GameControllerButton
	ARG(CONTROLLER_BUTTON_INVALID)
	ARG(CONTROLLER_BUTTON_A)
	ARG(CONTROLLER_BUTTON_B)
	ARG(CONTROLLER_BUTTON_X)
	ARG(CONTROLLER_BUTTON_Y)
	ARG(CONTROLLER_BUTTON_BACK)
	ARG(CONTROLLER_BUTTON_GUIDE)
	ARG(CONTROLLER_BUTTON_START)
	ARG(CONTROLLER_BUTTON_LEFTSTICK)
	ARG(CONTROLLER_BUTTON_RIGHTSTICK)
	ARG(CONTROLLER_BUTTON_LEFTSHOULDER)
	ARG(CONTROLLER_BUTTON_RIGHTSHOULDER)
	ARG(CONTROLLER_BUTTON_DPAD_UP)
	ARG(CONTROLLER_BUTTON_DPAD_DOWN)
	ARG(CONTROLLER_BUTTON_DPAD_LEFT)
	ARG(CONTROLLER_BUTTON_DPAD_RIGHT)
	ARG(CONTROLLER_BUTTON_MAX)
	// SDL_GameControllerBindType
	ARG(CONTROLLER_BINDTYPE_NONE)
	ARG(CONTROLLER_BINDTYPE_BUTTON)
	ARG(CONTROLLER_BINDTYPE_AXIS)
	ARG(CONTROLLER_BINDTYPE_HAT)
	END
	};
	lux_settable(state, args);

	/* Functions */

	luaL_Reg regs [] =
	{
	REG(GameControllerAddMapping)
	#if SDL_VERSION_ATLEAST(2, 0, 2)
	{"GameControllerAddMappingsFromFile", GameControllerAddMappingsFromFile},
	REG(GameControllerAddMappingsFromRW)
	#endif
	REG(GameControllerClose)
	REG(GameControllerEventState)
	REG(GameControllerGetAttached)
	REG(GameControllerGetAxis)
	REG(GameControllerGetAxisFromString)
	REG(GameControllerGetBindForAxis)
	REG(GameControllerGetBindForButton)
	REG(GameControllerGetButton)
	REG(GameControllerGetButtonFromString)
	REG(GameControllerGetJoystick)
	REG(GameControllerGetStringForAxis)
	REG(GameControllerGetStringForButton)
	REG(GameControllerMapping)
	REG(GameControllerMappingForGUID)
	REG(GameControllerName)
	REG(GameControllerNameForIndex)
	REG(GameControllerOpen)
	REG(GameControllerUpdate)
	REG(IsGameController)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Structures */

	luaL_newmetatable(state, Type<SDL_GameController>::name);

	/* Done */

	return 0;
}

