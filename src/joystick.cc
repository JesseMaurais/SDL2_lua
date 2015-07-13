#include "SDL.hpp"

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

extern "C" int luaopen_SDL_joystick(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 int value;
	}
	args [] =
	{
	 {"HAT_CENTERED", SDL_HAT_CENTERED},
	 {"HAT_UP", SDL_HAT_UP},
	 {"HAT_RIGHT", SDL_HAT_RIGHT},
	 {"HAT_DOWN", SDL_HAT_DOWN},
	 {"HAT_LEFT", SDL_HAT_LEFT},
	 {"HAT_RIGHTUP", SDL_HAT_RIGHTUP},
	 {"HAT_RIGHTDOWN", SDL_HAT_RIGHTDOWN},
	 {"HAT_LEFTUP", SDL_HAT_LEFTUP},
	 {"HAT_LEFTDOWN", SDL_HAT_LEFTDOWN},
	 {nullptr, 0}
	};
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs [] =
	{
	 {"JoystickClose", lux_cast(SDL_JoystickClose)},
	 {"JoystickEventState", lux_cast(SDL_JoystickEventState)},
	 {"JoystickGetAttached", lux_cast(SDL_JoystickGetAttached)},
	 {"JoystickGetAxis", lux_cast(SDL_JoystickGetAxis)},
//	 {"JoystickGetBall", lux_cast(SDL_JoystickGetBall)},
	 {"JoystickGetButton", lux_cast(SDL_JoystickGetButton)},
	 {"JoystickGetDeviceGUID", lux_cast(SDL_JoystickGetDeviceGUID)},
	 {"JoystickGetGUID", lux_cast(SDL_JoystickGetGUID)},
	 {"JoystickGetGUIDFromString", lux_cast(SDL_JoystickGetGUIDFromString)},
	 {"JoystrickGetGUIDString", lux_cast(SDL_JoystickGetGUIDString)},
	 {"JoystickGetHat", lux_cast(SDL_JoystickGetHat)},
	 {"JoystickInstanceID", lux_cast(SDL_JoystickInstanceID)},
	 {"JoystickName", lux_cast(SDL_JoystickName)},
	 {"JoystickNameForIndex", lux_cast(SDL_JoystickNameForIndex)},
	 {"JoystickNumAxes", lux_cast(SDL_JoystickNumAxes)},
	 {"JoystickNumBalls", lux_cast(SDL_JoystickNumBalls)},
	 {"JoystickNumButtons", lux_cast(SDL_JoystickNumButtons)},
	 {"JoystickNumHats", lux_cast(SDL_JoystickNumHats)},
	 {"JoystickOpen", lux_cast(SDL_JoystickOpen)},
	 {"JoystickUpdate", lux_cast(SDL_JoystickUpdate)},
	 {"NumJoysticks", lux_cast(SDL_NumJoysticks)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

