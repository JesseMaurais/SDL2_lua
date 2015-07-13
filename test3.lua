#!/usr/bin/lua

SDL = require 'SDL'
require 'SDL.events'
require 'SDL.render'
require 'SDL.video'

-- Create the window and renderer for drawing into
window, renderer = SDL.CreateWindowAndRenderer(600, 400, SDL.WINDOW_SHOWN)

-- Continue to process events until the window is closed
repeat SDL.WaitEvent(SDL.event) until SDL.event.type == SDL.QUIT

-- Clean up
SDL.DestroyRenderer(renderer);
SDL.DestroyWindow(window)
