#include "SDL.hpp"

extern "C" int luaopen_SDL_haptic(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 lua_Integer value;
	}
	args [] =
	{
	// effects
	ARG(HAPTIC_CONSTANT)
	ARG(HAPTIC_SINE)
	ARG(HAPTIC_LEFTRIGHT)
	ARG(HAPTIC_TRIANGLE)
	ARG(HAPTIC_SAWTOOTHUP)
	ARG(HAPTIC_SAWTOOTHDOWN)
	ARG(HAPTIC_RAMP)
	ARG(HAPTIC_SPRING)
	ARG(HAPTIC_DAMPER)
 	ARG(HAPTIC_INERTIA)
	ARG(HAPTIC_FRICTION)
	ARG(HAPTIC_CUSTOM)
	// device features
 	ARG(HAPTIC_GAIN)
	ARG(HAPTIC_AUTOCENTER)
	ARG(HAPTIC_STATUS)
	ARG(HAPTIC_PAUSE)
	// directions
	ARG(HAPTIC_POLAR)
	ARG(HAPTIC_CARTESIAN)
	ARG(HAPTIC_SPHERICAL)
//	ARG(HAPTIC_INFINITY)
	END
	};
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs [] =
	{
	REG(HapticClose)
	REG(HapticDestroyEffect)
	REG(HapticEffectSupported)
	REG(HapticGetEffectStatus)
	REG(HapticIndex)
	REG(HapticName)
	REG(HapticNewEffect)
	REG(HapticNumAxes)
	REG(HapticNumEffects)
	REG(HapticNumEffectsPlaying)
	REG(HapticOpen)
	REG(HapticOpenFromJoystick)
	REG(HapticOpenFromMouse)
	REG(HapticOpened)
	REG(HapticPause)
	REG(HapticQuery)
	REG(HapticRumbleInit)
	REG(HapticRumblePlay)
	REG(HapticRumbleStop)
	REG(HapticRumbleSupported)
	REG(HapticRunEffect)
//	REG(HapticSetAudioCenter)
	REG(HapticSetGain)
	REG(HapticStopAll)
	REG(HapticStopEffect)
	REG(HapticUnpause)
	REG(HapticUpdateEffect)
	REG(JoystickIsHaptic)
	REG(MouseIsHaptic)
	REG(NumHaptics)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

