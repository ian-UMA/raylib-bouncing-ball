game = "bounce"
CC = cc
C_LIBS = `pkgconf --cflags raylib`
L_LIBS = `pkgconf --libs raylib`

all: $(game)

$(game): main.c
	$(CC) -o $@ -Wall -Werror -pedantic $(C_LIBS) $(L_LIBS) $^

.PHONY: clean
clean:
	rm $(game) *.o
