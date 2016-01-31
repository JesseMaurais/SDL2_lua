#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Common.h"

#undef REG
#define REG(name) {#name, lux_cast(IMG_##name)},

extern "C" int luaopen_SDL_image(lua_State *state)
{
	/* Initialize */

	if (!IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF))
	{
		const char *error = IMG_GetError();
		return luaL_error(state, "IMG_Init: %s", error);
	}
	else
	if (atexit(IMG_Quit))
	{
		return luaL_error(state, "Cannot make exit (atexit < 0)");
	}

	/* Module Metatable */

	luaL_newmetatable(state, "SDL2_image");

	/* Functions */

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

	/* Done */

	return 0;
}

