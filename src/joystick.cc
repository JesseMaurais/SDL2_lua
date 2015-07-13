#include "SDL.hpp"

extern "C" int luaopen_SDL_joystick(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 lua_Integer value;
	}
	args [] =
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
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
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

