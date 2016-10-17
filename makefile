all: songs.c
	gcc songs.c -c
	gcc playlist.c -c
	gcc songs.o playlist.o driver.c

run: all
	./a.out
