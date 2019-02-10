all: main.c line.h
	gcc main.c
	
run:
	./a.out

clean:
	rm a.out
