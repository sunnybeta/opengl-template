CC = gcc

CFLAGS = -ggdb -Wall -Wextra -std=c11
INCFLAGS = -Ilib/glfw/include -Ilib/glad/include
LDFLAGS = lib/glad/src/gl.o -Llib/glfw/src -lglfw3 -lm -lpthread -ldl

SRC = $(wildcard  src/*.c)
OBJ = $(SRC:.c=.o)
BIN = bin

all: dirs libs gello

dirs:
	mkdir -p $(BIN)

gello: $(OBJ)
	$(CC) -o $(BIN)/$@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCFLAGS)

libs:
	cd lib/glfw && cmake -D GLFW_BUILD_EXAMPLES=OFF -D GLFW_BUILD_DOCS=OFF -D GLFW_BUILD_TESTS=OFF . && make
	cd lib/glad && $(CC) -o src/gl.o -c src/gl.c -Iinclude

clean:
	rm -rf $(OBJ) $(BIN) lib/glad/src/glad.o
