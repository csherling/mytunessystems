#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "songs.h"
#include "playlist.h"

int main() {
    srand(time(NULL));
    song_node* plist[26];
    int i;
    for (i = 0; i < 26; i++) {
        plist[i] = 0;
    }

    add_song(plist, "time", "pink floyd");
    add_song(plist, "thunderstruck", "acdc");
    add_song(plist, "alive", "pearl jam");
    add_song(plist, "back in black", "acdc");
    add_song(plist, "alivennn", "pearl jamnnn");
    add_song(plist, "fireflies", "owl city");
    add_song(plist, "viva la vida", "coldplay");
    add_song(plist, "check yes juliet", "we the kings");
    add_song(plist, "talking to the moon", "bruno mars");
    add_song(plist, "skywave avenue", "we the kings");
    add_song(plist, "vanilla twilight", "owl city");

    printf("Library:\n");
    print_library(plist);
    printf("\n\n");

    printf("Searching for various things:\n");
    printf("For time (song):\n");
    print_song(search_song("time", &plist[0]));

    printf("For a song by acdc:\n");
    print_song(search_artist("acdc", &plist[0]));

    printf("For a song by pearl jam:\n");
    print_song(search_artist("pearl jam", &plist[0]));

    printf("\n\n");

    printf("Songs under a given letter:\n");
    printf("Under 'a':\n");
    print_letter('a', &plist[0]);
    printf("Under 'p':\n");
    print_letter('p', &plist[0]);
    printf("\n\n");

    printf("shuffle of 10 songs:\n");
    shuffle(plist, 10);
    printf("\n\n");

    printf("Getting songs of a particular artist:\n");
    printf("songs by pearl jam:\n");
    artist_songs("pearl jam", plist);
    printf("\nsongs by acdc:\n");
    artist_songs("acdc", plist);
    printf("\nsongs by pink floyd:\n");
    artist_songs("pink floyd", plist);
    printf("\n\n");

    printf("Deleting songs:\n");
    delete_song("time","pink floyd", &plist[0]);
    printf("deleted time by pink floyd. What's left in plist:\n");
    print_library(plist);
    printf("(end of nodes)\n\n");

    delete_nodes(plist);
    printf("deleted all. What's left in plist:\n");
    print_library(plist);
    printf("(end of nodes)\n\n\n");

    printf("--------------------------------------------\n");
    printf("Tests for linked list functionality\n");

    printf("Testing insertion functions:\n");
    song_node* songs = insert_front(0, "time", "pink floyd");
    songs = insert_ordered(songs, "thunderstruck", "ac/dc");
    songs = insert_ordered(songs, "alive", "pearl jam");
    print_list(songs);
    printf("\n\n");

    printf("Test finding functions:\n");

    // Test find_by_name:
    printf("find_by_name(songs, \"alive\") -->\n");
    print_song(find_by_name(songs, "alive"));
    printf("\n");

    printf("find_by_name(songs, \"thunderstruck\") -->\n");
    print_song(find_by_name(songs, "thunderstruck"));
    printf("\n");

    printf("find_by_name(songs, \"time\") -->\n");
    print_song(find_by_name(songs, "time"));
    printf("\n");

    printf("find_by_name(songs, \"sympathy for the devil\") -->\n");
    print_song(find_by_name(songs, "sympathy for the devil"));
    printf("\n");

    // Test find_by_artist:
    printf("find_by_artist(songs, \"pearl jam\") -->\n");
    print_song(find_by_artist(songs, "pearl jam"));
    printf("\n");

    printf("find_by_artist(songs, \"ac/dc\") -->\n");
    print_song(find_by_artist(songs, "ac/dc"));
    printf("\n");

    printf("find_by_artist(songs, \"pink floyd\") -->\n");
    print_song(find_by_artist(songs, "pink floyd"));
    printf("\n");

    printf("find_by_artist(songs, \"rolling stones\") -->\n");
    print_song(find_by_artist(songs, "rolling stones"));
    printf("\n\n");

    printf("Testing random selection of song nodes:\n");

    printf("random selection:\n");
    print_song(select_random(songs));
    printf("\n\n");

    printf("random selection:\n");
    print_song(select_random(songs));
    printf("\n\n");

    printf("random selection:\n");
    print_song(select_random(songs));
    printf("\n\n");

    printf("random selection:\n");
    print_song(select_random(songs));
    printf("\n\n");

    printf("random selection:\n");
    print_song(select_random(songs));
    printf("\n\n\n");

    printf("Testing removal functions:\n");

    printf("Initial `songs`:\n");
    print_list(songs);

    songs = remove_node(songs, songs->next->next);
    printf("...now with its third entry removed:\n");
    print_list(songs);
    printf("\n");

    songs = remove_node(songs, songs);
    printf("...and with its first entry removed:\n");
    print_list(songs);
    printf("\n\n");

    printf("Freeing `songs`\n");
    free_list(songs);
    return 0;
}
