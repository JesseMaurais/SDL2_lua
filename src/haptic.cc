#include "SDL.hpp"

template <> luaL_Reg lux_Union<SDL_HapticDirection>::index[] =
{
	lux_index(SDL_HapticDirection, dir)
};

template <> luaL_Reg lux_Union<SDL_HapticConstant>::index[] =
{
	lux_subindex(SDL_HapticConstant, direction)
};
template <> luaL_Reg lux_Union<SDL_HapticConstant>::newindex[] =
{
	lux_newindex(SDL_HapticConstant, length),
	lux_newindex(SDL_HapticConstant, delay),
	lux_newindex(SDL_HapticConstant, button),
	lux_newindex(SDL_HapticConstant, interval),
	lux_newindex(SDL_HapticConstant, level),
	lux_newindex(SDL_HapticConstant, attack_length),
	lux_newindex(SDL_HapticConstant, attack_level),
	lux_newindex(SDL_HapticConstant, fade_length),
	lux_newindex(SDL_HapticConstant, fade_level)
};

template <> luaL_Reg lux_Union<SDL_HapticPeriodic>::index[] =
{
	lux_subindex(SDL_HapticPeriodic, direction)
};
template <> luaL_Reg lux_Union<SDL_HapticPeriodic>::newindex[] =
{
	lux_newindex(SDL_HapticPeriodic, length),
	lux_newindex(SDL_HapticPeriodic, delay),
	lux_newindex(SDL_HapticPeriodic, button),
	lux_newindex(SDL_HapticPeriodic, interval),
	lux_newindex(SDL_HapticPeriodic, period),
	lux_newindex(SDL_HapticPeriodic, magnitude),
	lux_newindex(SDL_HapticPeriodic, offset),
	lux_newindex(SDL_HapticPeriodic, phase),
	lux_newindex(SDL_HapticPeriodic, attack_length),
	lux_newindex(SDL_HapticPeriodic, attack_level),
	lux_newindex(SDL_HapticPeriodic, fade_length),
	lux_newindex(SDL_HapticPeriodic, fade_level)
};

template <> luaL_Reg lux_Union<SDL_HapticCondition>::index[] =
{
	lux_subindex(SDL_HapticCondition, direction),
	lux_index(SDL_HapticCondition, right_sat),
	lux_index(SDL_HapticCondition, left_sat),
	lux_index(SDL_HapticCondition, right_coeff),
	lux_index(SDL_HapticCondition, left_coeff),
	lux_index(SDL_HapticCondition, deadband),
	lux_index(SDL_HapticCondition, center)
};
template <> luaL_Reg lux_Union<SDL_HapticCondition>::newindex[] =
{
	lux_newindex(SDL_HapticCondition, length),
	lux_newindex(SDL_HapticCondition, delay),
	lux_newindex(SDL_HapticCondition, button),
	lux_newindex(SDL_HapticCondition, interval)
};

template <> luaL_Reg lux_Union<SDL_HapticRamp>::index[] =
{
	lux_subindex(SDL_HapticRamp, direction)
};
template <> luaL_Reg lux_Union<SDL_HapticRamp>::newindex[] =
{
	lux_newindex(SDL_HapticRamp, length),
	lux_newindex(SDL_HapticRamp, delay),
	lux_newindex(SDL_HapticRamp, button),
	lux_newindex(SDL_HapticRamp, interval),
	lux_newindex(SDL_HapticRamp, start),
	lux_newindex(SDL_HapticRamp, end),
	lux_newindex(SDL_HapticRamp, attack_length),
	lux_newindex(SDL_HapticRamp, attack_level),
	lux_newindex(SDL_HapticRamp, fade_length),
	lux_newindex(SDL_HapticRamp, fade_level)
};

template <> luaL_Reg lux_Union<SDL_HapticCustom>::index[] =
{
	lux_subindex(SDL_HapticCustom, direction),
	lux_index(SDL_HapticCustom, data)
};
template <> luaL_Reg lux_Union<SDL_HapticCustom>::newindex[] =
{
	lux_newindex(SDL_HapticCustom, length),
	lux_newindex(SDL_HapticCustom, delay),
	lux_newindex(SDL_HapticCustom, button),
	lux_newindex(SDL_HapticCustom, interval),
	lux_newindex(SDL_HapticCustom, channels),
	lux_newindex(SDL_HapticCustom, period),
	lux_newindex(SDL_HapticCustom, samples),
	lux_newindex(SDL_HapticCustom, data),
	lux_newindex(SDL_HapticCustom, attack_length),
	lux_newindex(SDL_HapticCustom, attack_level),
	lux_newindex(SDL_HapticCustom, fade_length),
	lux_newindex(SDL_HapticCustom, fade_level)
};

template <> luaL_Reg lux_Union<SDL_HapticLeftRight>::newindex[] =
{
	lux_newindex(SDL_HapticLeftRight, length),
	lux_newindex(SDL_HapticLeftRight, large_magnitude),
	lux_newindex(SDL_HapticLeftRight, small_magnitude)
};

