#!/usr/bin/env lua
SDL = require'SDL2'
require'SDL2.thread'

function Concat(a, b) return a .. b end

thread = SDL.CreateThread(Concat, 'Hello ', 'World!')
print('The thread message is: ')
string = SDL.WaitThread(thread)
print(string)

