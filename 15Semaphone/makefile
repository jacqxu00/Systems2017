all: control.o main.o
	gcc -o control control.o main.o

control.o: control.c
	gcc -c control.c

main.o: main.c
	gcc -c main.c

run: all


clean: 
	rm -rf control
	rm -rf story.txt
	rm -rf control.o
	rm -rf main.o

