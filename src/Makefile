CC=g++
INCLUDES=
CFLAGS=-O0 $(INCLUDES) -g -Wall -Wextra
LPATHS=-L../lib/fftwl -L../lib/linux/
LDFLAGS:=-lfftw3 -lSDL -lSDL_image -lSDL_mixer
SOURCES=CSurface.cpp fftw.cpp game.cpp mixer.cpp set_up.cpp
OBJECTS=$(SOURCES:.c=.o)
BINARY=asteroids_n_stuff

all: $(BINARY) $(OBJECTS)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(BINARY): $(OBJECTS)
	 $(CC) $(CFLAGS) $(LPATHS) $(OBJECTS) -o $@ $(LDFLAGS)

clean:
	 rm -v $(BINARY) *.o
