#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

extern "C" int luaopen_SDL_joystick(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}
	if (SDL_InitSubSystem(SDL_INIT_JOYSTICK) < 0)
	{
		auto error = SDL_GetError();
		return luaL_error(state, "SDL_InitSubSystem: %s", error);
	}
	lux_Reg<lua_Integer> args[] =
	{
	ARG(HAT_CENTERED)
	ARG(HAT_UP)
	ARG(HAT_RIGHT)
	ARG(HAT_DOWN)
	ARG(HAT_LEFT)
	ARG(HAT_RIGHTUP)
	ARG(HAT_RIGHTDOWN)
	ARG(HAT_LEFTUP)
	ARG(HAT_LEFTDOWN)
	END
	};
	lux_settable(state, args);
	luaL_Reg regs [] =
	{
	REG(JoystickClose)
	REG(JoystickEventState)
	REG(JoystickGetAttached)
	REG(JoystickGetAxis)
//	REG(JoystickGetBall)
	REG(JoystickGetButton)
	REG(JoystickGetDeviceGUID)
	REG(JoystickGetGUID)
	REG(JoystickGetGUIDFromString)
	REG(JoystickGetGUIDString)
	REG(JoystickGetHat)
	REG(JoystickInstanceID)
	REG(JoystickName)
	REG(JoystickNameForIndex)
	REG(JoystickNumAxes)
	REG(JoystickNumBalls)
	REG(JoystickNumButtons)
	REG(JoystickNumHats)
	REG(JoystickOpen)
	REG(JoystickUpdate)
	REG(NumJoysticks)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

