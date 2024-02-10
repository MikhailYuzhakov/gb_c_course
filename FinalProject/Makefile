all: sensor

sensor: main.o temp_functions.o common.o
	gcc -o sensor main.o temp_functions.o common.o

main.o: main.c temp_functions.h common.h
	gcc -c -o main.o main.c

temp_functions.o: temp_functions.c temp_functions.h common.h
	gcc -c -o temp_functions.o temp_functions.c

common.o: common.c common.h
	gcc -c -o common.o common.c

clean:
	del *.o
	del sensor.exe