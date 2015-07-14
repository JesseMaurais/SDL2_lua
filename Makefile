CC=g++
CFLAGS=-std=c++11 -fpic
SRC=audio.cc clipboard.cc cpuinfo.cc error.cc events.cc filesystem.cc gamecontroller.cc gesture.cc GL.cc haptic.cc hints.cc joystick.cc keys.cc messagebox.cc mouse.cc pixels.cc rect.cc render.cc rwops.cc shape.cc std.cc surface.cc timer.cc touch.cc video.cc
OBJ=$(SRC:%.cc=SDL/%.so)

all: $(OBJ) SDL.so TTF.so IMG.so Mix.so Net.so GFX.so

clean:
	rm SDL/*.so *.so

SDL/%.so: src/%.cc src/SDL.hpp
	$(CC) $(CFLAGS) -shared $< -o $@ -llux -lSDL2

SDL.so: src/SDL.cc src/SDL.hpp
	$(CC) $(CFLAGS) -shared src/SDL.cc -o SDL.so -llux -lSDL2

TTF.so: src/TTF.cc src/SDL.hpp
	$(CC) $(CFLAGS) -shared src/TTF.cc -o TTF.so -llux -lSDL2_ttf

IMG.so: src/IMG.cc src/SDL.hpp
	$(CC) $(CFLAGS) -shared src/IMG.cc -o IMG.so -llux -lSDL2_image

Mix.so: src/Mix.cc src/SDL.hpp
	$(CC) $(CFLAGS) -shared src/Mix.cc -o Mix.so -llux -lSDL2_mixer

Net.so: src/Net.cc src/SDL.hpp
	$(CC) $(CFLAGS) -shared src/Net.cc -o Net.so -llux -lSDL2_net

GFX.so: src/GFX.cc src/SDL.hpp
	$(CC) $(CFLAGS) -shared src/GFX.cc -o GFX.so -llux -lSDL2_gfx

test:
	lua -e 'require "SDL"'
