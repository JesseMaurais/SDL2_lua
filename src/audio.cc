#include "SDL.hpp"


template <> void lux_push<SDL_AudioStatus>(lua_State *state, SDL_AudioStatus s)
{
	lua_pushinteger(state, s);
}

template <> SDL_AudioStatus lux_to<SDL_AudioStatus>(lua_State *state, int in)
{
	return (SDL_AudioStatus) luaL_checkinteger(state, in);
}

/*
template <> luaL_Reg lux_Union<SDL_AudioSpec>::index[] =
{
	lux_index(SDL_AudioSpec, freq),
	lux_index(SDL_AudioSpec, format),
	lux_index(SDL_AudioSpec, channels),
	lux_index(SDL_AudioSpec, silence),
	lux_index(SDL_AudioSpec, samples),
	lux_index(SDL_AudioSpec, size)
//	lux_index(SDL_AudioSpec, callback),
//	lux_index(SDL_AudioSpec, userdata)
};

template <> luaL_Reg lux_Union<SDL_AudioCVT>::index[] =
{
	lux_index(SDL_AudioCVT, needed),
	lux_index(SDL_AudioCVT, src_format),
	lux_index(SDL_AudioCVT, dst_format),
	lux_index(SDL_AudioCVT, rate_incr),
	lux_index(SDL_AudioCVT, buf),
	lux_index(SDL_AudioCVT, len),
	lux_index(SDL_AudioCVT, len_cvt),
	lux_index(SDL_AudioCVT, len_mult),
	lux_index(SDL_AudioCVT, len_ratio)
//	lux_index(SDL_AudioCVT, filters),
//	lux_index(SDL_AudioCVT, filter_index)
};
*/


extern "C" int luaopen_SDL_audio(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	lux_Union<SDL_AudioSpec>::open(state);
	lux_Union<SDL_AudioCVT>::open(state);
	struct {
	 const char *name;
	 int value;
	}
	args [] =
	{
	 // SDL_AudioStatus
	 {"AUDIO_STOPPED", SDL_AUDIO_STOPPED},
	 {"AUDIO_PLAYING", SDL_AUDIO_PLAYING},
	 {"AUDIO_PAUSED", SDL_AUDIO_PAUSED},
	 // SDL_AudioFormat
	 {"AUDIO_MASK_BITSIZE", SDL_AUDIO_MASK_BITSIZE},
	 {"AUDIO_MASK_DATATYPE", SDL_AUDIO_MASK_DATATYPE},
	 {"AUDIO_MASK_ENDIAN", SDL_AUDIO_MASK_ENDIAN},
	 {"AUDIO_MASK_SIGNED", SDL_AUDIO_MASK_SIGNED},
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
//	 {"AudioInit", lux_cast(SDL_AudioInit)},
//	 {"AudioQuit", lux_cast(SDL_AudioQuit)},
	 {"BuildAudioCVT", lux_cast(SDL_BuildAudioCVT)},
//	 {"ClearQueuedAudio", lux_cast(SDL_ClearQueuedAudio)},
	 {"CloseAudio", lux_cast(SDL_CloseAudio)},
	 {"CloseAudioDevice", lux_cast(SDL_CloseAudioDevice)},
	 {"ConvertAudio", lux_cast(SDL_ConvertAudio)},
//	 {"FreeWAV", lux_cast(SDL_FreeWAV)},
	 {"GetAudioDeviceName", lux_cast(SDL_GetAudioDeviceName)},
	 {"GetAudioDeviceStatus", lux_cast(SDL_GetAudioDeviceStatus)},
	 {"GetAudioDriver", lux_cast(SDL_GetAudioDriver)},
	 {"GetAudioStatus", lux_cast(SDL_GetAudioStatus)},
	 {"GetCurrentAudioDriver", lux_cast(SDL_GetCurrentAudioDriver)},
	 {"GetNumAudioDevices", lux_cast(SDL_GetNumAudioDevices)},
	 {"GetNumAudioDrivers", lux_cast(SDL_GetNumAudioDrivers)},
//	 {"GetQueuedAudioSize", lux_cast(SDL_GetQueuedAudioSize)},
//	 {"LoadWAV", lux_cast(SDL_LoadWAV)},
//	 {"LoadWAV_RW", lux_cast(SDL_LoadWAV_RW)},
	 {"LockAudio", lux_cast(SDL_LockAudio)},
	 {"LockAudioDevice", lux_cast(SDL_LockAudioDevice)},
//	 {"MixAudio", lux_cast(SDL_MixAudio)},
//	 {"MixAudioFormat", lux_cast(SDL_MixAudioFormat)},
	 {"OpenAudio", lux_cast(SDL_OpenAudio)},
	 {"OpenAudioDevice", lux_cast(SDL_OpenAudioDevice)},
	 {"PauseAudio", lux_cast(SDL_PauseAudio)},
	 {"PauseAudioDevice", lux_cast(SDL_PauseAudioDevice)},
//	 {"QueueAudio", lux_cast(SDL_QueueAudio)},
	 {"UnlockAudio", lux_cast(SDL_UnlockAudio)},
	 {"UnlockAudioDevice", lux_cast(SDL_UnlockAudioDevice)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 0;
}

