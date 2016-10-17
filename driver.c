#include "songs.h"

int main() {
    song_node* songs = insert_front(0, "time", "pink floyd");
    songs = insert_ordered(songs, "thunderstruck", "ac/cd");
    songs = insert_ordered(songs, "alive", "pearl jam");
    print_list(songs);
    free_list(songs);
    return 0;
}
