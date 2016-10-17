all: songs.c
	gcc songs.c -c
	gcc songs.o driver.c

run: all
	./a.out
