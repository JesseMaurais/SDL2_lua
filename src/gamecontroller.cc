#include "SDL.hpp"

extern "C" int luaopen_SDL_gamecontroller(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 lua_Integer param;
	}
	args [] =
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
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->param);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs [] =
	{
	REG(GameControllerAddMapping)
//	REG(GameControllerAddMappingsFromFile)
//	REG(GameControllerAddMappingsFromRW)
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
	return 1;
}

