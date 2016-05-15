SDL = require 'SDL2'
TTF = require 'SDL2.ttf'
require 'SDL2.video'
require 'SDL2.events'
require 'SDL2.surface'

message = 'Hello World!'
font = TTF.OpenFont('Serif.ttf', 64)
w, h = TTF.SizeText(font, message)
window = SDL.CreateWindow('True Type Font', 100, 100, w, h, SDL.WINDOW_HIDDEN)
surface = SDL.GetWindowSurface(window)
text = TTF.RenderText(font, message, 'Solid', '0.255.0')
SDL.BlitSurface(text, nil, surface, nil)
SDL.FreeSurface(text)
SDL.ShowWindow(window)
SDL.UpdateWindowSurface(window)
event = SDL.Event.new()
repeat SDL.WaitEvent(event) until event:type() == SDL.QUIT
SDL.DestroyWindow(window)
