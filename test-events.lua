SDL = require 'SDL2'
require 'SDL2.events'
require 'SDL2.video'

window = SDL.CreateWindow(
	'Lua & SDL', -- title
	SDL.WINDOWPOS_UNDEFINED, -- x
	SDL.WINDOWPOS_UNDEFINED, -- y
	600, -- width
	400, -- height
	SDL.WINDOW_SHOWN -- flags
	)

-- Create an event record for receiving device input
event = SDL.Event.new()
-- Continue to process events until the window is closed
repeat SDL.WaitEvent(event) until event:type() == SDL.QUIT

SDL.DestroyWindow(window)
