songs: songs.c
	gcc songs.c -o songs

test: songs.c
	gcc songs.c -g

run: songs
	./songs
