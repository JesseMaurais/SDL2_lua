#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "Common.h"

template <> Mix_MusicType lux_to<Mix_MusicType>(lua_State *state, int arg)
{
	const char *opt[] =
	{
	"NONE",
	"CMD",
	"WAV",
	"MOD",
	"MID",
	"OGG",
	"MP3",
	"MP3_MAD",
	"FLAC",
	"MODPLUG",
	nullptr
	};
	switch (luaL_checkoption(state, arg, *opt, opt))
	{
	case 0: return MUS_NONE;
	case 1: return MUS_CMD;
	case 2: return MUS_WAV;
	case 3: return MUS_MOD;
	case 4: return MUS_MID;
	case 5: return MUS_OGG;
	case 6: return MUS_MP3;
	case 7: return MUS_MP3_MAD;
	case 8: return MUS_FLAC;
	case 9: return MUS_MODPLUG;
	};
}

static int QuerySpec(lua_State *state)
{
	int frequency;
	Uint16 format;
	int channels;
	if (Mix_QuerySpec(&frequency, &format, &channels))
	{
		return lux_push(state, frequency, format, channels);
	}
	return 0;
}

static Mix_Chunk *LoadWAV(const char *path)
{
	return Mix_LoadWAV(path);
}

static int PlayChannel(int channel, Mix_Chunk *chunk, int loops)
{
	return Mix_PlayChannel(channel, chunk, loops);
}

#undef REG
#define REG(name) {#name, lux_cast(Mix_##name)},

extern "C" int luaopen_SDL_mixer(lua_State *state)
{
	/* Initialize */

	if (!Mix_Init(MIX_INIT_FLAC|MIX_INIT_MOD|MIX_INIT_MP3|MIX_INIT_OGG))
	{
		const char *error = Mix_GetError();
		return luaL_error(state, "Mix_Init: %s", error);
	}
	else 
	if (atexit(Mix_Quit))
	{
		return luaL_error(state, "Cannot make exit (atexit < 0)");
	}

	/* Module Metatable */

	luaL_newmetatable(state, "SDL2_mixer");

	/* Functions */

	luaL_Reg regs [] =
	{
	REG(OpenAudio)
	REG(AllocateChannels)
	{"QuerySpec", QuerySpec},
	{"LoadWAV", lux_cast(LoadWAV)},
	REG(LoadWAV_RW)
	REG(LoadMUS)
	REG(LoadMUS_RW)
	REG(LoadMUSType_RW)
	REG(QuickLoad_WAV)
	REG(QuickLoad_RAW)
	REG(FreeChunk)
	REG(FreeMusic)
	REG(GetNumChunkDecoders)
	REG(GetChunkDecoder)
	REG(GetNumMusicDecoders)
	REG(GetMusicDecoder)
//	REG(GetMusicType)
//	REG(SetPostMix)
//	REG(HookMusic)
//	REG(HookMusicFinished)
//	REG(GetMusicHookData)
//	REG(ChannelFinished)
//	REG(RegisterEffect)
//	REG(UnregisterEffect)
//	REG(UnregisterAllEffects)
	REG(SetPanning)
	REG(SetPosition)
	REG(SetDistance)
	REG(SetReverseStereo)
	REG(ReserveChannels)
	REG(GroupChannel)
	REG(GroupChannels)
	REG(GroupAvailable)
	REG(GroupCount)
	REG(GroupOldest)
	REG(GroupNewer)
	{"PlayChannel", lux_cast(PlayChannel)},
	REG(PlayChannelTimed)
	REG(PlayMusic)
	REG(FadeInMusic)
	REG(FadeInMusicPos)
	REG(FadeInChannelTimed)
	REG(Volume)
	REG(VolumeChunk)
	REG(VolumeMusic)
	REG(HaltChannel)
	REG(HaltGroup)
	REG(HaltMusic)
	REG(ExpireChannel)
	REG(FadeOutChannel)
	REG(FadeOutGroup)
	REG(FadeOutMusic)
	REG(FadingMusic)
	REG(FadingChannel)
	REG(Pause)
	REG(Resume)
	REG(Paused)
	REG(PauseMusic)
	REG(ResumeMusic)
	REG(RewindMusic)
	REG(PausedMusic)
	REG(SetMusicPosition)
	REG(Playing)
	REG(PlayingMusic)
	REG(SetMusicCMD)
	REG(SetSynchroValue)
	REG(GetSynchroValue)
	REG(SetSoundFonts)
	REG(GetSoundFonts)
//	REG(EachSoundFont)
	REG(GetChunk)
	REG(CloseAudio)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Done */

	return 0;
}
