#include "SDL.hpp"

#undef REG
#define REG(name) {#name, lux_cast(SDL_GL_##name)},
#undef ARG
#define ARG(name) {#name, SDL_GL_##name},

extern "C" int luaopen_SDL_GL(lua_State *state)
{
	luaL_newmetatable(state, GLC_METATABLE);
	struct {
	 const char *name;
	 lua_Integer value;
	}
	args [] = 
	{
	// SDL_GLattr
	ARG(RED_SIZE)
	ARG(GREEN_SIZE)
	ARG(BLUE_SIZE)
	ARG(ALPHA_SIZE)
	ARG(BUFFER_SIZE)
	ARG(DOUBLEBUFFER)
	ARG(DEPTH_SIZE)
	ARG(STENCIL_SIZE)
	ARG(ACCUM_RED_SIZE)
	ARG(ACCUM_GREEN_SIZE)
	ARG(ACCUM_BLUE_SIZE)
	ARG(ACCUM_ALPHA_SIZE)
	ARG(STEREO)
	ARG(MULTISAMPLEBUFFERS)
	ARG(MULTISAMPLESAMPLES)
	ARG(ACCELERATED_VISUAL)
	ARG(RETAINED_BACKING)
	ARG(CONTEXT_MAJOR_VERSION)
	ARG(CONTEXT_MINOR_VERSION)
	ARG(CONTEXT_EGL)
	ARG(CONTEXT_FLAGS)
	ARG(CONTEXT_PROFILE_MASK)
	ARG(SHARE_WITH_CURRENT_CONTEXT)
	ARG(FRAMEBUFFER_SRGB_CAPABLE)
	// SDL_GLprofile
	ARG(CONTEXT_PROFILE_CORE)
	ARG(CONTEXT_PROFILE_COMPATIBILITY)
	ARG(CONTEXT_PROFILE_ES)
	// SDL_GLcontextFlag
//	ARG(CONTEXT_DEBUG_FLAGS)
	ARG(CONTEXT_FORWARD_COMPATIBLE_FLAG)
	ARG(CONTEXT_RESET_ISOLATION_FLAG)
	END
	};
	for (auto r=args; r->name; ++r)
	{
	 lua_pushinteger(state, r->value);
	 lua_setfield(state, -2, r->name);
	}
	luaL_Reg regs [] =
	{
	REG(BindTexture)
	REG(CreateContext)
	REG(DeleteContext)
	REG(ExtensionSupported)
//	REG(GetAttribute)
	REG(GetCurrentContext)
	REG(GetCurrentWindow)
//	REG(GetDrawableSize)
	REG(GetProcAddress)
	REG(GetSwapInterval)
	REG(LoadLibrary)
	REG(MakeCurrent)
	REG(ResetAttributes)
	REG(SetAttribute)
	REG(SetSwapInterval)
	REG(SwapWindow)
	REG(UnbindTexture)
	REG(UnloadLibrary)
	END
	};
	luaL_setfuncs(state, regs, 0);
	// _G.GL = SDL.GL = GL
	luaL_newmetatable(state, SDL_METATABLE);
	lua_pushvalue(state, -2);
	lua_setfield(state, -2, GLC_METATABLE);
	lua_pop(state, 1);
	return 1;
}

