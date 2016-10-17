#include <stdio.h>
#include <stdlib.h>
#include "songs.h"

int main() {
  song_node plist[26];

  add_song(plist, "time", "pinkfloyd");
  add_song(plist, "thunderstruck", "acdc");
  add_song(plist, "alive", "pearl jam"); 

  print_library(plist);
  
  
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

    printf("songs has %d songs\n\n", count_songs(songs));

    // Test random selection
    printf("random selection:\n");
    print_list(select_random(songs));
    printf("\n\n");

    printf("random selection:\n");
    print_list(select_random(songs));
    printf("\n\n");

    printf("random selection:\n");
    print_list(select_random(songs));
    printf("\n\n");

    printf("random selection:\n");
    print_list(select_random(songs));
    printf("\n\n");

    printf("random selection:\n");
    print_list(select_random(songs));
    printf("\n\n");

    // Test removal
    songs = remove_node(songs, songs->next);
    printf("songs with its second entry removed:\n");
    print_list(songs);
    printf("\n\n");

    free_list(songs);
    return 0;
}
