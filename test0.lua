#!/usr/bin/lua

SDL = require'SDL'
require'SDL.audio'
require'SDL.clipboard'
require'SDL.cpuinfo'
require'SDL.error'
require'SDL.events'
require'SDL.gamecontroller'
GL = require'SDL.GL'
require'SDL.haptic'
require'SDL.hints'
require'SDL.joystick'
require'SDL.keys'
require'SDL.mouse'
require'SDL.pixels'
require'SDL.rect'
require'SDL.render'
require'SDL.rwops'
require'SDL.std'
require'SDL.surface'
require'SDL.timer'
require'SDL.video'

for key in pairs(SDL) do
	print(key)
end

for key in pairs(GL) do
	print(key)
end

