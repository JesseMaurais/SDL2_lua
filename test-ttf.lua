SDL = require 'SDL'
TTF = require 'SDL.ttf'
require 'SDL.video'
require 'SDL.events'
require 'SDL.surface'

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
