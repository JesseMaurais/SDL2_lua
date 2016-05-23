#!/usr/bin/env lua
SDL = require'SDL2'
require'SDL2.power'

state, seconds, percent = SDL.GetPowerInfo()

if state == SDL.POWERSTATE_UNKNOWN then
	print 'Power state unknown'
elseif  state == SDL.POWERSTATE_ON_BATTERY then
	print 'Running on battery'
elseif state == SDL.POWERSTATE_NO_BATTERY then
	print 'No battery available'
elseif state == SDL.POWERSTATE_CHARGING then
	print 'Charging battery'
elseif state == SDL.POWERSTATE_CHARGED then
	print 'Battery charged'
end

if seconds > 0 then
	print(string.format('%d seconds remaining', seconds))
end

if percent > 0 then
	print(string.format('%d percent remaining', percent))
end

