all: exec

display.o : display.c display.h params.h
			gcc -c display.c -o display.o


main.o : main.c main.h params.h
			gcc -c main.c -o main.o


exec : main.o func.o display.o
			gcc -c main.o func.o display.o -o exec


clean:
    rm -f *.o
	rm -f exec
