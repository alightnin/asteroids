CC=g++
INCLUDES=
CFLAGS=-O0 $(INCLUDES) -g -Wall -Wextra
LPATHS=-L../lib/linux/
LDFLAGS:=-lSDL -lSDL_mixer
SOURCES=CSurface.cpp game.cpp game_OnInit.cpp mixer.cpp  
OBJECTS=$(SOURCES:.c=.o)
BINARY=asteroids_n_stuff

all: $(BINARY) $(OBJECTS)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(BINARY): $(OBJECTS)
	 $(CC) $(CFLAGS) $(LPATHS) $(OBJECTS) -o $@ $(LDFLAGS)

clean:
	 rm -rf $(BINARY) $(OBJECTS) *.o
