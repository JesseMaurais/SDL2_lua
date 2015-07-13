#!/usr/bin/lua

SDL = require 'SDL'
IMG = require 'IMG'
require 'SDL.video'
require 'SDL.events'
require 'SDL.surface'
require 'SDL.render'

image = IMG.Load('Logo.png')
window, render = SDL.CreateWindowAndRenderer(image.w, image.h, SDL.WINDOW_SHOWN)
texture = SDL.CreateTextureFromSurface(render, image)
SDL.FreeSurface(image)
SDL.RenderClear(render)
SDL.RenderCopy(render, texture, nil, nil)
SDL.RenderPresent(render)
repeat SDL.WaitEvent(SDL.event) until SDL.event.type == SDL.QUIT
SDL.DestroyTexture(texture)
SDL.DestroyRenderer(render)
SDL.DestroyWindow(window)
