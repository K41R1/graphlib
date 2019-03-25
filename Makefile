build:
	gcc -O2 -I ./ *.c -o main -Wall
	./main
	rm main

show:
	gcc -O2 -I ./ -E *.c > preprocessed
	cat preprocessed | less
	rm preprocessed

debug:
	gcc -I ./ *.c -g -o main
	gdb main
	rm main

test:
	gcc -O2 -I ./ test.c -o test -Wall
	./test
	rm test
