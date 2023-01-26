all: quadraticroots.o main.out

quadraticroots.o: quadraticroots.c quadraticroots.h
	gcc -c quadraticroots.c -o quadraticroots.o

main.out: quadraticroots.o main.c
	gcc main.c quadraticroots.o -lm -o main.out

clean:
	rm -f *.o *.out