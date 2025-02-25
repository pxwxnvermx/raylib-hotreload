CC = clang
CFLAGS= -std=c17 -Wall -Wextra -ggdb -Werror
LIBS= -lraylib -lm -ldl -lpthread -lglfw -lc
CFILES = ./src/game.c ./src/main.c

run: bin/libgame.so bin/main 
	./bin/main

bin/libgame.so: src/game.c
	${CC} ${CFLAGS} -fPIC -shared -o ./bin/libgame.so ./src/game.c ${LIBS}

bin/main: src/main.c 
	${CC} -I./bin/ ${CFLAGS} -o ./bin/main ./src/main.c ${LIBS} -Wl,-rpath=./bin/ -L./bin/


clean:
	mkdir -p bin
	rm -f ./bin/*

full: ${CFILES}
	${CC} ${CFLAGS} -o ./bin/full_main ${CFILES} ${LIBS}
