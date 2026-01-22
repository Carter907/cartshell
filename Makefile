build: main.c
	mkdir build
	gcc -o crsh -std=c23 -g -Wall -Werror -Wconversion -fanalyzer -fsanitize=address,undefined,leak -fsanitize-trap=undefined main.c
	mv crsh ./build

debug: clean build
	gdb ./build/crsh

run: clean build
	./build/crsh

clean:
	rm -rf ./build

