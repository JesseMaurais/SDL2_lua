#!/usr/bin/env lua
SDL = require'SDL2'
require'SDL2.cpuinfo'
require'SDL2.platform'
io = require'stdio'

print('Operating System      ', SDL.GetPlatform())
print('CPU cache line size   ', SDL.GetCPUCacheLineSize())
print('CPU count             ', SDL.GetCPUCount())
-- Version >= 2.0.1
if SDL.GetSystemRAM then
print('System RAM            ', SDL.GetSystemRAM())
end
print('Has 3DNow! SIMD       ', SDL.Has3DNow())
-- Version >= 2.0.2
if SDL.HasAVX then
print('Has AVX               ', SDL.HasAVX())
end
-- Version >= 2.0.4
if SDL.HasAVX2 then
print('Has AVX2              ', SDL.HasAVX2())
end
print('Has AltiVec           ', SDL.HasAltiVec())
print('Has MMX               ', SDL.HasMMX())
print('Has RDTSC             ', SDL.HasRDTSC())
print('Has SSE               ', SDL.HasSSE())
print('Has SSE2              ', SDL.HasSSE2())
print('Has SSE3              ', SDL.HasSSE3())
print('Has SSE4.1            ', SDL.HasSSE41())
print('Has SSE4.2            ', SDL.HasSSE42())

