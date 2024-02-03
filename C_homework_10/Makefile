all: homework_10

homework_10: main.o task01.o task02.o task03.o stack.o
	gcc -o homework_10 main.o task01.o task02.o task03.o stack.o

main.o: main.c task01.h 
	gcc -c -o main.o main.c

task01.o: task01.c task01.h stack.h
	gcc -c -o task01.o task01.c

task02.o: task02.c task02.h
	gcc -c -o task02.o task02.c

task03.o: task03.c task03.h
	gcc -c -o task03.o task03.c

stack.o: stack.c stack.h
	gcc -c -o stack.o stack.c

clean:
	del *.o
	del homework_10.exe

