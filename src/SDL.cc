#include "SDL.hpp"

#define newtype(state, type) lux_newtype<SDL_##type*>(state, #type)

extern "C" int luaopen_SDL(lua_State *state)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		const char *error = SDL_GetError();
		return luaL_error(state, "SDL_Init: %s", error);
	}
	else atexit(SDL_Quit);

	luaL_newmetatable(state, SDL_METATABLE);
	// base types
	newtype(state, Point);
	newtype(state, Rect);
	newtype(state, Event);
	newtype(state, Window);
	newtype(state, Surface);
	newtype(state, Renderer);
	newtype(state, Texture);
	newtype(state, Color);
	newtype(state, Palette);
	newtype(state, PixelFormat);
	newtype(state, RendererInfo);
	newtype(state, DisplayMode);
	newtype(state, AudioSpec);
	newtype(state, AudioCVT);
	newtype(state, HapticEffect);
	newtype(state, Joystick);
	newtype(state, Haptic);
	newtype(state, Cursor);
	newtype(state, Finger);
	newtype(state, Keysym);
	newtype(state, RWops);
	return 1;
}
