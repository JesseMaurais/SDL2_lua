#!/usr/bin/lua

SDL = require 'SDL'
require 'SDL.events'
require 'SDL.video'

window = SDL.CreateWindow(
	'Lua & SDL', -- title
	SDL.WINDOWPOS_UNDEFINED, -- x
	SDL.WINDOWPOS_UNDEFINED, -- y
	600, -- width
	400, -- height
	SDL.WINDOW_SHOWN -- flags
	)

-- Continue to process events until the window is closed
repeat SDL.WaitEvent(SDL.event) until SDL.event.type == SDL.QUIT

SDL.DestroyWindow(window)
