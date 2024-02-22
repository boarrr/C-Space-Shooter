CC := /usr/bin/gcc
CFLAGS := -I/opt/homebrew/include/SDL2 -D_THREAD_SAFE
LDFLAGS := -L/opt/homebrew/lib
LDLIBS := -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
SRC := $(wildcard *.c)
TARGET := pewpew

all:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) $(LDLIBS) -o $(TARGET) && ./$(TARGET)

clean:
	rm -f $(TARGET)
