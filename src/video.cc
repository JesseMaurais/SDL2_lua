#include "SDL.hpp"

template <> luaL_Reg lux_Union<SDL_DisplayMode>::index [] =
{
	lux_index(SDL_DisplayMode, format),
	lux_index(SDL_DisplayMode, w),
	lux_index(SDL_DisplayMode, h),
	lux_index(SDL_DisplayMode, refresh_rate)
};

extern "C" int luaopen_SDL_video(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 int value;
	}
	args [] =
	{
	 {"WINDOWPOS_UNDEFINED", SDL_WINDOWPOS_UNDEFINED},
	 {"WINDOWPOS_CENTERED", SDL_WINDOWPOS_CENTERED},
	 // SDL_WindowFlags
	 {"WINDOW_FULLSCREEN", SDL_WINDOW_FULLSCREEN},
	 {"WINDOW_OPENGL", SDL_WINDOW_OPENGL},
	 {"WINDOW_SHOWN", SDL_WINDOW_SHOWN},
	 {"WINDOW_HIDDEN", SDL_WINDOW_HIDDEN},
	 {"WINDOW_BORDERLESS", SDL_WINDOW_BORDERLESS},
	 {"WINDOW_RESIZABLE", SDL_WINDOW_RESIZABLE},
	 {"WINDOW_MINIMIZED", SDL_WINDOW_MINIMIZED},
	 {"WINDOW_MAXIMIZED", SDL_WINDOW_MAXIMIZED},
	 {"WINDOW_INPUT_GRABBED", SDL_WINDOW_INPUT_GRABBED},
	 {"WINDOW_INPUT_FOCUS", SDL_WINDOW_INPUT_FOCUS},
	 {"WINDOW_MOUSE_FOCUS", SDL_WINDOW_MOUSE_FOCUS},
	 {"WINDOW_FULLSCREEN_DESKTOP", SDL_WINDOW_FULLSCREEN_DESKTOP},
	 {"WINDOW_FOREIGN", SDL_WINDOW_FOREIGN},
	 {"WINDOW_ALLOW_HIGHDPI", SDL_WINDOW_ALLOW_HIGHDPI},
//	 {"WINDOW_MOUSE_CAPTURE", SDL_WINDOW_MOUSE_CAPTURE},
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
/*	 // SDL_HitTestResult
	 {"HITTEST_NORMAL", SDL_HITTEST_NORMAL},
	 {"HITTEST_DRAGGABLE", SDL_HITTEST_DRAGGABLE},
	 {"HITTEST_RESIZE_TOPLEFT", SDL_HITTEST_RESIZE_TOPLEFT},
	 {"HITTEST_RESIZE_TOP", SDL_HITTEST_RESIZE_TOP},
	 {"HITTEST_RESIZE_TOPRIGHT", SDL_HITTEST_RESIZE_TOPRIGHT},
	 {"HITTEST_RESIZE_RIGHT", SDL_HITTEST_RESIZE_RIGHT},
	 {"HITTEST_RESIZE_BOTTOMRIGHT", SDL_HITTEST_RESIZE_BOTTOMRIGHT},
	 {"HITTEST_RESIZE_BOTTOM", SDL_HITTEST_RESIZE_BOTTOM},
	 {"HITTEST_RESIZE_BOTTOMLEFT", SDL_HITTEST_RESIZE_BOTTOMLEFT},
	 {"HITTEST_RESIZE_LEFT", SDL_HITTEST_RESIZE_LEFT},
*/	 // end
	 {nullptr, 0}
	};
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs[] =
	{
	 {"CreateWindow", lux_cast(SDL_CreateWindow)},
	 {"DestroyWindow", lux_cast(SDL_DestroyWindow)},
	 {"DisableScreenSaver", lux_cast(SDL_DisableScreenSaver)},
	 {"EnableScreenSaver", lux_cast(SDL_EnableScreenSaver)},
	 {"GetClosestDisplayMode", lux_cast(SDL_GetClosestDisplayMode)},
	 {"GetCurrentDisplayMode", lux_cast(SDL_GetCurrentDisplayMode)},
	 {"GetCurrentVideoDriver", lux_cast(SDL_GetCurrentVideoDriver)},
	 {"GetDesktopDisplayMode", lux_cast(SDL_GetDesktopDisplayMode)},
	 {"GetDisplayBounds", lux_cast(SDL_GetDisplayBounds)},
	 {"GetDisplayMode", lux_cast(SDL_GetDisplayMode)},
	 {"GetDisplayName", lux_cast(SDL_GetDisplayName)},
//	 {"GetGrabbedWindow", lux_cast(SDL_GetGrabbedWindow)},
	 {"GetNumDisplayModes", lux_cast(SDL_GetNumDisplayModes)},
	 {"GetNumVideoDisplays", lux_cast(SDL_GetNumVideoDisplays)},
	 {"GetNumVideoDrivers", lux_cast(SDL_GetNumVideoDrivers)},
	 {"GetVideoDriver", lux_cast(SDL_GetVideoDriver)},
	 {"GetWindowBrightness", lux_cast(SDL_GetWindowBrightness)},
	 {"GetWindowData", lux_cast(SDL_GetWindowData)},
	 {"GetWindowDisplayIndex", lux_cast(SDL_GetWindowDisplayIndex)},
//	 {"GetWindowDisplayMode", lux_cast(SDL_GetWindowDisplayMode)},
	 {"GetWindowFlags", lux_cast(SDL_GetWindowFlags)},
	 {"GetWindowFromID", lux_cast(SDL_GetWindowFromID)},
//	 {"GetWindowGammaRamp", lux_cast(SDL_GetWindowGammaRamp)},
	 {"GetWindowGrab", lux_cast(SDL_GetWindowGrab)},
	 {"GetWindowID", lux_cast(SDL_GetWindowID)},
//	 {"GetWindowMaximumSize", lux_cast(SDL_GetWindowMaximumSize)},
//	 {"GetWindowMinimumSize", lux_cast(SDL_GetWindowMinimumSize)},
	 {"GetWindowPixelFormat", lux_cast(SDL_GetWindowPixelFormat)},
//	 {"GetWindowPosition", lux_cast(SDL_GetWindowPosition)},
//	 {"GetWindowSize", lux_cast(SDL_GetWindowSize)},
	 {"GetWindowSurface", lux_cast(SDL_GetWindowSurface)},
	 {"GetWindowTitle", lux_cast(SDL_GetWindowTitle)},
//	 {"GetWindowWMInfo", lux_cast(SDL_GetWindowWMInfo)},
	 {"HideWindow", lux_cast(SDL_HideWindow)},
	 {"IsScreenSaverEnabled", lux_cast(SDL_IsScreenSaverEnabled)},
	 {"MaximizeWindow", lux_cast(SDL_MaximizeWindow)},
	 {"MinimizeWindow", lux_cast(SDL_MinimizeWindow)},
	 {"RaiseWindow", lux_cast(SDL_RaiseWindow)},
	 {"RestoreWindow", lux_cast(SDL_RestoreWindow)},
	 {"SetWindowBordered", lux_cast(SDL_SetWindowBordered)},
	 {"SetWindowBrightness", lux_cast(SDL_SetWindowBrightness)},
	 {"SetWindowData", lux_cast(SDL_SetWindowData)},
	 {"SetWindowDisplayMode", lux_cast(SDL_SetWindowDisplayMode)},
	 {"SetWindowFullscreen", lux_cast(SDL_SetWindowFullscreen)},
	 {"SetWindowGammaRamp", lux_cast(SDL_SetWindowGammaRamp)},
	 {"SetWindowGrab", lux_cast(SDL_SetWindowGrab)},
//	 {"SetWindowHitTest", lux_cast(SDL_SetWindowHitTest)},
//	 {"SetWindowIcon", lux_cast(SDL_SetWindowIcon)},
	 {"SetWindowMaximumSize", lux_cast(SDL_SetWindowMaximumSize)},
	 {"SetWindowMinimumSize", lux_cast(SDL_SetWindowMinimumSize)},
	 {"SetWindowPosition", lux_cast(SDL_SetWindowPosition)},
	 {"SetWindowSize", lux_cast(SDL_SetWindowSize)},
	 {"SetWindowTitle", lux_cast(SDL_SetWindowTitle)},
	 {"ShowWindow", lux_cast(SDL_ShowWindow)},
	 {"UpdateWindowSurface", lux_cast(SDL_UpdateWindowSurface)},
	 {"UpdateWindowSurfaceRects", lux_cast(SDL_UpdateWindowSurfaceRects)},
//	 {"VideoInit", lux_cast(SDL_VideoInit)},
//	 {"VideoQuit", lux_cast(SDL_VideoQuit)},
	 {nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

