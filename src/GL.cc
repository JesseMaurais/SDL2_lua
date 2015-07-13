#include "SDL.hpp"

extern "C" int luaopen_SDL_GL(lua_State *state)
{
	luaL_newmetatable(state, GLC_METATABLE);
	struct {
	  const char *name;
	  long int param;
	}
	args [] = 
	{
	// SDL_GLattr
	{"RED_SIZE", SDL_GL_RED_SIZE},
	{"GREEN_SIZE", SDL_GL_GREEN_SIZE},
	{"BLUE_SIZE", SDL_GL_BLUE_SIZE},
	{"ALPHA_SIZE", SDL_GL_ALPHA_SIZE},
	{"BUFFER_SIZE", SDL_GL_BUFFER_SIZE},
	{"DOUBLEBUFFER", SDL_GL_DOUBLEBUFFER},
	{"DEPTH_SIZE", SDL_GL_DEPTH_SIZE},
	{"STENCIL_SIZE", SDL_GL_STENCIL_SIZE},
	{"ACCUM_RED_SIZE", SDL_GL_ACCUM_RED_SIZE},
	{"ACCUM_GREEN_SIZE", SDL_GL_ACCUM_GREEN_SIZE},
	{"ACCUM_BLUE_SIZE", SDL_GL_ACCUM_BLUE_SIZE},
	{"ACCUM_ALPHA_SIZE", SDL_GL_ACCUM_ALPHA_SIZE},
	{"STEREO", SDL_GL_STEREO},
	{"MULTISAMPLEBUFFERS", SDL_GL_MULTISAMPLEBUFFERS},
	{"MULTISAMPLESAMPLES", SDL_GL_MULTISAMPLESAMPLES},
	{"ACCELERATED_VISUAL", SDL_GL_ACCELERATED_VISUAL},
	{"RETAINED_BACKING", SDL_GL_RETAINED_BACKING},
	{"CONTEXT_MAJOR_VERSION", SDL_GL_CONTEXT_MAJOR_VERSION},
	{"CONTEXT_MINOR_VERSION", SDL_GL_CONTEXT_MINOR_VERSION},
	{"CONTEXT_EGL", SDL_GL_CONTEXT_EGL},
	{"CONTEXT_FLAGS", SDL_GL_CONTEXT_FLAGS},
	{"CONTEXT_PROFILE_MASK", SDL_GL_CONTEXT_PROFILE_MASK},
	{"SHARE_WITH_CURRENT_CONTEXT", SDL_GL_SHARE_WITH_CURRENT_CONTEXT},
	{"FRAMEBUFFER_SRGB_CAPABLE", SDL_GL_FRAMEBUFFER_SRGB_CAPABLE},
	// SDL_GLprofile
	{"CONTEXT_PROFILE_CORE", SDL_GL_CONTEXT_PROFILE_CORE},
	{"CONTEXT_PROFILE_COMPATIBILITY",SDL_GL_CONTEXT_PROFILE_COMPATIBILITY},
	{"CONTEXT_PROFILE_ES", SDL_GL_CONTEXT_PROFILE_ES},
	// SDL_GLcontextFlag
	{"CONTEXT_DEBUG_FLAGS", SDL_GL_CONTEXT_DEBUG_FLAG},
	{"CONTEXT_FORWARD_COMPATIBLE_FLAG", SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG},
	{"CONTEXT_RESET_ISOLATION_FLAG", SDL_GL_CONTEXT_RESET_ISOLATION_FLAG},
	// end
	{nullptr, 0}
	};
	for (auto reg=args; reg->name; ++reg)
	{
	 lua_pushinteger(state, reg->param);
	 lua_setfield(state, -2, reg->name);
	}
	luaL_Reg regs [] =
	{
	{"BindTexture", lux_cast(SDL_GL_BindTexture)},
	{"CreateContext", lux_cast(SDL_GL_CreateContext)},
	{"DeleteContext", lux_cast(SDL_GL_DeleteContext)},
	{"ExtensionSupported", lux_cast(SDL_GL_ExtensionSupported)},
//	{"GetAttribute", lux_get(SDL_GL_GetAttribute)},
	{"GetCurrentContext", lux_cast(SDL_GL_GetCurrentContext)},
	{"GetCurrentWindow", lux_cast(SDL_GL_GetCurrentWindow)},
//	{"GetDrawableSize", lux_cast(SDL_GL_GetDrawableSize)},
	{"GetProcAddress", lux_cast(SDL_GL_GetProcAddress)},
	{"GetSwapInterval", lux_cast(SDL_GL_GetSwapInterval)},
	{"LoadLibrary", lux_cast(SDL_GL_LoadLibrary)},
	{"MakeCurrent", lux_cast(SDL_GL_MakeCurrent)},
	{"ResetAttributes", lux_cast(SDL_GL_ResetAttributes)},
	{"SetAttribute", lux_cast(SDL_GL_SetAttribute)},
	{"SetSwapInterval", lux_cast(SDL_GL_SetSwapInterval)},
	{"SwapWindow", lux_cast(SDL_GL_SwapWindow)},
	{"UnbindTexture", lux_cast(SDL_GL_UnbindTexture)},
	{"UnloadLibrary", lux_cast(SDL_GL_UnloadLibrary)},
	{nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	// _G.GL = SDL.GL = GL
	luaL_newmetatable(state, SDL_METATABLE);
	lua_pushvalue(state, -2);
	lua_setfield(state, -2, GLC_METATABLE);
	lua_pop(state, 1);
	return 1;
}

