CC=g++
CFLAGS=-std=c++11 -g -fPIC
OBJ=array.so audio.so clipboard.so cpuinfo.so error.so events.so filesystem.so gamecontroller.so gesture.so gfx.so haptic.so hints.so image.so joystick.so keys.so main.so messagebox.so mixer.so mouse.so mutex.so net.so opengl.so pixels.so platform.so power.so rect.so render.so rwops.so shape.so stdinc.so surface.so thread.so timer.so touch.so ttf.so version.so video.so
LIB=$(addprefix SDL/,$(OBJ))

all: $(LIB)

clean:
	rm $(LIB)

SDL/%.so: src/%.cc src/Common.h
	$(CC) $(CFLAGS) -shared $< -o $@ -lSDL2

SDL/ttf.so: src/ttf.cc src/Common.h
	$(CC) $(CFLAGS) -shared $< -o $@ -lSDL2_ttf

SDL/image.so: src/image.cc src/Common.h
	$(CC) $(CFLAGS) -shared $< -o $@ -lSDL2_image

SDL/mixer.so: src/mixer.cc src/Common.h
	$(CC) $(CFLAGS) -shared $< -o $@ -lSDL2_mixer

SDL/net.so: src/net.cc src/Common.h
	$(CC) $(CFLAGS) -shared $< -o $@ -lSDL2_net

SDL/gfx.so: src/gfx.cc src/Common.h
	$(CC) $(CFLAGS) -shared $< -o $@ -lSDL2_gfx

