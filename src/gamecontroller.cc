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
	 {"CONTROLLER_AXIS_INVALID", SDL_CONTROLLER_AXIS_INVALID},
	 {"CONTROLLER_AXIS_LEFTX", SDL_CONTROLLER_AXIS_LEFTX},
	 {"CONTROLLER_AXIS_LEFTY", SDL_CONTROLLER_AXIS_LEFTY},
	 {"CONTROLLER_AXIS_RIGHTX", SDL_CONTROLLER_AXIS_RIGHTX},
	 {"CONTROLLER_AXIS_RIGHTY", SDL_CONTROLLER_AXIS_RIGHTY},
	 {"CONTROLLER_AXIS_TRIGGERLEFT", SDL_CONTROLLER_AXIS_TRIGGERLEFT},
	 {"CONTROLLER_AXIS_TRIGGERRIGHT", SDL_CONTROLLER_AXIS_TRIGGERRIGHT},
	 {"CONTROLLER_AXIS_MAX", SDL_CONTROLLER_AXIS_MAX},
	 // SDL_GameControllerButton
	 {"CONTROLLER_BUTTON_INVALID", SDL_CONTROLLER_BUTTON_INVALID},
	 {"CONTROLLER_BUTTON_A", SDL_CONTROLLER_BUTTON_A},
	 {"CONTROLLER_BUTTON_B", SDL_CONTROLLER_BUTTON_B},
	 {"CONTROLLER_BUTTON_X", SDL_CONTROLLER_BUTTON_X},
	 {"CONTROLLER_BUTTON_Y", SDL_CONTROLLER_BUTTON_Y},
	 {"CONTROLLER_BUTTON_BACK", SDL_CONTROLLER_BUTTON_BACK},
	 {"CONTROLLER_BUTTON_GUIDE", SDL_CONTROLLER_BUTTON_GUIDE},
	 {"CONTROLLER_BUTTON_START", SDL_CONTROLLER_BUTTON_START},
	 {"CONTROLLER_BUTTON_LEFTSTICK", SDL_CONTROLLER_BUTTON_LEFTSTICK},
	 {"CONTROLLER_BUTTON_RIGHTSTICK", SDL_CONTROLLER_BUTTON_RIGHTSTICK},
	 {"CONTROLLER_BUTTON_LEFTSHOULDER", SDL_CONTROLLER_BUTTON_LEFTSHOULDER},
	 {"CONTROLLER_BUTTON_RIGHTSHOULDER", SDL_CONTROLLER_BUTTON_RIGHTSHOULDER},
	 {"CONTROLLER_BUTTON_DPAD_UP", SDL_CONTROLLER_BUTTON_DPAD_UP},
	 {"CONTROLLER_BUTTON_DPAD_DOWN", SDL_CONTROLLER_BUTTON_DPAD_DOWN},
	 {"CONTROLLER_BUTTON_DPAD_LEFT", SDL_CONTROLLER_BUTTON_DPAD_LEFT},
	 {"CONTROLLER_BUTTON_DPAD_RIGHT", SDL_CONTROLLER_BUTTON_DPAD_RIGHT},
	 {"CONTROLLER_BUTTON_MAX", SDL_CONTROLLER_BUTTON_MAX},
	 // SDL_GameControllerBindType
	 {"CONTROLLER_BINDTYPE_NONE", SDL_CONTROLLER_BINDTYPE_NONE},
	 {"CONTROLLER_BINDTYPE_BUTTON", SDL_CONTROLLER_BINDTYPE_BUTTON},
	 {"CONTROLLER_BINDTYPE_AXIS", SDL_CONTROLLER_BINDTYPE_AXIS},
	 {"CONTROLLER_BINDTYPE_HAT", SDL_CONTROLLER_BINDTYPE_HAT},
	 // end
	 {nullptr, 0}
	};
	for (auto reg=args; reg->name; ++reg)
	{
	 lua_pushinteger(state, reg->param);
	 lua_setfield(state, -2, reg->name);
	}
	luaL_Reg regs [] =
	{
	 {"GameControllerAddMapping", lux_cast(SDL_GameControllerAddMapping)},
//	 {"GameControllerAddMappingsFromFile", lux_cast(SDL_GameControllerAddMappingsFromFile)},
//	 {"GameControllerAddMappingsFromRW", lux_cast(SDL_GameControllerAddMappingsFromeRW)},
	 {"GameControllerClose", lux_cast(SDL_GameControllerClose)},
	 {"GameControllerEventState", lux_cast(SDL_GameControllerEventState)},
	 {"GameControllerGetAttached", lux_cast(SDL_GameControllerGetAttached)},
	 {"GameControllerGetAxis", lux_cast(SDL_GameControllerGetAxis)},
	 {"GameControllerGetAxisFromString", lux_cast(SDL_GameControllerGetAxisFromString)},
	 {"GameControllerGetBidnForAxis", lux_cast(SDL_GameControllerGetBindForAxis)},
	 {"GameControllerGetBindForButton", lux_cast(SDL_GameControllerGetBindForButton)},
	 {"GameControllerGetButton", lux_cast(SDL_GameControllerGetButton)},
	 {"GameControllerGetButtonFromString", lux_cast(SDL_GameControllerGetButtonFromString)},
	 {"GameControllerGetJoystick", lux_cast(SDL_GameControllerGetJoystick)},
	 {"GameControllerGetStringForAxis", lux_cast(SDL_GameControllerGetStringForAxis)},
	 {"GameControllerGetStringForButton", lux_cast(SDL_GameControllerGetStringForButton)},
	 {"GameControllerMapping", lux_cast(SDL_GameControllerMapping)},
	 {"GameControllerMappingForGUID", lux_cast(SDL_GameControllerMappingForGUID)},
	 {"GameControllerName", lux_cast(SDL_GameControllerName)},
	 {"GameControllerNameForIndex", lux_cast(SDL_GameControllerNameForIndex)},
	 {"GameControllerOpen", lux_cast(SDL_GameControllerOpen)},
	 {"GameControllerUpdate", lux_cast(SDL_GameControllerUpdate)},
	 {"IsGameController", lux_cast(SDL_IsGameController)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

