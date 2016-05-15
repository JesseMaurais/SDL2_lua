#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

extern "C" int luaopen_SDL2_haptic(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Initialize */

	if (SDL_InitSubSystem(SDL_INIT_HAPTIC) < 0)
	{
		auto error = SDL_GetError();
		return luaL_error(state, "SDL_InitSubSystem: %s", error);
	}

	/* Parameters */

	lux_Reg<lua_Integer> args[] =
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
	lux_settable(state, args);

	/* Functions */

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
	REG(HapticSetAutocenter)
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

	/* Structures */

	luaL_newmetatable(state, Type<SDL_Haptic>::name);

	/* Done */

	return 0;
}

