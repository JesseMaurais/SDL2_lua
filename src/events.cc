#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

template <> luaL_Reg lux_Class<SDL_Event>::index[] =
	{
	{"type", lux_member(SDL_Event, type)},
	{nullptr}
	};

extern "C" int luaopen_SDL2_events(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}

	/* Initialize */

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		auto error = SDL_GetError();
		return luaL_error(state, "SDL_InitSubSystem: %s", error);
	}

	/* Parameters */

	lux_Reg<lua_Integer> args [] =
	{
	// SDL_EventType
	ARG(QUIT)
	ARG(APP_TERMINATING)
	ARG(APP_LOWMEMORY)
	ARG(APP_WILLENTERBACKGROUND)
	ARG(APP_DIDENTERBACKGROUND)
	ARG(APP_WILLENTERFOREGROUND)
	ARG(APP_DIDENTERFOREGROUND)
	ARG(WINDOWEVENT)
	ARG(SYSWMEVENT)
	ARG(KEYDOWN)
	ARG(KEYUP)
	ARG(TEXTEDITING)
	ARG(TEXTINPUT)
	ARG(MOUSEMOTION)
	ARG(MOUSEBUTTONDOWN)
	ARG(MOUSEBUTTONUP)
	ARG(MOUSEWHEEL)
	ARG(JOYAXISMOTION)
	ARG(JOYBALLMOTION)
	ARG(JOYHATMOTION)
//	ARG(JOYBUTTONMOTION)
	ARG(JOYBUTTONDOWN)
	ARG(JOYBUTTONUP)
	ARG(JOYDEVICEADDED)
	ARG(JOYDEVICEREMOVED)
	ARG(CONTROLLERAXISMOTION)
	ARG(CONTROLLERBUTTONDOWN)
	ARG(CONTROLLERBUTTONUP)
	ARG(CONTROLLERDEVICEADDED)
	ARG(CONTROLLERDEVICEREMOVED)
//	ARG(CONTROLLERDEVICEREMAPPED)
	ARG(FINGERDOWN)
	ARG(FINGERUP)
	ARG(FINGERMOTION)
	ARG(DOLLARGESTURE)
	ARG(MULTIGESTURE)
	ARG(CLIPBOARDUPDATE)
	ARG(DROPFILE)
//	ARG(AUDIODEVICEADDED)
//	ARG(AUDIODEVICEREMOVED)
	ARG(RENDER_TARGETS_RESET)
//	ARG(RENDER_DEVICE_RESET)
	// SDL_WindowEventID
	ARG(WINDOWEVENT_SHOWN)
	ARG(WINDOWEVENT_HIDDEN)
	ARG(WINDOWEVENT_EXPOSED)
	ARG(WINDOWEVENT_MOVED)
	ARG(WINDOWEVENT_RESIZED)
	ARG(WINDOWEVENT_SIZE_CHANGED)
	ARG(WINDOWEVENT_MINIMIZED)
	ARG(WINDOWEVENT_MAXIMIZED)
	ARG(WINDOWEVENT_RESTORED)
	ARG(WINDOWEVENT_ENTER)
	ARG(WINDOWEVENT_LEAVE)
	ARG(WINDOWEVENT_FOCUS_GAINED)
	ARG(WINDOWEVENT_FOCUS_LOST)
	ARG(WINDOWEVENT_CLOSE)
	// SDL_eventaction
	ARG(ADDEVENT)
	ARG(PEEKEVENT)
 	ARG(GETEVENT)
	END
	};
	lux_settable(state, args);

	/* Functions */

	luaL_Reg regs [] = 
	{
//	REG(AddEventWatch)
//	REG(DelEventWatch)
	REG(EventState)
//	REG(FilterEvents)
	REG(FlushEvent)
	REG(FlushEvents)
//	REG(GetEventFilter)
	REG(GetNumTouchDevices)
	REG(GetNumTouchFingers)
	REG(GetTouchDevice)
	REG(GetTouchFinger)
	REG(HasEvent)
	REG(HasEvents)
	REG(LoadDollarTemplates)
	REG(PeepEvents)
	REG(PollEvent)
	REG(PumpEvents)
	REG(PushEvent)
//	REG(QuitRequested)
	REG(RecordGesture)
	REG(RegisterEvents)
	REG(SaveAllDollarTemplates)
	REG(SaveDollarTemplate)
//	REG(SetEventFilter)
	REG(WaitEvent)
	REG(WaitEventTimeout)
	END
	};
	luaL_setfuncs(state, regs, 0);

	/* Structures */

	lux_Class<SDL_Event>::require(state);
	lua_setfield(state, -2, "Event");

	/* Done */
	
	return 0;
}
 