template <> luaL_Reg lux_Union<SDL_HapticEffect>::index[] =
{
	lux_index(SDL_HapticEffect, type),
	lux_subindex(SDL_HapticEffect, constant),
	lux_subindex(SDL_HapticEffect, periodic),
	lux_subindex(SDL_HapticEffect, condition),
	lux_subindex(SDL_HapticEffect, ramp),
	lux_subindex(SDL_HapticEffect, leftright),
	lux_subindex(SDL_HapticEffect, custom)
};

extern "C" int luaopen_SDL_haptic(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 int value;
	}
	args [] =
	{
	 // effects
	 {"HAPTIC_CONSTANT", SDL_HAPTIC_CONSTANT},
	 {"HAPTIC_SINE", SDL_HAPTIC_SINE},
	 {"HAPTIC_LEFTRIGHT", SDL_HAPTIC_LEFTRIGHT},
	 {"HAPTIC_TRIANGLE", SDL_HAPTIC_TRIANGLE},
	 {"HAPTIC_SAWTOOTHUP", SDL_HAPTIC_SAWTOOTHUP},
	 {"HAPTIC_SAWTOOTHDOWN", SDL_HAPTIC_SAWTOOTHDOWN},
	 {"HAPTIC_RAMP", SDL_HAPTIC_RAMP},
	 {"HAPTIC_SPRING", SDL_HAPTIC_SPRING},
	 {"HAPTIC_DAMPER", SDL_HAPTIC_DAMPER},
 	 {"HAPTIC_INERTIA", SDL_HAPTIC_INERTIA},
	 {"HAPTIC_FRICTION", SDL_HAPTIC_FRICTION},
	 {"HAPTIC_CUSTOM", SDL_HAPTIC_CUSTOM},
	 // device features
 	 {"HAPTIC_GAIN", SDL_HAPTIC_GAIN},
	 {"HAPTIC_AUTOCENTER", SDL_HAPTIC_AUTOCENTER},
	 {"HAPTIC_STATUS", SDL_HAPTIC_STATUS},
	 {"HAPTIC_PAUSE", SDL_HAPTIC_PAUSE},
	 // directions
	 {"HAPTIC_POLAR", SDL_HAPTIC_POLAR},
	 {"HAPTIC_CARTESIAN", SDL_HAPTIC_CARTESIAN},
	 {"HAPTIC_SPHERICAL", SDL_HAPTIC_SPHERICAL},
//	 {"HAPTIC_INFINITY", SDL_HAPTIC_INFINITY},
	 // end
	 {nullptr, 0}
	};
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs [] =
	{
	 {"HapticClose", lux_cast(SDL_HapticClose)},
	 {"HapticDestroyEffect", lux_cast(SDL_HapticDestroyEffect)},
	 {"HapticEffectSupported", lux_cast(SDL_HapticEffectSupported)},
	 {"HapticGetEffectStatus", lux_cast(SDL_HapticGetEffectStatus)},
	 {"HapticIndex", lux_cast(SDL_HapticIndex)},
	 {"HapticName", lux_cast(SDL_HapticName)},
	 {"HapticNewEffect", lux_cast(SDL_HapticNewEffect)},
	 {"HapticNumAxes", lux_cast(SDL_HapticNumAxes)},
	 {"HapticNumEffects", lux_cast(SDL_HapticNumEffects)},
	 {"HapticNumEffectsPlaying", lux_cast(SDL_HapticNumEffectsPlaying)},
	 {"HapticOpen", lux_cast(SDL_HapticOpen)},
	 {"HapticOpenFromJoystick", lux_cast(SDL_HapticOpenFromJoystick)},
	 {"HapticOpenFromMouse", lux_cast(SDL_HapticOpenFromMouse)},
	 {"HapticOpened", lux_cast(SDL_HapticOpened)},
	 {"HapticPause", lux_cast(SDL_HapticPause)},
	 {"HapticQuery", lux_cast(SDL_HapticQuery)},
	 {"HapticRumbleInit", lux_cast(SDL_HapticRumbleInit)},
	 {"HapticRumblePlay", lux_cast(SDL_HapticRumblePlay)},
	 {"HapticRumbleStop", lux_cast(SDL_HapticRumbleStop)},
	 {"HapticRumbleSupported", lux_cast(SDL_HapticRumbleSupported)},
	 {"HapticRunEffect", lux_cast(SDL_HapticRunEffect)},
	 {"HapticSetAudiocenter", lux_cast(SDL_HapticSetAutocenter)},
	 {"HapticSetGain", lux_cast(SDL_HapticSetGain)},
	 {"HapticStopAll", lux_cast(SDL_HapticStopAll)},
	 {"HapticStopEffect", lux_cast(SDL_HapticStopEffect)},
	 {"HapticUnpause", lux_cast(SDL_HapticUnpause)},
	 {"HapticUpdateEffect", lux_cast(SDL_HapticUpdateEffect)},
	 {"JoystickIsHaptic", lux_cast(SDL_JoystickIsHaptic)},
	 {"MouseIsHaptic", lux_cast(SDL_MouseIsHaptic)},
	 {"NumHaptics", lux_cast(SDL_NumHaptics)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

