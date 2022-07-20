all:
	gcc -Wall word.c -o word
install:
	sudo cp word /bin/word
