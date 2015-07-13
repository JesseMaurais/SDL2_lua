#include "SDL.hpp"


template <> luaL_Reg lux_Union<SDL_Event>::index [] =
{
	lux_index(SDL_Event, type),
	lux_subindex(SDL_Event, window),
	lux_subindex(SDL_Event, key),
	lux_subindex(SDL_Event, edit),
	lux_subindex(SDL_Event, text),
	lux_subindex(SDL_Event, motion),
	lux_subindex(SDL_Event, button),
	lux_subindex(SDL_Event, wheel),
	lux_subindex(SDL_Event, jaxis),
	lux_subindex(SDL_Event, jball),
	lux_subindex(SDL_Event, jhat),
	lux_subindex(SDL_Event, jbutton),
	lux_subindex(SDL_Event, jdevice),
	lux_subindex(SDL_Event, caxis),
	lux_subindex(SDL_Event, cbutton),
	lux_subindex(SDL_Event, cdevice),
//	lux_subindex(SDL_Event, adevice),
//	lux_subindex(SDL_Event, quit),
	lux_subindex(SDL_Event, user),
//	lux_subindex(SDL_Event, syswm),
	lux_subindex(SDL_Event, tfinger),
	lux_subindex(SDL_Event, mgesture),
	lux_subindex(SDL_Event, dgesture),
	lux_subindex(SDL_Event, drop)
};
template <> luaL_Reg lux_Union<SDL_WindowEvent>::index [] =
{
	lux_index(SDL_WindowEvent, windowID),
	lux_index(SDL_WindowEvent, event),
	lux_index(SDL_WindowEvent, data1),
	lux_index(SDL_WindowEvent, data2)
};
template <> luaL_Reg lux_Union<SDL_KeyboardEvent>::index [] =
{
	lux_index(SDL_KeyboardEvent, windowID),
	lux_index(SDL_KeyboardEvent, state),
	lux_index(SDL_KeyboardEvent, repeat),
	lux_subindex(SDL_KeyboardEvent, keysym)
};
template <> luaL_Reg lux_Union<SDL_TextEditingEvent>::index [] =
{
	lux_index(SDL_TextEditingEvent, windowID),
//	lux_index(SDL_TextEditingEvent, text),
	lux_index(SDL_TextEditingEvent, start),
	lux_index(SDL_TextEditingEvent, length)
};
template <> luaL_Reg lux_Union<SDL_TextInputEvent>::index [] =
{
	lux_index(SDL_TextInputEvent, windowID),
//	lux_index(SDL_TextInputEvent, text),
};
template <> luaL_Reg lux_Union<SDL_MouseMotionEvent>::index [] =
{
	lux_index(SDL_MouseMotionEvent, windowID),
	lux_index(SDL_MouseMotionEvent, which),
	lux_index(SDL_MouseMotionEvent, state),
	lux_index(SDL_MouseMotionEvent, x),
	lux_index(SDL_MouseMotionEvent, y),
	lux_index(SDL_MouseMotionEvent, xrel),
	lux_index(SDL_MouseMotionEvent, yrel)
};
template <> luaL_Reg lux_Union<SDL_MouseButtonEvent>::index [] =
{
	lux_index(SDL_MouseButtonEvent, windowID),
	lux_index(SDL_MouseButtonEvent, which),
	lux_index(SDL_MouseButtonEvent, button),
	lux_index(SDL_MouseButtonEvent, state),
	lux_index(SDL_MouseButtonEvent, clicks),
	lux_index(SDL_MouseButtonEvent, x),
	lux_index(SDL_MouseButtonEvent, y)
};
template <> luaL_Reg lux_Union<SDL_MouseWheelEvent>::index [] =
{
	lux_index(SDL_MouseWheelEvent, windowID),
	lux_index(SDL_MouseWheelEvent, which),
	lux_index(SDL_MouseWheelEvent, x),
	lux_index(SDL_MouseWheelEvent, y),
//	lux_index(SDL_MouseWheelEvent, direction)
};
template <> luaL_Reg lux_Union<SDL_JoyAxisEvent>::index [] =
{
	lux_index(SDL_JoyAxisEvent, which),
	lux_index(SDL_JoyAxisEvent, axis),
	lux_index(SDL_JoyAxisEvent, value)
};
template <> luaL_Reg lux_Union<SDL_JoyBallEvent>::index [] =
{
	lux_index(SDL_JoyBallEvent, which),
	lux_index(SDL_JoyBallEvent, ball),
	lux_index(SDL_JoyBallEvent, xrel),
	lux_index(SDL_JoyBallEvent, yrel)
};
template <> luaL_Reg lux_Union<SDL_JoyHatEvent>::index [] =
{
	lux_index(SDL_JoyHatEvent, which),
	lux_index(SDL_JoyHatEvent, hat),
	lux_index(SDL_JoyHatEvent, value)
};
template <> luaL_Reg lux_Union<SDL_JoyButtonEvent>::index [] =
{
	lux_index(SDL_JoyButtonEvent, which),
	lux_index(SDL_JoyButtonEvent, button),
	lux_index(SDL_JoyButtonEvent, state)
};
template <> luaL_Reg lux_Union<SDL_JoyDeviceEvent>::index [] =
{
	lux_index(SDL_JoyDeviceEvent, which)
};
template <> luaL_Reg lux_Union<SDL_ControllerAxisEvent>::index [] =
{
	lux_index(SDL_ControllerAxisEvent, which),
	lux_index(SDL_ControllerAxisEvent, axis),
	lux_index(SDL_ControllerAxisEvent, value)
};
template <> luaL_Reg lux_Union<SDL_ControllerButtonEvent>::index [] =
{
	lux_index(SDL_ControllerButtonEvent, which),
	lux_index(SDL_ControllerButtonEvent, button),
	lux_index(SDL_ControllerButtonEvent, state)
};
template <> luaL_Reg lux_Union<SDL_ControllerDeviceEvent>::index [] =
{
	lux_index(SDL_ControllerButtonEvent, which)
};
/*
template <> luaL_Reg lux_Union<SDL_AudioDeviceEvent>::index [] =
{
	lux_index(SDL_AudioDeviceEvent, which),
	lux_index(SDL_AudiODeviceEvent, iscapture)
};
*/
template <> luaL_Reg lux_Union<SDL_UserEvent>::index [] = 
{
	lux_index(SDL_UserEvent, windowID),
	lux_index(SDL_UserEvent, code),
	lux_index(SDL_UserEvent, data1),
	lux_index(SDL_UserEvent, data2)
};
template <> luaL_Reg lux_Union<SDL_TouchFingerEvent>::index [] =
{
	lux_index(SDL_TouchFingerEvent, touchId),
	lux_index(SDL_TouchFingerEvent, fingerId),
	lux_index(SDL_TouchFingerEvent, x),
	lux_index(SDL_TouchFingerEvent, y),
	lux_index(SDL_TouchFingerEvent, dx),
	lux_index(SDL_TouchFingerEvent, dy),
	lux_index(SDL_TouchFingerEvent, pressure)
};
template <> luaL_Reg lux_Union<SDL_MultiGestureEvent>::index [] =
{
	lux_index(SDL_MultiGestureEvent, touchId),
	lux_index(SDL_MultiGestureEvent, dTheta),
	lux_index(SDL_MultiGestureEvent, dDist),
	lux_index(SDL_MultiGestureEvent, x),
	lux_index(SDL_MultiGestureEvent, y),
	lux_index(SDL_MultiGestureEvent, numFingers)
};
template <> luaL_Reg lux_Union<SDL_DollarGestureEvent>::index [] =
{
	lux_index(SDL_DollarGestureEvent, touchId),
	lux_index(SDL_DollarGestureEvent, gestureId),
	lux_index(SDL_DollarGestureEvent, numFingers),
	lux_index(SDL_DollarGestureEvent, error),
	lux_index(SDL_DollarGestureEvent, x),
	lux_index(SDL_DollarGestureEvent, y)
};
/*
template <> luaL_Reg lux_Union<SDL_DropEvent>::index [] =
{
	lux_index(SDL_DropEvent, file)
};
*/


