#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

static int GetWindowData(lua_State *state)
{
	auto window = lux_to<SDL_Window*>(state, 1);
	auto name = lua_tostring(state, 2);
	auto data = SDL_GetWindowData(window, name);
	auto stack = reinterpret_cast<lua_State*>(data);
	int size = lua_gettop(stack);
	lua_xmove(stack, state, size);
	return size;
}

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

#if SDL_VERSION_ATLEAST(2, 0, 4)
static int GetDisplayDPI(lua_State *state)
{
	float ddpi, hdpi, vdpi;
	int index = lua_tointeger(state, 1);
	if (!SDL_GetDisplayDPI(index, &ddpi, &hdpi, &vdpi))
	{
	 return lux_push(state, ddpi, hdpi, vdpi);
	}
	return 0;
}
#endif

static int SetWindowData(lua_State *state)
{
	// TODO
}

#if SDL_VERSION_ATLEAST(2, 0, 4)
static SDL_HitTestResult HitTest(SDL_Window *window, const SDL_Point *point, void *data)
{
	auto state = reinterpret_cast<lua_State*>(data);
	int n = lux_push(state, window, point->x, point->y, point->w, point->h);
	lua_call(state, n, 1);
	return lux_to<SDL_HitTestResult>(state, -1);
}

static int SetWindowHitTest(lua_State *state)
{
	int error = SDL_SetWindowHitTest(window, HitTest, state);
	lua_pushinteger(state, error);
	return 1;	
}
#endif

extern "C" int luaopen_SDL_video(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}
	// Video subsystem initialization
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
	{
		auto error = SDL_GetError();
		return luaL_error(state, "SDL_InitSubSystem: %s", error);
	}
	// Register types for video
	luaL_newmetatable(state, Type<SDL_DisplayMode>::name);
	luaL_newmetatable(state, Type<SDL_Window>::name);
	lua_pop(state, 2);
	// Register functions for video
	lux_Reg<lua_Integer> args[] =
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
	lux_settable(state, args);
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
	#if SDL_VERSION_ATLEAST(2, 0, 4)
	{"GetDisplayDPI", GetDisplayDPI},
	#endif
	REG(GetDisplayMode)
	REG(GetDisplayName)
	#if SDL_VERSION_ATLEAST(2, 0, 4)
	REG(GetGrabbedWindow)
	#endif
	REG(GetNumDisplayModes)
	REG(GetNumVideoDisplays)
	REG(GetNumVideoDrivers)
	REG(GetVideoDriver)
	REG(GetWindowBrightness)
	{"GetWindowData", GetWindowData},
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
	REG(HideWindow)
	REG(IsScreenSaverEnabled)
	REG(MaximizeWindow)
	REG(MinimizeWindow)
	REG(RaiseWindow)
	REG(RestoreWindow)
	REG(SetWindowBordered)
	REG(SetWindowBrightness)
	{"SetWindowData", SetWindowData},
	REG(SetWindowDisplayMode)
	REG(SetWindowFullscreen)
	REG(SetWindowGammaRamp)
	REG(SetWindowGrab)
#if SDL_VERSION_ATLEAST(2, 0, 4)
	{"SetWindowHitTest", SetWindowHitTest},
#endif
	REG(SetWindowIcon)
	REG(SetWindowMaximumSize)
	REG(SetWindowMinimumSize)
	REG(SetWindowPosition)
	REG(SetWindowSize)
	REG(SetWindowTitle)
	REG(ShowWindow)
	REG(UpdateWindowSurface)
	REG(UpdateWindowSurfaceRects)
	REG(VideoInit)
	REG(VideoQuit)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

