CC = clang
CFLAGS= -std=c17 -Wall -Wextra -ggdb 
LIBS= -lraylib -lm -ldl -lpthread -lglfw -lc
CFILES = ./src/game.c ./src/main.c

clean:
	rm ./bin/*

build: 
	mkdir -p bin
	${CC} ${CFLAGS} -o ./bin/main ${CFILES} ${LIBS}

run: build
	./bin/main

build-game:
	${CC} ${CFLAGS} -fPIC -shared -o ./bin/libgame.so ./src/game.c ${LIBS}

build-base: build-game
	${CC} -I./bin/ ${CFLAGS} -o ./bin/main ./src/main.c ${LIBS} -Wl,-rpath=./bin/ -L./bin/
