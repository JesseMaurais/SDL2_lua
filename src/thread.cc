#include <lux/lux.hpp>
#include <SDL2/SDL.h>
#include "Common.h"

static int ThreadFunction(void *stack)
{
	// Convert thread argument to a state
	auto state = reinterpret_cast<lua_State*>(stack);
	// Assume that a function and arguments are on it
	lua_call(state, lua_gettop(state) - 1, LUA_MULTRET);
	// Put ref key in global table
	lua_pushglobaltable(state);
	lua_pushthread(state);
	int ref = luaL_ref(state, -2);
	lua_pop(state, 1);
	return ref;
}

static int CreateThread(lua_State *state)
{
	SDL_Thread *thread;
	// Create independent execution stack
	lua_State *stack = lua_newthread(state);
	lua_pop(state, 1); // remove the stack
	// Copy the state contents over to stack
	lua_xmove(state, stack, lua_gettop(state));
	// Launch the thread function which executes stack
	thread = SDL_CreateThread(ThreadFunction, NULL, stack);
	lux_push(state, thread);
	return 1;
}

static int WaitThread(lua_State *state)
{
	auto thread = lux_to<SDL_Thread*>(state, 1);
	int ref; // is a stack
	// Wait for return status
	SDL_WaitThread(thread, &ref);
	// Use ref as global key
	lua_pushglobaltable(state);
	lua_rawgeti(state, -1, ref);
	// Thread results are stored here
	auto stack = lua_tothread(state, -1);
	int size = lua_gettop(stack);
	lua_pop(state, 1);
	// Copy as return values here
	lua_xmove(stack, state, size);
	return size;
}

template <> const char *Type<SDL_Thread>::name = "Thread";

extern "C" int luaopen_SDL_thread(lua_State *state)
{
	if (!luaL_getmetatable(state, SDL_METATABLE))
	{
		return luaL_error(state, SDL_REQUIRED);
	}
	luaL_newmetatable(state, Type<SDL_Thread>::name);
	lua_pop(state, 1);
	luaL_Reg regs [] =
	{
	{"CreateThread", CreateThread},
	{"DetachThread", lux_cast(SDL_DetachThread)},
	{"GetThreadID", lux_cast(SDL_GetThreadID)},
	{"WaitThread", WaitThread},
	{nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}


