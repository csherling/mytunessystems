void add_song(song_node *song, song_node *playlist);
song_node* search_song(char *song, song_node *playlist);
song_node* search_artist(char *artist, song_node *playlist);
void print_letter(char letter, song_node *playlist);
void artist_songs(char *artist, song_node *playlist);
void print_library(song_node *playlist);
void shuffle(song_node *playlist);
void delete_song(char *song, song_node *playlist);
void delete_nodes(song_node *playlist);
