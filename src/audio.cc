#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

template <> luaL_Reg lux_Class<SDL_AudioSpec>::index[] =
	{
	MEM(SDL_AudioSpec, freq)
	MEM(SDL_AudioSpec, format)
	MEM(SDL_AudioSpec, channels)
	MEM(SDL_AudioSpec, silence)
	MEM(SDL_AudioSpec, samples)
	MEM(SDL_AudioSpec, size)
	END
	};

template <> luaL_Reg lux_Class<SDL_AudioCVT>::index[] =
	{
	MEM(SDL_AudioCVT, needed)
	MEM(SDL_AudioCVT, src_format)
	MEM(SDL_AudioCVT, dst_format)
	MEM(SDL_AudioCVT, rate_incr)
	MEM(SDL_AudioCVT, buf)
	MEM(SDL_AudioCVT, len)
	MEM(SDL_AudioCVT, len_cvt)
	MEM(SDL_AudioCVT, len_mult)
	MEM(SDL_AudioCVT, len_ratio)
//	MEM(SDL_AudioCVT, filters)
	MEM(SDL_AudioCVT, filter_index)
	END
	};

extern "C" int luaopen_SDL2_audio(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Initialize */

	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
	{
		auto error = SDL_GetError();
		return luaL_error(state, "SDL_InitSubSystem: %s", error);
	}

	/* Parameters */
	
	lux_Reg<lua_Integer> args [] =
	{
	// SDL_AudioStatus
	ARG(AUDIO_STOPPED)
	ARG(AUDIO_PLAYING)
	ARG(AUDIO_PAUSED)
	// SDL_AudioFormat
	ARG(AUDIO_MASK_BITSIZE)
	ARG(AUDIO_MASK_DATATYPE)
	ARG(AUDIO_MASK_ENDIAN)
	ARG(AUDIO_MASK_SIGNED)
	// format
	{"AUDIO_S8", AUDIO_S8},
	{"AUDIO_U8", AUDIO_U8},
	{"AUDIO_S16LSB", AUDIO_S16LSB},
	{"AUDIO_S16MSB", AUDIO_S16MSB},
	{"AUDIO_S16SYS", AUDIO_S16SYS},
	{"AUDIO_S16", AUDIO_S16},
	{"AUDIO_U16LSB", AUDIO_S16LSB},
	{"AUDIO_U16MSB", AUDIO_U16MSB},
	{"AUDIO_U16SYS", AUDIO_U16SYS},
	{"AUDIO_U16", AUDIO_U16},
	{"AUDIO_S32LSB", AUDIO_S32LSB},
	{"AUDIO_S32MSB", AUDIO_S32MSB},
	{"AUDIO_S32SYS", AUDIO_S32SYS},
	{"AUDIO_S32", AUDIO_S32},
	{"AUDIO_F32LSB", AUDIO_F32LSB},
	{"AUDIO_F32MSB", AUDIO_F32MSB},
	{"AUDIO_F32SYS", AUDIO_F32SYS},
	{"AUDIO_F32", AUDIO_F32},
	END
	};
	lux_settable(state, args);

	/* Functions */

	luaL_Reg regs [] =
	{
//	REG(AudioInit)
//	REG(AudioQuit)
	REG(BuildAudioCVT)
	#if SDL_VERSION_ATLEAST(2, 0, 4)
	REG(ClearQueuedAudio)
	#endif
	REG(CloseAudio)
	REG(CloseAudioDevice)
	REG(ConvertAudio)
//	REG(FreeWAV)
	REG(GetAudioDeviceName)
	REG(GetAudioDeviceStatus)
	REG(GetAudioDriver)
	REG(GetAudioStatus)
	REG(GetCurrentAudioDriver)
	REG(GetNumAudioDevices)
	REG(GetNumAudioDrivers)
	#if SDL_VERSION_ATLEAST(2, 0, 4)
	REG(GetQueuedAudioSize)
	#endif
//	REG(LoadWAV)
//	REG(LoadWAV_RW)
	REG(LockAudio)
	REG(LockAudioDevice)
//	REG(MixAudio)
//	REG(MixAudioFormat)
	REG(OpenAudio)
	REG(OpenAudioDevice)
	REG(PauseAudio)
	REG(PauseAudioDevice)
	#if SDL_VERSION_ATLEAST(2, 0, 4)
//	REG(QueueAudio)
	#endif
	REG(UnlockAudio)
	REG(UnlockAudioDevice)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Structures */

	lux_Class<SDL_AudioSpec>::require(state);
	lux_Class<SDL_AudioCVT>::require(state);

	/* Done */

	return 0;
}

