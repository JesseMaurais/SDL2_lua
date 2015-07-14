#include "SDL.hpp"

static int GetWindowGammaRamp(lua_State *state)
{
	auto window = lux_to<SDL_Window*>(state, 1);
	Uint16 R, G, B;
	if (!SDL_GetWindowGammaRamp(window, &R, &G, &B))
	{
	 return lux_push(state, R, G, B);
	}
	return 0;
}

static int GetWindowMaximumSize(lua_State *state)
{
	auto window = lux_to<SDL_Window*>(state, 1);
	int w, h;
	SDL_GetWindowMaximumSize(window, &w, &h);
	return lux_push(state, w, h);
}

static int GetWindowMinimumSize(lua_State *state)
{
	auto window = lux_to<SDL_Window*>(state, 1);
	int w, h;
	SDL_GetWindowMinimumSize(window, &w, &h);
	return lux_push(state, w, h);
}

static int GetWindowPosition(lua_State *state)
{
	auto window = lux_to<SDL_Window*>(state, 1);
	int x, y;
	SDL_GetWindowPosition(window, &x, &y);
	return lux_push(state, x, y);
}

static int GetWindowSize(lua_State *state)
{
	auto window = lux_to<SDL_Window*>(state, 1);
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	return lux_push(state, w, h);
}

extern "C" int luaopen_SDL_video(lua_State *state)
{
	luaL_newmetatable(state, SDL_METATABLE);
	struct {
	 const char *name;
	 lua_Integer value;
	}
	args [] =
	{
	ARG(WINDOWPOS_UNDEFINED)
	ARG(WINDOWPOS_CENTERED)
	// SDL_WindowFlags
	ARG(WINDOW_FULLSCREEN)
	ARG(WINDOW_OPENGL)
	ARG(WINDOW_SHOWN)
	ARG(WINDOW_HIDDEN)
	ARG(WINDOW_BORDERLESS)
	ARG(WINDOW_RESIZABLE)
	ARG(WINDOW_MINIMIZED)
	ARG(WINDOW_MAXIMIZED)
	ARG(WINDOW_INPUT_GRABBED)
	ARG(WINDOW_INPUT_FOCUS)
	ARG(WINDOW_MOUSE_FOCUS)
	ARG(WINDOW_FULLSCREEN_DESKTOP)
	ARG(WINDOW_FOREIGN)
	ARG(WINDOW_ALLOW_HIGHDPI)
//	ARG(WINDOW_MOUSE_CAPTURE)
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
/*	// SDL_HitTestResult
	ARG(HITTEST_NORMAL)
	ARG(HITTEST_DRAGGABLE)
	ARG(HITTEST_RESIZE_TOPLEFT)
	ARG(HITTEST_RESIZE_TOP)
	ARG(HITTEST_RESIZE_TOPRIGHT)
	ARG(HITTEST_RESIZE_RIGHT)
	ARG(HITTEST_RESIZE_BOTTOMRIGHT)
	ARG(HITTEST_RESIZE_BOTTOM)
	ARG(HITTEST_RESIZE_BOTTOMLEFT)
	ARG(HITTEST_RESIZE_LEFT)
*/
	END
	};
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs[] =
	{
	REG(CreateWindow)
	REG(DestroyWindow)
	REG(DisableScreenSaver)
	REG(EnableScreenSaver)
	REG(GetClosestDisplayMode)
	REG(GetCurrentDisplayMode)
	REG(GetCurrentVideoDriver)
	REG(GetDesktopDisplayMode)
	REG(GetDisplayBounds)
	REG(GetDisplayMode)
	REG(GetDisplayName)
//	REG(GetGrabbedWindow)
	REG(GetNumDisplayModes)
	REG(GetNumVideoDisplays)
	REG(GetNumVideoDrivers)
	REG(GetVideoDriver)
	REG(GetWindowBrightness)
	REG(GetWindowData)
	REG(GetWindowDisplayIndex)
	REG(GetWindowDisplayMode)
	REG(GetWindowFlags)
	REG(GetWindowFromID)
	{"GetWindowGammaRamp", GetWindowGammaRamp},
	REG(GetWindowGrab)
	REG(GetWindowID)
	{"GetWindowMaximumSize", GetWindowMaximumSize},
	{"GetWindowMinimumSize", GetWindowMinimumSize},
	REG(GetWindowPixelFormat)
	{"GetWindowPosition", GetWindowPosition},
	{"GetWindowSize", GetWindowSize},
	REG(GetWindowSurface)
	REG(GetWindowTitle)
//	REG(GetWindowWMInfo)
	REG(HideWindow)
	REG(IsScreenSaverEnabled)
	REG(MaximizeWindow)
	REG(MinimizeWindow)
	REG(RaiseWindow)
	REG(RestoreWindow)
	REG(SetWindowBordered)
	REG(SetWindowBrightness)
	REG(SetWindowData)
	REG(SetWindowDisplayMode)
	REG(SetWindowFullscreen)
	REG(SetWindowGammaRamp)
	REG(SetWindowGrab)
//	REG(SetWindowHitTest)
	REG(SetWindowIcon)
	REG(SetWindowMaximumSize)
	REG(SetWindowMinimumSize)
	REG(SetWindowPosition)
	REG(SetWindowSize)
	REG(SetWindowTitle)
	REG(ShowWindow)
	REG(UpdateWindowSurface)
	REG(UpdateWindowSurfaceRects)
//	REG(VideoInit)
//	REG(VideoQuit)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

