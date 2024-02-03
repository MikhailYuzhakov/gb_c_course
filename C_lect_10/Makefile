all: stack

stack: main.o stack.o queue.o filesystem.o
	gcc -o stack main.o stack.o queue.o filesystem.o

main.o: main.c stack.h queue.h filesystem.h
	gcc -c -o main.o main.c

queue.o: queue.c queue.h
	gcc -c -o queue.o queue.c

filesystem.o: filesystem.c filesystem.h
	gcc -c -o filesystem.o filesystem.c

stack.o: stack.c stack.h
	gcc -c -o stack.o stack.c

clean:
	del *.o
	del stack.exe

