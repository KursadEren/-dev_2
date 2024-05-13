all: compile run

compile:
	gcc -I./include/ -o ./lib/Read.o -c ./src/Read.c
	gcc -I./include/ -o ./lib/Canli.o -c ./src/Canli.c
	gcc -I./include/ -o ./lib/LinkedList.o -c ./src/LinkedList.c
	gcc -I./include/ -o ./lib/Bitki.o -c ./src/Bitki.c
	gcc -I./include/ -o ./lib/Bocek.o -c ./src/Bocek.c
	gcc -I./include/ -o ./lib/Pire.o -c ./src/Pire.c
	gcc -I./include/ -o ./lib/Sinek.o -c ./src/Sinek.c
	gcc -I./include/ -o ./lib/Node.o -c ./src/Node.c
	gcc -I./include/ -o ./lib/Habitat.o -c ./src/Habitat.c
	gcc -I./include/ -o ./bin/main ./src/main.c ./lib/Read.o ./lib/Canli.o ./lib/LinkedList.o ./lib/Bitki.o ./lib/Bocek.o ./lib/Pire.o ./lib/Sinek.o ./lib/Node.o  ./lib/Habitat.o       

run:
	./bin/main
