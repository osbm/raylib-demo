all: clean compile run

run:
	./main

compile:
	gcc -o main main.c -lraylib

clean:
	if [ -f main ]; then rm main; fi
