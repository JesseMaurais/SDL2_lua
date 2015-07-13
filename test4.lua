#!/usr/bin/lua

SDL = require 'SDL'
TTF = require 'TTF'
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
repeat SDL.WaitEvent(SDL.event) until SDL.event.type == SDL.QUIT
SDL.DestroyWindow(window)
