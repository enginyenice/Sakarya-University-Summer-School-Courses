hepsi:program starter
program:FileOperation LuhnAlgorithm main
	gcc ./obj/FileOperation.o ./obj/LuhnAlgorithm.o ./obj/main.o -o ./bin/Program
main:
	gcc -c ./src/main.c -o ./obj/main.o
	
FileOperation: ./lib/FileOperation.h
	gcc -c ./src/FileOperation.c  -o ./obj/FileOperation.o
LuhnAlgorithm: ./lib/LuhnAlgorithm.h
	gcc -c ./src/LuhnAlgorithm.c  -o ./obj/LuhnAlgorithm.o
starter:
	./bin/Program