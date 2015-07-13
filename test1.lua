#!/usr/bin/lua

SDL = require 'SDL'
require 'SDL.video'
require 'SDL.timer'

window = SDL.CreateWindow(
	'An SDL2 window',
	SDL.WINDOWPOS_UNDEFINED,
	SDL.WINDOWPOS_UNDEFINED,
	400,
	300, SDL.WINDOW_SHOWN
	)

SDL.Delay(3000)

SDL.DestroyWindow(window)

