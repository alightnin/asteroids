CC=g++
INCLUDES=
CFLAGS=-O0 $(INCLUDES) -g -Wall -Wextra
LPATHS=-L../lib/fftwl -L../lib/linux/
LDFLAGS:=-lSDL -lSDL_gfx -lSDL_image -lSDL_mixer
SOURCES=CSurface.cpp game.cpp mixer.cpp game_events.cpp ship.cpp
OBJECTS=$(SOURCES:.c=.o)
BINARY=asteroids_n_stuff

all: $(BINARY) $(OBJECTS)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(BINARY): $(OBJECTS)
	 $(CC) $(CFLAGS) $(LPATHS) $(OBJECTS) -o $@ $(LDFLAGS)

clean:
	 rm -v $(BINARY) *.o
