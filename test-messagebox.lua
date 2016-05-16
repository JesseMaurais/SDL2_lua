SDL = require'SDL2'
require'SDL2.messagebox'

SDL.ShowSimpleMessageBox(SDL.MESSAGEBOX_INFORMATION, "Hello World!",
	"This is simple messagebox. Click OK to see another kind.", nil)

labels = {"OKAY?", "Not OKAY!", "OMG Abort!!!"}
id = SDL.ShowMessageBox{
	flags=SDL.MESSAGEBOX_WARNING,
	title="WARNING!",
	message="Nothing to worry about. Just click OKAY.",
	buttons=labels
	}

print('You picked ' .. labels[id])

