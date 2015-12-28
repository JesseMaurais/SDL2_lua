SDL = require 'SDL'
IMG = require 'SDL.image'
require 'SDL.video'
require 'SDL.events'
require 'SDL.surface'
require 'SDL.render'

image = IMG.Load('Logo.png')
window, render = SDL.CreateWindowAndRenderer(457, 266, SDL.WINDOW_SHOWN)
texture = SDL.CreateTextureFromSurface(render, image)
SDL.FreeSurface(image)
SDL.RenderClear(render)
SDL.RenderCopy(render, texture, nil, nil)
SDL.RenderPresent(render)
event = SDL.Event.new()
repeat SDL.WaitEvent(event) until event:type() == SDL.QUIT
SDL.DestroyTexture(texture)
SDL.DestroyRenderer(render)
SDL.DestroyWindow(window)

