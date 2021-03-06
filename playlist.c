#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "songs.h"
#include "playlist.h"

void add_song(song_node** playlist, char * name, char * artist){
    char first = artist[0];
    song_node* slot = playlist[first - 'a'];
    if(slot == 0) {
        playlist[first - 'a'] = (song_node *)malloc(sizeof(song_node));
        slot = playlist[first - 'a'];
        strcpy(slot->name, name);
        strcpy(slot->artist, artist);
    } else {
        playlist[first - 'a'] = insert_ordered(slot, name, artist);
    }
}

song_node* search_song(char *song, song_node** playlist){
    int i = 0;
    for(; i < 26; i++){
        if(find_by_name(playlist[i], song)){
            return find_by_name(playlist[i], song);
        }
    }
    return 0;
}

song_node* search_artist(char *artist, song_node **playlist){
    char first = artist[0];
    return find_by_artist(playlist[first-97], artist);
}

void print_letter(char letter, song_node **playlist){
    print_list(playlist[letter - 'a']);
}

void artist_songs(char *artist, song_node **playlist){
    song_node* slot = search_artist(artist, playlist);
    if (slot == 0) {
        return;
    }
    // Move slot up to the first song by `artist`
    while (slot != 0 && strcmp(slot->artist, artist) != 0) {
        slot = slot->next;
    }
    // Print out each song by `artist`
    while (slot != 0 && strcmp(slot->artist, artist) == 0){
        printf("%s\n", slot->name);
        slot = slot->next;
    }
}

void print_library(song_node *playlist[26]){
    int i = 0;
    if(playlist[0] != 0){
        for(; i < 26; i++){
            if (playlist[i] != 0) {
                printf("%c:\n", (char) i + 'A');
                print_list(playlist[i]);
            }
        }
    }
}

void shuffle(song_node **playlist, int leng){
    song_node * temp;
    song_node* songs;
    while (leng > 0) {
        songs = playlist[rand() % 26];
        if (songs != 0) {
            temp = select_random(songs);
            printf("%s - %s\n", temp->name, temp->artist);
            leng -= 1;
        }
    }

}

int delete_song(char *name, char *artist, song_node **playlist){
    song_node* node = find_song(playlist[artist[0] - 'a'], name, artist);
    if (node == 0) {
        return 1;
    }
    playlist[artist[0] - 'a'] = remove_node(playlist[artist[0] - 'a'], node);
    return 0;
}

void delete_nodes(song_node **playlist){
    int i = 0;
    for(; i < 26; i++){
        playlist[i] = 0;
        free_list(playlist[i]);
    }

}
