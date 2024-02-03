all: sensor

sensor: main.o sensor.o
	gcc -o sensor main.o sensor.o

main.o: main.c sensor.h
	gcc -c -o main.o main.c

sensor.o: sensor.c sensor.h
	gcc -c -o sensor.o sensor.c

clean:
	del *.o
	del sensor.exe

