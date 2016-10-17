#include <stdio.h>
#include "songs.h"

int main() {
    // Test insertion functions:
    song_node* songs = insert_front(0, "time", "pink floyd");
    songs = insert_ordered(songs, "thunderstruck", "ac/dc");
    songs = insert_ordered(songs, "alive", "pearl jam");
    print_list(songs);

    // Test find_by_name:
    printf("find_by_name(songs, \"alive\") -->\n");
    print_list(find_by_name(songs, "alive"));
    printf("\n");

    printf("find_by_name(songs, \"thunderstruck\") -->\n");
    print_list(find_by_name(songs, "thunderstruck"));
    printf("\n");

    printf("find_by_name(songs, \"time\") -->\n");
    print_list(find_by_name(songs, "time"));
    printf("\n");

    printf("find_by_name(songs, \"sympathy for the devil\") -->\n");
    print_list(find_by_name(songs, "sympathy for the devil"));
    printf("\n");

    // Test find_by_artist:
    printf("find_by_artist(songs, \"pearl jam\") -->\n");
    print_list(find_by_artist(songs, "pearl jam"));
    printf("\n");

    printf("find_by_artist(songs, \"ac/dc\") -->\n");
    print_list(find_by_artist(songs, "ac/dc"));
    printf("\n");

    printf("find_by_artist(songs, \"pink floyd\") -->\n");
    print_list(find_by_artist(songs, "pink floyd"));
    printf("\n");

    printf("find_by_artist(songs, \"rolling stones\") -->\n");
    print_list(find_by_artist(songs, "rolling stones"));
    printf("\n");

    free_list(songs);
    return 0;
}