template <> SDL_eventaction lux_to<SDL_eventaction>(lua_State *state, int index)
{
	return (SDL_eventaction) luaL_checkinteger(state, index);
}


extern "C" int luaopen_SDL_events(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	lux_Union<SDL_Event>::open(state);
	lux_Union<SDL_WindowEvent>::open(state);
	lux_Union<SDL_KeyboardEvent>::open(state);
//	lux_Union<SDL_TextEditingEvent>::open(state);
//	lux_Union<SDL_TextInputEvent>::open(state);
	lux_Union<SDL_MouseMotionEvent>::open(state);
	lux_Union<SDL_MouseButtonEvent>::open(state);
	lux_Union<SDL_MouseWheelEvent>::open(state);
	lux_Union<SDL_JoyAxisEvent>::open(state);
	lux_Union<SDL_JoyBallEvent>::open(state);
	lux_Union<SDL_JoyHatEvent>::open(state);
	lux_Union<SDL_JoyButtonEvent>::open(state);
	lux_Union<SDL_JoyDeviceEvent>::open(state);
	lux_Union<SDL_ControllerAxisEvent>::open(state);
	lux_Union<SDL_ControllerButtonEvent>::open(state);
	lux_Union<SDL_ControllerDeviceEvent>::open(state);
//	lux_Union<SDL_AudioDeviceEvent>::open(state);
//	lux_Union<SDL_QuitEvent>::open(state);
//	lux_Union<SDL_UserEvent>::open(state);
//	lux_Union<SDL_SysWMEvent>::open(state);
//	lux_Union<SDL_TouchFingerEvent>::open(state);
//	lux_Union<SDL_MultiGestureEvent>::open(state);
//	lux_Union<SDL_DollarGestureEvent>::open(state);
//	lux_Union<SDL_DropEvent>::open(state);

	static SDL_Event event;
	lux_push(state, &event);
	lua_setfield(state, -2, "event");
	
	struct {
	 const char *name;
	 int value;
	}
	args [] =
	{
	 // SDL_EventType
	 {"QUIT", SDL_QUIT},
	 {"APP_TERMINATING", SDL_APP_TERMINATING},
	 {"APP_LOWMEMORY", SDL_APP_LOWMEMORY},
	 {"APP_WILLENTERBACKGROUND", SDL_APP_WILLENTERBACKGROUND},
	 {"APP_DIDENTERBACKGROUND", SDL_APP_DIDENTERBACKGROUND},
	 {"APP_WILLENTERFOREGROUND", SDL_APP_WILLENTERFOREGROUND},
	 {"APP_DIDENTERFOREGROUND", SDL_APP_DIDENTERFOREGROUND},
	 {"WINDOWEVENT", SDL_WINDOWEVENT},
	 {"SYSWMEVENT", SDL_SYSWMEVENT},
	 {"KEYDOWN", SDL_KEYDOWN},
	 {"KEYUP", SDL_KEYUP},
	 {"TEXTEDITING", SDL_TEXTEDITING},
	 {"TEXTINPUT", SDL_TEXTINPUT},
	 {"MOUSEMOTION", SDL_MOUSEMOTION},
	 {"MOUSEBUTTONDOWN", SDL_MOUSEBUTTONDOWN},
	 {"MOUSEBUTTONUP", SDL_MOUSEBUTTONUP},
	 {"MOUSEWHEEL", SDL_MOUSEWHEEL},
	 {"JOYAXISMOTION", SDL_JOYAXISMOTION},
	 {"JOYBALLMOTION", SDL_JOYBALLMOTION},
	 {"JOYHATMOTION", SDL_JOYHATMOTION},
//	 {"JOYBUTTONMOTION", SDL_JOYBUTTONMOTION},
	 {"JOYBUTTONDOWN", SDL_JOYBUTTONDOWN},
	 {"JOYBUTTONUP", SDL_JOYBUTTONUP},
	 {"JOYDEVICEADDED", SDL_JOYDEVICEADDED},
	 {"JOYDEVICEREMOVED", SDL_JOYDEVICEREMOVED},
	 {"CONTROLLERAXISMOTION", SDL_CONTROLLERAXISMOTION},
	 {"CONTROLLERBUTTONDOWN", SDL_CONTROLLERBUTTONDOWN},
	 {"CONTROLLERBUTTONUP", SDL_CONTROLLERBUTTONUP},	
	 {"CONTROLLERDEVICEADDED", SDL_CONTROLLERDEVICEADDED},
	 {"CONTROLLERDEVICEREMOVED", SDL_CONTROLLERDEVICEREMOVED},
//	 {"CONTROLLERDEVICEREMAPPED", SDL_CONTROLLERDDEVICEREMAPPED},
	 {"FINGERDOWN", SDL_FINGERDOWN},
	 {"FINGERUP", SDL_FINGERUP},
	 {"FINGERMOTION", SDL_FINGERMOTION},
	 {"DOLLARGESTURE", SDL_DOLLARGESTURE},
	 {"MULTIGESTURE", SDL_MULTIGESTURE},
	 {"CLIPBOARDUPDATE", SDL_CLIPBOARDUPDATE},
	 {"DROPFILE", SDL_DROPFILE},
//	 {"AUDIODEVICEADDED", SDL_AUDIODEVICEADDED},
//	 {"AUDIODEVICEREMOVED", SDL_AUDIODEVICEREMOVED},
	 {"RENDER_TARGETS_RESET", SDL_RENDER_TARGETS_RESET},
//	 {"RENDER_DEVICE_RESET", SDL_RENDER_DEVICE_RESET},
	 // SDL_WindowEventID
	 {"WINDOWEVENT_SHOWN", SDL_WINDOWEVENT_SHOWN},
	 {"WINDOWEVENT_HIDDEN", SDL_WINDOWEVENT_HIDDEN},
	 {"WINDOWEVENT_EXPOSED", SDL_WINDOWEVENT_EXPOSED},
	 {"WINDOWEVENT_MOVED", SDL_WINDOWEVENT_MOVED},
	 {"WINDOWEVENT_RESIZED", SDL_WINDOWEVENT_RESIZED},
	 {"WINDOWEVENT_SIZE_CHANGED", SDL_WINDOWEVENT_SIZE_CHANGED},
	 {"WINDOWEVENT_MINIMIZED", SDL_WINDOWEVENT_MINIMIZED},
	 {"WINDOWEVENT_MAXIMIZED", SDL_WINDOWEVENT_MAXIMIZED},
	 {"WINDOWEVENT_RESTORED", SDL_WINDOWEVENT_RESTORED},
	 {"WINDOWEVENT_ENTER", SDL_WINDOWEVENT_ENTER},
	 {"WINDOWEVENT_LEAVE", SDL_WINDOWEVENT_LEAVE},
	 {"WINDOWEVENT_FOCUS_GAINED", SDL_WINDOWEVENT_FOCUS_GAINED},
	 {"WINDOWEVENT_FOCUS_LOST", SDL_WINDOWEVENT_FOCUS_LOST},
	 {"WINDOWEVENT_CLOSE", SDL_WINDOWEVENT_CLOSE},
	 // SDL_eventaction
	 {"ADDEVENT", SDL_ADDEVENT},
	 {"PEEKEVENT", SDL_PEEKEVENT},
 	 {"GETEVENT", SDL_GETEVENT},
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
//	 {"AddEventWatch", lux_cast(SDL_AddEventWatch)},
//	 {"DelEventWatch", lux_cast(SDL_DelEventWatch)},
	 {"EventState", lux_cast(SDL_EventState)},
//	 {"FilterEvents", lux_cast(SDL_FilterEvents)},
	 {"FlushEvent", lux_cast(SDL_FlushEvent)},
	 {"FlushEvents", lux_cast(SDL_FlushEvents)},
//	 {"GetEventFilter", lux_cast(SDL_GetEventFilter)},
	 {"GetNumTouchDevices", lux_cast(SDL_GetNumTouchDevices)},
	 {"GetNumTouchFingers", lux_cast(SDL_GetNumTouchFingers)},
	 {"GetTouchDevice", lux_cast(SDL_GetTouchDevice)},
	 {"GetTouchFinger", lux_cast(SDL_GetTouchFinger)},
	 {"HasEvent", lux_cast(SDL_HasEvent)},
	 {"HasEvents", lux_cast(SDL_HasEvents)},
	 {"LoadDollarTemplates", lux_cast(SDL_LoadDollarTemplates)},
	 {"PeepEvents", lux_cast(SDL_PeepEvents)},
	 {"PollEvents", lux_cast(SDL_PollEvent)},
	 {"PumpEvents", lux_cast(SDL_PumpEvents)},
	 {"PushEvent", lux_cast(SDL_PushEvent)},
//	 {"QuitRequested", lux_cast(SDL_QuitRequested)},
	 {"RecordGesture", lux_cast(SDL_RecordGesture)},
	 {"RegisterEvents", lux_cast(SDL_RegisterEvents)},
	 {"SaveAllDollarTemplates", lux_cast(SDL_SaveAllDollarTemplates)},
	 {"SaveDollarTemplate", lux_cast(SDL_SaveDollarTemplate)},
//	 {"SetEventFilter", lux_cast(SDL_SetEventFilter)},
	 {"WaitEvent", lux_cast(SDL_WaitEvent)},
	 {"WaitEventTimeout", lux_cast(SDL_WaitEventTimeout)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}
 
