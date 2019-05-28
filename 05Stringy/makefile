all: work05.o main.o
	gcc -o work05 work05.o main.o

dwstring.o: work05.c work05.h
	gcc -c work05.c

main.o: main.c work05.h
	gcc -c main.c

clean:
	rm *.o
	rm *~

run: all
	./work05
