#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

static int JoystickGetBall(lua_State *state)
{
	int dx, dy;
	auto joystick = lux_to<SDL_Joystick*>(state, 1);
	int ball = lua_tointeger(state, 2);
	if (!SDL_JoystickGetBall(joystick, ball, &dx, &dy))
	{
		return lux_push(state, dx, dy);
	}
	return 0;
}

extern "C" int luaopen_SDL_joystick(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Initialize */

	if (SDL_InitSubSystem(SDL_INIT_JOYSTICK) < 0)
	{
		auto error = SDL_GetError();
		return luaL_error(state, "SDL_InitSubSystem: %s", error);
	}

	/* Parameters */

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
	#if SDL_VERSION_ATLEAST(2, 0, 4)
	// SDL_JoystickCurrentPowerLevel
	ARG(JOYSTICK_POWER_UNKNOWN)
	ARG(JOYSTICK_POWER_EMPTY)
	ARG(JOYSTICK_POWER_LOW)
	ARG(JOYSTICK_POWER_MEDIUM)
	ARG(JOYSTICK_POWER_FULL)
	ARG(JOYSTICK_POWER_WIRED)
	ARG(JOYSTICK_POWER_MAX)
	#endif
	END
	};
	lux_settable(state, args);

	/* Functions */

	luaL_Reg regs [] =
	{
	REG(JoystickClose)
	#if SDL_VERSION_ATLEAST(2, 0, 4)
	REG(JoystickCurrentPowerLevel)
	#endif
	REG(JoystickEventState)
	#if SDL_VERSION_ATLEAST(2, 0, 4)
	REG(JoystickFromInstanceID)
	#endif
	REG(JoystickGetAttached)
	REG(JoystickGetAxis)
	{"JoystickGetBall", JoystickGetBall},
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

	/* Structures */

	luaL_newmetatable(state, Type<SDL_Joystick>::name);

	/* Done */

	return 0;
}

