SDL = require'SDL2'
require'SDL2.version'

major, minor, patch = SDL.GetVersion()
revision = SDL.GetRevision()

print(string.format('SDL %d.%d.%d %s', major, minor, patch, revision))

