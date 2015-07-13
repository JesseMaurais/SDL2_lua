#include "SDL.hpp"

extern "C" int luaopen_SDL_audio(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 lua_Integer value;
	}
	args [] =
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
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs [] =
	{
//	REG(AudioInit)
//	REG(AudioQuit)
	REG(BuildAudioCVT)
//	REG(ClearQueuedAudio)
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
//	REG(GetQueuedAudioSize)
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
//	REG(QueueAudio)
	REG(UnlockAudio)
	REG(UnlockAudioDevice)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 0;
}

