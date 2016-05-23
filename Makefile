CC=g++
CFLAGS=-std=c++11 -g -fPIC
OBJ=array.so audio.so clipboard.so cpuinfo.so error.so events.so filesystem.so gamecontroller.so gesture.so gfx.so haptic.so hints.so image.so joystick.so keys.so main.so messagebox.so mixer.so mouse.so mutex.so net.so opengl.so pixels.so platform.so power.so rect.so render.so rwops.so shape.so stdinc.so surface.so thread.so timer.so touch.so ttf.so version.so video.so
LIB=$(addprefix lib/, $(OBJ))
DIR=/usr/local/lib/lua/5.3/SDL2/

all: $(LIB)

clean:
	rm $(LIB)

install: $(LIB)
	mkdir -p $(DIR)
	cp $(LIB) $(DIR)
	cp lib/init.lua $(DIR)

uninstall:
	rm $(addprefix $(DIR), init.lua)
	rm $(addprefix $(DIR), $(OBJ))
	rmdir $(DIR)

lib/%.so: src/%.cc src/Common.h
	$(CC) $(CFLAGS) -shared $< -o $@ -lSDL2

lib/ttf.so: src/ttf.cc src/Common.h
	$(CC) $(CFLAGS) -shared $< -o $@ -lSDL2_ttf

lib/image.so: src/image.cc src/Common.h
	$(CC) $(CFLAGS) -shared $< -o $@ -lSDL2_image

lib/mixer.so: src/mixer.cc src/Common.h
	$(CC) $(CFLAGS) -shared $< -o $@ -lSDL2_mixer

lib/net.so: src/net.cc src/Common.h
	$(CC) $(CFLAGS) -shared $< -o $@ -lSDL2_net

lib/gfx.so: src/gfx.cc src/Common.h
	$(CC) $(CFLAGS) -shared $< -o $@ -lSDL2_gfx

