compile_flags = -g3 -O0 -Wall -Werror 

.PHONY: clean open

./bin/board : ./build/main.o ./build/board.o ./build/check_strokes.o bin 
		gcc $(compile_flags) -o ./bin/board ./build/main.o ./build/board.o ./build/check_strokes.o -lm

./build/main.o : ./src/main.c ./src/board.h build
		gcc $(compile_flags) -o build/main.o -c src/main.c -lm

./build/board.o : ./src/board.c ./src/board.h build
		gcc $(compile_flags) -o ./build/board.o -c ./src/board.c -lm

./build/check_strokes.o : ./src/check_strokes.c ./src/check_strokes.h build
		gcc $(compile_flags) -o ./build/check_strokes.o -c ./src/check_strokes.c -lm
build:
	mkdir build

bin:
	mkdir bin

clean:
	rm -rf build bin

open:
	./bin/board