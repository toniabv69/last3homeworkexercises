all: processes.o taskmanager.out

processes.o: processes.c processes.h
	gcc -c processes.c -o processes.o

taskmanager.out:
	gcc taskmanager.c processes.o -o taskmanager.out

clean:
	rm -f *.o *.out
