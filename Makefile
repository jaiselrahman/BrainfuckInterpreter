CC=gcc
PREFIX=/usr/local

bf: brainfuck.c
	$(CC) -o bf brainfuck.c

install: bf
	cp ./bf $(PREFIX)/bin

uninstall:
	rm $(PREFIX)/bin/bf

clean:
	rm ./bf	
