SDL = require'SDL'
require'SDL.thread'

function Concat(a, b) return a .. b end

thread = SDL.CreateThread(Concat, 'Hello ', 'World!')
print('The thread message is: ')
string = SDL.WaitThread(thread)
print(string)

