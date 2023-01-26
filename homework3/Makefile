all: bitstate.o robot.out

bitstate.o: bitstate.h bitstate.c
	gcc -c bitstate.c -o bitstate.o

robot.out: robot.c bitstate.o
	gcc robot.c bitstate.o -o robot.out

clean: 
	rm -f *.o *.out