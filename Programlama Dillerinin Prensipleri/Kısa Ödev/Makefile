BIN = ./bin/
INC = ./include/
LIB= ./lib/
SRC= ./src/

buildandrun:program starter
program:main
	gcc ${LIB}main.o -o ${BIN}program

main:
	gcc -c ${SRC}main.c -o ${LIB}main.o

starter:
	${BIN}program.exe