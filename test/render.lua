#!/usr/bin/env lua
SDL = require 'SDL2'
require 'SDL2.events'
require 'SDL2.render'
require 'SDL2.video'

-- Create the window and renderer for drawing into
window, renderer = SDL.CreateWindowAndRenderer(600, 400, SDL.WINDOW_SHOWN)
-- Create an event record to receive device input
event = SDL.Event.new()
-- Continue to process events until the window is closed
repeat SDL.WaitEvent(event) until event:type() == SDL.QUIT
-- Clean up our resources
SDL.DestroyRenderer(renderer);
SDL.DestroyWindow(window)

