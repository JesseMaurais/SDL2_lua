SDL = require 'SDL'
require 'SDL.video'
require 'SDL.timer'

pos = SDL.WINDOWPOS_CENTERED
window = SDL.CreateWindow('Test Window', pos, pos, 400, 300, SDL.SHOWN)
SDL.Delay(5000)
SDL.HideWindow(window)
SDL.DestroyWindow(window)
