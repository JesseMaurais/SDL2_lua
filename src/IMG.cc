#include "SDL.hpp"
#include <SDL2/SDL_image.h>

#define REG(name) {#name, lux_cast(IMG_##name)},
#define END {nullptr, nullptr}

extern "C" int luaopen_IMG(lua_State *state)
{
	if (!IMG_Init(IMG_INIT_PNG))
	{
		const char *error = IMG_GetError();
		return luaL_error(state, "IMG_Init: %s", error);
	}
	else atexit(IMG_Quit);

	luaL_newmetatable(state, IMG_METATABLE);
	luaL_Reg regs [] =
	{
	REG(Load)
	REG(Load_RW)
	REG(LoadTyped_RW)
	REG(LoadTexture)
	REG(LoadTexture_RW)
	REG(LoadTextureTyped_RW)
	END
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

