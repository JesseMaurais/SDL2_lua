SDL = require'SDL'
require'SDL.timer'

count = 1
function TimerCallback(interval)
	print(count)
	count = count + 1
	return TimerCallback, interval
end

SDL.AddTimer(1000, TimerCallback)
SDL.Delay(5000)
