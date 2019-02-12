build:
	gcc -O2 -I ./ *.c -o main
	./main
	rm main

show:
	gcc -O2 -I ./ -E *.c > preprocessed
	cat preprocessed | less
	rm preprocessed

debug:
	gcc -O2 -I ./ *.c -g -o main
	gdb main
	rm main
