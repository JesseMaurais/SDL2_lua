SDL = require 'SDL2'
require 'SDL2.video'
require 'SDL2.timer'

pos = SDL.WINDOWPOS_CENTERED
window = SDL.CreateWindow('Test Window', pos, pos, 400, 300, SDL.SHOWN)
SDL.Delay(5000)
SDL.HideWindow(window)
SDL.DestroyWindow(window)
